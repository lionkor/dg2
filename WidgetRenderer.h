#ifndef WIDGETRENDERER_H
#define WIDGETRENDERER_H

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <memory>
#include <unordered_map>

using WidgetRenderId = std::uint64_t;

class WidgetRenderer
{
public:
    ~WidgetRenderer() {}

    static WidgetRenderer* the();

    void submit(class Widget* w);
    void draw(sf::RenderWindow& window);

private:
    WidgetRenderer();

    // FIXME Assumes rectangles
    // std::map<Widget*, sf::VertexArray> m_widget_vertices;
    std::vector<Widget*> m_widget_vertices;
    sf::VertexBuffer m_render_buffer;
    static WidgetRenderer* m_instance;
};

#endif // WIDGETRENDERER_H
