#include "WidgetRenderer.h"
#include "Widget.h"

template<typename _First, typename _Second>
bool compare_layers(const _First& first, const _Second& second)
{
    return first.layer() < second.layer();
}

WidgetRenderer* WidgetRenderer::m_instance = nullptr;

WidgetRenderer::WidgetRenderer()
    : m_render_buffer(sf::PrimitiveType::Quads, sf::VertexBuffer::Usage::Static)
{
}

WidgetRenderer* WidgetRenderer::the()
{
    if (!m_instance)
    {
        m_instance = new WidgetRenderer();
    }
    return m_instance; // FIXME: this is super janky
}

void WidgetRenderer::submit(Widget* w)
{
    if (!w)
        return;
    auto it = std::find(m_widget_vertices.begin(), m_widget_vertices.end(), w);
    if (it != m_widget_vertices.end())
    {
        m_widget_vertices.erase(it);
    }
    m_widget_vertices.push_back(w);
}

void WidgetRenderer::draw(sf::RenderWindow& window)
{
    for (const auto& widget : m_widget_vertices)
    {
        window.draw(widget->drawable());
    }
}
