#ifndef WIDGETCONSTRAINTSAUTOMATIC_H
#define WIDGETCONSTRAINTSAUTOMATIC_H

#include "WidgetConstraints.h"

class WidgetConstraintsAutomatic : public WidgetConstraints
{
public:
    WidgetConstraintsAutomatic();

    // WidgetConstraints interface
    glm::vec2 absolute_position() const;
    glm::vec2 absolute_size() const;
    void resize(float, float, float, float);
};

#endif // WIDGETCONSTRAINTSAUTOMATIC_H
