#include <iostream>
#include <vector>
#include <memory>

class Polygon{
  public:
    virtual void draw(){
      std::cout << "画多边形" << std::endl;
    }
};

class Rectangle: public Polygon{
  public:
    virtual void draw(){
      std::cout << "画矩形" << std::endl;
    }
};

class Triangle: public Polygon{
  public:
    virtual void draw(){
      std::cout << "画三角形" << std::endl;
    }
};

int main(){
  std::shared_ptr<Polygon> p1 = std::shared_ptr<Polygon>(new Polygon());
  std::shared_ptr<Polygon> p2 = std::shared_ptr<Polygon>(new Rectangle());
  std::shared_ptr<Polygon> p3 = std::shared_ptr<Polygon>(new Triangle());

  std::vector<std::shared_ptr<Polygon>> list = {p1,p2,p3};

  for(const auto &p:list){
    p->draw();
  }

  return 0;
}