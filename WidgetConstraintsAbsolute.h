#ifndef WIDGETCONSTRAINTSABSOLUTE_H
#define WIDGETCONSTRAINTSABSOLUTE_H

#include "WidgetConstraints.h"

class WidgetConstraintsAbsolute : public WidgetConstraints
{
public:
    WidgetConstraintsAbsolute(const vec2& abs_position, const vec2& abs_size);
    virtual ~WidgetConstraintsAbsolute() override;

    // WidgetConstraints interface
    glm::vec2 absolute_position() const override;
    glm::vec2 absolute_size() const override;

    void resize(float, float, float, float) override;

protected:
    vec2 m_abs_position;
    vec2 m_abs_size;
};

#endif // WIDGETCONSTRAINTSABSOLUTE_H
