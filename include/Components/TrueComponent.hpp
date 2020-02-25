/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** TrueComponent
*/

#ifndef TRUECOMPONENT_HPP_
#define TRUECOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class TrueComponent : public AComponent
    {
        public:
            TrueComponent(const std::string &name);
            ~TrueComponent() = default;

        private:
            Tristate computeComponent() const;
    };
}

#endif /* !TRUECOMPONENT_HPP_ */
