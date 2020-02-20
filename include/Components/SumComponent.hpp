/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** SumComponent
*/

#ifndef SUMCOMPONENT_HPP_
#define SUMCOMPONENT_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class SumComponent : public Component
    {
        public:
            SumComponent();
            ~SumComponent() = default;

            nts::Tristate compute(size_t pin = 1) const override;

        private:
            nts::Tristate computeComponent() const;
            nts::Tristate computeCarry() const;
    };
}

#endif /* !SUMCOMPONENT_HPP_ */
