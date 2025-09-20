#pragma once

namespace uk {

    express_tcp_t flex() {
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
                       @media( max-width: ${0}px ) {
                    ), size.second ));
                }

                data+=( regex::format( _STRING_(
                    .uk-flex${0}         { align-content: normal; display: flex; }
                    .uk-flex-shrink${0}  { flex-grow: 0; flex-shrink: 1  }
                    .uk-flex-grow${0}    { flex-grow: 1; flex-shrink: 0; }
                    .uk-flex-inline${0}  { display: inline-flex; }
                    .uk-flex-initial${0} { flex:    initial;     }
                    .uk-flex-none${0}    { flex:    none;        }
                    .uk-flex-auto${0}    { flex:    auto;        }
                ), size.first ));

                for( auto& item: map_t<string_t,string_t>({
                    { "around",  "space-around"  },
                    { "between", "space-between" },
                    { "center",  "center"        },
                    { "left",    "flex-start"    },
                    { "right",   "flex-end"      }
                }).data() ){
                    data+=( regex::format( _STRING_(
                       .uk-flex-${0}${2} { justify-content: ${1}; }
                    ), item.first, item.second, size.first ));
                }

                for( auto& item: map_t<string_t,string_t>({
                    { "top",     "flex-start" },
                    { "bottom",  "flex-end"   },
                    { "stretch", "stretch"    },
                    { "middle",  "center"     },
                }).data() ){
                    data+=( regex::format( _STRING_(
                       .uk-flex-${0}${2} { align-items: ${1}; }
                    ), item.first, item.second, size.first ));
                }

                for( auto& item: ptr_t<string_t>({
                    "column-reverse", "column",
                    "row-reverse"   , "row"
                })){
                    data+=( regex::format( _STRING_(
                       .uk-flex-${0}${1} { flex-direction: ${0}; }
                    ), item, size.first ));
                }

                for( auto& item: ptr_t<string_t>({
                    "wrap", "nowrap", "wrap-reverse"
                })){
                    data+=( regex::format( _STRING_(
                       .uk-flex-${0}${1} { flex-wrap: ${0}; }
                    ), item, size.first ));
                }

                for( auto& item: map_t<string_t,string_t>({
                    { "between", "space-between" },
                    { "around",  "space-around"  },
                    { "top",     "flex-start"    },
                    { "bottom",  "flex-end"      },
                    { "stretch", "stretch"       },
                    { "middle",  "center"        },
                }).data() ){
                    data+=( regex::format( _STRING_(
                       .uk-flex-wrap-${0}${2} { align-content: ${1}; }
                    ), item.first, item.second, size.first ));
                }

                if( size.first != nullptr ){ data+=( "}" ); }

            }

            cli.write( data );

        });

        return app;
    }

}
