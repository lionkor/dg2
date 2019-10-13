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

// class WidgetConstraints

enum class ScaleMode
{
    ScaleVertically,
    ScaleHorizontally
};

enum class Origin
{
    TopLeft,
    TopRight,
    BottomLeft,
    BottomRight
};

class WidgetConstraintsFixedAspect : public WidgetConstraints
{
public:
    WidgetConstraintsFixedAspect(const vec2& position, const vec2& size,
                                 class Widget* reference, Origin origin,
                                 ScaleMode size_scale = ScaleMode::ScaleVertically,
                                 ScaleMode position_scale = ScaleMode::ScaleHorizontally);

    glm::vec2 absolute_position() const;
    glm::vec2 absolute_size() const;
    void resize(float, float, float, float);

protected:
    float m_aspect;
    ScaleMode m_size_scale;
    ScaleMode m_position_scale;
    Origin m_origin;
};


#endif // WIDGETCONSTRAINTS_H
