/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Inputcomponent
*/

#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class InputComponent : public AComponent
    {
        public:
            InputComponent(nts::Tristate pinValue);
            ~InputComponent() = default;

        private:
            nts::Tristate computeComponent(void) const;
    };
}

#endif /* !INPUTCOMPONENT_HPP_ */
