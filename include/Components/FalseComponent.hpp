/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** FalseComponent
*/

#ifndef FALSECOMPONENT_HPP_
#define FALSECOMPONENT_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class FalseComponent : public Component
    {
        public:
            FalseComponent();
            ~FalseComponent();

            Tristate compute(size_t pin = 1) const override;
    };
}

#endif /* !FALSECOMPONENT_HPP_ */
