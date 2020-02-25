/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** QuadTripleNandComponent
*/

#ifndef QUADTRIPLENANDCOMPONENT_HPP_
#define QUADTRIPLENANDCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class QuadTripleNandComponent : public AComponent
    {
        public:
            QuadTripleNandComponent(const std::string &name);
            ~QuadTripleNandComponent() = default;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
} // namespace nts::Components

#endif /* !QUADTRIPLENANDCOMPONENT_HPP_ */
