/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** SRFlipFlopComponent
*/

#ifndef SRFlipFlopComponent_HPP_
#define SRFlipFlopComponent_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class SRFlipFlopComponent : public Component
    {
        public:
            SRFlipFlopComponent();
            ~SRFlipFlopComponent() = default;

            nts::Tristate compute(size_t pin) const override;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
} // namespace nts::Components

#endif /* !SRFlipFlopComponent_HPP_ */
