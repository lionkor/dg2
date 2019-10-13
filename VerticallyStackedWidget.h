#ifndef VERTICALLYSTACKEDWIDGET_H
#define VERTICALLYSTACKEDWIDGET_H

#include "Widget.h"


/// Widget that can be stacked within VerticalStackWidget
class VerticallyStackedWidget : public Widget
{
public:
    VerticallyStackedWidget(class VerticalStackWidget* parent,
                            const sf::Color& color);
};

#endif // VERTICALLYSTACKEDWIDGET_H
