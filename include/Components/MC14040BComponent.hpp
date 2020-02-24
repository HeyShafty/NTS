/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** MC14040B
*/

#ifndef MC14040B_HPP_
#define MC14040B_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class MC14040BComponent : public AComponent
    {
        public:
            MC14040BComponent();
            ~MC14040BComponent() = default;

            nts::Tristate computeComponent(size_t pin_idx);

        private:
            short _value;
            nts::Tristate oldClockValue;
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
}

#endif /* !MC14040B_HPP_ */
