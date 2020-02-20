/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
#define ORCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class OrComponent : public AComponent
    {
        public:
            OrComponent();
            ~OrComponent() = default;

            Tristate compute(size_t pin = 1) const override;

        private:
            Tristate computeComponent() const;
    };
}

#endif /* !ORCOMPONENT_HPP_ */
