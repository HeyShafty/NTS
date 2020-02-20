/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NorComponent
*/

#ifndef NorComponent_HPP_
#define NorComponent_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class NorComponent : public Component
    {
        public:
            NorComponent();
            ~NorComponent() = default;

            Tristate compute(size_t pin = 1) const override;

        private:
            Tristate computeComponent() const;
    };
}

#endif /* !NorComponent_HPP_ */
