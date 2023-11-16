/**
 * @file RenderTarget.h
 * @author MeerkatBoss (solodovnikov.ia@phystech.edu)
 *
 * @brief
 *
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright MeerkatBoss (c) 2023
 */
#ifndef __PLUG_GRAPHICS_RENDER_TARGET_H
#define __PLUG_GRAPHICS_RENDER_TARGET_H

#include "Plug/Graphics/VertexArray.h"
#include "Plug/Graphics/Texture.h"

namespace plug
{

class RenderTarget
{
public:
  virtual ~RenderTarget(void) = default;

  virtual void draw(const VertexArray& array) = 0;

  virtual void draw(const VertexArray& array, const Texture& texture) = 0;

  virtual void clear(Color color) = 0;

  unsigned getNativeHandle(void) const;
};

} // namespace plug

#endif /* RenderTarget.h */
