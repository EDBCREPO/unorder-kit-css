#pragma once

namespace uk {

    express_tcp_t root() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){
            cli.render( _STRING_ (

                @font-face {
                    font-family: 'Material Symbols Rounded';
                    src: url(./icon.woff2) format('woff2');
                    font-style: normal;
                    font-weight: 400;
                }

                /*.........................................................................*/

                :root {
                    --secondary: #0c0b0e;
                    --primary:   #6200ff;
                    --success:   #1f0;
                    --warning:   #ffc300;
                    --neutral:   #444;
                    --danger:    #ff004c;
                    --light:     white;
                    --dark:      black;
                    --mute:      #aaa;
                    --none:      transparent
                }

                /*.........................................................................*/

                html {
                    font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, "Helvetica Neue", Arial, "Noto Sans", sans-serif, "Apple Color Emoji", "Segoe UI Emoji", "Segoe UI Symbol", "Noto Color Emoji";
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

            ));
        });

        return app;
    }

}
