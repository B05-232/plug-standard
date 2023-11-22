#ifndef _SFML_RENDER_TARGET_H_
#define _SFML_RENDER_TARGET_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdio>

#include "Plug/Graphics.h"

class SfmlRenderTarget : public plug::RenderTarget {
public:
  SfmlRenderTarget(sf::RenderTarget &target) : m_target(target) {}

  ~SfmlRenderTarget() = default;

  virtual void draw(const plug::VertexArray &array) override;

  virtual void draw(const plug::VertexArray &array,
                    const plug::Texture &texture) override;

  virtual void clear(plug::Color color) override;

  virtual unsigned getNativeHandle(void) const override;

private:
  sf::RenderTarget &m_target;
};

#endif