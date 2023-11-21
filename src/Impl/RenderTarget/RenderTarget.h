#ifndef _RENDER_TARGET_H_
#define _RENDER_TARGET_H_

#include <cstdio>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Plug/Graphics.h"
#include "Impl/Graphics/RenderTarget/RenderWindow/RenderWindow.h"
  
sf::Color   getSFMLColor(const plug::Color &plug_color);
plug::Color getPlugColor(const sf::Color &sf_color);

sf::Vector2f getSFMLVector2f(const plug::Vec2d &plug_vector);

void coppyToSFMLVertex       (sf::Vertex &sf_vertex, const plug::Vertex &plug_vertex);
void coppyToSFMLVertexArray  (sf::VertexArray &sf_array, const plug::VertexArray &plug_array);
void coppyToSFMLTexture      (sf::Texture &sf_texture, const plug::Texture &plug_texture);

plug::Texture getPlugTexture (const char *texture_path);

#endif