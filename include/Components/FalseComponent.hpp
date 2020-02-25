/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** FalseComponent
*/

#ifndef FALSECOMPONENT_HPP_
#define FALSECOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class FalseComponent : public AComponent
    {
        public:
            FalseComponent(const std::string &name);
            ~FalseComponent() = default;

        private:
            Tristate computeComponent() const;
    };
}

#endif /* !FALSECOMPONENT_HPP_ */
