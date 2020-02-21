/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** HCF4081BComponent
*/

#ifndef HCF4081BCOMPONENT_HPP_
#define HCF4081BCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class HCF4081BComponent : public AComponent
    {
        public:
            HCF4081BComponent();
            ~HCF4081BComponent() = default;

        private:
            std::vector<std::unique_ptr<IComponent>> innerComponents;
    };
}

#endif /* !HCF4081BCOMPONENT_HPP_ */
