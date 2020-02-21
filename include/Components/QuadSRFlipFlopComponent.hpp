/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** QuadSRFlipFlopComponent
*/

#ifndef QuadSRFlipFlopComponent_HPP_
#define QuadSRFlipFlopComponent_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class QuadSRFlipFlopComponent : public AComponent
    {
        public:
            QuadSRFlipFlopComponent();
            ~QuadSRFlipFlopComponent() = default;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
} // namespace nts::Components

#endif /* !QuadSRFlipFlopComponent_HPP_ */
