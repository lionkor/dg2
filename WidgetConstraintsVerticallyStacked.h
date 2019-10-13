#ifndef WIDGETCONSTRAINTSVERTICALSTACK_H
#define WIDGETCONSTRAINTSVERTICALSTACK_H

#include "WidgetConstraints.h"


class WidgetConstraintsVerticallyStacked : public WidgetConstraints
{
public:
    WidgetConstraintsVerticallyStacked(class VerticalStackWidget* reference);
    
    void set_stack_element(class VerticallyStackedWidget* stack_element);
    
    // WidgetConstraints interface
    glm::vec2 absolute_position() const;
    glm::vec2 absolute_size() const;
protected:
    VerticallyStackedWidget* m_stack_element;
};

#endif // WIDGETCONSTRAINTSVERTICALSTACK_H
