#pragma once

namespace uk { 

    express_tcp_t transform() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            for( auto& item: map_t<string_t,string_t>({
                { "center",        "translate(-50%, -50%)" },
                { "bottom-right",  "100% 100%" },
                { "bottom-center", " 50% 100%" },
                { "center-right",  "100% 50%"  },
                { "bottom-left",   "0 100%"    },
                { "top-right",     "100% 0"    },
                { "center-left",   "0 50%"     },
                { "top-center",    "50% 0"     },
                { "top-left",      "0 0"       }
            }).data() ){
                data+=( regex::format( _STRING_(
                   .uk-transform-origin-${0} { transform-origin: ${1}; }
                ), item.first, item.second )); 
            }

            cli.write( data );

        });

        return app;
    }

}