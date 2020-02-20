/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** TripleNandComponent
*/

#ifndef TRIPLENANDCOMPONENT_HPP_
#define TRIPLENANDCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class TripleNandComponent : public AComponent {
        public:
            TripleNandComponent();
            ~TripleNandComponent() = default;

            nts::Tristate compute(size_t pin) const override;

        private:
            Tristate computeComponent(void) const;
    };
}

#endif /* !TripleNandComponent_HPP_ */
