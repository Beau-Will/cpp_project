#include <iostream>
#include <memory>

class BaseClass{
  public:
    BaseClass(){
      std::cout << "调用基类构造函数" << std::endl;
    }
    virtual ~BaseClass(){
      std::cout << "调用基类析构函数" << std::endl;
    }
};

class SubClass: public BaseClass{
  public:
    SubClass(){
      std::cout << "调用子类构造函数" << std::endl;
    }
    ~SubClass(){
      std::cout << "调用子类析构函数" << std::endl;
    }
};

int main(){
  std::shared_ptr<BaseClass> ptr = std::shared_ptr<BaseClass>(new SubClass());

  return 0;
}