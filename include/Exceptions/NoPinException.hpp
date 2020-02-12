/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NoPinException
*/

#ifndef NOPINEXCEPTION_HPP_
#define NOPINEXCEPTION_HPP_

#include "NtsException.hpp"

namespace nts::exception
{
    /**
     * @brief
     * To be raised when a requested pin doesn't exist
     */
    class NoPinException : public NtsException
    {
        public:
            NoPinException(std::string const &message = "Given pin does not exists", std::string const &component = "Unknown");

        protected:
        private:
    };
}

#endif /* !NOPINEXCEPTION_HPP_ */
