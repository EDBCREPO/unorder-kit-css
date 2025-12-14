#pragma once

namespace uk {

    express_tcp_t animation() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ 
            
            cli.send( _STRING_(
            
                [class*="uk-animation"] { animation: 0.5s ease-out both; }

                /* Fade */
                [animation="fade"] {
                    animation-name: uk-fade;
                    animation-duration: 0.8s;
                    animation-timing-function: linear;
                }

                /* Fade */
                [animation="shake"] {
                    animation-name: uk-shake;
                    animation-duration: 0.8s;
                    animation-timing-function: linear;
                }

                /* Fade */
                [animation="kenburns"] {
                    animation-duration: 0.8s;
                    animation-name: uk-kenburns;
                    animation-timing-function: linear;
                }

                /* Scale */
                [animation="scale-up"]  { animation-name: uk-fade, uk-scale-up;   }
                [animation="scale-down"]{ animation-name: uk-fade, uk-scale-down; }

                /* Slide */
                [animation="slide-top"]   { animation-name: uk-fade, uk-slide-top;    }
                [animation="slide-left"]  { animation-name: uk-fade, uk-slide-left;   }
                [animation="slide-right"] { animation-name: uk-fade, uk-slide-right;  }
                [animation="slide-bottom"]{ animation-name: uk-fade, uk-slide-bottom; }

                /* Slide Small */
                [animation="slide-top-small"]   { animation-name: uk-fade, uk-slide-top-small;    }
                [animation="slide-left-small"]  { animation-name: uk-fade, uk-slide-left-small;   }
                [animation="slide-right-small"] { animation-name: uk-fade, uk-slide-right-small;  }
                [animation="slide-bottom-small"]{ animation-name: uk-fade, uk-slide-bottom-small; }

                /* Slide Medium */
                [animation="slide-top-medium"]   { animation-name: uk-fade, uk-slide-top-medium;    }
                [animation="slide-left-medium"]  { animation-name: uk-fade, uk-slide-left-medium;   }
                [animation="slide-right-medium"] { animation-name: uk-fade, uk-slide-right-medium;  }
                [animation="slide-bottom-medium"]{ animation-name: uk-fade, uk-slide-bottom-medium; }

                /* -- -- -- */

                .uk-animation-loop     { animation-iteration-count: infinite; }
                .uk-animation-alternate{ animation-direction: alternate; }
                .uk-animation-reverse  { animation-direction: reverse; }
                .uk-animation-slow     { animation-duration: 0.9s; }
                .uk-animation-fast     { animation-duration: 0.1s; }

                /* -- -- -- */

                .uk-animation-delay-1s { animation-delay: 1s; }
                .uk-animation-delay-2s { animation-delay: 2s; }
                .uk-animation-delay-3s { animation-delay: 3s; }
                .uk-animation-delay-4s { animation-delay: 4s; }
                .uk-animation-delay-5s { animation-delay: 5s; }
                .uk-animation-delay-6s { animation-delay: 6s; }
                .uk-animation-delay-7s { animation-delay: 7s; }
                .uk-animation-delay-8s { animation-delay: 8s; }
                .uk-animation-delay-9s { animation-delay: 9s; }
                .uk-animation-delay-10s{ animation-delay:10s; }

                /* -- -- -- */

                .uk-animation-toggle:not(:hover):not(:focus) [class*="uk-animation"] { animation-name: none; }

                /* Fade */
                @keyframes uk-fade {
                    0%   { opacity: 0; }
                    100% { opacity: 1; }
                }

                /* Scale */
                @keyframes uk-scale-up {
                    0%   { transform: scale(0.9); }
                    100% { transform: scale(1);   }
                }
                
                @keyframes uk-scale-down {
                    0%   { transform: scale(1.1); }
                    100% { transform: scale(1);   }
                }
                
                /* Slide */
                @keyframes uk-slide-top {
                    0%   { transform: translateY(-100%); }
                    100% { transform: translateY(0);     }
                }

                @keyframes uk-slide-bottom {
                    0%   { transform: translateY(100%); }
                    100% { transform: translateY(0);    }
                }

                @keyframes uk-slide-left {
                    0%   { transform: translateX(-100%); }
                    100% { transform: translateX(0);     }
                }

                @keyframes uk-slide-right {
                    0%   { transform: translateX(100%); }
                    100% { transform: translateX(0);    }
                }

                /* Slide Small */
                @keyframes uk-slide-top-small {
                    0%   { transform: translateY(-10px); }
                    100% { transform: translateY(0); }
                }
                @keyframes uk-slide-bottom-small {
                    0%   { transform: translateY(10px); }
                    100% { transform: translateY(0); }
                }
                @keyframes uk-slide-left-small {
                    0%   { transform: translateX(-10px); }
                    100% { transform: translateX(0); }
                }
                @keyframes uk-slide-right-small {
                    0%   { transform: translateX(10px); }
                    100% { transform: translateX(0); }
                }

                /* Slide Medium */
                @keyframes uk-slide-top-medium {
                    0%   { transform: translateY(-50px); }
                    100% { transform: translateY(0); }
                }
                @keyframes uk-slide-bottom-medium {
                    0%   { transform: translateY(50px); }
                    100% { transform: translateY(0); }
                }
                @keyframes uk-slide-left-medium {
                    0%   { transform: translateX(-50px); }
                    100% { transform: translateX(0); }
                }
                @keyframes uk-slide-right-medium {
                    0%   { transform: translateX(50px); }
                    100% { transform: translateX(0); }
                }

                /* Kenburns */
                @keyframes uk-kenburns {
                    0%   { transform: scale(1);   }
                    100% { transform: scale(1.2); }
                }

                /* Shake */
                @keyframes uk-shake {
                    0%, 100% { transform: translateX(0);    }
                    10%      { transform: translateX(-9px); }
                    20%      { transform: translateX(8px);  }
                    30%      { transform: translateX(-7px); }
                    40%      { transform: translateX(6px);  }
                    50%      { transform: translateX(-5px); }
                    60%      { transform: translateX(4px);  }
                    70%      { transform: translateX(-3px); }
                    80%      { transform: translateX(2px);  }
                    90%      { transform: translateX(-1px); }
                }

            ));

        });

        return app;
    }

}
