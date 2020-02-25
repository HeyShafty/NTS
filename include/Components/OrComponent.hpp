/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
#define ORCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class OrComponent : public AComponent
    {
        public:
            OrComponent(const std::string &name);
            ~OrComponent() = default;

        private:
            Tristate computeComponent() const;
    };
}

#endif /* !ORCOMPONENT_HPP_ */
