#pragma once

namespace uk {

    express_tcp_t toggle() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            data+=( _STRING_( [toggle=""]:not(input):has(input[toggle]:checked) { display: none !important; } ));
            data+=( _STRING_( [toggle-hover=""]:not(:hover) [toggle]{ display: none !important; } ));

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

                for( auto x=0; x<=12; x++ ){
                    data+=( regex::format( _STRING_(
                       body:has(input[class="uk-toggle-${0}${1}"]:checked)       [toggle="${0}"] { display: none !important; }
                       body:has(input[class="uk-toggle-${0}${1}"]:not(:checked)) [toggle="!${0}"]{ display: none !important; }
                    ), x, size.first ));
                }

                if( size.first != nullptr ){ data+=( "}" ); }

            }

            cli.write( data );

        });

        return app;
    }

}
