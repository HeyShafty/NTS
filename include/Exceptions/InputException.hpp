/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** InputException
*/

#ifndef INPUTEXCEPTION_HPP_
#define INPUTEXCEPTION_HPP_

#include "NtsException.hpp"

namespace nts::Exception
{
    /**
     * @brief
     * To be raised when one or several input values were not provided on the command line
     */
    class InputException : public NtsException
    {
        public:
            InputException(std::string const &message, std::string const &component = "Unknown");

        protected:
        private:
    };
}

#endif /* !INPUTEXCEPTION_HPP_ */
