#include <iostream>
#include "math.h"
struct Point {
  int x;
  int y;
};

class Polygon {
private:
  Point* vertices; // remember to think arrays for this
  int numVertices;

public:
  Polygon(); // constructor
  ~Polygon(); // destructor  
  Polygon(const Polygon& poly);  // copy constructor
  Polygon& operator=(const Polygon& poly);  // copy assignment operator


  // other member functions
  void addVertex(int x, int y);
  Point* getVertices() const;
  int getNumVertices() const;
  void print(); // outputs the list of vertices (x1, y1), (x2, y2), ... 
  virtual double area(){}
};

Polygon::Polygon() : vertices(nullptr), numVertices(0){}

Polygon::~Polygon(){
    delete[] vertices;
}

Polygon::Polygon(const Polygon& poly) : vertices(nullptr), numVertices(poly.numVertices) {
    vertices = new Point[poly.numVertices];
    for(int i = 0; i < poly.numVertices; i++){
        vertices[i] = poly.vertices[i];
    }
}

Polygon& Polygon::operator=(const Polygon& poly){
    if(this != &poly){
        numVertices = poly.numVertices;
        delete[] vertices;
        vertices = new Point[numVertices];
        for(int i = 0; i < numVertices; i++){
            vertices[i] = poly.vertices[i];
        }
    }
    return *this;
}

void Polygon::addVertex(int x, int y){
    Point* temp = new Point[numVertices+1];
    for(int i = 0; i < numVertices; i++){
        temp[i] = vertices[i];
    }
    temp[numVertices].x = x;
    temp[numVertices].y = y;
    delete[] vertices;
    vertices = temp;
    numVertices++;
}

Point* Polygon::getVertices() const{
    return vertices;
}

int Polygon::getNumVertices() const{
    return numVertices;
}

void Polygon::print() {
    for(int i = 0; i < numVertices; i++){
        std::cout << "(" << vertices[i].x << ", " <<
            vertices[i].y << "), ";
    }
    std::cout << std::endl;
}

class Rectangle : public Polygon{
    int side;
    public:
        double area(){
            double side = 0;
            double per = 0;
            if(getNumVertices() != 4){ return 0; }
            Point* vertices = getVertices();
            for(int i = 0; i < 3; i++){
                side = sqrt(pow(vertices[i+1].x-vertices[i].x,2)+
                    pow(vertices[i+1].y-vertices[i].y,2));
                per+=side;
            }
            per+= sqrt(pow(vertices[0].x-vertices[3].x,2)+
                pow(vertices[0].y-vertices[3].y,2));
            return per;
        }
};

int main() {
  Rectangle p1;
  p1.addVertex(1, 4);
  p1.addVertex(1, 3);
  p1.addVertex(3, 3);
  p1.addVertex(3, 4);
  std::cout << p1.area() << std::endl;
  Polygon p2(p1);
  p2.addVertex(3, 2);
  Polygon p3;
  p3 = p1;
  p3.addVertex(2, 2);
  p1.print();
  p2.print();
  p3.print();
}
