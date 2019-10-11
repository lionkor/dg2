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

void WidgetConstraints::resize(float, float, float, float)
{
}
