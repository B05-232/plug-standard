#include "RenderWindow.h"

#include "Impl/Graphics/RenderTarget/RenderTarget.h"
//====================================================================================

void RenderWindow::draw(const plug::VertexArray &array)
{
    sf::VertexArray sf_array;
    coppyToSFMLVertexArray(sf_array, array);

    window_.draw(sf_array);
}

void RenderWindow::draw(const plug::VertexArray &array, const plug::Texture &texture)
{
    sf::VertexArray sf_array;
    coppyToSFMLVertexArray(sf_array, array);

    sf::Texture sf_texture;
    coppyToSFMLTexture(sf_texture, texture);

    window_.draw(sf_array, &sf_texture);
}


void RenderWindow::clear(plug::Color color)
{
    window_.clear(getSFMLColor(color));
}

unsigned RenderWindow::getNativeHandle(void) const
{
    return window_.getSystemHandle();
}

bool RenderWindow::isOpen(void) const
{
    return window_.isOpen();
}

bool RenderWindow::pollEvent(sf::Event &event)
{
    return window_.pollEvent(event);
}

void RenderWindow::close(void)
{
    window_.close();
}

void RenderWindow::display(void)
{
    window_.display();
}

Vec2d RenderWindow::getMouseCoord(void) const
{
    sf::Mouse mouse;
    return Vec2d((double)mouse.getPosition(window_).x, (double)mouse.getPosition(window_).y);
}

//====================================================================================