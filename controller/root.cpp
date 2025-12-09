#pragma once

namespace uk {

    express_tcp_t root() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send( _STRING_ (

            @font-face {
                font-family: "emoji"; src: local("Segoe UI")        , local("Segoe UI Symbol")  , 
                                           local("Segoe UI Emoji")  , local("Apple Color Emoji"),
                                           local("Noto Color Emoji"), url(./emoji.ttf); unicode-range:
                U+00A9, U+00AE,                 /* Copyright, Registered Sign */
                U+200D,                         /* Zero Width Joiner */
                U+20E3,                         /* Combining Enclosing Keycap */
                U+2122, U+2139,                 /* TM, Information */
                U+2194-2199, U+21A9-21AA,       /* Arrows */
                U+2300-23FF,                    /* Various Technical, Control Pictures, Misc. Technical (incl. watch, hourglass, play buttons) */
                U+24C2,                         /* Circled M */
                U+25AA-25B6, U+25C0-25FF,       /* Geometric Shapes (incl. black/white squares, triangles, circles) */
                U+2600-27BF,                    /* Miscellaneous Symbols, Dingbats (huge range, covers hearts, stars, checkmarks, weather, religious, etc.) */
                U+2934-2935, U+2B05-2B07, U+2B1B-2B1C, U+2B50, U+2B55, /* More arrows, black/white large squares, stars, circle */
                U+3030, U+303D,                 /* Wavy Dash, Part Alternation Mark */
                U+3297, U+3299,                 /* Circled Japanese characters */
                U+1F000-1F02F,                  /* Mahjong Tiles, Domino Tiles */
                U+1F0A0-1F0FF,                  /* Playing Cards */
                U+1F100-1F1FF,                  /* Enclosed Alphanumerics, Regional Indicators (flags) */
                U+1F200-1F2FF,                  /* Enclosed Ideographic Supplement, CJK Compatibility Ideographs */
                U+1F300-1F64F,                  /* Miscellaneous Symbols and Pictographs, Emoticons (most faces, animals, food, sports, activities) */
                U+1F680-1F6FF,                  /* Transport and Map Symbols (cars, trains, buildings, signs) */
                U+1F700-1F77F,                  /* Alchemical Symbols */
                U+1F780-1F7FF,                  /* Geometric Shapes Extended */
                U+1F800-1F8FF,                  /* Supplemental Arrows-C */
                U+1F900-1F9FF,                  /* Supplemental Symbols and Pictographs (more faces, skin tones, newer animals, food, objects) */
                U+1FA00-1FA6F,                  /* Chess Symbols, Symbols and Pictographs Extended-A (incl. Melting Face) */
                U+1FA70-1FAFF,                  /* Symbols and Pictographs Extended-B (incl. Bandage) */
                U+1FB00-1FBFF,                  /* Symbols and Pictographs Extended-C (for future additions) */
                U+FE0F;                         /* Emoji Variation Selector */
            }

            @font-face {
                font-family: 'Material Symbols Rounded';
                src: url(./uikit.woff2) format('woff2');
                font-weight: lighter;
                font-style: normal;
            }

            /*.........................................................................*/

            :root {
                --secondary: #0d0d0c;
                --primary:   #6636fc;
                --success:   #00f782;
                --warning:   orange;
                --neutral:   #444;
                --danger:    #ff0d3b;
                --light:     white;
                --dark:      black;
                --mute:      #aaa;
                --none:      transparent
            }

            /*.........................................................................*/

            html {
                font-family: "emoji", -apple-system, BlinkMacSystemFont, Roboto, "Helvetica Neue", Arial, "Noto Sans", sans-serif;
                -webkit-text-size-adjust: 100%; background: var(--light); font-weight: normal; color: var(--dark); line-height: 1.5; font-size: 16px;
            }

            /*.........................................................................*/

            *        { color: inherit; text-decoration: none !important; align-content: flex-start; box-sizing: border-box; margin: 0px; font-size: inherit; word-wrap: break-word; }
            hr       { border-bottom: unset; border-color: var(--mute); }
            body     { overflow-x: hidden; margin: 0px; }
            s        { font-weight: bold !important; }
            textarea { transition: none; }

            /*.........................................................................*/

            audio, canvas, iframe, img, svg, video { vertical-align: middle; max-width: 100%; height: auto; }
            form:has(input[type="submit"]:focus){ pointer-events: none; }
            h1,h2,h3,h4,h5,h6 { display: flex; align-items: center; }
            img:not([src]) { visibility: hidden; display: none; }

            /*.........................................................................*/

            .uk-yflip { transform: scaleY(-1) !important; }
            .uk-xflip { transform: scaleX(-1) !important; }

            /*.........................................................................*/

            .uk-inline {
                -webkit-backface-visibility: hidden;
                vertical-align: middle;
                display: inline-block;
                position: relative;
                max-width: 100%;
            }

            /*.........................................................................*/

            a, .uk-link, label:has(input) {
                text-decoration: none;
                cursor: pointer;
                color: inherit;
            }

        )); });

        return app;
    }

}
