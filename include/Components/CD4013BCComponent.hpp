/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4013BCComponent
*/

#ifndef CD4013BCCOMPONENT_HPP_
#define CD4013BCCOMPONENT_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class CD4013BCComponent : public Component
    {
        public:
            CD4013BCComponent();
            ~CD4013BCComponent() = default;

            nts::Tristate compute(size_t pin) const override;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
}

#endif /* !CD4013BCCOMPONENT_HPP_ */
