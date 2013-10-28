#include "logger.h"
#include <iostream>
#include <sstream>
#include <iomanip>

SuperLog Log;

SuperLog::SuperLog(): m_iLogCounter(0)
{
    m_bToFile = false;
  //ctor
}

SuperLog::~SuperLog()
{
    m_fLogFile.close();
    //dtor
}

void SuperLog::print(const logType type, const std::string& msg, const std::string& file, const int line)
{
    std::ostringstream _out;

    switch(type)
    {
        case SuperLog::logType::ERROR:
            _out << "\x1b[31m";
            _out << "(EE) " ;
            break;
        case SuperLog::logType::WARNING:
            _out << "\x1b[33m";
            //_out << "\x1b[48;5;" << colorWarn << "m";
            _out << "(WW) " ;
            break;
        case SuperLog::logType::INFO:
            _out << "\x1b[36m";
            //_out << "\x1b[48;5;" << colorInfo << "m";
            _out << "(II) " ;
            break;
    }
    _out << "[" << std::setw(4) << m_iLogCounter++ << "]" ;

    _out << "[" << file << ":" << line << "] : ";
    _out<<msg;
    _out << "\x1b[0m ";

    std::cout << _out.str() << std::endl;
    if(m_bToFile)
    {
        m_fLogFile << "[" << std::setw(4) << m_iLogCounter-1 << "]" ;
        m_fLogFile << "[" << file << ":" << line << "] : ";
        m_fLogFile << msg << std::endl;
    }
}

void SuperLog::print(char* msg)
{
    std::ostringstream _out;
    _out << "\x1b[31m  ";
    _out << msg ;
    _out << "\x1b[0m ";
    std::cout << _out.str() << std::endl;
}

void SuperLog::print(const std::string& msg)
{
    std::ostringstream _out;
    _out << "\x1b[31m  ";
    _out << msg ;
    _out << "\x1b[0m ";
    std::cout << _out.str() << std::endl;
}

void SuperLog::toggleLogFile()
{
    if(m_bToFile)
        m_fLogFile.close();
    else
        m_fLogFile.open("log.txt");//, std::ofstream::app);


    m_bToFile = !m_bToFile;

}
