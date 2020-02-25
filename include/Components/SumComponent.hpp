/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** SumComponent
*/

#ifndef SUMCOMPONENT_HPP_
#define SUMCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class SumComponent : public AComponent
    {
        public:
            SumComponent(const std::string &name);
            ~SumComponent() = default;

        private:
            nts::Tristate computeComponent() const;
            nts::Tristate computeCarry() const;
    };
}

#endif /* !SUMCOMPONENT_HPP_ */
