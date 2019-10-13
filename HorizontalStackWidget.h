#ifndef HORIZONTALSTACKWIDGET_H
#define HORIZONTALSTACKWIDGET_H

#include "StackWidget.h"
#include <deque>

class HorizontalStackWidget : public StackWidget
{
public:
    HorizontalStackWidget(Widget* parent, WidgetConstraints* constraints, const sf::Color& color);
};

#endif // HORIZONTALSTACKWIDGET_H
