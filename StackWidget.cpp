#include "StackWidget.h"

StackWidget::StackWidget(Widget* parent, class WidgetConstraints* constraints, const sf::Color& color)
    : Widget(parent, constraints, color)
{
}

std::int64_t StackWidget::stack_index_of(Widget* w) const
{
    return std::distance(m_internal_stack.begin(), std::find(m_internal_stack.begin(), m_internal_stack.end(), w));
}

void StackWidget::on_child_register(Widget* child)
{
    m_internal_stack.push_back(child);
}

