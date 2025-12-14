#pragma once

namespace uk {

    express_tcp_t background() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            for( auto& color: map_t<string_t,string_t>({
                { "primary",   "var(--light)" }, { "secondary", "var(--light)" },
                { "success",   "var(--dark)"  }, { "warning",   "var(--dark)"  },
                { "danger",    "var(--light)" }, { "mute",      "var(--dark)"  },
                { "dark",      "var(--light)" }, { "light",     "var(--dark)"  },
                { "neutral",   "var(--light)" }, { "none",      "inherit"      }
            }).data() ){
                data+=( regex::format( _STRING_(
                   .uk-background-hover-${0}:hover { background-color: var(--${0}) !important; color: ${1} !important; }
                   .uk-background-${0}             { background-color: var(--${0}) !important; color: ${1} !important; }
                   .uk-hr-${0}                     { border-color:     var(--${0}) !important; }
                ), color.first, color.second ));
            }

            for( auto& item: array_t<string_t>({
                "revert", "bottom", "center", "bottom", "left", "right"
            })){ data+=( regex::format( _STRING_(
                .uk-background-position-${0} { background-position: ${0} !important; }
            ), item )); }

            for( auto& item: array_t<string_t>({
                "revert", "contain", "cover", "fill", "none"
            })){ data+=( regex::format( _STRING_(
                .uk-object-fit-${0} { object-fit: ${0} !important; }
            ), item )); }

            cli.write( data );

        });

        return app;
    }

}
