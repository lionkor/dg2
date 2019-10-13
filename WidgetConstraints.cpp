#include "WidgetConstraints.h"
#include "Widget.h"

WidgetConstraints::WidgetConstraints(const glm::vec2& position, const glm::vec2& size,
                                     Widget* reference)
    : m_position(position), m_size(size), m_reference(reference)
{
}

glm::vec2 WidgetConstraints::absolute_position() const
{
    if (m_reference)
    {
        return m_reference->constraints()->absolute_position() +
               m_reference->constraints()->absolute_size() * m_position;
    }
    else
    {
        std::cerr << __FILE__ << ":" << __LINE__
                  << ": WidgetConstraints has NULL reference! Returning { -1, -1 }"
                  << std::endl;
        return { -1, -1 };
    }
}

glm::vec2 WidgetConstraints::absolute_size() const
{
    if (m_reference)
    {
        return m_reference->constraints()->absolute_size() * m_size;
    }
    else
    {
        std::cerr << __FILE__ << ":" << __LINE__
                  << ": WidgetConstraints has NULL reference! Returning { -1, -1 }"
                  << std::endl;
        return { -1, -1 };
    }
}

void WidgetConstraints::resize(float, float, float, float) {}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

WidgetConstraintsFixedAspect::WidgetConstraintsFixedAspect(
    const vec2& position, const vec2& size, class Widget* reference, Origin origin,
    ScaleMode size_scale, ScaleMode position_scale)
    : WidgetConstraints(position, size, reference), m_aspect(size.y / size.x),
      m_size_scale(size_scale), m_position_scale(position_scale), m_origin(origin)
{
}

glm::vec2 WidgetConstraintsFixedAspect::absolute_position() const
{
    if (m_origin == Origin::TopLeft)
    {
        if (m_position_scale == ScaleMode::ScaleVertically)
        {
            return m_reference->constraints()->absolute_position() +
                   m_reference->constraints()->absolute_size().x * m_position;
        }
        else if (m_position_scale == ScaleMode::ScaleHorizontally)
        {
            return m_reference->constraints()->absolute_position() +
                   m_reference->constraints()->absolute_size().y * m_position;
        }
    }
    else if (m_origin == Origin::TopRight)
    {
        if (m_position_scale == ScaleMode::ScaleVertically)
        {
            return ((m_reference->constraints()->absolute_position() +
                     m_reference->constraints()->absolute_size() * vec2(1, 0)) +
                    vec2(-m_reference->constraints()->absolute_size().x,
                         m_reference->constraints()->absolute_size().x) *
                        m_position) -
                   vec2(absolute_size().x, 0);
        }
        else if (m_position_scale == ScaleMode::ScaleHorizontally)
        {
            return ((m_reference->constraints()->absolute_position() +
                     m_reference->constraints()->absolute_size() * vec2(1, 0)) +
                    vec2(-m_reference->constraints()->absolute_size().y,
                         m_reference->constraints()->absolute_size().y) *
                        m_position) -
                   vec2(absolute_size().x, 0);
        }
    }
    else if (m_origin == Origin::BottomRight)
    {
        if (m_position_scale == ScaleMode::ScaleVertically)
        {
            return ((m_reference->constraints()->absolute_position() +
                     m_reference->constraints()->absolute_size()) +
                    vec2(-m_reference->constraints()->absolute_size().x,
                         -m_reference->constraints()->absolute_size().x) *
                        m_position) -
                   absolute_size();
        }
        else if (m_position_scale == ScaleMode::ScaleHorizontally)
        {
            return ((m_reference->constraints()->absolute_position() +
                     m_reference->constraints()->absolute_size()) +
                    vec2(-m_reference->constraints()->absolute_size().y,
                         -m_reference->constraints()->absolute_size().y) *
                        m_position) -
                   absolute_size();
        }
    }
    else if (m_origin == Origin::BottomLeft)
    {
        if (m_position_scale == ScaleMode::ScaleVertically)
        {
            return ((m_reference->constraints()->absolute_position() +
                     m_reference->constraints()->absolute_size() * vec2(0, 1)) +
                    vec2(m_reference->constraints()->absolute_size().x,
                         -m_reference->constraints()->absolute_size().x) *
                        m_position) -
                   vec2(0, absolute_size().y);
        }
        else if (m_position_scale == ScaleMode::ScaleHorizontally)
        {
            return ((m_reference->constraints()->absolute_position() +
                     m_reference->constraints()->absolute_size() * vec2(0, 1)) +
                    vec2(m_reference->constraints()->absolute_size().y,
                         -m_reference->constraints()->absolute_size().y) *
                        m_position) -
                   vec2(0, absolute_size().y);
        }
    }
}

glm::vec2 WidgetConstraintsFixedAspect::absolute_size() const
{
    vec2 v = m_reference->constraints()->absolute_size() * m_size;
    if (m_size_scale == ScaleMode::ScaleVertically)
    {
        v.x = v.y * (1.f / m_aspect);
    }
    else if (m_size_scale == ScaleMode::ScaleHorizontally)
    {
        v.y = v.x * m_aspect;
    }
    return v;
}

void WidgetConstraintsFixedAspect::resize(float, float, float, float) {}
