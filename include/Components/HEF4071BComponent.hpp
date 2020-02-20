/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** HEF4071B
*/

#ifndef HEF4071B_HPP_
#define HEF4071B_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class HEF4071BComponent : public AComponent {
        public:
            HEF4071BComponent();
            ~HEF4071BComponent() = default;

            nts::Tristate compute(size_t pin) const override;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
}

#endif /* !HEF4071B_HPP_ */
