/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** J74HC4017Component
*/

#ifndef J74HC4017COMPONENT_HPP_
#define J74HC4017COMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class J74HC4017Component : public AComponent
    {
        public:
            J74HC4017Component();
            ~J74HC4017Component() = default;

            nts::Tristate computeComponent(size_t pin_index);
            nts::Tristate compute12Pin(void);

        private:
            static const std::vector<size_t> indexes;
            size_t i = 0;
            nts::Tristate _oldClockValue;
    };
}

#endif /* !J74HC4017COMPONENT_HPP_ */
