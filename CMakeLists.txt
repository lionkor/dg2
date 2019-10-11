project(dg2)

add_executable(dg2 main.cpp
    Widget.h Widget.cpp
    WidgetRenderer.h WidgetRenderer.cpp
    ButtonWidget.h ButtonWidget.cpp
    # add files here
)

target_link_libraries(dg2 sfml-window sfml-graphics sfml-system)
