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

            static std::shared_ptr<IComponent> createComponent(const std::string &type, const std::string &value = "");

            template<class T, typename ...Args>
            static std::shared_ptr<IComponent> createBasicComponent(Args &&...args)
            {
                return std::make_shared<T>(std::forward<Args>(args)...);
            }

        protected:
        private:
            static const std::map<const std::string, std::function<std::shared_ptr<nts::IComponent>(const std::string &value)>> componentMap;
    };
}


#endif /* !FACTORY_HPP_ */
