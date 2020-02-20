/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP_
#define OUTPUTCOMPONENT_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class OutputComponent : public Component
    {
        public:
            OutputComponent();
            ~OutputComponent() = default;

            nts::Tristate compute(size_t pin = 1) const override;
    };
}

#endif /* !OUTPUTCOMPONENT_HPP_ */
