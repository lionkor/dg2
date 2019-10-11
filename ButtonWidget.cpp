#include "ButtonWidget.h"

bool ButtonWidget::on_click(float x, float y)
{
    std::cout << "ButtonWidget::on_click : " << this << " : " << x << " " << y << " "
              << aabb_collision({ x, y }) << std::endl;
    return !aabb_collision({ x, y });
}
