/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4011B
*/

#ifndef CD4011B_HPP_
#define CD4011B_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class CD4011BComponent : public AComponent
    {
        public:
            CD4011BComponent(const std::string &name);
            ~CD4011BComponent() = default;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
}



#endif /* !CD4011B_HPP_ */
