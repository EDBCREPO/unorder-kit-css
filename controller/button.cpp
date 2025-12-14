#pragma once

namespace uk {

    express_tcp_t button() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            data+=( _STRING_(

                .uk-button:hover  { opacity: 90% !important; }

                .uk-button:active { opacity: 60% !important; }

                .uk-button-icon {
                    background-color: var(--none);
                    border: 1px solid var(--none);
                    border-color: var(--none);
                    -webkit-appearance: none;
                    justify-content: center;
                    align-items: center;
                    text-align: center;
                    border-radius: 5px;
                    user-select: none;
                    font-weight: 600;
                    cursor: pointer;
                    font-size: 16px;
                    color: inherit;
                    display: flex;
                    padding: 10px;
                }

                .uk-button {
                    background-color: var(--none);
                    border: 1px solid var(--none);
                    text-transform: capitalize;
                    border-color: var(--none);
                    -webkit-appearance: none;
                    justify-content: center;
                    align-items: center;
                    text-align: center;
                    border-radius: 5px;
                    padding: 6px 10px;
                    user-select: none;
                    font-weight: 600;
                    cursor: pointer;
                    font-size: 16px;
                    color: inherit;
                    display: flex;
                    gap: 3px;
                }

    /*.........................................................................*/

                .uk-button-text::before {
                    border-bottom: 1px solid var(--neutral);
                    transition: right 0.3s ease-out;
                    position: absolute;
                    content: "";
                    right: 100%;
                    bottom: 0;
                    left: 0;
                }

                .uk-button-text {
                    text-transform: capitalize;
                    border-color: var(--none);
                    align-items: center;
                    border-radius: 0px;
                    text-align: center;
                    position: relative;
                    font-weight: 600;
                    line-height: 1.5;
                    background: none;
                    cursor: pointer;
                    font-size: 16px;
                    color: inherit;
                    padding: 10px;
                    display: flex;
                    gap: 3px;
                }

                .uk-button-text:hover::before { right: 0; }

                .uk-button-text:disabled::before { display: none; }

            ));

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
                    .uk-button-text-${0}::before {
                        border-color: var(--${0}) !important;
                    }
                    .uk-button-${0} {
                        background-color: var(--${0});
                        color: var(--${1}) !important;
                    }
                    .uk-button-${0}-opaque {
                        background-color: rgb( from var(--${0}) r g b / 30% );
                        border: 1px solid rgb( from var(--${0}) r g b / 50% );
                    }
                    .uk-button-${0}-outline {
                        background: var(--none) !important;
                        color: var(--${0}) !important;
                        border-color: var(--${0});
                    }
                    .uk-button-hover-${0}:hover {
                        background-color: var(--${0}) !important;
                        color: var(--${1}) !important;
                        border-color: var(--${0});
                        opacity: 100% !important;
                    }
                    .uk-button-hover-${0}-outline:hover {
                        background: var(--none) !important;
                        color: var(--${0}) !important;
                        border-color: var(--${0});
                        opacity: 100% !important;
                    }
                    .uk-button-hover-${0}-opaque:hover {
                        background-color: rgb( from var(--${0}) r g b / 30% );
                        border: 1px solid rgb( from var(--${0}) r g b / 50% );
                    }
                    .uk-button-active-${0}:active {
                        background-color: var(--${0}) !important;
                        color: var(--${1}) !important;
                        border-color: var(--${0});
                        opacity: 100% !important;
                    }
                    .uk-button-active-${0}-outline:active {
                        background: var(--none) !important;
                        color: var(--${0}) !important;
                        border-color: var(--${0});
                        opacity: 100% !important;
                    }
                ), color.first, color.second ));
            }

            cli.write( data );

        });

        return app;
    }

}
