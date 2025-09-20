#pragma once

namespace uk {

    express_tcp_t margin() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            for( auto& size: map_t<string_t,int>({
                { nullptr,   0 },
                { "\\@2l",1600 },
                { "\\@l", 1200 },
                { "\\@m",  960 },
                { "\\@s",  640 }
            }).data() ){

                if( size.first != nullptr ){
                    data+=( regex::format( _STRING_(
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
                    data+=( regex::format( _STRING_ (
                       .uk-child-margin-${0}${2}>:not([class*="uk-margin"]){ margin:${1} !important; }
                       .uk-margin-${0}${2}                                 { margin:${1} !important; }
                    ), item.first, item.second, size.first ));
                }

                data+=( regex::format( _STRING_ (

                    .uk-child-margin${0}>:not([class*="uk-margin"]){ margin:20px; }
                    .uk-margin${0}                                 { margin:20px; }

                    .uk-margin-remove-bottom${0} { margin-bottom: 0px !important; }
                    .uk-margin-remove-top${0}    { margin-top:    0px !important; }
                    .uk-margin-remove-left${0}   { margin-left:   0px !important; }
                    .uk-margin-remove-right${0}  { margin-right:  0px !important; }

                    .uk-margin-remove-horizontal${0} {
                        margin-left:  0px !important;
                        margin-right: 0px !important;
                    }

                    .uk-margin-remove-vertical${0} {
                        margin-top:    0px !important;
                        margin-bottom: 0px !important;
                    }

                    .uk-margin-remove${0} {
                        margin-left:   0px !important;
                        margin-right:  0px !important;
                        margin-top:    0px !important;
                        margin-bottom: 0px !important;
                    }

                ), size.first ));

                if( size.first != nullptr ){ data+=( "}" ); }

            }

            cli.write( data );

        });

        return app;
    }

}
