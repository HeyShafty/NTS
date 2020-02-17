/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
#define ORCOMPONENT_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class OrComponent : public Component
    {
        public:
            OrComponent();
            ~OrComponent();

            Tristate compute(size_t pin = 1) const override;
    };
}

#endif /* !ORCOMPONENT_HPP_ */
