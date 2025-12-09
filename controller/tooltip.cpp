#pragma once

namespace uk { 

    express_tcp_t tooltip() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            for( auto& color : map_t<string_t,string_t>({
                { "primary",   "light" },
                { "secondary", "light" },
                { "success",   "dark"  },
                { "warning",   "dark"  },
                { "danger",    "light" },
                { "mute",      "dark"  },
                { "light",     "dark"  },
                { "dark",      "light" },
                { "neutral",   "light" }
            }).data() ){
                data+=( regex::format( _STRING_(
                    .uk-tooltip-${0}-outline { 
                        border-color: var(--${0}); 
                        color: var(--${0}); 
                    } 
                    .uk-tooltip-${0}:hover:after { 
                        background-color: var(--${0}); 
                        color: var(--${1}); 
                    }
                ), color.first, color.second ));
            }

            data+=( _STRING_(
                .uk-tooltip { position: relative; z-index: 1000; }

                .uk-tooltip:hover::after {
                    transform: translateX(-50%) translateY(-100%);
                    text-transform: capitalize !important;
                    content: attr(tooltip);
                    color: var(--light);
                    text-align: center;
                    position: absolute;
                    background: var(--neutral);
                    padding:4px 2px;
                    font-size: 12px;
                    min-width: 80px;
                    left:50%; top:-6px;
                    border-radius: 5px;
                    pointer-events: none;
                }

                /*.........................................................................*/

                .uk-tooltip-top:hover::after {
                    transform: translateX(-50%) translateY(-100%) !important;
                    left:50%; top:-6px;
                }

                .uk-tooltip-bottom:hover::after {
                    transform: translateX(-50%) translateY( 100%) !important;
                    bottom: -6px; top: unset;
                }

                .uk-tooltip-left:hover::after {
                    transform: translateX(-100%) translateY(0%) !important;
                    left: 0%; top: calc( 50% - 15px );
                }

                .uk-tooltip-right:hover::after {
                    transform: translateX(100%) translateY(0%) !important;
                    left: unset; right: 0px; top: calc( 50% - 15px );
                }

            ));

            cli.write( data );

        });

        return app;
    }

}