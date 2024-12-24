#pragma once

namespace uk { 

    express_tcp_t header() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            for( auto& item: map_t<string_t,string_t>({
                { "h1",   "font-size: xx-large !important;" },
                { "h2",   "font-size: x-large  !important;" },
                { "h3",   "font-size: large    !important;" },
                { "h4",   "font-size: medium   !important;" },
                { "h5",   "font-size: unset    !important;" },
                { "h6",   "font-size: unset    !important;" },
            }).data() ){ cli.write( regex::format( _STRING_(
                ${0} *, .uk-${0} * { font-size: inherit !important; font-weight: inherit !important; }
                ${0},   .uk-${0}   { ${1} }
            ), item.first, item.second )); }
            
        });

        return app;
    }

}