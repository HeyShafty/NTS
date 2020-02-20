/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** DFlipFlopComponent
*/

#ifndef DFLIPFLOPCOMPONENT_HPP_
#define DFLIPFLOPCOMPONENT_HPP_

#define IS_ASCENDANT(pc, cc) (pc == nts::Tristate::FALSE && cc == nts::Tristate::TRUE)
#define IS_DESCENDANT(pc, cc) (pc == nts::Tristate::TRUE && cc == nts::Tristate::FALSE)

#include "Component.hpp"

namespace nts::Components
{
    class DFlipFlopComponent : public Component
    {
        public:
            DFlipFlopComponent();
            ~DFlipFlopComponent() = default;

            nts::Tristate compute(size_t pin) const override;

        private:
            enum PinDesc
            {
                    Q = 0,
                    NQ = 1,
                    CLOCK = 2,
                    RESET = 3,
                    DATA = 4,
                    SET = 5
            };

            Tristate currClock;
            void computeComponent();
            Tristate computeQPin(const Tristate * const states) const;
            Tristate computeNotQPin(const Tristate * const states) const;
    };
} // namespace nts::Components

#endif /* !DFlipFlopComponent_HPP_ */
