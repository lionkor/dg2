#include "ButtonWidget.h"
#include "HorizontalStackWidget.h"
#include "HorizontallyStackedWidget.h"
#include "VerticalStackWidget.h"
#include "VerticallyStackedWidget.h"
#include "Widget.h"
#include "WidgetConstraints.h"
#include "WidgetConstraintsAbsolute.h"
#include "WidgetRenderer.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <glm/glm.hpp>
#include <iostream>

using glm::vec;
using glm::vec2;

class MyTestWidget : public VerticalStackWidget
{
public:
    MyTestWidget(Widget* parent, WidgetConstraints* constraints, const sf::Color& color)
        : VerticalStackWidget(parent, constraints, color)
    {
    }

    // Widget interface
protected:
    bool on_click(float, float)
    {
        VerticallyStackedWidget* w = new VerticallyStackedWidget(
            this, sf::Color(rand() % 255, rand() % 255, rand() % 255));
        m_widgets.push_back(w);
        return true;
    }

    std::vector<VerticallyStackedWidget*> m_widgets;
};

class MyOtherTestWidget : public HorizontalStackWidget
{
public:
    MyOtherTestWidget(Widget* parent, WidgetConstraints* constraints,
                      const sf::Color& color)
        : HorizontalStackWidget(parent, constraints, color)
    {
    }

    // Widget interface
protected:
    bool on_click(float, float)
    {
        HorizontallyStackedWidget* w = new HorizontallyStackedWidget(
            this, sf::Color(rand() % 255, rand() % 255, rand() % 255));
        m_widgets.push_back(w);
        return true;
    }

    std::vector<HorizontallyStackedWidget*> m_widgets;
};


int main()
{
    srand(time(NULL));
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1280, 720), "dg2");
    sf::Event event;
    window->setFramerateLimit(60);


    Widget super(nullptr,
                 new WidgetConstraintsAbsolute(
                     { 0, 0 }, { window->getSize().x, window->getSize().y }),
                 sf::Color::Black);

    // Widget sub(&super, new WidgetConstraintsFixedAspect({.01, 0.01}, {.2, .08},
    // &super), sf::Color::Red);

    /*
    MyOtherTestWidget widget_left2(&super, new WidgetConstraints({ 0.01, 0.01 }, { 0.6,
    .30 }, &super), sf::Color::Blue); MyTestWidget widget_right(&super, new
    WidgetConstraints({ .79, 0.01 }, { 0.2, 0.98 }, &super), sf::Color::Green);
    */


    /*
    Widget widget_left(&super,
                       new WidgetConstraintsFixedAspect({ 0.01, 0.01 }, { 0.1, .98 },
                                                        &super, Origin::TopLeft),
                       sf::Color::Blue);
    Widget left_cool(&widget_left,
                     new WidgetConstraints({ .08, .01 }, { 1. - 2. * .08, .5 - 2. * .01 },
                                           &widget_left),
                     sf::Color::Cyan);
    Widget weird_button(&widget_left,
                        new WidgetConstraints({ 0., 1.01 }, { .49, .1 }, &left_cool),
                        sf::Color::Red);
    Widget weird_button2(&widget_left,
                         new WidgetConstraints({ .51, 1.01 }, { .49, .1 }, &left_cool),
                         sf::Color::Red);*/

    MyOtherTestWidget test_widget(&super,
                                  new WidgetConstraintsFixedAspect(
                                      { .01, .01 }, { .4, .1 }, &super, Origin::TopRight),
                                  sf::Color::Magenta);

    MyOtherTestWidget test_widget2(&super,
                                   new WidgetConstraintsFixedAspect({ .01, .01 },
                                                                    { .4, .1 }, &super,
                                                                    Origin::BottomRight),
                                   sf::Color::Yellow);

    MyTestWidget test_widget3(&super,
                              new WidgetConstraintsFixedAspect(
                                  { .01, .22 }, { .1, .3 }, &super, Origin::BottomRight),
                              sf::Color::Yellow);

    MyOtherTestWidget test_widget4(&super,
                                   new WidgetConstraintsFixedAspect(
                                       { .01, .01 }, { .4, .1 }, &super, Origin::TopLeft),
                                   sf::Color::White);

    MyOtherTestWidget test_widget5(&super,
                                   new WidgetConstraintsFixedAspect(
                                       { .01, .01 }, { .4, .1 }, &super, Origin::BottomLeft),
                                   sf::Color::White);
    
    /*
    Widget super(nullptr, { 0, 0 }, { 640, 480 }, sf::Color::Green);

    Widget main_widget(&super, { 0, 0 }, { 300, 300 }, sf::Color::White);
    ButtonWidget my_button(&main_widget, { 20, 20 }, { 200, 100 });

    Widget second_widget(&super, { 300, 0 }, { 300, 300 }, sf::Color::Blue);
    ButtonWidget my_button2(&second_widget, { 280, 50 }, { 200, 100 });
    */

    // FIXME: Percentage & absolute size constraint system. Should be based on super
    // widget.

    while (window->isOpen())
    {
        super.fire_update_event();

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
                    auto pos = window->mapPixelToCoords({ 0, 0 });
                    super.fire_resize_event(pos.x, pos.y, window->getSize().x,
                                            window->getSize().y);
                }
                break;
            }
        }
    }

    delete WidgetRenderer::the();
}
