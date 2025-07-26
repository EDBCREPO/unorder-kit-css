#pragma once

namespace uk {

    express_tcp_t visibility() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            for( auto& size: map_t<string_t,int>({
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

                data+=( regex::format( _STRING_(
                   .uk-visible${0} { display: none !important; }
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

                data+=( regex::format( _STRING_(
                   .uk-hidden${0} { display: none !important; }
                ), size.first ));

                if( size.first != nullptr ){ data+=( "}" ); }

            }

            cli.write( data );

        });

        return app;
    }

}
