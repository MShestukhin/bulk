#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
#include <iostream>
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
    void warning(std::string s);
    void error(std::string s);
    void msg(std::string s,std::string inf_level);
    virtual void handleEvent(const SupervisedString& ref)
    {
        path="/";
        file_name=currentDateTime("%d.%m.%Y")+".log";
        std::ofstream ifs(file_name.c_str(), std::ios_base::in | std::ios_base::app);
    }
};

#endif // LOGGER_H
