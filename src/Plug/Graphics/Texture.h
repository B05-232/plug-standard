/**
 * @file Texture.h
 * @author MeerkatBoss (solodovnikov.ia@phystech.edu)
 *
 * @brief
 *
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright MeerkatBoss (c) 2023
 */
#ifndef __PLUG_GRAPHICS_TEXTURE_H
#define __PLUG_GRAPHICS_TEXTURE_H

#include <cstddef>

namespace plug
{

struct Texture
{
  Texture(size_t width, size_t height, const Color* data) :
    data(data), width(width), height(height)
  {
  }

  const Color const* data;
  const size_t width;
  const size_t height;
};

} // namespace plug

#endif /* Texture.h */
