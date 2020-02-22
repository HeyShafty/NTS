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
            DFlipFlopComponent();
            ~DFlipFlopComponent() = default;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
} // namespace nts::Components

#endif /* !DFlipFlopComponent_HPP_ */
