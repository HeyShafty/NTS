/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4008BMSComponent
*/

#ifndef CD4008BMSCOMPONENT_HPP_
#define CD4008BMSCOMPONENT_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class CD4008BMSComponent : public Component {
        public:
            CD4008BMSComponent();
            ~CD4008BMSComponent() = default;

            nts::Tristate compute(size_t pin = 1) const override;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
}

#endif /* !CD4008BMSCOMPONENT_HPP_ */
