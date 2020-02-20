/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Inputcomponent
*/

#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class InputComponent : public Component
    {
        public:
            InputComponent(nts::Tristate pinValue);
            ~InputComponent() = default;

            nts::Tristate compute(size_t pin = 1) const override;
            nts::Tristate computeComponent(void) const;

        protected:
        private:
    };
}

#endif /* !INPUTCOMPONENT_HPP_ */
