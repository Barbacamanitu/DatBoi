#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H
#include <SFML/Graphics.hpp>
#include <memory>
class GraphicsWindow
{
    public:
        GraphicsWindow();
        virtual ~GraphicsWindow();
        void createWindow();
        sf::RenderWindow& getWindow();
        void handleEvents();
        void render();
        void mainLoop();
        void update(double timestep);
    protected:

    private:
        std::unique_ptr<sf::RenderWindow> mWindow;
        sf::Clock mainClock;

        sf::CircleShape mCircle;
};

#endif // GRAPHICSWINDOW_H
