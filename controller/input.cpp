#pragma once

namespace uk {

    express_tcp_t input() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            data+=( _STRING_(

                .uk-checkbox:checked { background-image: url( data:image/svg+xml;charset=UTF-8,%3Csvg%20width%3D%2214%22%20height%3D%2211%22%20viewBox%3D%220%200%2014%2011%22%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%3E%0A%20%20%20%20%3Cpolygon%20fill%3D%22%23fff%22%20points%3D%2212%201%205%207.5%202%205%201%205.5%205%2010%2013%201.5%22%20%2F%3E%0A%3C%2Fsvg%3E%0A ); }

                .uk-radio:checked { background-image: url( data:image/svg+xml;charset=UTF-8,%3Csvg%20width%3D%2216%22%20height%3D%2216%22%20viewBox%3D%220%200%2016%2016%22%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%3E%0A%20%20%20%20%3Ccircle%20fill%3D%22%23fff%22%20cx%3D%228%22%20cy%3D%228%22%20r%3D%222%22%20%2F%3E%0A%3C%2Fsvg%3E ); }

                .uk-checkbox, .uk-radio {
                    transition-property: background-color, border;
                    border: 1px solid var(--neutral);
                    background-position: 50% 50%;
                    background-repeat: no-repeat;
                    height: 16px; width: 16px;
                    -webkit-appearance: none;
                    vertical-align: middle;
                    display: inline-block;
                    overflow: hidden;
                }

                .uk-input {
                    border: 1px solid var(--neutral);
                    background: var(--none);
                    vertical-align: middle;
                    display: inline-block;
                    border-radius: 5px;
                    overflow: hidden;
                    font-size: 16px;
                    color: inherit;
                    padding: 5px;
                }

                input[class=".uk-input"] { -webkit-appearance: none; }

                .uk-input::placeholder { color: var(--neutral); }

                .uk-radio:checked, .uk-checkbox:checked {
                    background-color: var(--primary);
                    border-color: var(--primary);
                }

                .uk-input * { color: initial; }

                .uk-range {
                    border: 1px solid var(--neutral);
                    padding: 0; margin: 0; height: 0;
                    -webkit-appearance: none;
                    background: var(--none);
                    vertical-align: middle;
                    display: inline-block;
                    align-items: baseline;
                    display: flex;
                }

                .uk-radio { border-radius: 10px; }

                .uk-range::-webkit-slider-thumb {
                    border: 1px solid var(--primary);
                    background: var(--primary);
                    -webkit-appearance: none;
                    border-radius: 500px;
                    margin-top: -7px;
                    height: 15px;
                    width: 15px;
                }

                .uk-input:focus { outline: 0; }

                .uk-input[type="date"]{ display: flex !important; }

            ));

            forEach( color, ptr_t<string_t>({
                "primary", "secondary", "success",
                "warning", "danger"   , "mute"   ,
                "dark"   , "light"    , "neutral"
            })){ data+=( regex::format( _STRING_(

                .uk-radio-checked-${0}:checked, .uk-checkbox-checked-${0}:checked {
                    background-color: var(--${0});
                    border-color: var(--${0});
                }

                .uk-placeholder-${0}::placeholder { color: var(--${0}); }

                .uk-checkbox-${0}, .uk-radio-${0}, .uk-input-${0} {
                    border: 1px solid var(--neutral);
                }

                .uk-input-required-${0}:required {
                    border-color: var(--${0});
                }

                .uk-input-invalid-${0}:invalid {
                    border-color: var(--${0});
                }

                .uk-input-focus-${0}:focus {
                    border-color: var(--${0});
                }

                .uk-range-${0}::-webkit-slider-thumb {
                    border: 1px solid var(--${0});
                    background: var(--${0});
                }

            ), color )); }

            cli.write( data );

        });

        return app;
    }

}
