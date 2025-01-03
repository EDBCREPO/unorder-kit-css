#pragma once

namespace uk { 

    express_tcp_t dropdown() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            cli.write( _STRING_(

                .uk-dropdown-hover:hover>[toggle], .uk-dropdown:has(:checked)>[toggle], .uk-dropdown>[toggle]:hover {
                    padding: 6px 10px; margin: 0px; width: 100%; z-index: 1;
                    color: var(--light); position: absolute;
                    flex-direction: column; display: flex;
                    left: 0; top:100%; list-style: none;
                    background-color: var(--secondary);
                    border: inherit; user-select: none;
                    border-radius: 0px 0px 5px 5px;
                }

                [class*="uk-dropdown"]>[toggle], .uk-dropdown>input                      { display: none; }

                .uk-dropdown:has(:checked),.uk-dropdown-bottom:has(:checked)             { border-bottom-right-radius: 0; border-bottom-left-radius: 0; }

                .uk-dropdown-top:hover>[toggle],    .uk-dropdown-top>[toggle]:hover      { left:0; top:unset; bottom:100%; right:unset; }
                .uk-dropdown-bottom:hover>[toggle], .uk-dropdown-bottom>[toggle]:hover   { left:0; top:100%; bottom:unset; right:unset; }
                .uk-dropdown-right:hover>[toggle],  .uk-dropdown-right>[toggle]:hover    { left:unset; top:unset; bottom:unset; right:100%; transform:translate( 0px, -50% ); }
                .uk-dropdown-left:hover>[toggle],   .uk-dropdown-left>[toggle]:hover     { left:100%; top:unset; bottom:unset; right:unset; transform:translate( 0px, -50% ); }
                
                [class*="uk-dropdown"]                                                   { position: relative; transition: none; padding: 6px 10px; cursor: pointer; user-select: none; }

            ));

        });

        return app;
    }

}