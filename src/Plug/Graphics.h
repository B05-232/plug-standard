#ifndef GRAPHICS_H
#define GRAPHICS_H

#define SFML //! <-- TODO: Replace with an actual library specification

#ifdef SFML

// TODO: Implement graphics wrappers

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/VertexArray.hpp>

typedef sf::Texture      Texture;
typedef sf::VertexArray  VertexArray;
typedef sf::RenderTarget RenderTarget;

#endif

#ifdef SDL

// TODO: Implement graphics wrappers

#endif

#endif
