/**
 * @file Widget.h
 * @author Kudryashov Ilya (kudriashov.it@phystech.edu)
 * @brief Usable widget template
 * @version 0.1
 * @date 2023-11-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef WIDGET_H
#define WIDGET_H

#include "Plug/Widget.h"

/**
 * @brief Usable widget
 *
 */
class Widget : public plug::Widget
{
public:
  explicit Widget(const plug::LayoutBox& box);
  Widget(const Widget& widget);
  Widget& operator=(const Widget& widget);
  ~Widget() override;

  void draw(plug::TransformStack& stack, plug::RenderTarget& target) override {}

  void onEvent(const plug::Event& plug::Event, plug::EHC& context) override;

  void onParentUpdate(const plug::LayoutBox& parent_box) override;

  plug::LayoutBox&       getLayoutBox() override { return box_; }
  const plug::LayoutBox& getLayoutBox() const override { return box_; }
  void                   setLayoutBox(const plug::LayoutBox& box) override;

protected:
  bool covers(plug::TransformStack& stack,
              const plug::Vec2d&    position) const override;
  void onTick(const plug::TickEvent& event, plug::EHC& ehc) override {}

  void onMouseMove(const plug::MouseMoveEvent& event, plug::EHC& ehc) override
  {
  }

  void onMousePressed(const plug::MousePressedEvent& event,
                      plug::EHC&                     ehc) override
  {
  }

  void onMouseReleased(const plug::MouseReleasedEvent& event,
                       plug::EHC&                      ehc) override
  {
  }

  void onKeyboardPressed(const plug::KeyboardPressedEvent& event,
                         plug::EHC&                        ehc) override
  {
  }

  void onKeyboardReleased(const plug::KeyboardReleasedEvent& event,
                          plug::EHC&                         ehc) override
  {
  }

private:
  plug::LayoutBox* box_;
};

#endif
