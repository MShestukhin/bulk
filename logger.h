#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
#include <iostream>
#include <sstream>
#include "observer.h"
#include <thread>
#include <mutex>

class logger : public IObserver
{
    vector<string> cmd_local_buf;
public:
    static int iter;
    bool first_thread;
    static vector<string> cmd_str;
    logger();
    std::string currentDateTime(std::string format);
    std::string path;
    std::string file_name;
    void init(std::string path_log);
    void info(std::string s);
    static void msg(std::string s);
    static void cmd_line_log_thread();
    static void file_log_thread_one();
    static void file_log_thread_two();
    virtual void handleEvent(const SupervisedString& ref)
    {
        time_t     now = time(0);
        time_t seconds;
        time(&seconds);

        std::stringstream ss;
        ss << seconds;

        file_name="bulk"+ss.str()+".log";
        first_thread=true;
        std::ofstream ifs(file_name.c_str(), std::ios_base::in | std::ios_base::app);
        std::thread thr(cmd_line_log_thread);
        std::thread thr1(file_log_thread_one);
        std::thread thr2(file_log_thread_two);
        thr.detach();
    }
};

#endif // LOGGER_H
