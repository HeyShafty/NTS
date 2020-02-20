/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NotComponent
*/

#ifndef NOTCOMPONENT_HPP_
#define NOTCOMPONENT_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class NotComponent : public Component
    {
        public:
            NotComponent();
            ~NotComponent() = default;

            Tristate compute(size_t pin = 1) const override;

        private:
            Tristate computeComponent() const;
    };
}

#endif /* !NOTCOMPONENT_HPP_ */
