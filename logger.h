#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
#include <iostream>
#include <sstream>
#include "observer.h"
class logger : public IObserver
{
public:
    logger();
    std::string currentDateTime(std::string format);
    std::string path;
    std::string file_name;
    void init(std::string path_log);
    void info(std::string s);
    void msg(std::string s,std::string inf_level);
    virtual void handleEvent(const SupervisedString& ref);
};

#endif // LOGGER_H
