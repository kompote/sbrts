#ifndef SUPERLOG_H
#define SUPERLOG_H

#include <string>
#include <cstring>
#include <fstream>

#define __SHORT_FORM_OF_FILE__ \
(std::strrchr(__FILE__,'/') \
? std::strrchr(__FILE__,'/')+1 \
: __FILE__ \
)
#define DBG_INFO(msg) (Log.print(SuperLog::logType::INFO,msg,__SHORT_FORM_OF_FILE__,__LINE__))
#define DBG_WARN(msg) (Log.print(SuperLog::logType::WARNING,msg,__SHORT_FORM_OF_FILE__,__LINE__))
#define DBG_ERROR(msg) (Log.print(SuperLog::logType::ERROR,msg,__SHORT_FORM_OF_FILE__,__LINE__))
#define debug(format, ...) \
do { \
 char buf[512]; \
 snprintf(buf, 512, format, ## __VA_ARGS__); \
 DBG_INFO(buf); \
} while(false)

 //Log.print(buf); 


class SuperLog
{
  public:
    enum logType {ERROR, WARNING, INFO};
    SuperLog();
    ~SuperLog();
    void print(const logType type, const std::string& msg, const std::string& file, const int line);
    void print(char* msg);
    void print(const std::string& msg);
    void toggleLogFile();

private:
    unsigned int m_iLogCounter;
    bool m_bToFile;
    std::ofstream m_fLogFile; // ("log.txt");
};
extern SuperLog Log;



#endif // LOGGER_H
