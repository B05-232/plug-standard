#ifndef _RENDER_WINDOW_H_
#define _RENDER_WINDOW_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Plug/Graphics.h"

class RenderWindow : public plug::RenderTarget
{
    public:
        RenderWindow(   const size_t width, const size_t height, const char* name):
                        window_(sf::VideoMode(width, height), name){}

        ~RenderWindow() = default;

        virtual void draw(const plug::VertexArray &array) override;

        virtual void draw(const plug::VertexArray &array, const plug::Texture &texture) override;

        virtual void clear(plug::Color color) override;

        unsigned getNativeHandle(void) const;

        bool isOpen(void) const;

        bool pollEvent(sf::Event &event);

        void close(void);

        void display(void);

        plug::Vec2d getMouseCoord(void) const;

    private:
    
        sf::RenderWindow window_;
};




#endif