#ifndef SUPERLOG_H
#define SUPERLOG_H

#include <string>
#include <cstring>

#define __SHORT_FORM_OF_FILE__ \
(std::strrchr(__FILE__,'/') \
? std::strrchr(__FILE__,'/')+1 \
: __FILE__ \
)
#define DBG_INFO(msg) (SuperLog::print(SuperLog::logType::INFO,msg,__SHORT_FORM_OF_FILE__,__LINE__))
#define DBG_WARN(msg) (SuperLog::print(SuperLog::logType::WARNING,msg,__SHORT_FORM_OF_FILE__,__LINE__))
#define DBG_ERROR(msg) (SuperLog::print(SuperLog::logType::ERROR,msg,__SHORT_FORM_OF_FILE__,__LINE__))


class SuperLog
{
  public:
    enum logType {ERROR, WARNING, INFO};
    SuperLog();
    ~SuperLog();
    static void print(const logType type, const std::string& msg, const std::string& file, const int line);
    void suce();

  private:
    unsigned int m_iLogCounter;
};


#endif // LOGGER_H
