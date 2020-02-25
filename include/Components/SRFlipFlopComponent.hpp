/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** SRFlipFlopComponent
*/

#ifndef SRFlipFlopComponent_HPP_
#define SRFlipFlopComponent_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class SRFlipFlopComponent : public AComponent
    {
        public:
            SRFlipFlopComponent(const std::string &name);
            ~SRFlipFlopComponent() = default;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
} // namespace nts::Components

#endif /* !SRFlipFlopComponent_HPP_ */
