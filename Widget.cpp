#include "Widget.h"
#include <iostream>

bool Widget::aabb_collision(const glm::vec2& point)
{
    return point.x > m_position.x && point.x < m_position.x + m_size.x &&
           point.y > m_position.y && point.y < m_position.y + m_size.y;
}

Widget::Widget(Widget* parent, const vec2& position, const vec2& size,
               const sf::Color& color)
    : m_parent(parent), m_position(position), m_size(size) // std::move?
{
    if (parent)
    {
        parent->register_child(this);
        m_layer = parent->m_layer + 1;
    }
    else
    {
        m_layer = 0;
    }
    m_varray = sf::VertexArray(sf::Quads, 4);
    m_varray[0] = sf::Vertex({ m_position.x, m_position.y }, color);
    m_varray[1] = sf::Vertex({ m_position.x + m_size.x, m_position.y }, color);
    m_varray[2] = sf::Vertex({ m_position.x + m_size.x, m_position.y + m_size.y }, color);
    m_varray[3] = sf::Vertex({ m_position.x, m_position.y + m_size.y }, color);
    WidgetRenderer::the()->submit(this, color);
}

void Widget::fire_click_event(int x, int y)
{
    bool propagate = true;
    for (Widget* w : m_children)
    {
        // on_click is able to stop propagation of the event.
        if (w->aabb_collision({ x, y }))
        {
            if (!w->on_click(x, y))
            {
                propagate = false;
                break;
            }
        }
    }
    if (propagate && aabb_collision({ x, y }))
        on_click(x, y);
}

bool Widget::operator<(const Widget& rhs) { return m_layer < rhs.m_layer; }

bool Widget::operator>(const Widget& rhs) { return m_layer > rhs.m_layer; }

void Widget::fire_update_event()
{
    // std::cout << this << " - on_update" << std::endl;
    for (Widget* w : m_children)
    {
        w->on_update();
    }
}

void Widget::register_child(Widget* c)
{
    m_children.push_back(c);
    std::sort(m_children.begin(), m_children.end(), [](Widget* first, Widget* second) {
        // Sorting backwards to support proper propagation handling
        return first->layer() > second->layer();
    });
}
