#pragma once

namespace uk {

    express_tcp_t width() {
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
                       .uk-vw-${0}-${1}${2}    { min-width: calc( 100vw * ${0} / ${1} ); max-width: calc( 100vw * ${0} / ${1} ); }
                       .uk-width-${0}-${1}${2} { min-width: calc( ${0}00% / ${1} );      max-width: calc( ${0}00%      / ${1} ); }
                    ), x, y, size.first ));
                }}

                for( auto& item : map_t<string_t,string_t>({
                    { "none",    "0px"   },
                    { "small",   "150px" },
                    { "medium",  "300px" },
                    { "large",   "450px" }
                }).data() ){
                    data+=( regex::format( _STRING_ (
                       .uk-width-${0}${2}     { min-width:${1}; max-width:${1}; }
                    ), item.first, item.second, size.first ));
                }

                data+=( regex::format( _STRING_(
                   .uk-width-auto${0}   { flex: auto; min-width: unset; max-width: unset; width: 100%; }
                   .uk-width-expand${0} { min-width: fit-content; }
                   .uk-width-fill${0}   { min-width: 100%; }
                   .uk-width-1-1${0}    { min-width: 100%; }
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
                       .uk-child-width-${0}-${1}${2}>:not([class*='uk-width']){ min-width: calc( ${0}00% / ${1} ); max-width: calc( ${0}00% / ${1} ); }
                    ), x, y, size.first ));
                }}

                data+=( regex::format( _STRING_(
                   .uk-child-width-auto${0}>:not([class*='uk-width'])  { flex: auto; min-width: unset; max-width: unset; width: 100%; }
                   .uk-child-width-expand${0}>:not([class*='uk-width']){ min-width: fit-content; }
                   .uk-child-width-fill${0}>:not([class*='uk-width'])  { min-width: 100%; }
                   .uk-child-width-1-1${0}>:not([class*='uk-width'])   { min-width: 100%; }
                ), size.first ));

                if( size.first != nullptr ){ data+=( "}" ); }

            }

            cli.write( data );

        });

        return app;
    }

}
