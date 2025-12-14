#pragma once

namespace uk { 

    express_tcp_t dropdown() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ 
            
            cli.send( _STRING_(

                .uk-dropdown-hover:hover>[toggle], .uk-dropdown:has(:checked)>[toggle], .uk-dropdown>[toggle]:hover {
                    position: absolute; flex-direction: column; display: flex;
                    padding: 6px 10px; margin: 0px; width: 100%; z-index: 1;
                    color: inherit; background-color: inherit;
                    left: 0; top:100%; list-style: none;
                    border: inherit; user-select: none;
                }

                [class*="uk-dropdown"]>[toggle], .uk-dropdown>input                      { display: none; }

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