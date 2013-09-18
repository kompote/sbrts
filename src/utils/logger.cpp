#include "logger.h"
#include <iostream>
#include <sstream>

SuperLog::SuperLog() : m_iLogCounter(0)
{
  //ctor
}

SuperLog::~SuperLog()
{
  //dtor
}

void SuperLog::print(const logType type, const std::string& msg, const std::string& file, const int line)
{
	std::ostringstream _out;
	//16 + (red * 36) + (green * 6) + blue;
	unsigned colorInfo = 16 + (0 * 36) + (0 * 6) + 6;
	unsigned colorWarn = 16 + (0 * 36) + (6 * 6) + 6;
	unsigned colorError = 16 + (6 * 36) + (0 * 6) + 0;

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
  //_out << "[" << m_iLogCounter++ << "]" ;
  _out << "[" << file << ":" << line << "] : ";
  _out<<msg;
  _out << "\x1b[0m ";

  std::cout << _out.str() << std::endl;
}

void SuperLog::suce()
{
std::cout<<" SUCE! "<<std::endl;
}
