#ifndef VERTICALSTACKWIDGET_H
#define VERTICALSTACKWIDGET_H

#include "StackWidget.h"
#include <deque>

class VerticalStackWidget : public StackWidget
{
public:
    VerticalStackWidget(Widget* parent, WidgetConstraints* constraints, const sf::Color& color);
};

#endif // VERTICALSTACKWIDGET_H
