/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4030C
*/

#ifndef CD4030C_HPP_
#define CD4030C_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class CD4030CComponent : public AComponent {
        public:
            CD4030CComponent();
            ~CD4030CComponent() = default;

            nts::Tristate compute(size_t pin) const override;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
}

#endif /* !CD4030C_HPP_ */
