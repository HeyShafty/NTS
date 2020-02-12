/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NtsException
*/

#ifndef NTSEXCEPTION_HPP_
#define NTSEXCEPTION_HPP_

#include <exception>
#include <string>

namespace nts::exception
{
    /**
     * @brief
     * Main class for nts exceptions
     */
    class NtsException : public std::exception
    {
        public:
            NtsException(std::string const &message, std::string const &component = "Unknown");

            std::string const &getComponent() const;
            const char* what() const noexcept override;

        protected:
        private:
            std::string _message;
            std::string _component;
    };
}

#endif /* !NTSEXCEPTION_HPP_ */
