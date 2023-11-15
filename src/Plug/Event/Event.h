/**
 * @file Event.h
 * @author MeerkatBoss (solodovnikov.ia@phystech.edu)
 *
 * @brief
 *
 * @version 0.1
 * @date 2023-11-15
 *
 * @copyright Copyright MeerkatBoss (c) 2023
 */
#ifndef __PLUG_EVENT_EVENT_H
#define __PLUG_EVENT_EVENT_H

#include "Plug/Event/KeyCode.h"
#include "Plug/Event/MouseButton.h"
#include "Plug/Math.h"

namespace plug
{

enum EventType
{
  Tick             = 0,
  MouseMove        = 1,
  MousePressed     = 2,
  MouseReleased    = 3,
  KeyboardPressed  = 4,
  KeyboardReleased = 5
};

class Event
{
public:
  Event(size_t type) : m_type(type) {}


  size_t getType(void) const { return m_type; }

private:
  const size_t m_type;
};

struct MouseMoveEvent : public Event
{
  bool  shift, ctrl, alt;
  Vec2d pos;
};

struct MousePressedEvent : public Event
{
  MouseButton button_id;
  bool        shift, ctrl, alt;
  Vec2d       pos;
};

struct MouseReleasedEvent : public Event
{
  MouseButton button_id;
  bool        shift, ctrl, alt;
  Vec2d       pos;
};

struct KeyboardPressedEvent : public Event
{
  KeyCode key_id;
  bool    shift, ctrl, alt;
};

struct KeyboardReleasedEvent : public Event
{
  KeyCode key_id;
  bool    shift, ctrl, alt;
};

struct TickEvent : public Event
{
  double delta_time;
}

} // namespace plug

#endif /* Event.h */
