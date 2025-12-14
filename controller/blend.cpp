#pragma once

namespace uk { 

    express_tcp_t blend() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            for( auto& item: ptr_t<string_t>({
                "multiply", "screen", "overlay", "darken", "lighten", "color-dodge", "color-burn",
                "hard-light", "soft-light", "difference", "exclusion", "saturation",
                "color" "luminosity", "hue"
            }) ){
                data+=( regex::format( _STRING_(
                   .uk-blend-${0} { mix-blend-mode: ${0}; }
                ), item )); 
            }

            cli.write( data );

        });

        return app;
    }

}