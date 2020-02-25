/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** DFlipFlopComponent
*/

#ifndef DFLIPFLOPCOMPONENT_HPP_
#define DFLIPFLOPCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class DFlipFlopComponent : public AComponent
    {
        public:
            DFlipFlopComponent(const std::string &name);
            ~DFlipFlopComponent() = default;

        private:
            Tristate computeComponent(size_t pin_index);
            Tristate computeQPin(Tristate clock, Tristate prevClock);
            Tristate computeNQPin(Tristate clock, Tristate prevClock);

            Tristate clockSave;
    };
} // namespace nts::Components

#endif /* !DFlipFlopComponent_HPP_ */
