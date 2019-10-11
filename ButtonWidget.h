#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include "Widget.h"
#include "WidgetRenderer.h"
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <iostream>

using glm::vec2;

class ButtonWidget : public Widget
{
public:
    // Widget interface
protected:
    bool on_click(float x, float y);

private:
};
#endif // BUTTONWIDGET_H
