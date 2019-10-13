#ifndef WIDGETCONSTRAINTHORIZONTALLYSTACKED_H
#define WIDGETCONSTRAINTHORIZONTALLYSTACKED_H
#include "WidgetConstraints.h"


class WidgetConstraintsHorizontallyStacked : public WidgetConstraints
{
public:
    WidgetConstraintsHorizontallyStacked(class HorizontalStackWidget* reference);
    
    void set_stack_element(class HorizontallyStackedWidget* stack_element);
    
    // WidgetConstraints interface
    glm::vec2 absolute_position() const;
    glm::vec2 absolute_size() const;
protected:
    HorizontallyStackedWidget* m_stack_element;
};
#endif // WIDGETCONSTRAINTHORIZONTALLYSTACKED_H
