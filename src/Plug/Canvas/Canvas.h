#ifndef __PLUG_CANVAS_CANVAS_H
#define __PLUG_CANVAS_CANVAS_H

#include "Plug/Canvas/SelectionMask.h"
#include "Plug/Color.h"
#include "Plug/Math/Vec2d.h"
#include "Plug/VertexArray.h"

namespace plug
{
    class Canvas
    {
    public:
        Canvas () {}

        virtual ~Canvas () = 0;

        /**
         * \brief Draw on canvas using vertex array mapping
         */
		virtual void draw (const VertexArray &vertex_array) = 0;

        /**
         * \brief Draw texture on canvas using vertex array mapping
         */
		virtual void draw (const VertexArray &vertex_array, const Texture &texture) = 0;

        /**
         * \brief Get native handle of canvas' texture
         */
		virtual unsigned int getNativeHandle (void) const = 0;

        /**
         * \brief Return sise of canvas
         */
		virtual Vec2d getSize (void) const = 0;

        /**
         * \brief Set size of canvas
         */
		virtual void setSize (const Vec2d &size) = 0;

        /**
         * \brief Get selection mask of canvas
         */
		virtual SelectionMask &getSelectionMask (void) = 0;

        /**
         * \brief Get color of pixel on canvas by coordinates
         */
		virtual Color getPixel (size_t x, size_t y) const = 0;

        /**
         * \brief Set color of pixel on canvas by coordinates
         */
		virtual void setPixel (size_t x, size_t y, const Color &color) = 0;

        /**
         * \brief Get texture of canvas
         */
		virtual const Texture &getTexture (void) const = 0;
    };

}  // namespace plug

#endif  // __PLUG_CANVAS_CANVAS_H

