#ifndef WIDGETRENDERER_H
#define WIDGETRENDERER_H

#include <cstdint>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <memory>

using WidgetRenderId=std::uint64_t;

class WidgetRenderer
{
public:
    ~WidgetRenderer() {}
    
    static WidgetRenderer* the();
    
    void submit(class Widget* w, const sf::Color& color);
    void draw(sf::RenderWindow& window);
private:
    WidgetRenderer();
    
    // FIXME Assumes rectangles
    //std::map<Widget*, sf::VertexArray> m_widget_vertices;
    std::vector<Widget*> m_widget_vertices;
    sf::VertexBuffer m_render_buffer;
    static WidgetRenderer* m_instance;
};

#endif // WIDGETRENDERER_H
