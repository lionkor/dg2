#include "WidgetConstraintsAbsolute.h"


WidgetConstraintsAbsolute::WidgetConstraintsAbsolute(const glm::vec2& abs_position,
                                                     const glm::vec2& abs_size)
    : WidgetConstraints({ 0, 0 }, { 0, 0 }, nullptr), m_abs_position(abs_position),
      m_abs_size(abs_size)
{
}

WidgetConstraintsAbsolute::~WidgetConstraintsAbsolute() {}

glm::vec2 WidgetConstraintsAbsolute::absolute_position() const { return m_abs_position; }

glm::vec2 WidgetConstraintsAbsolute::absolute_size() const { return m_abs_size; }

void WidgetConstraintsAbsolute::resize(float x, float y, float w, float h)
{
    m_abs_position = { x, y };
    m_abs_size = { w, h };
}
