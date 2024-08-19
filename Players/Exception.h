//
// Created by USER on 01/04/2024.
//

#ifndef NEW_EXCEPTION_H
#define NEW_EXCEPTION_H


#include <exception>
#include <string>

class InvalidPlayersFile :public std::exception
{
public:
    InvalidPlayersFile() : m_error_line("Invalid Players File")
    {
    }
    const char* what() const noexcept override
    {
        return m_error_line.c_str();
    }
private:
    std::string m_error_line;
};


class InvalidEventFile :public std::exception
{
public:
    InvalidEventFile() : m_error_line("Invalid Events File")
    {
    }
    const char* what() const noexcept override
    {
        return m_error_line.c_str();
    }
private:
    std::string m_error_line;

};



#endif //NEW_EXCEPTION_H
