/**
 * @file Widget.h
 * @author Kudryashov Ilya (kudriashov.it@phystech.edu)
 * @brief Widget interface
 * @version 0.1
 * @date 2023-11-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PLUG_WIDGET_H
#define __PLUG_WIDGET_H

#include "Plug/Event.h"
#include "Plug/Graphics.h"
#include "Plug/LayoutBox.h"
#include "Plug/Math.h"

namespace plug
{

/**
 * @brief Interactive object with visual representation
 *
 */
class Widget
{
public:
  virtual ~Widget() = 0;

  /**
   * @brief Draw widget
   *
   * @param stack
   * @param target buffer which the widget will be drawn on
   */
  virtual void draw(TransformStack& stack, RenderTarget& target) = 0;

  /**
   * @brief Handle abstract event
   *
   * @param event
   * @param context event handling context
   */
  virtual void onEvent(const Event& event, EHC& context) = 0;

  /**
   * @brief Update widget according to the parent
   *
   * @param parent_box parent layout box
   */
  virtual void onParentUpdate(const LayoutBox& parent_box) = 0;

  virtual LayoutBox&       getLayoutBox()                     = 0;
  virtual const LayoutBox& getLayoutBox() const               = 0;
  virtual void             setLayoutBox(const LayoutBox& box) = 0;

protected:
  /**
   * @brief Check if widget covers specified position
   *
   * @param stack
   * @param position position to check (in stack output coords (screen coords in
   * most cases))
   * @return true if widget covers the specified position
   * @return false otherwise
   */
  virtual bool covers(TransformStack& stack, const Vec2d& position) const = 0;

  /**
   * @brief Handle tick event (called every input tick)
   *
   * @param event
   * @param ehc event handling context
   */
  virtual void onTick(const TickEvent& event, EHC& ehc) {}

  /**
   * @brief Handle mouse movement event
   *
   * @param event
   * @param ehc event handling context
   */
  virtual void onMouseMove(const MouseMoveEvent& event, EHC& ehc) {}

  /**
   * @brief Handle mouse button press
   *
   * @param event
   * @param ehc event handling context
   */
  virtual void onMousePressed(const MousePressedEvent& event, EHC& ehc) {}

  /**
   * @brief Handle mouse button release
   *
   * @param event
   * @param ehc event handling context
   */
  virtual void onMouseReleased(const MouseReleasedEvent& event, EHC& ehc) {}

  /**
   * @brief handle keyboard key press
   *
   * @param event
   * @param ehc event handling context
   */
  virtual void onKeyboardPressed(const KeyboardPressedEvent& event, EHC& ehc) {}

  /**
   * @brief Handle keyboard key release
   *
   * @param event
   * @param ehc event handling context
   */
  virtual void onKeyboardReleased(const KeyboardReleasedEvent& event, EHC& ehc)
  {
  }
};

} // namespace plug

#endif
