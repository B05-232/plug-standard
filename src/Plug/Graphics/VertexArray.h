/**
 * @file VertexArray.h
 * @author MeerkatBoss (solodovnikov.ia@phystech.edu)
 *
 * @brief Vertex array class
 *
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright MeerkatBoss (c) 2023
 */
#ifndef __PLUG_GRAPHICS_VERTEX_ARRAY_H
#define __PLUG_GRAPHICS_VERTEX_ARRAY_H

#include <cstddef>

#include "Plug/Graphics/Color.h"
#include "Plug/Graphics/PrimitiveType.h"
#include "Plug/Math.h"

namespace plug
{

/**
 * @brief Geometrical vertex
 *
 */
class Vertex
{
public:
  /**
   * @brief Vertex position in piskels (SFML screen units, equal to 1 pixel if
   * the window is not resizable)
   *
   */
  Vec2d position;

  /**
   * @brief Coordinate of the vertex on the texture (from 0 to 1 on each axis)
   *
   */
  Vec2d tex_coords;

  /**
   * @brief Vertex color (can be used to transfer some additional data to the
   * GPU)
   *
   */
  Color color;
};

/**
 * @brief Vertex buffer with defined primitive type and index-based vertex
 * enumeration
 *
 */
class VertexArray
{
public:
  VertexArray(PrimitiveType type, size_t size);

  VertexArray(const VertexArray& other);

  VertexArray& operator=(const VertexArray& other);

  ~VertexArray(void);

  /**
   * @brief Get rendering primitive
   *
   * @return PrimitiveType
   */
  PrimitiveType getPrimitive(void) const;

  /**
   * @brief Set rendering primitive
   *
   * @param type
   */
  void setPrimitive(PrimitiveType type);

  /**
   * @brief Get number of vertices in the array
   *
   */
  void getSize(void) const;

  /**
   * @brief Resize the array to fit specified number of vertices
   *
   * @param new_size
   */
  void resize(size_t new_size);

  /**
   * @brief Add vertex to the end of the array
   *
   * @param vertex
   */
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
