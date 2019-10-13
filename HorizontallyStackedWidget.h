#ifndef HORIZONTALLYSTACKEDWIDGET_H
#define HORIZONTALLYSTACKEDWIDGET_H

#include "Widget.h"


/// Widget that can be stacked within VerticalStackWidget
class HorizontallyStackedWidget : public Widget
{
public:
    HorizontallyStackedWidget(class HorizontalStackWidget* parent,
                            const sf::Color& color);
};

#endif // HORIZONTALLYSTACKEDWIDGET_H
