#include "HorizontallyStackedWidget.h"
#include "HorizontalStackWidget.h"
#include "WidgetConstraintsHorizontallyStacked.h"

HorizontallyStackedWidget::HorizontallyStackedWidget(HorizontalStackWidget* parent,
                                                     const sf::Color& color)
    : Widget(parent, new WidgetConstraintsHorizontallyStacked(parent), color)
{
    dynamic_cast<WidgetConstraintsHorizontallyStacked*>(m_constraints.get())
        ->set_stack_element(this);
    m_layer += std::uint64_t(parent->stack_index_of(this));
    parent->fire_redraw_event();
}
