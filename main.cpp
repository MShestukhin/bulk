#include <iostream>
#include <string>
#include "logger.h"
using namespace std;

vector<string> cmd_str;
int iter=0;
class Reflector: public IObserver // Prints the observed string into cout
{
public:
    virtual void handleEvent(const SupervisedString& ref)
    {
        if(ref.get() != "}" && ref.get() !="{")
            cmd_str.push_back(ref.get());
    }
};

class Counter: public IObserver // Prints the length of observed string into cout
{

public:
  virtual void handleEvent(const SupervisedString& ref)
  {
      iter--;
  }
};

class ObjCounter: public IObserver // Prints the length of observed string into cout
{
public:
  static int local_iter;
  virtual void handleEvent(const SupervisedString& ref)
  {
        if(ref.get()=="{"){
            local_iter=local_iter+1;
            iter=local_iter;
        }
        if(ref.get()=="}"){
            local_iter=local_iter-1;
            iter=local_iter;
        }

  }
};

int ObjCounter::local_iter=0;

int main(int argc, char *argv[])
{
    int n=atoi(argv[1]);
    iter=n;
    SupervisedString str;
    Reflector refl;
    Counter cnt;
    logger logger;
    ObjCounter objCnt;
    str.add(refl);
    str.add(cnt);
    str.add(objCnt);
    str.add(logger);
    while (1) {
        string cmd;
        std::cin>>cmd;
        if(cmd == "}" || cmd =="{"){
            str.remove(cnt);
            if(!ObjCounter::local_iter)
                cmd_str.clear();
        }
        str.reset(cmd);
        str.remove(logger);
        if(iter == 0){
            std::string sum_cmd="bulk: ";
            for(const string & str : cmd_str)
                sum_cmd=sum_cmd+str+" ";
            std::cout<<sum_cmd;
            logger.info(sum_cmd);
            iter=n;
            cmd_str.clear();
            str.remove(cnt);
            str.add(cnt);
            std::cout<<std::endl;
        }
    }
    return 0;
}
