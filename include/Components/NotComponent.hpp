/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NotComponent
*/

#ifndef NOTCOMPONENT_HPP_
#define NOTCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class NotComponent : public AComponent
    {
        public:
            NotComponent(const std::string &name);
            ~NotComponent() = default;

        private:
            Tristate computeComponent() const;
    };
}

#endif /* !NOTCOMPONENT_HPP_ */
