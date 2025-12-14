#pragma once

namespace uk {

    express_tcp_t list() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send(); string_t data;

            data+=( regex::format( _STRING_(

                .uk-list-striped > *                 { padding: 8px 10px; margin: 0px !important; }
                .uk-list-striped > :nth-of-type(odd) { background: var(--neutral); }

                .uk-list-decimal> ::before { content: counter(decimal, decimal) '\200A.\00A0'; }
                .uk-list-hyphen > ::before { content: '–\00A0\00A0';  }

                .uk-list-disc              { list-style-type: disc   !important; }
                .uk-list-circle            { list-style-type: circle !important; }
                .uk-list-square            { list-style-type: square !important; }

                .uk-list > :nth-child(n+2), .uk-list > * > ul { margin-top: 10px; }
                .uk-list > * > :last-child { margin-bottom: 0; }
                .uk-list > * { break-inside: avoid-column; }
                .uk-list { list-style: none; }

                .uk-list-decimal   { counter-reset: decimal;     }
                .uk-list-decimal>* { counter-increment: decimal; }

                .uk-list-divider > :nth-child(n+2) {
                    border-top:  1px solid var(--neutral);
                    padding-top: 10px;
                    margin-top:  10px;
                }

                .uk-list { padding: 0px 10px; }

            )));

            for( auto& color : ptr_t<string_t>({
                "primary", "secondary", "success",
                "warning", "danger"   , "mute"   ,
                "dark"   , "light"    , "neutral"
            })){ data+=( regex::format( _STRING_(
                .uk-list-divider-${0} > :nth-child(n+2) {
                    border-top:  1px solid var(--${0});
                    padding-top: 10px;
                    margin-top:  10px;
                }
            ), color )); }

            for( auto& color: map_t<string_t,string_t>({
                { "primary",   "var(--light)" },
                { "secondary", "var(--light)" },
                { "success",   "var(--dark)"  },
                { "warning",   "var(--dark)"  },
                { "danger",    "var(--light)" },
                { "mute",      "var(--dark)"  },
                { "dark",      "var(--light)" },
                { "light",     "var(--dark)"  },
                { "neutral",   "var(--light)" },
                { "none",      "inherit"      }
            }).data() ){ data+=( regex::format( _STRING_(
               .uk-list-striped-${0} > :nth-of-type(odd) { background-color: var(--${0}); color: ${1}; }
            ), color.first, color.second )); }

            cli.write( data );

        });

        return app;
    }

}
