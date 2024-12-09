#pragma once

namespace uk { 

    express_tcp_t margin() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            for( auto& size: map_t<string_t,int>({ 
                { nullptr,   0 },
                { "\\@s",  640 },
                { "\\@m",  960 },
                { "\\@l", 1200 },
                { "\\@2l",1600 }
            }).data() ){

                if( size.first != nullptr ){
                    cli.write( regex::format( _STRING_(
                       @media( min-width: ${0}px ) {
                    ), size.second ));
                }

                for( auto& item : map_t<string_t,string_t>({
                    { "none",    "0px"  },
                    { "2xsmall", "5px"  },
                    { "xsmall",  "10px" },
                    { "small",   "15px" },
                    { "medium",  "25px" },
                    { "large",   "30px" },
                    { "xlarge",  "35px" },
                    { "2xlarge", "40px" }
                }).data() ){
                    cli.write( regex::format( _STRING_ (
                       .uk-child-margin-${0}${2}>:not([class*="uk-margin"]){ margin:${1}; } 
                       .uk-margin-${0}${2}                                  { margin:${1}; }
                    ), item.first, item.second, size.first ));
                }

                cli.write( regex::format( _STRING_ (

                    .uk-margin-remove-bottom${0} { margin-bottom: 0px; }
                    .uk-margin-remove-top${0}    { margin-top:    0px; }
                    .uk-margin-remove-left${0}   { margin-left:   0px; }
                    .uk-margin-remove-right${0}  { margin-right:  0px; }

                    .uk-margin-remove-horizontal${0} {
                        margin-left:  0px;
                        margin-right: 0px;
                    }

                    .uk-margin-remove-vertical${0} {
                        margin-top:    0px;
                        margin-bottom: 0px;
                    }

                    .uk-margin-remove${0} {
                        margin-left:   0px;
                        margin-right:  0px;
                        margin-top:    0px;
                        margin-bottom: 0px;
                    }
                    
                    .uk-child-margin${0}>:not([class*="uk-margin"]){ margin:20px; }
                    .uk-margin${0}                                  { margin:20px; }

                ), size.first ));

                if( size.first != nullptr ){ cli.write( "}" ); }

            }

        });

        return app;
    }

}