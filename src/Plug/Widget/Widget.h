#ifndef WIDGET_H
#define WIDGET_H

#include "Plug/Graphics.h"

class LayoutBox;

class EHC;

class Event;
class TickEvent;
class MouseMoveEvent;
class MousePressedEvent;
class MouseReleasedEvent;
class KeyboardPressedEvent;
class KeyboardReleasedEvent;

class Vec2d;
class TransformStack;

/**
 * @brief Interactive object with visual representation
 *
 */
class Widget
{
public:
  explicit Widget(const LayoutBox& box);
  Widget(const Widget& widget);
  Widget& operator=(const Widget& widget);
  virtual ~Widget();

  /**
   * @brief Draw widget
   *
   * @param stack
   * @param target buffer which the widget will be drawn on
   */
  virtual void draw(TransformStack& stack, RenderTarget& target) {}

  /**
   * @brief Handle abstract event
   *
   * @param event
   * @param context event handling context
   */
  virtual void onEvent(const Event& event, EHC& context);

  /**
   * @brief Update widget according to the parent
   *
   * @param parent_box parent layout box
   */
  virtual void onParentUpdate(const LayoutBox& parent_box);

  LayoutBox&       getLayoutBox() { return box_; }
  const LayoutBox& getLayoutBox() const { return box_; }
  void             setLayoutBox(const LayoutBox& box);

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
  virtual bool covers(TransformStack& stack, const Vec2d& position) const;

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

private:
  /**
   * @brief Layout box of the widget
   *
   */
  LayoutBox* box_;
};

#endif
