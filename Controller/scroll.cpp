#pragma once

namespace uk { express_tcp_t scroll() {
    auto app = express::http::add();

    app.ALL([=]( express_http_t cli ){ cli.send();

        cli.write( _STRING_(

            * { scrollbar-width: none; }

            ::-webkit-scrollbar {
                background: transparent;
                width: 0; height: 0;
            }

        ));

        cli.write(_STRING_(

            .uk-scroll-x::-webkit-scrollbar {
                height: 0.3em;
                width:  0.0em;
            }

            .uk-scroll-x {
                scrollbar-height: 0.3em;
                scrollbar-width:  0.0em;
            }

            .uk-scroll-y::-webkit-scrollbar {
                height: 0.0em;
                width:  0.3em;
            }

            .uk-scroll-y {
                scrollbar-height: 0.0em;
                scrollbar-width:  0.3em;
            }

            .uk-scroll::-webkit-scrollbar {
                height: 0.3em;
                width:  0.3em;
            }

            .uk-scroll {
                scrollbar-height: 0.3em;
                scrollbar-width:  0.3em;
            }

        ));

        for( auto& color : array_t<string_t>({
             "primary", "secondary", "success",
             "warning", "danger"   , "mute"   ,
             "light"  , "dark"     , "neutral"
        })){
            cli.write( regex::format( _STRING_(

                .uk-scroll-${0}::-webkit-scrollbar-thumb {
                    background-color: var(--${0});
                }

                .uk-scroll-${0} {
                    scrollbar-color: var(--${0}) transparent;
                }

            ), color ));
        }

    });

    return app;
}}
