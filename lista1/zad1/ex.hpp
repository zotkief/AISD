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
        char* base="Empty Exception:";
        strcat(base,m_msg.c_str());
        return base;
    }

    const std::string m_msg;
};

#endif