/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4069UBCComponent
*/

#ifndef CD4069UBCComponent_HPP_
#define CD4069UBCComponent_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class CD4069UBCComponent : public AComponent
    {
        public:
            CD4069UBCComponent(const std::string &name);
            ~CD4069UBCComponent() = default;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
} // namespace nts::Components

#endif /* !CD4069UBCComponent_HPP_ */
