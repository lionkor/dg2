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

    Widget main_widget(nullptr, { 0, 0 }, { 300, 300 }, sf::Color::White);
    ButtonWidget my_button(&main_widget, { 20, 20 }, { 200, 100 });

    Widget second_widget(nullptr, { 300, 0 }, { 300, 300 }, sf::Color::Blue);
    ButtonWidget my_button2(&second_widget, { 320, 320 }, { 200, 100 });

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
                    main_widget.fire_click_event(event.mouseButton.x,
                                                 event.mouseButton.y);
                    second_widget.fire_click_event(event.mouseButton.x,
                                                   event.mouseButton.y);
                    break;
            }
        }
    }

    delete WidgetRenderer::the();
}
