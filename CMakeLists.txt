project(dg2)

add_executable(dg2 main.cpp
    Widget.h Widget.cpp
    WidgetRenderer.h WidgetRenderer.cpp
    ButtonWidget.h ButtonWidget.cpp
    WidgetConstraints.h WidgetConstraints.cpp
    WidgetConstraintsAbsolute.h WidgetConstraintsAbsolute.cpp
    WidgetConstraintsVerticallyStacked.h WidgetConstraintsVerticallyStacked.cpp
    WidgetConstraintsHorizontallyStacked.h WidgetConstraintsHorizontallyStacked.cpp
    StackWidget.h StackWidget.cpp
    VerticalStackWidget.h VerticalStackWidget.cpp
    HorizontalStackWidget.h HorizontalStackWidget.cpp
    HorizontallyStackedWidget.h HorizontallyStackedWidget.cpp
    VerticallyStackedWidget.h VerticallyStackedWidget.cpp
    # add files here
)

target_link_libraries(dg2 sfml-window sfml-graphics sfml-system)
 
