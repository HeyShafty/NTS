/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AndComponent
*/

#ifndef ANDCOMPONENT_HPP_
#define ANDCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class AndComponent : public AComponent
    {
        public:
            AndComponent();
            ~AndComponent() = default;

            Tristate compute(size_t pin = 1) const override;

        private:
            Tristate computeComponent() const;
    };
}

#endif /* !ANDCOMPONENT_HPP_ */
