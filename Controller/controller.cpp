#pragma once
#include "./gap.cpp"
#include "./root.cpp"
#include "./flex.cpp"
#include "./text.cpp"
#include "./icon.cpp"
#include "./list.cpp"
#include "./blend.cpp"
#include "./width.cpp"
#include "./badge.cpp"
#include "./input.cpp"
#include "./index.cpp"
#include "./header.cpp"
#include "./height.cpp"
#include "./border.cpp"
#include "./margin.cpp"
#include "./button.cpp"
#include "./toggle.cpp"
#include "./scroll.cpp"
#include "./opacity.cpp"
#include "./tooltip.cpp"
#include "./padding.cpp"
#include "./rounded.cpp"
#include "./position.cpp"
#include "./selector.cpp"
#include "./dropdown.cpp"
#include "./overflow.cpp"
#include "./animation.cpp"
#include "./transform.cpp"
#include "./visibility.cpp"
#include "./background.cpp"

namespace uk {

    template< class T >
    void controller( T& app ) {
        app.USE( "gap",        gap()        );
        app.USE( "root",       root()       );
        app.USE( "flex",       flex()       );
        app.USE( "text",       text()       );
        app.USE( "icon",       icon()       );
        app.USE( "list",       list()       );
        app.USE( "blend",      blend()      );
        app.USE( "width",      width()      );
        app.USE( "badge",      badge()      );
        app.USE( "input",      input()      );
        app.USE( "index",      index()      );
        app.USE( "height",     height()     );
        app.USE( "header",     header()     );
        app.USE( "border",     border()     );
        app.USE( "button",     button()     );
        app.USE( "toggle",     toggle()     );
        app.USE( "scroll",     scroll()     );
        app.USE( "margin",     margin()     );
        app.USE( "opacity",    opacity()    );
        app.USE( "padding",    padding()    );
        app.USE( "rounded",    rounded()    );
        app.USE( "tooltip",    tooltip()    );
        app.USE( "selector",   selector()   );
        app.USE( "overflow",   overflow()   );
        app.USE( "dropdown",   dropdown()   );
        app.USE( "position",   position()   );
        app.USE( "animation",  animation()  );
        app.USE( "transform",  transform()  );
        app.USE( "background", background() );
        app.USE( "visibility", visibility() );
    }

}
