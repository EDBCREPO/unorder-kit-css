#pragma once

namespace uk { 

    express_tcp_t header() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            for( auto& item: map_t<string_t,string_t>({
                { "h0", "font-size: xxx-large !important; line-height: 1.2;" },
                { "h1", "font-size: xx-large  !important; line-height: 1.2;" },
                { "h2", "font-size: x-large   !important; line-height: 1.3;" },
                { "h3", "font-size: large     !important; line-height: 1.4;" },
                { "h4", "font-size: medium    !important; line-height: 1.4;" },
                { "h5", "font-size: unset     !important; line-height: 1.4;" },
                { "h6", "font-size: unset     !important; line-height: 1.4;" },
            }).data() ){ data+=( regex::format( _STRING_(

                ${0}, .uk-${0}{ ${1} }

                ${0}     *:not([class*="uk-h"],h1,h2,h3,h4,h5,h6), 
                .uk-${0} *:not([class*="uk-h"],h1,h2,h3,h4,h5,h6) { 
                    font-size:   inherit !important; 
                    font-weight: inherit !important; 
                }

            ), item.first, item.second )); }

            cli.write( data );
            
        });

        return app;
    }

}