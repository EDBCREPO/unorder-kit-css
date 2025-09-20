#pragma once

namespace uk { 

    express_tcp_t rounded() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            for( auto& item : map_t<string_t,string_t>({
                { "none",    "0px"  },
                { "2xsmall", "2px"  },
                { "xsmall",  "3px"  },
                { "small",   "10px" },
                { "medium",  "20px" },
                { "large",   "25px" },
                { "xlarge",  "30px" },
                { "2xlarge", "35px" }
            }).data() ){
                data+=( regex::format( _STRING_(
                   .uk-rounded-hover-${0}:hover { border-radius: ${1}; }
                   .uk-rounded-${0}             { border-radius: ${1}; }
                ), item.first, item.second ));
            }

            data+=( _STRING_ ( 

                .uk-rounded-hover-phill:hover { border-radius: 500px; }
                .uk-rounded-phill             { border-radius: 500px; }

                .uk-rounded-hover:hover       { border-radius: 5px;  } 
                .uk-rounded                   { border-radius: 5px;  }
                
                .uk-rounded-remove-top { 
                    border-top-left-radius:    0px !important; 
                    border-top-right-radius:   0px !important; 
                }
                
                .uk-rounded-remove-left { 
                    border-top-left-radius:    0px !important; 
                    border-bottom-left-radius: 0px !important; 
                }
                
                .uk-rounded-remove-right { 
                    border-top-right-radius:    0px !important; 
                    border-bottom-right-radius: 0px !important; 
                }
                
                .uk-rounded-remove-bottom { 
                    border-bottom-left-radius:  0px !important; 
                    border-bottom-right-radius: 0px !important; 
                }
                
                .uk-rounded-remove { 
                    border-top-left-radius:     0px !important; 
                    border-top-right-radius:    0px !important; 
                    border-bottom-left-radius:  0px !important; 
                    border-bottom-right-radius: 0px !important; 
                }
                
            ));

            cli.write( data );

        });

        return app;
    }

}