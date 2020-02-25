/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4013BCComponent
*/

#ifndef CD4013BCCOMPONENT_HPP_
#define CD4013BCCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class CD4013BCComponent : public AComponent
    {
        public:
            CD4013BCComponent(const std::string &name);
            ~CD4013BCComponent() = default;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
}

#endif /* !CD4013BCCOMPONENT_HPP_ */
