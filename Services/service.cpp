#define MAX_FILENO 1048576

#include <nodepp/nodepp.h>
#include <express/http.h>
#include <nodepp/query.h>
#include <nodepp/fs.h>

using namespace nodepp;

#include "../Controller/controller.cpp"

void compile() {

    auto app = express::http::add();

    app.ALL([=]( express_http_t cli ){
        console::log( "->", cli.path );
    }); uk::controller( app );

    app.USE( express::http::file( "./View" ) );

    app.listen( "0.0.0.0", 8000, []( ... ){
        console::log( "-> http://localhost:8000" );

        fetch_t args;
        args.method = "GET";
        args.url    = "http://localhost:8000/uikit.css";

        http::fetch( args ).then([=]( http_t cli ){
            auto file = fs::writable("./Build/uikit.css");
            cli.onDrain([=](){ process::exit(); });
            stream::pipe( cli, file );
        }).fail([=]( ... ){
            process::error("something went wrong");
        });

    });

}

void test() {

    auto app = express::http::add();

    app.ALL([=]( express_http_t cli ){
        console::log( "->", cli.path );
    });

    app.USE( express::http::file( "./Build" ) );

    app.listen( "0.0.0.0", 8000, []( ... ){
        console::log( "-> http://localhost:8000" );
    });

}

void onMain(){

    if( process::env::get("mode") == "test" )
      { test(); } else { compile(); }

}
