#pragma once

namespace uk {

    express_tcp_t position() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            data+=( _STRING_( [class*=uk-position]{ position: absolute; }));

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
                    { "center",       "bottom: 50%; left: 50%; right: 50%; top: 50%;" },
                    { "bottom",       "bottom:  0%;"                                  },
                    { "right",        "bottom: 50%; top:  50%; right:  0%;"           },
                    { "left",         "bottom: 50%; top:  50%; left:   0%;"           },
                    { "top",          "top:     0%;"                                  },
                    { "top-left",     "top:     0%; left:  0%;"                       },
                    { "top-right",    "top:     0%; right: 0%;"                       },
                    { "bottom-left",  "bottom:  0%; left:  0%;"                       },
                    { "bottom-right", "bottom:  0%; right: 0%;"                       },
                    { "fixed",        "position: fixed !important;"                   },
                    { "relative",     "position: relative !important;"                },
                    { "absolute",     "position: absolute !important;"                },
                    { "sticky",       "position: sticky !important; top: 20px;"       }
                }).data() ){
                    data+=( regex::format( _STRING_(
                       .uk-position-${0}${2} { ${1} }
                    ), item.first, item.second, size.first ));
                }

                if( size.first != nullptr ){ data+=( "}" ); }

            }

            cli.write( data );

        });

        return app;
    }

}
