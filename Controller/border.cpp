#pragma once

namespace uk { 

    express_tcp_t border() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();
            
            cli.write( _STRING_( .uk-border { border: solid var(--neutral) 1px !important; } ));
        
            forEach( item, ptr_t<string_t>({
                "top", "bottom", "left", "right"
            })){

                forEach( color, ptr_t<string_t>({
                    "primary", "secondary", "success",
                    "warning", "danger"   , "mute"   , 
                    "dark"   , "light"    , "none"   ,
                    "neutral" 
                })){
                    cli.write( regex::format( _STRING_(
                       .uk-border-${0}-${1} { border-${0}-color: var(--${1}) !important; }
                    ), item, color )); 
                }
            }
        
            forEach( color, ptr_t<string_t>({
                "top", "bottom", "left", "right"
            })){
                cli.write( regex::format( _STRING_(
                   .uk-border-remove-${0} { border-${0}-color: var(--none) !important; }
                ), color )); 
            }
        
            forEach( color, ptr_t<string_t>({
                "primary", "secondary", "success",
                "warning", "danger"   , "mute"   ,
                "dark"   , "light"    , "none"   ,
                "neutral"
            })){
                cli.write( regex::format( _STRING_(
                   .uk-border-${0}               { border-color: var(--${0}) !important; }
                   .uk-border-hover-${0}:hover   { border-color: var(--${0}) !important; }
                   .uk-border-active-${0}:active { border-color: var(--${0}) !important; }
                ), color )); 
            }

        });

        return app;
    }

}