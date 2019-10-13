#include "WidgetConstraintsVerticallyStacked.h"
#include "VerticallyStackedWidget.h"
#include "VerticalStackWidget.h"

VerticallyStackedWidget::VerticallyStackedWidget(VerticalStackWidget* parent,
                                                 const sf::Color& color)
    : Widget(parent, new WidgetConstraintsVerticallyStacked(parent), color)
{
    dynamic_cast<WidgetConstraintsVerticallyStacked*>(m_constraints.get())
        ->set_stack_element(this);
    m_layer += std::uint64_t(parent->stack_index_of(this));
    parent->fire_redraw_event();
}
