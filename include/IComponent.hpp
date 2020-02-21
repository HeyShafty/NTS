/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <memory>
#include "Pin.hpp"
#include "Tristate.h"

namespace nts
{
    class IComponent
    {
        public:
            virtual ~IComponent() = default;

            virtual const std::shared_ptr<Pin> &getPin(size_t pin) const = 0;

            virtual Tristate compute(size_t pin) const = 0;
            virtual void setLink(size_t pin, const IComponent &other, size_t otherPin) const = 0;
            virtual void dump() const = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
