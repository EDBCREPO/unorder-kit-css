#pragma once

namespace uk { 

    express_tcp_t opacity() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            for( auto x=10; x>0; x-- ){
                cli.write( regex::format( _STRING_(
                   .uk-border-opacity-${0}     { border-color: rgba( from currentColor r g b / ${0}0% ) !important; }
                   .uk-opacity-${0}            { opacity: ${0}0% !important; }
                ), x )); 
            }

        });

        return app;
    }

}