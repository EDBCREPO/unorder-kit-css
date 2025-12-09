#pragma once

namespace uk { 

    express_tcp_t icon() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ 
            
            cli.send( _STRING_(

                .uk-icon::before, 
                .uk-icon-end::after,
                .uk-icon-begin::before { 
                    vertical-align: -webkit-baseline-middle;
                    font-family: 'Material Symbols Rounded';
                    vertical-align: text-bottom;
                    align-content: center;
                    font-weight: lighter;
                    font-style: normal;
                    line-height: 1;
                    content: attr(icon);
                    direction: ltr;
                    font-size: 22px;
                    word-wrap: normal;
                    white-space: nowrap;
                    text-transform: none;
                    display: inline-block;
                    -webkit-font-smoothing: antialiased;
                    -webkit-font-feature-settings: 'liga';
                    letter-spacing: normal; user-select: none;
                }

                icon { 
                    vertical-align: -webkit-baseline-middle;
                    font-family: 'Material Symbols Rounded';
                    vertical-align: text-bottom;
                    align-content: center;
                    font-weight: lighter;
                    font-style: normal;
                    line-height: 1;
                    direction: ltr;
                    font-size: 22px;
                    word-wrap: normal;
                    white-space: nowrap;
                    text-transform: none;
                    display: inline-block;
                    -webkit-font-smoothing: antialiased;
                    -webkit-font-feature-settings: 'liga';
                    letter-spacing: normal; user-select: none;
                }

                input[type="date"]::after {
                    vertical-align: -webkit-baseline-middle;
                    font-family: 'Material Symbols Rounded';
                    vertical-align: text-bottom;
                    align-content: center;
                    font-weight: lighter;
                    font-style: normal;
                    line-height: 1;
                    direction: ltr;
                    font-size: inherit;
                    word-wrap: normal;
                    white-space: nowrap;
                    text-transform: none;
                    display: inline-block;
                    content: "edit_calendar";
                    -webkit-font-smoothing: antialiased;
                    -webkit-font-feature-settings: 'liga';
                    letter-spacing: normal; user-select: none;
                }

            ));

        });

        return app;
    }

}