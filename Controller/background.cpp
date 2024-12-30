#pragma once

namespace uk { 

    express_tcp_t background() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();
            
            for( auto& color: map_t<string_t,string_t>({
                { "primary",   "var(--light)" },
                { "secondary", "var(--light)" },
                { "success",   "var(--dark)"  },
                { "warning",   "var(--light)" },
                { "danger",    "var(--light)" },
                { "mute",      "var(--dark)"  },
                { "dark",      "var(--light)" },
                { "light",     "var(--dark)"  },
                { "neutral",   "var(--light)" },
                { "none",      "inherit"      }
            }).data() ){
                cli.write( regex::format( _STRING_(
                   .uk-background-hover-${0}:hover { background-color: var(--${0}) !important; color: ${1}  !important; }
                   .uk-background-${0}             { background-color: var(--${0}); color: ${1}; }
                   .uk-hr-${0}                     { border-color: var(--${0}) !important; }
                ), color.first, color.second )); 
            }

        });

        return app;
    }

}