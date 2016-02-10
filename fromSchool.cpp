#include <iostream>

using namespace std;

class Point
{
  int x_, y_;
public:

  Point(int x=0, int y=0) : x_(x), y_(y) {}
  
  int get_x()
  {
    return x_;
  }
  
  int get_y()
  {
    return y_;
  }
};

class Shape
{
public:

  virtual void draw() const=0;  
};

class Circle : public Shape
{
  int radius_;
  Point center_;

public:
  
  Circle(Point center, int radius) : center_(center), radius_(radius) {}
  
  void draw() const
  {
    cout << "circle cx=\"" << center.get_x()
      << "\" cy=\"" center.get_y()
        << "\" r=\"" << radius_ << "\" />"
        << endl;
  }          
};

class CompositeFigure : public Shape
{
  list<Shape> content_;
  
  public:
  
  ~CompositeFigure()
  {
    for(list<Shape>::iterator it = content_.begin(); it != content_.end();it++)
    {
      delete *it;
  }
  
  void add(Shape* shape)
  {
    content_.push_back(shape);  
  }

  void draw() const
  {
    for(list<Shape>::iterator it = content_.begin(); it != content_.end();it++)
    {
      (*it)->draw();
    }
  }
};

class Canvas : public CompositeFigure
{
  int width_, heigh_;
  public:
  
  Canvas(int width=100, int heigh=100) : width_(width), heigh_(heigh) {}
  
  //void draw() const
  //{
    ///
  //}
};

int main()
{
  Shape* s1 = new Circle(Point(20, 20), 15);
  s1->draw();
  return 0;
}
