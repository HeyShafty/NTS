/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4008BMSComponent
*/

#ifndef CD4008BMSCOMPONENT_HPP_
#define CD4008BMSCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class CD4008BMSComponent : public AComponent {
        public:
            CD4008BMSComponent(const std::string &name);
            ~CD4008BMSComponent() = default;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
}

#endif /* !CD4008BMSCOMPONENT_HPP_ */
