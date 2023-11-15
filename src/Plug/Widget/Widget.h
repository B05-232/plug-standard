#ifndef WIDGET_H
#define WIDGET_H

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

class Widget
{
public:
  explicit Widget(const LayoutBox& box);
  Widget(const Widget& widget);
  Widget& operator=(const Widget& widget);
  virtual ~Widget();

  /**
   * @brief Handle abstract event
   *
   * @param event
   * @param context
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
  virtual bool covers(TransformStack& stack, const Vec2d& position) const;

  virtual void onTick(const TickEvent& event, EHC& ehc) {}
  virtual void onMouseMove(const MouseMoveEvent& event, EHC& ehc) {}
  virtual void onMousePressed(const MousePressedEvent& event, EHC& ehc) {}
  virtual void onMouseReleased(const MouseReleasedEvent& event, EHC& ehc) {}
  virtual void onKeyboardPressed(const KeyboardPressedEvent& event, EHC& ehc) {}
  virtual void onKeyboardReleased(const KeyboardReleasedEvent& event, EHC& ehc)
  {
  }

private:
  LayoutBox* box_;
};

#endif
