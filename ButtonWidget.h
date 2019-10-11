#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Widget.h"
#include "WidgetRenderer.h"
#include <glm/glm.hpp>

using glm::vec;
using glm::vec2;

class ButtonWidget : public Widget
{
public:
    ButtonWidget(Widget* parent, const vec2& pos, const vec2& size);
    
    // Widget interface
protected:
    bool on_click(int x, int y);
private:
};
#endif // BUTTONWIDGET_H
