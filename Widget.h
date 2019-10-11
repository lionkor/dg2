#ifndef WIDGET_H
#define WIDGET_H

#include <functional>
#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include "WidgetRenderer.h"
#include <iostream>

using glm::vec2;

class Widget
{
public:
    Widget(Widget* parent, const vec2& position, const vec2& size, const sf::Color& color);
    virtual ~Widget() {};
    
    inline const Widget* parent() { return m_parent; }
    
    virtual void fire_update_event() final;
    virtual void fire_click_event(int x, int y) final;
    
    // accessors
    inline vec2& position() { return m_position; }
    inline vec2& size() { return m_size; }
    inline unsigned& layer() { return m_layer; }
    
    // virtual accessors
    inline virtual sf::Drawable& drawable() { return m_varray; }
    
    // const accessors
    inline const vec2& position() const { return m_position; }
    inline const vec2& size() const { return m_size; }
    inline unsigned layer() const { return m_layer; }
    
    // virtual const accessors
    inline virtual const sf::Drawable& drawable() const { return m_varray; }
    
    bool operator<(const Widget& rhs);
    bool operator>(const Widget& rhs);
protected:
    virtual inline void on_update() { }
    // bool since it can stop propagation
    virtual inline bool on_click(int x, int y) { std::cout << "Widget received click event!" << std::endl; return true; }
    
    vec2 m_size;
    vec2 m_position;
    unsigned m_layer;
    
    Widget* m_parent;
    std::vector<Widget*> m_children;
    sf::VertexArray m_varray;
    bool aabb_collision(const glm::vec2& point);
private:
    virtual void register_child(Widget* c) final;
};

#endif // WIDGET_H
