/*
 * Copyright 2023 The Nodepp Project Authors. All Rights Reserved.
 *
 * Licensed under the MIT (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://github.com/NodeppOficial/nodepp/blob/main/LICENSE
 */

/*────────────────────────────────────────────────────────────────────────────*/

#ifndef NODEPP_EXPRESS_HTTPS
#define NODEPP_EXPRESS_HTTPS

/*────────────────────────────────────────────────────────────────────────────*/

#define MIDDL function_t<void,express_https_t&,function_t<void>>
#define CALBK function_t<void,express_https_t&>

/*────────────────────────────────────────────────────────────────────────────*/

#include <nodepp/nodepp.h>

#include <nodepp/optional.h>
#include <nodepp/cookie.h>
#include <nodepp/stream.h>
#include <nodepp/https.h>
#include <nodepp/http.h>
#include <nodepp/path.h>
#include <nodepp/json.h>
#include <nodepp/zlib.h>
#include <nodepp/url.h>
#include <nodepp/fs.h>

/*────────────────────────────────────────────────────────────────────────────*/

#ifndef NODEPP_EXPRESS_GENERATOR
#define NODEPP_EXPRESS_GENERATOR
namespace nodepp { namespace _express_ { 


     GENERATOR( ssr ) {
     protected:

          ptr_t<bool> state = new bool(0);
          array_t<ptr_t<ulong>> match;
          string_t      raw, dir;
          ulong         pos, sop;
          _file_::write gen;
          ptr_t<ulong>  reg;
          ptr_t<ssr>    cb;

     public:

          template< class T >
          coEmit( T& str, string_t path ){
               if( !str.is_available() ){ return -1; }
          gnStart

               if( !url::is_valid( path ) ){
               if( !fs::exists_file(path) ){ coGoto(1); }
                    
                    do{ auto file = fs::readable(path);
                              raw = stream::await(file);
                              gen = _file_::write(); pos=0; sop=0;
                            match = regex::search_all(raw,"<°[^°]+°>");
                    } while(0); while( sop != match.size() ){ 
                         
                         reg = match[sop]; cb = new ssr(); do {
                         auto war = raw.slice( reg[0], reg[1] );
                              dir = regex::match( war,"[^<°> \n\t]+" );
                         } while(0);

                         while( gen( &str, raw.slice( pos, reg[0] ) )==1 )
                              { coNext; } pos = match[sop][1]; sop++;

                         while( (*cb)( str, dir )==1 ){ coNext; }

                    } while( gen( &str, raw.slice( pos ) )==1 ){ coNext; }

               } else {

                    if( url::protocol(path)=="http" ){ do {
                         auto self = type::bind( this );
                         fetch_t args; *state=1;

                         args.url     = path;
                         args.method  = "GET";
                         args.headers = header_t({
                              { "Params", query::format( str.params ) },
                              { "User-Agent", "Nodepp Fetch" },
                              { "Host", url::hostname(path) }
                         });

                         http::fetch( args ).fail([=](...){ *self->state=0; })
                                            .then([=]( http_t cli ){
                              if( !str.is_available() ){ return; }
                              cli.onData([=]( string_t data ){ str.write(data); });
                              cli.onDrain.once([=](){ *self->state=0; });
                              stream::pipe( cli );
                         });

                    } while(0); while( *state==1 ){ coNext; } }

                    elif( url::protocol(path)=="https" ){ do {
                         ssl_t ssl; fetch_t args; *state=1;
                         auto self = type::bind( this );

                         args.url     = path;
                         args.method  = "GET";
                         args.headers = header_t({
                              { "Params", query::format( str.params ) },
                              { "User-Agent", "Nodepp Fetch" },
                              { "Host", url::hostname(path) }
                         });

                         https::fetch( args, &ssl ).fail([=](...){ *self->state=0; })
                                                   .then([=]( https_t cli ){
                              if( !str.is_available() ){ return; }
                              cli.onData([=]( string_t data ){ str.write(data); });
                              cli.onDrain.once([=](){ *self->state=0; });
                              stream::pipe( cli );
                         });

                    } while(0); while( *state==1 ){ coNext; } }

                    else { coYield(1);
                    
                         do{  raw = path;
                              gen = _file_::write(); pos=0; sop=0;
                            match = regex::search_all(raw,"<°[^°]+°>");
                         } while(0); while( sop != match.size() ){ 
                              
                              reg = match[sop]; cb = new ssr(); do {
                              auto war = raw.slice( reg[0], reg[1] );
                                   dir = regex::match( war,"[^<°> \n\t]+" );
                              } while(0);

                              while( gen( &str, raw.slice( pos, reg[0] ) )==1 )
                                   { coNext; } pos = match[sop][1]; sop++;

                              while( (*cb)( str, dir )==1 ){ coNext; }

                         } while( gen( &str, raw.slice( pos ) )==1 ){ coNext; }

                    }

               }

          gnStop
          }

     };

}}
#endif

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { class express_https_t : public https_t { 
protected:

    struct NODE {
        header_t _headers; 
        cookie_t _cookies;
        uint  status= 200;
        int    state= 1;
    };  ptr_t<NODE> exp;

public: query_t params;

     express_https_t ( https_t& cli ) noexcept : https_t( cli ), exp( new NODE() ) { exp->state = 1; }

    ~express_https_t () noexcept { if( exp.count() > 1 ){ return; } close(); exp->state = 0; } 

     express_https_t () noexcept : exp( new NODE() ) { exp->state = 0; }

    /*.........................................................................*/

    bool is_express_available() const noexcept { return exp->state >  0; }

    bool is_express_closed()    const noexcept { return exp->state <= 0; }

    /*.........................................................................*/

     express_https_t& send( string_t msg ) noexcept { 
          if( exp->state == 0 ){ return (*this); }
          header( "Content-Length", string::to_string(msg.size()) );
          if( regex::test( headers["Accept-Encoding"], "gzip" ) && msg.size()>UNBFF_SIZE ){
              header( "Content-Encoding", "gzip" ); send();
              write( zlib::gzip::get( msg ) ); close(); 
          } else {
              send(); write( msg ); close(); 
          }   exp->state =0; return (*this); 
     }

     express_https_t& sendFile( string_t dir ) noexcept {
          if( exp->state == 0 ){ return (*this); } if( fs::exists_file( dir ) == false )
            { status(404).send("file does not exist"); } file_t file ( dir, "r" );
              header( "Content-Length", string::to_string(file.size()) );
              header( "Content-Type", path::mimetype(dir) );
          if( regex::test( headers["Accept-Encoding"], "gzip" ) ){
              header( "Content-Encoding", "gzip" ); send();
              zlib::gzip::pipe( file, *this );
          } else {
              send(); stream::pipe( file, *this );
          }   exp->state = 0; return (*this);
     }

     express_https_t& sendJSON( object_t json ) noexcept {
          if( exp->state == 0 ){ return (*this); } auto data = json::stringify(json);
          header( "content-length", string::to_string(data.size()) );
          header( "content-type", path::mimetype(".json") );
          send( data ); exp->state = 0; return (*this);
     }

     express_https_t& cache( ulong time ) noexcept {
          if( exp->state == 0 ){ return (*this); }
          header( "Cache-Control",string::format( "public, max-age=%lu",time) );
          return (*this);
     }

     express_https_t& cookie( string_t name, string_t value ) noexcept {
          if( exp->state == 0 ){ return (*this); } exp->_cookies[ name ] = value;
          header( "Set-Cookie", cookie::format( exp->_cookies ) );
          return (*this);
     }

     express_https_t& header( string_t name, string_t value ) noexcept {
          if( exp->state == 0 )    { return (*this); }
          exp->_headers[name]=value; return (*this);
     }

     express_https_t& redirect( uint value, string_t url ) noexcept {
          if( exp->state == 0 ){ return (*this); }
          header( "location",url ); status( value ); 
          send(); exp->state = 0; return (*this);
     }

     template< class T >
     express_https_t& sendStream( T readableStream ) noexcept {
          if( exp->state == 0 ){ return (*this); }
          if( regex::test( headers["Accept-Encoding"], "gzip" ) ){
              header( "Content-Encoding", "gzip" ); send();
              zlib::gzip::pipe( readableStream, *this );
          } else { send();
              stream::pipe( readableStream, *this );
          }   exp->state = 0; return (*this);
     }

     express_https_t& header( header_t headers ) noexcept {
          if( exp->state == 0 ){ return (*this); }
          forEach( item, headers.data() ){
              header( item.first, item.second );
          }   return (*this);
     }

     express_https_t& redirect( string_t url ) noexcept {
          if( exp->state == 0 ){ return (*this); }
          return redirect( 302, url );
     }

     express_https_t& render( string_t path ) noexcept {
          if( exp->state == 0 ){ return (*this); }
		auto cb = _express_::ssr(); send();  
          process::poll::add( cb, *this, path ); 
          return (*this);
     }

     express_https_t& status( uint value ) noexcept {
          if( exp->state == 0 ){ return (*this); }
              exp->status=value; return (*this);
     }

     express_https_t& clear_cookies() noexcept {
          if( exp->state == 0 ){ return (*this); } 
          header( "Clear-Site-Data", "\"cookies\"" );
          return (*this);
     }

     express_https_t& send() noexcept {
          if( exp->state == 0 ){ return (*this); }
          write_header(exp->status,exp->_headers); 
          exp->state = 0; return (*this);
     }

     express_https_t& done() noexcept {
          if( exp->state == 0 ){ return (*this); }
          exp->state = 0; return (*this);
     }

};}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { class express_tls_t {
protected:

     struct express_item_t {
          optional_t<MIDDL> middleware;
          optional_t<CALBK> callback;
          optional_t<any_t> router;
          string_t          method;
          string_t          path;
     };

     struct NODE {
          queue_t<express_item_t> list;
          ssl_t*   ssl  = nullptr;
          agent_t* agent= nullptr;
          string_t path = nullptr;
          tls_t    fd;
     };   ptr_t<NODE> obj;

     void execute( string_t path, express_item_t& data, express_https_t& cli, function_t<void>& next ) const noexcept {
            if( !cli.is_available() || cli.is_express_closed() ){ next(); } 
          elif( data.middleware.has_value() ){ data.middleware.value()( cli, next ); }
          elif( data.callback.has_value()   ){ data.callback.value()( cli ); next(); }
          elif( data.router.has_value()     ){ 
                auto self = type::bind( data.router.value().as<express_tls_t>() );
                     self->run( path, cli ); next();
          }
     }

     bool path_match( express_https_t& cli, string_t base, string_t path ) const noexcept {
          string_t pathname = normalize( base, path );

          array_t<string_t> _path[2] = {
               string::split( cli.path, '/' ), 
               string::split( pathname, '/' )
          };

          if( regex::test( cli.path, "^"+pathname ) ){ return true;  }
          if( _path[0].size() != _path[1].size() )   { return false; }

          for ( ulong x=0; x<_path[0].size(); x++ ){ if( _path[1][x]==nullptr ){ return false; }
          elif( _path[1][x][0] == ':' ){ if( _path[0][x].empty() ){ return false; }
                cli.params[_path[1][x].slice(1)] = url::normalize( _path[0][x] ); }
          elif( _path[1][x]    == "*"         ){ continue;     }
          elif( _path[1][x]    == nullptr     ){ continue;     }
          elif( _path[1][x]    != _path[0][x] ){ return false; }
          }

          return true;
     }

     void run( string_t path, express_https_t& cli ) const noexcept {

          auto n     = obj->list.first(); 
          auto _base = normalize( path, obj->path );
          function_t<void> next = [&](){ n = n->next; };

          while( n!=nullptr ){
               if( !cli.is_available() || cli.is_express_closed() ){ break; } 
               if(( n->data.path == nullptr && regex::test( cli.path, "^"+_base )) 
               || ( n->data.path == nullptr && obj->path == nullptr ) 
               || ( path_match( cli, _base, n->data.path )) ){
               if ( n->data.method==nullptr || n->data.method==cli.method ){ 
                    execute( _base, n->data, cli, next ); 
               } else { next(); }
               } else { next(); }
          }
          
     }

     string_t normalize( string_t base, string_t path ) const noexcept {
          return base.empty() ? ("/"+path) : path.empty() ? 
                                ("/"+base) : path::join( base, path );
     }

public:

    express_tls_t( ssl_t* ssl, agent_t* agent ) noexcept : obj( new NODE() )
                 { obj->agent = agent; obj->ssl = ssl; }

    express_tls_t( ssl_t* ssl ) noexcept : obj( new NODE() )
                 { obj->ssl = ssl; }

    express_tls_t() noexcept : obj( new NODE() ) {}

   ~express_tls_t() noexcept {}

    /*.........................................................................*/

    void     set_path( string_t path ) const noexcept { obj->path = path; }

    string_t get_path() const noexcept { return obj->path; }

    /*.........................................................................*/

    bool is_closed() const noexcept { return obj->fd.is_closed(); }

    tls_t get_fd() const noexcept { return obj->fd; }

    void close() const noexcept { obj->fd.close(); }

    /*.........................................................................*/

    const express_tls_t& USE( string_t _path, express_tls_t cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         cb.set_path( normalize( obj->path, _path ) );
         item.path       = nullptr;
         item.method     = nullptr;
         item.router     = optional_t<any_t>(cb);
         obj->list.push( item ); return (*this);
    }

    const express_tls_t& USE( express_tls_t cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         cb.set_path( normalize( obj->path, nullptr ) );
         item.path       = nullptr;
         item.method     = nullptr;
         item.router     = optional_t<any_t>(cb);
         obj->list.push( item ); return (*this);
    }

    /*.........................................................................*/

    const express_tls_t& USE( string_t _path, MIDDL cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.middleware = optional_t<MIDDL>(cb);
         item.method     = nullptr;
         item.path       = _path;
         obj->list.push( item ); return (*this);
    }

    const express_tls_t& USE( MIDDL cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.middleware = optional_t<MIDDL>(cb);
         item.method     = nullptr;
         item.path       = nullptr;
         obj->list.push( item ); return (*this);
    }

    /*.........................................................................*/

    const express_tls_t& ALL( string_t _path, CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = nullptr;
         item.path     = _path;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    const express_tls_t& ALL( CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.path     = nullptr;
         item.method   = nullptr;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    /*.........................................................................*/

    const express_tls_t& RAW( string_t _method, string_t _path, CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = _method;
         item.path     = _path;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    const express_tls_t& RAW( string_t _method, CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.path     = nullptr;
         item.method   = _method;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    /*.........................................................................*/

    const express_tls_t& GET( string_t _path, CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = "GET";
         item.path     = _path;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    const express_tls_t& GET( CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.path     = nullptr;
         item.method   = "GET";
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    /*.........................................................................*/

    const express_tls_t& POST( string_t _path, CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = "POST";
         item.path     = _path;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    const express_tls_t& POST( CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.path     = nullptr;
         item.method   = "POST";
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    /*.........................................................................*/

    const express_tls_t& REMOVE( string_t _path, CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = "DELETE";
         item.path     = _path;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    const express_tls_t& REMOVE( CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = "DELETE";
         item.path     = nullptr;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    /*.........................................................................*/

    const express_tls_t& PUT( string_t _path, CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = "PUT";
         item.path     = _path;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    const express_tls_t& PUT( CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.path     = nullptr;
         item.method   = "PUT";
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    /*.........................................................................*/

    const express_tls_t& HEAD( string_t _path, CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = "HEAD";
         item.path     = _path;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    const express_tls_t& HEAD( CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.path     = nullptr;
         item.method   = "HEAD";
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    /*.........................................................................*/

    const express_tls_t& TRACE( string_t _path, CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = "TRACE";
         item.path     = _path;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    const express_tls_t& TRACE( CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.path     = nullptr;
         item.method   = "TRACE";
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    /*.........................................................................*/

    const express_tls_t& PATCH( string_t _path, CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = "PATCH";
         item.path     = _path;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    const express_tls_t& PATCH( CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.path     = nullptr;
         item.method   = "PATCH";
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    /*.........................................................................*/

    const express_tls_t& OPTIONS( string_t _path, CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = "OPTIONS";
         item.path     = _path;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    const express_tls_t& OPTIONS( CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = "OPTIONS";
         item.path     = nullptr;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    /*.........................................................................*/

    const express_tls_t& CONNECT( string_t _path, CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = "CONNECT";
         item.path     = _path;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    const express_tls_t& CONNECT( CALBK cb ) const noexcept {
         express_item_t item; memset( &item, sizeof(item), 0 );
         item.method   = "CONNECT";
         item.path     = nullptr;
         item.callback = cb;
         obj->list.push( item ); return (*this);
    }

    /*.........................................................................*/

    template<class... T> 
    tls_t& listen( const T&... args ) const {
          if( obj->ssl == nullptr ){ process::error("SSL not found"); }
          auto self = type::bind( this );

          function_t<void,https_t> cb = [=]( https_t cli ){
               express_https_t res( cli ); if( res.headers["params"] ){
                   res.params = query::parse( res.headers["params"] ); 
               }   self->run( nullptr, res );
          };

          obj->fd=https::server( cb, obj->ssl, obj->agent );
          obj->fd.listen( args... ); return obj->fd;
    }

};}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace express { namespace https {  

     template< class... T > express_tls_t add( T... args ) { return express_tls_t(args...); }

     express_tls_t file( string_t base ) { 
          
          express_tls_t app;

          app.ALL([=]( express_https_t cli ){

               auto pth = regex::replace( cli.path, app.get_path(), "/" );
                    pth = regex::replace_all( pth, "\\.[.]+/", "" );

               auto dir = pth.empty() ? path::join( base, "" ) :
                                        path::join( base,pth ) ;

               if ( dir.empty() ){ dir = path::join( base, "index.html" ); }
               if ( dir[dir.last()] == '/' ){ dir += "index.html"; }

               if( fs::exists_file(dir+".html") == true ){ dir += ".html"; }
               if( fs::exists_file(dir) == false || dir == base ){
               if( fs::exists_file( path::join( base, "404.html" ) )){
                   dir = path::join( base, "404.html" );
                   cli.status(404);
               } else { 
                   cli.status(404).send("Oops 404 Error"); 
                   return; 
               }}

               if ( cli.headers["Range"].empty() == true ){

                    if( regex::test(path::mimetype(dir),"audio|video",true) )
                      { cli.send(); return; } else { cli.render(dir); }

               } else { auto str = fs::readable( dir );

                    array_t<string_t> range = regex::match_all(cli.headers["Range"],"\\d+",true);
                     ulong rang[3]; rang[0] = string::to_ulong( range[0] );
                           rang[1] =min(rang[0]+CHUNK_MB(10),str.size()-1);
                           rang[2] =min(rang[0]+CHUNK_MB(10),str.size()  );

                    cli.header( "Content-Range", string::format("bytes %lu-%lu/%lu",rang[0],rang[1],str.size()) );
                    cli.header( "Content-Type",  path::mimetype(dir) ); cli.header( "Accept-Range", "bytes" );
                    cli.header( "Cache-Control", "public, max-age=604800" ); 

                    str.set_range( rang[0], rang[2] ); 
                    cli.status(206).sendStream( str );

               }
          });

          return app;
     }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

#undef CALBK
#undef MIDDL
#endif