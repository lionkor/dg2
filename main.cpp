#include "ButtonWidget.h"
#include "Widget.h"
#include "WidgetRenderer.h"
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <iostream>

using glm::vec;
using glm::vec2;

int main()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(640, 480), "dg2");
    sf::Event event;

    Widget super(nullptr, { 0, 0 }, { 640, 480 }, sf::Color::Green);

    Widget main_widget(&super, { 0, 0 }, { 300, 300 }, sf::Color::White);
    ButtonWidget my_button(&main_widget, { 20, 20 }, { 200, 100 });

    Widget second_widget(&super, { 300, 0 }, { 300, 300 }, sf::Color::Blue);
    ButtonWidget my_button2(&second_widget, { 280, 50 }, { 200, 100 });

    // FIXME: Percentage & absolute size constraint system. Should be based on super widget.
    
    while (window->isOpen())
    {
        main_widget.fire_update_event();

        window->clear();
        WidgetRenderer::the()->draw(*window);
        // TODO draw
        window->display();

        while (window->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::MouseButtonPressed:
                {
                    auto coords = window->mapPixelToCoords(
                        { event.mouseButton.x, event.mouseButton.y });
                    super.fire_click_event(coords.x, coords.y);
                }
                break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                        window->close();
                    break;
                case sf::Event::Resized:
                {
                    auto view = window->getView();
                    view.setSize(event.size.width, event.size.height);
                    window->setView(view);
                }
                break;
            }
        }
    }

    delete WidgetRenderer::the();
}
