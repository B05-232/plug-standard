/**
 * @file VertexArray.h
 * @author MeerkatBoss (solodovnikov.ia@phystech.edu)
 *
 * @brief
 *
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright MeerkatBoss (c) 2023
 */
#ifndef __PLUG_GRAPHICS_VERTEX_ARRAY_H
#define __PLUG_GRAPHICS_VERTEX_ARRAY_H

#include <cstddef>

#include "Plug/Math.h"
#include "Plug/Graphics/PrimitiveType.h"

namespace plug
{

class Vertex
{
public:
  Vec2d position;
  Vec2d tex_coords;
  Color color;
};

class VertexArray
{
public:
  VertexArray(PrimitiveTypes type, size_t size);

  VertexArray(const VertexArray& other);

  VertexArray& operator=(const VertexArray& other);

  ~VertexArray(void);

  PrimitiveTypes getPrimitive(void) const;

  void setPrimitive(PrimitiveTypes type);

  void getSize(void) const;

  void resize(size_t new_size);

  void appendVertex(const Vertex& vertex);

  Vertex& operator[](size_t index);

  const Vertex& operator[](size_t index) const;

private:

  // TODO: implement (in header)

  Vertex* m_data;
  size_t  m_size;
  size_t  m_capacity;

} // namespace plug

#endif /* VertexArray.h */
