#ifndef WIDGET_H
#define WIDGET_H

#include "WidgetConstraints.h"
#include "WidgetRenderer.h"
#include <functional>
#include <glm/glm.hpp>
#include <iostream>
#include <memory>
#include <vector>

using glm::vec2;

class Widget
{
public:
    Widget(Widget* parent, WidgetConstraints* constraints, const sf::Color& color);
    virtual ~Widget() {}

    inline const Widget* parent() { return m_parent; }


    // accessors
    inline vec2 position() const { return m_constraints->absolute_position(); }
    inline vec2 size() const { return m_constraints->absolute_size(); }
    inline std::uint64_t& layer() { return m_layer; }
    inline WidgetConstraints* constraints() { return m_constraints.get(); }

    // virtual accessors
    inline virtual sf::Drawable& drawable() { return m_varray; }

    // const accessors
    inline std::uint64_t layer() const { return m_layer; }
    inline const WidgetConstraints* constraints() const { return m_constraints.get(); }
    inline std::size_t child_count() const { return m_children.size(); }

    // virtual const accessors
    inline virtual const sf::Drawable& drawable() const { return m_varray; }

    bool operator<(const Widget& rhs);
    bool operator>(const Widget& rhs);

    virtual void fire_update_event() final;
    virtual void fire_resize_event(float, float, float, float) final;
    virtual bool fire_click_event(float, float) final;
    virtual void fire_redraw_event() final;
protected:
    virtual void on_update();
    virtual void on_resize(float, float);
    virtual bool on_click(float, float);
    virtual void on_redraw();
    
    /// WARNING: Instance-specific event; does not propagate to children!
    virtual void on_child_register(Widget*);
    virtual void fire_child_register_event(Widget* child) final;
    
    
    Widget* m_parent;
    std::unique_ptr<WidgetConstraints> m_constraints;
    sf::VertexArray m_varray;
    std::uint64_t m_layer;
    sf::Color m_color;
    std::vector<Widget*> m_children;

    bool aabb_collision(const glm::vec2& point);

private:
    virtual void register_child(Widget* c) final;
};

#endif // WIDGET_H
