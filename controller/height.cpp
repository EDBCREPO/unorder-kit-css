#pragma once

namespace uk {

    express_tcp_t height() {
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

                for( auto x=1; x<=12; x++ ){ for( auto y=1; y<=12; y++ ){ if( x >= y ){ continue; }
                    data+=( regex::format( _STRING_(
                       .uk-vh-${0}-${1}${2}     { min-height: calc( 100vh*${0}/${1} ); max-height: calc( 100vh*${0}/${1} ); }
                       .uk-height-${0}-${1}${2} { min-height: calc( ${0}00%   /${1} ); max-height: calc( ${0}00%   /${1} ); }
                    ), x, y, size.first ));
                }}

                for( auto& item : map_t<string_t,string_t>({
                   { "none",    "0px"   },
                   { "small",   "150px" },
                   { "medium",  "300px" },
                   { "large",   "450px" }
                }).data() ){
                    data+=( regex::format( _STRING_ (
                       .uk-height-${0}${2}     { min-height:${1}; }
                    ), item.first, item.second, size.first ));
                }

                data+=( regex::format( _STRING_(
                   .uk-height-expand${0} { min-height: 100vh; }
                   .uk-height-fill${0}   { min-height: 100%;  }
                   .uk-height-1-1${0}    { min-height: 100%;  }
                ), size.first ));

                if( size.first != nullptr ){ data+=( "}" ); }

            }

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

                for( auto x=1; x<=12; x++ ){ for( auto y=1; y<=12; y++ ){ if( x >= y ){ continue; }
                    data+=( regex::format( _STRING_(
                       .uk-child-height-${0}-${1}${2}>:not([class*='uk-height']){ min-height: calc( ${0}00% / ${1} );  max-height: calc( ${0}00% / ${1} );  }
                    ), x, y, size.first ));
                }}

                data+=( regex::format( _STRING_(
                   .uk-child-height-expand${0}>:not([class*='uk-height']){ min-height: 100vh; }
                   .uk-child-height-fill${0}>:not([class*='uk-height'])  { min-height: 100%;  }
                   .uk-child-height-1-1${0}>:not([class*='uk-height'])   { min-height: 100%;  }
                ), size.first ));

                if( size.first != nullptr ){ data+=( "}" ); }

            }

            cli.write( data );

        });

        return app;
    }

}
