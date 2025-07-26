#pragma once

namespace uk { 

    express_tcp_t index() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ 
            cli.send( _STRING_(
                .uk-index-top-most   { z-index: 2001; }
                .uk-index-top        { z-index: 1001; }
                .uk-index-normal     { z-index:    0; }
                .uk-index-bottom     { z-index:-1001; }
                .uk-index-bottom-most{ z-index:-2001; }
            ));
        });

        return app;
    }

}