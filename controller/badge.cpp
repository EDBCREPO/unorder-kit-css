#pragma once

namespace uk {

    express_tcp_t badge() {
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
                { "neutral",   "light" },
            }).data() ){
                data+=( regex::format( _STRING_(
                    .uk-badge-${0}-outline {
                        border-color: var(--${0}) !important;
                        color: var(--${0}) !important;
                    }
                    .uk-badge-${0} {
                        color: var(--${1}) !important;
                        background-color: var(--${0});
                    }
                ), color.first, color.second ));
            }

            data+=( _STRING_(
                .uk-badge {
                    border: 1px solid var(--none);
                    align-content: center;
                    border-radius: 5px;
                    text-align: center;
                    font-weight: bold;
                    padding: 0px 10px;
                    user-select: none;
                    width: auto;
                }
            ));

            cli.write( data );

        });

        return app;
    }

}
