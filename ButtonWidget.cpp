#include "ButtonWidget.h"

ButtonWidget::ButtonWidget(Widget* parent, const glm::vec2& pos, const glm::vec2& size)
    : Widget(parent, pos, size, sf::Color(128, 128, 128, 255))
{
}

bool ButtonWidget::on_click(float x, float y)
{
    std::cout << "ButtonWidget::on_click : " << this << " : " << x << " " << y << " "
              << aabb_collision({ x, y }) << std::endl;
    return !aabb_collision({ x, y });
}
