#include "Widget.h"
#include "WidgetConstraintsAbsolute.h"
#include <iostream>

bool Widget::aabb_collision(const glm::vec2& point)
{
    return point.x > m_position.x && point.x < m_position.x + m_size.x &&
           point.y > m_position.y && point.y < m_position.y + m_size.y;
}

Widget::Widget(Widget* parent, WidgetConstraints* constraints,
               const sf::Color& color)
    : m_parent(parent), m_constraints(constraints),
      m_position(m_constraints->absolute_position()), m_size(m_constraints->absolute_size()), m_color(color)
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
    m_varray[0] = sf::Vertex({ m_position.x, m_position.y }, m_color);
    m_varray[1] = sf::Vertex({ m_position.x + m_size.x, m_position.y }, m_color);
    m_varray[2] = sf::Vertex({ m_position.x + m_size.x, m_position.y + m_size.y }, m_color);
    m_varray[3] = sf::Vertex({ m_position.x, m_position.y + m_size.y }, m_color);
    WidgetRenderer::the()->submit(this);
}


void Widget::on_update() {}

void Widget::on_resize(float, float) {}

bool Widget::on_click(float, float)
{
    std::cout << "Widget received click event!" << std::endl;
    return true;
}

bool Widget::operator<(const Widget& rhs) { return m_layer < rhs.m_layer; }

bool Widget::operator>(const Widget& rhs) { return m_layer > rhs.m_layer; }

bool Widget::fire_click_event(float x, float y)
{
    bool propagate = true;
    for (Widget* w : m_children)
    {
        // on_click is able to stop propagation of the event.
        if (w->aabb_collision({ x, y }))
        {
            if (!w->fire_click_event(x, y))
            {
                propagate = false;
                break;
            }
        }
    }
    if (propagate && aabb_collision({ x, y }))
        return on_click(x, y);
    return false;
}

void Widget::fire_update_event()
{
    for (Widget* w : m_children)
    {
        w->on_update();
    }
}

void Widget::fire_resize_event(float x, float y, float w, float h)
{
    m_constraints->resize(x, y, w, h);
    m_position = m_constraints->absolute_position();
    m_size = m_constraints->absolute_size();

    m_varray[0] = sf::Vertex({ m_position.x, m_position.y }, m_color);
    m_varray[1] = sf::Vertex({ m_position.x + m_size.x, m_position.y }, m_color);
    m_varray[2] = sf::Vertex({ m_position.x + m_size.x, m_position.y + m_size.y }, m_color);
    m_varray[3] = sf::Vertex({ m_position.x, m_position.y + m_size.y }, m_color);
    WidgetRenderer::the()->submit(this);
    
    for (Widget* widget : m_children)
    {
        widget->fire_resize_event(x, y, w, h);
    }
    on_resize(w, h);
}

void Widget::register_child(Widget* c)
{
    m_children.push_back(c);

    std::sort(m_children.begin(), m_children.end(), [](Widget* first, Widget* second) {
        // Sorting backwards to support proper propagation handling
        return first->layer() > second->layer();
    });
}
