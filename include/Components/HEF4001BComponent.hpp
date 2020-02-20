/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** HEF4001BComponent
*/

#ifndef HEF4001BCOMPONENT_HPP_
#define HEF4001BCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class HEF4001BComponent : public AComponent {
        public:
            HEF4001BComponent();
            ~HEF4001BComponent() = default;

            nts::Tristate compute(size_t pin) const override;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
}

#endif /* !HEF4001BCOMPONENT_HPP_ */
