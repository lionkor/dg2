#ifndef STACKWIDGET_H
#define STACKWIDGET_H

#include "Widget.h"
#include <deque>

class StackWidget : public Widget
{
public:
    StackWidget(Widget* parent, WidgetConstraints* constraints, const sf::Color& color);
    
    virtual inline std::int64_t stack_index_of(Widget* w) const;
    
protected:
    void on_child_register(Widget* child);
    
    std::deque<Widget*> m_internal_stack;
};

#endif // STACKWIDGET_H
