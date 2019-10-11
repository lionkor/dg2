#ifndef WIDGETCONSTRAINTS_H
#define WIDGETCONSTRAINTS_H

#include <glm/glm.hpp>
#include <iostream>

using glm::vec2;

class WidgetConstraints
{
public:
    WidgetConstraints(const vec2& position, const vec2& size, class Widget* reference);
    virtual ~WidgetConstraints() {}

    virtual glm::vec2 absolute_position() const;
    virtual glm::vec2 absolute_size() const;

    virtual void resize(float, float, float, float);
protected:
    vec2 m_position;
    vec2 m_size;
    Widget* m_reference;
};


#endif // WIDGETCONSTRAINTS_H
