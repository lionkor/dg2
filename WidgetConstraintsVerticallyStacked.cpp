#include "WidgetConstraintsVerticallyStacked.h"
#include "VerticalStackWidget.h"
#include "VerticallyStackedWidget.h"
#include "Widget.h"

WidgetConstraintsVerticallyStacked::WidgetConstraintsVerticallyStacked(
    VerticalStackWidget* reference)
    : WidgetConstraints({ 0, 0 }, { 0, 0 }, reference)
{
}

void WidgetConstraintsVerticallyStacked::set_stack_element(
    VerticallyStackedWidget* stack_element)
{
    m_stack_element = stack_element;
}

glm::vec2 WidgetConstraintsVerticallyStacked::absolute_position() const
{
    // stack_x, (stack_height / stack_item_count) * index_in_stack
    return vec2(m_reference->constraints()->absolute_position().x,
                m_reference->constraints()->absolute_position().y +
                    ((float(m_reference->constraints()->absolute_size().y) /
                      float(m_reference->child_count())) *
                     float(dynamic_cast<VerticalStackWidget*>(m_reference)
                               ->stack_index_of(m_stack_element))));
}

glm::vec2 WidgetConstraintsVerticallyStacked::absolute_size() const
{
    // stack_x, (stack_height / stack_item_count)
    return vec2(m_reference->constraints()->absolute_size().x,
                float(m_reference->constraints()->absolute_size().y) /
                    float(m_reference->child_count()));
}
