#include "logger.h"
#include <unistd.h>

logger::logger()
{
}

void logger::init(std::string path_log){
    path="/";
    file_name=currentDateTime("%d.%m.%Y")+".log";
    std::ofstream ifs(file_name.c_str(), std::ios_base::in | std::ios_base::app);
}

std::string logger::currentDateTime(std::string format) {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), format.c_str(), &tstruct);
    return buf;
}
void logger::info(std::string s){
//    msg(s,"INFO");
}

void logger::cmd_line_log_thread(){
    while(1){
        if(iter == 0){
            std::string sum_cmd="bulk: ";
            for (auto str = cmd_str.begin(); str != cmd_str.end(); ++str) {
                sum_cmd=sum_cmd+*str;
                if(str!=cmd_str.end()-1)
                    sum_cmd+=", ";
            }
            std::cout<<sum_cmd<<"\n";
            cmd_str.clear();
        }
    }
}

void logger::file_log_thread_one(){
    while(1){
        if(iter == 0){
            std::string sum_cmd="bulk: ";
            for (auto str = cmd_str.begin(); str != cmd_str.end(); ++str) {
                sum_cmd=sum_cmd+*str;
                if(str!=cmd_str.end()-1)
                    sum_cmd+=", ";
            }
            msg(sum_cmd);
            cmd_str.clear();
        }
    }
}

void logger::file_log_thread_two(){
    while(1){
        if(iter == 0){
            std::string sum_cmd="bulk: ";
            for (auto str = cmd_str.begin(); str != cmd_str.end(); ++str) {
                sum_cmd=sum_cmd+*str;
                if(str!=cmd_str.end()-1)
                    sum_cmd+=", ";
            }
            msg(sum_cmd);
            cmd_str.clear();
        }
    }
}


int logger::iter=0;
std::vector<std::string> logger::cmd_str;

void logger::msg(std::string s){
    mutex lock;
    lock.lock();
    std::ofstream ifs(file_name.c_str(), std::ios_base::in | std::ios_base::app);
     if (ifs.is_open())
     {
         ifs << s+"\n";
         ifs.close();
     }
     else
         std::cout << "Error opening file\n";
     lock.unlock();
}



