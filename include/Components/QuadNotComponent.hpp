/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** QuadNotComponent
*/

#ifndef QUADNOTCOMPONENT_HPP_
#define QUADNOTCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class QuadNotComponent : public AComponent
    {
        public:
            QuadNotComponent();
            ~QuadNotComponent() = default;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
} // namespace nts::Components

#endif /* !QUADNOTCOMPONENT_HPP_ */
