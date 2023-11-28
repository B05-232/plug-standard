/**
 * @file Canvas.h
 * @author Kudryashov Ilya (kudriashov.it@phystech.edu)
 * @brief Canvas implementation
 * @version 0.1
 * @date 2023-11-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __IMPL_CANVAS_CANVAS_H
#define __IMPL_CANVAS_CANVAS_H

#include "Plug/Canvas/Canvas.h"

#include <SFML/Graphics/RenderTexture.hpp>

class Canvas : public plug::Canvas {
public:
  Canvas(size_t width, size_t height);
  Canvas(const plug::Texture &texture);
  Canvas(const char *path);

  void draw(const plug::VertexArray &vertex_array) override;

  void draw(const plug::VertexArray &vertex_array,
            const plug::Texture &texture) override;

  plug::Vec2d getSize(void) const override;

  void setSize(const plug::Vec2d &size) override;

  plug::SelectionMask &getSelectionMask(void) override { return mask_; }

  plug::Color getPixel(size_t x, size_t y) const override;

  void setPixel(size_t x, size_t y, const plug::Color &color) override;

  const plug::Texture &getTexture(void) const override;

private:
  void synchGPU() const;
  void synchCPU() const;

  mutable bool cpu_sided_ = true;

  mutable sf::RenderTexture gpu_content_;
  mutable plug::texture_ cpu_content_;

  plug::SelectionMask mask_;
};

#endif
