/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** XorComponent
*/

#ifndef XorCOMPONENT_HPP_
#define XorCOMPONENT_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class XorComponent : public Component
    {
        public:
            XorComponent();
            ~XorComponent() = default;

            Tristate compute(size_t pin = 1) const override;
    };
}

#endif /* !XorCOMPONENT_HPP_ */
