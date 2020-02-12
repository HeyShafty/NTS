/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** UnknownComponentException
*/

#ifndef UNKNOWNCOMPONENTEXCEPTION_HPP_
#define UNKNOWNCOMPONENTEXCEPTION_HPP_

#include "NtsException.hpp"

namespace nts::exception
{
    /**
     * @brief
     * To be raised when a component type (or component name) is unknown
     */
    class UnknownComponentException : public NtsException
    {
        public:
            UnknownComponentException(std::string const &message, std::string const &component = "Unknown");

        protected:
        private:
    };
}

#endif /* !UNKNOWNCOMPONENTEXCEPTION_HPP_ */
