#include "Widget.h"

#include "Plug/Event.h"
#include "Plug/Graphics.h"
#include "Plug/LayoutBox.h"

Widget::Widget(const LayoutBox& box) : box_(box.clone()) {}

Widget::Widget(const Widget& widget) : box_(nullptr) { operator=(widget); }

Widget& Widget::operator=(const Widget& widget)
{
  delete box_;
  box_ = widget.box_->clone();
  return *this;
}

Widget::~Widget() { delete box_; }

void Widget::onEvent(const Event& event, EHC& context)
{
  switch (event.getType())
  {
  case EventType::Tick:
  {
    onTick((TickEvent&)event, context);
  }
  break;
  case EventType::KeyboardPressed:
  {
    onKeyboardPressed((KeyboardPressedEvent&)event, context);
  }
  break;
  case EventType::KeyboardReleased:
  {
    onKeyboardReleased((KeyboardReleasedEvent&)event, context);
  }
  break;
  case EventType::MousePressed:
  {
    onMousePressed((MousePressedEvent&)event, context);
  }
  break;
  case EventType::MouseReleased:
  {
    onMouseReleased((MouseReleasedEvent&)event, context);
  }
  break;
  case EventType::MouseMove:
  {
    onMouseMove((MouseMoveEvent&)event, context);
  }
  break;
  default:
    break;
  }
}

void Widget::onParentUpdate(const LayoutBox& parent_box)
{
  box_->onParentUpdate(parent_box);
}

void Widget::setLayoutBox(const LayoutBox& box)
{
  delete box_;
  box_ = box.clone();
}

bool Widget::covers(TransformStack& stack, const Vec2d& position) const
{
  //* I would be happy to provide you with the implementation that covers
  //* 99% of the use cases, but, unfortunately, we do not have `getCorner`
  //* method in the standard (yet).
  //* If you wish to ease the pain in the a*s that is the current
  //* standard, here is an implementation of this method with bits of
  //* dark magic there and there.

  //   if (box_->getSize().get_x() == 0.0 || box_->getSize().get_y() == 0.0)
  //     return false;

  //   // clang-format off
  //   Vec2d tl = getCorner(TOP_LEFT,     stack);
  //   Vec2d tr = getCorner(TOP_RIGHT,    stack);
  //   Vec2d br = getCorner(BOTTOM_RIGHT, stack);
  //   Vec2d bl = getCorner(BOTTOM_LEFT,  stack);

  //   bool top_check      = cross(tl - tr, screen_pos - tr) <= 0.0;
  //   bool right_check    = cross(tr - br, screen_pos - br) <= 0.0;
  //   bool bottom_check   = cross(br - bl, screen_pos - bl) <= 0.0;
  //   bool left_check     = cross(bl - tl, screen_pos - tl) <= 0.0;
  //   // clang-format on

  //   return top_check && right_check && bottom_check && left_check;

  return false;
}
