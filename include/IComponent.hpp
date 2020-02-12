/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <stddef.h>

namespace nts
{
    enum Tristate
    {
        UNDEFINED = (-true),
        FALSE = false,
        TRUE = true
    };

    class IComponent
    {
        public:
            virtual ~IComponent() = default;

            virtual Tristate compute(size_t pin = 1) const = 0;
            virtual void setLink(size_t pin, const IComponent &other, size_t otherPin) const = 0;
            virtual void dump() const = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
