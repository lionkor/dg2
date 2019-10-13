#include "WidgetConstraintsHorizontallyStacked.h"
#include "HorizontalStackWidget.h"
#include "HorizontallyStackedWidget.h"
#include "Widget.h"

WidgetConstraintsHorizontallyStacked::WidgetConstraintsHorizontallyStacked(
    HorizontalStackWidget* reference)
    : WidgetConstraints({ 0, 0 }, { 0, 0 }, reference)
{
}

void WidgetConstraintsHorizontallyStacked::set_stack_element(
    HorizontallyStackedWidget* stack_element)
{
    m_stack_element = stack_element;
}

glm::vec2 WidgetConstraintsHorizontallyStacked::absolute_position() const
{
    // (stack_height / stack_item_count) * index_in_stack, stack_y
    return vec2(m_reference->constraints()->absolute_position().x +
                    ((float(m_reference->constraints()->absolute_size().x) /
                      float(m_reference->child_count())) *
                     float(dynamic_cast<HorizontalStackWidget*>(m_reference)
                               ->stack_index_of(m_stack_element))),
                m_reference->constraints()->absolute_position().y);
}

glm::vec2 WidgetConstraintsHorizontallyStacked::absolute_size() const
{
    // (stack_height / stack_item_count), stack_y
    return vec2(float(m_reference->constraints()->absolute_size().x) /
                    float(m_reference->child_count()),
                m_reference->constraints()->absolute_size().y);
}
