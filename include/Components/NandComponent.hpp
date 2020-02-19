/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NandComponent
*/

#ifndef NANDCOMPONENT_HPP_
#define NANDCOMPONENT_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class NandComponent : public Component {
        public:
            NandComponent();
            ~NandComponent() = default;

            nts::Tristate compute(size_t pin) const override;

        private:
            Tristate computeComponent(void) const;
    };
}

#endif /* !NANDCOMPONENT_HPP_ */
