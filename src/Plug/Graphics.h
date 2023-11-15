#ifndef GRAPHICS_H
#define GRAPHICS_H

#define SFML //! <-- TODO: Replace with an actual library specification

#ifdef SFML

// TODO: Implement graphics wrappers

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>

/**
 * @brief 2-dimensional RGBA8 texture (GPU buffer identifier)
 *
 */
typedef sf::Texture Texture;

/**
 * @brief Array of vertices (2f position, 2f tex coord, RGBA8 color) with
 * primitive ID (stored both on GPU and CPU)
 *
 */
typedef sf::VertexArray VertexArray;

/**
 * @brief Framebuffer with attached color (as Texture) and depth (as
 * Renderbuffer) buffers
 *
 */
typedef sf::RenderTarget RenderTarget;

#endif

#ifdef SDL

// TODO: Implement graphics wrappers

#endif

#endif
