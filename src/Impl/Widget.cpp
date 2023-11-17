#include "Widget.h"

Widget::Widget(const plug::LayoutBox& box) : box_(box.clone()) {}

Widget::Widget(const Widget& widget) : box_(widget.getLayoutBox().clone()) {}

Widget& Widget::operator=(const Widget& widget)
{
  delete box_;
  box_ = widget.box_->clone();
  return *this;
}

Widget::~Widget() { delete box_; }

void Widget::onEvent(const plug::Event& event, plug::EHC& context)
{
  switch (event.getType())
  {
  case plug::EventType::Tick:
  {
    onTick((const plug::TickEvent&)event, context);
  }
  break;
  case plug::EventType::KeyboardPressed:
  {
    onKeyboardPressed((const plug::KeyboardPressedEvent&)event, context);
  }
  break;
  case plug::EventType::KeyboardReleased:
  {
    onKeyboardReleased((const plug::KeyboardReleasedEvent&)event, context);
  }
  break;
  case plug::EventType::MousePressed:
  {
    onMousePressed((const plug::MousePressedEvent&)event, context);
  }
  break;
  case plug::EventType::MouseReleased:
  {
    onMouseReleased((const plug::MouseReleasedEvent&)event, context);
  }
  break;
  case plug::EventType::MouseMove:
  {
    onMouseMove((const plug::MouseMoveEvent&)event, context);
  }
  break;
  default:
    break;
  }
}

void Widget::onParentUpdate(const plug::LayoutBox& parent_box)
{
  box_->onParentUpdate(parent_box);
}

void Widget::setLayoutBox(const plug::LayoutBox& box)
{
  delete box_;
  box_ = box.clone();
}

Vec2d Widget::getCorner(Corner corner, const TransformStack& stack) const
{
  Vec2d direction = Vec2d((corner & 1) ? 0.5 : -0.5, (corner & 2) ? -0.5 : 0.5);
  Vec2d corner    = getPosition() + getSize() * direction;

  return stack.top().apply(corner);
}

bool Widget::covers(plug::TransformStack& stack,
                    const plug::Vec2d&    position) const
{
  if (box_->getSize().get_x() == 0.0 || box_->getSize().get_y() == 0.0)
  {
    return false;
  }

  // clang-format off
  plug::Vec2d tl = getCorner(TOP_LEFT,     stack);
  plug::Vec2d tr = getCorner(TOP_RIGHT,    stack);
  plug::Vec2d br = getCorner(BOTTOM_RIGHT, stack);
  plug::Vec2d bl = getCorner(BOTTOM_LEFT,  stack);

  bool top_check      = plug::cross(tl - tr, screen_pos - tr) <= 0.0;
  bool right_check    = plug::cross(tr - br, screen_pos - br) <= 0.0;
  bool bottom_check   = plug::cross(br - bl, screen_pos - bl) <= 0.0;
  bool left_check     = plug::cross(bl - tl, screen_pos - tl) <= 0.0;
  // clang-format on

  return top_check && right_check && bottom_check && left_check;

  return false;
}
