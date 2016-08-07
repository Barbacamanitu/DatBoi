#include "GraphicsWindow.h"
#include <memory>
GraphicsWindow::GraphicsWindow()
{
    //ctora
    mCircle.setRadius(50);
    mCircle.setFillColor(sf::Color::Green);
    mCircle.setPosition(50,50);
}

GraphicsWindow::~GraphicsWindow()
{
    //dtor
}

void GraphicsWindow::createWindow()
{
    mWindow = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(1280,700),"Graphics Window"));
}

sf::RenderWindow& GraphicsWindow::getWindow()
{
    return *mWindow;
}

void GraphicsWindow::handleEvents()
{
    sf::Event ev;
    if (mWindow->pollEvent(ev))
    {
        if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::A)
        {
            mWindow->close();
            return;
        }

        if (ev.type == sf::Event::Closed)
        {
            mWindow->close();
        }


    }
}

void GraphicsWindow::render()
{
    mWindow->clear(sf::Color::White);
    mWindow->draw(mCircle);
    mWindow->display();
}

void GraphicsWindow::mainLoop()
{
    double timestep = 1/60.f;
    double elapsed = 0;
    mainClock.restart();
    elapsed = mainClock.restart().asSeconds();
    while(mWindow->isOpen())
    {
        //only update if enough time has passed
        handleEvents();
        elapsed += mainClock.restart().asSeconds();
        if (elapsed >= timestep)
        {
            elapsed -= timestep;
            update(timestep);
        }
        render();


    }
}

void GraphicsWindow::update(double timestep)
{
    mCircle.move(100 * timestep,0);

}
