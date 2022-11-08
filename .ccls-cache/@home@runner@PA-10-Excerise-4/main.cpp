#include <iostream>

using namespace std;

class BasicShape 
{
  private:
	  int x, y;
  public:
	  BasicShape(int x, int y) :x(x), y(y) {}
	  int getX() 
    {
		  return x;
	  }
	  int getY() 
    {
		  return y;
	  }
	  virtual double area() = 0;
	  virtual double perimeter() = 0;
	  virtual void print() 
    {
		  cout << "(" << x << ',' << y << ")";
	  }
};

class Circle : public BasicShape 
{
  private:
	  double radius;
  public:
	  Circle() :BasicShape(5,5),radius(1.0) {}
	  Circle(int x, int y, double radius) :BasicShape(x, y), radius(radius) {}
	  double area() 
    {
		  return 3.14*radius*radius;
	  }
	  double perimeter() 
    {
		  return 3.14 * 2 * radius;
	  }
	  void print() 
    {
		  cout << "circle: center point ";
		  BasicShape::print();
		  cout << " and radius " << radius;
	  }
};


class Rectangle : public BasicShape 
{
  private:
	  int width, length;
  public:
	  Rectangle() :BasicShape(0, 0), width(1), length(1) {}
	  Rectangle(int x, int y, int width, int length) :BasicShape(x, y), width(width), length(length) {}
	  double area() 
    {
		  return length*width;
	  }
	  double perimeter() 
    {
		  return 2 * (length + width);
	  }
	  void print() 
    {
		  cout << "Rectangle: top left point ";
		  BasicShape::print();
		  cout << ", " << width;
		  cout << " by " << length;
	  }
};




int main()
{
	Circle c1;
	Circle c2(5, 7, 2.5);
	Rectangle r1;
	Rectangle r2(10, 7, 10, 15);
	BasicShape *pShapeArray[4] = { &c1, &c2, &r1, &r2 };
	for (int i = 0;i < 4;i++) 
  {
		pShapeArray[i]->print();
		cout << "\narea: " << pShapeArray[i]->area();
		cout << "\nperimeter: " << pShapeArray[i]->perimeter() << endl << endl;
	}
    return 0;
}