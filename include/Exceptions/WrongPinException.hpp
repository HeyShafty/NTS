/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** WrongPinException
*/

#ifndef NOPINEXCEPTION_HPP_
#define NOPINEXCEPTION_HPP_

#include "NtsException.hpp"

namespace nts::exception
{
    /**
     * @brief
     * To be raised when a requested pin doesn't exist, or when a pin type is missed used
     */
    class WrongPinException : public NtsException
    {
        public:
            WrongPinException(std::string const &message = "Given pin does not exists", std::string const &component = "Unknown");

        protected:
        private:
    };
}

#endif /* !NOPINEXCEPTION_HPP_ */
