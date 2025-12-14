#include <nodepp/nodepp.h>
#include <nodepp/cluster.h>
#include <nodepp/query.h>
#include <nodepp/json.h>
#include <nodepp/fs.h>

#include <express/http.h>

using namespace nodepp;

#include "./controller/controller.cpp"

void compile() { try {
    if( process::is_child() ){ throw 0; }

    auto app = express::http::add();

    app.ALL([=]( express_http_t cli ){
        console::log( "->", cli.path );
    }); uk::controller( app );

    app.listen( "0.0.0.0", 8000, []( ... ){
        console::log( "-> http://localhost:8000" );
        cluster::add().onDrain([=](){
            console::done("uikit compilled");
            process::exit(1);
        });
    });

} catch(...) {

    auto file = fs::writable( "./www/uikit.css" );
    auto data = fs::read_file( "./package.json" );
    auto obj  = json::parse( data );

    for( auto x: obj["list"].as<array_t<object_t>>() ){
         
        fetch_t args;
                args.url    = x.as<string_t>();
                args.headers= header_t({  });
                args.method = "GET";

        auto fetch = http::fetch( args ).await();
        if( !fetch.has_value() ) /*---*/ { break; }
        if( fetch.value().status != 200 ){ break; }

        while( fetch.value().is_available() )
             { file.write( fetch.value().read() ); }

    }

}}

void test() {

    auto app = express::http::add();

    app.ALL([=]( express_http_t cli ){
        console::log( "->", cli.path );
    });

    app.USE( express::http::file( "./www" ) );

    app.listen( "0.0.0.0", 8000, []( ... ){
        console::log( "-> http://localhost:8000" );
    });

}

void onMain(){

    if( process::env::get("mode") == "test" )
      { test(); } else { compile(); }

}
