#include "logger.h"

logger::logger()
{
}

void logger::init(std::string path_log){
    path="/";
    file_name=currentDateTime("%d.%m.%Y")+".log";
    std::ofstream ifs(file_name.c_str(), std::ios_base::in | std::ios_base::app);
}

void logger::handleEvent(const SupervisedString& ref){
    time_t     now = time(0);
    time_t seconds;
    time(&seconds);

    std::stringstream ss;
    ss << seconds;

    file_name="bulk"+ss.str()+".log";
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
    msg(s,"INFO");
}

void logger::msg(std::string s, std::string inf_level){
    std::ofstream ifs(file_name.c_str(), std::ios_base::in | std::ios_base::app);
     if (ifs.is_open())
     {
         ifs << s+"\n";
         ifs.close();
     }
     else
         std::cout << "Error opening file\n";
}



