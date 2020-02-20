/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <memory>
#include <map>
#include <functional>
#include "IComponent.hpp"

namespace nts
{
    class Factory {
        public:
            Factory() = default;
            ~Factory() = default;
            static std::unique_ptr<IComponent> createComponent(const std::string &type, const std::string &value);

        protected:
        private:
            static const std::map<const std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>> componentMap;
            static std::unique_ptr<nts::IComponent> createTrue(void) noexcept;
            static std::unique_ptr<nts::IComponent> createInput(const std::string &value) noexcept;
            static std::unique_ptr<nts::IComponent> createOutput(void) noexcept;
            static std::unique_ptr<nts::IComponent> create4071(void) noexcept;
    };
}


#endif /* !FACTORY_HPP_ */
