#ifndef DATAEXCEPTION
#define DATAEXCEPTION

#include <iostream>
#include <string>
#include <cstring>

class NoElement : public std::exception
{
public:
    NoElement(const std::string& msg) : m_msg(msg){}

    virtual const char* what() const throw () 
    {
        std::string base="Empty Exception:"+m_msg;
        return base.c_str();
    }

    const std::string m_msg;
};

#endif