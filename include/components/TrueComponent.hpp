/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** TrueComponent
*/

#ifndef TRUECOMPONENT_HPP_
#define TRUECOMPONENT_HPP_

#include "IComponent.hpp"

namespace nts
{
    class TrueComponent : public IComponent
    {
        public:
            TrueComponent();
            ~TrueComponent();

            Tristate compute(size_t pin = 1);
            void setLink(size_t pin, IComponent &other, size_t otherPin);
            void dump() const;
    };
}

#endif /* !TRUECOMPONENT_HPP_ */
