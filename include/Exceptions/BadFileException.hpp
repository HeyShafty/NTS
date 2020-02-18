/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** MyFileException
*/

#ifndef MYFILEEXCEPTION_HPP_
#define MYFILEEXCEPTION_HPP_

#include "NtsException.hpp"

namespace nts::Exception
{
    class BadFileException : public NtsException
    {
        public:
            BadFileException(std::string const &message, std::string const &component = "Unknown");

        protected:
        private:
    };
}

#endif /* !MYFILEEXCEPTION_HPP_ */
