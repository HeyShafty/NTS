/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NandComponent
*/

#ifndef NANDCOMPONENT_HPP_
#define NANDCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class NandComponent : public AComponent {
        public:
            NandComponent(const std::string &name);
            ~NandComponent() = default;

        private:
            Tristate computeComponent(void) const;
    };
}

#endif /* !NANDCOMPONENT_HPP_ */
