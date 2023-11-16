/**
 * @file TransformStack.h
 * @author DenzeL2004 (kolomiitsev.dv@phystech.edu)
 *
 * @brief
 *
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright DenzeL2004 (c) 2023
 */
#ifndef _TRANSFORM_STACK_H_
#define _TRANSFORM_STACK_H_

#include "Vec2d.h"
#include "Transform.h"

namespace plug 
{
    class TransformStack
    {
        public:

        TransformStack(){}

        virtual ~TransformStack() = 0;

        virtual void enter (const Transform &transform) = 0;
        virtual void leave () = 0;
        
        virtual Transform top () const = 0;

        virtual Vec2d apply     (const Vec2d &vec) const = 0; 
        virtual Vec2d restore   (const Vec2d &vec) const = 0;

    };
};

#endif