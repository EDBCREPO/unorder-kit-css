#pragma once

namespace uk {

    express_tcp_t text() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            forEach( item, ptr_t<string_t>({
                "none", "blink", "dashed", "dotted", "solid", "double", "wavy", "overline", "undeline"
            })){
                data+=( regex::format( _STRING_(
                   .uk-text-decoration-${0} { text-decoration: ${0}; }
                ), item ));
            }

            forEach( item, ptr_t<string_t>({ "left", "right", "center", "justify" })){
                data+=( regex::format( _STRING_(
                   .uk-text-${0} { text-align: ${0}; }
                ), item ));
            }

            forEach( color, ptr_t<string_t>({
                "primary", "secondary", "success",
                "warning", "danger"   , "mute"   ,
                "dark"   , "light"    , "neutral"
            })){
                data+=( regex::format( _STRING_(
                   .uk-placeholder-${0}::placeholder { color: var(--${0}) !important; }
                   .uk-text-hover-${0}:hover         { color: var(--${0}) !important; }
                   .uk-text-${0}                     { color: var(--${0}) !important; }
                ), color ));
            }

            data+=( _STRING_(

                .uk-text-lead       { font-size: 1.5rem; line-height: 1.5; }
                .uk-text-inherit    { font-size: inherit !important; }
                .uk-text-nowrap     { text-wrap-mode: nowrap; }
                .uk-text-wrap       { text-wrap-mode: wrap; }
                .uk-text-italic     { font-style: italic; }

                .uk-text-lowercase  { text-transform: lowercase;  }
                .uk-text-uppercase  { text-transform: uppercase;  }
                .uk-text-capitalize { text-transform: capitalize; }

                .uk-text-light      { font-weight: 300 !important;     }
                .uk-text-normal     { font-weight: 400 !important;     }
                .uk-text-bold       { font-weight: 700 !important;     }
                .uk-text-bolder     { font-weight: bolder !important;  }
                .uk-text-lighter    { font-weight: lighter !important; }

            ));

            cli.write( data );

        });

        return app;
    }

}
