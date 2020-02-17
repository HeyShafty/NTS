/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** N4081Component
*/

#ifndef N4081COMPONENT_HPP_
#define N4081COMPONENT_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class N4081Component : public Component
    {
        public:
            N4081Component();
            ~N4081Component();

            Tristate compute(size_t pin = 1) const override;
    };
}

#endif /* !N4081COMPONENT_HPP_ */
