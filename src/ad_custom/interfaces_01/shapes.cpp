#include <iostream>
#include <memory> // Include the memory header for std::shared_ptr
using namespace std;

// Abstract class (interface)
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;
    virtual double area() = 0;
};
// Derived class
class Circle : public Shape {
    private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() override {
        cout << "Drawing Circle" << endl;
    }

    double area() override {
        return 3.14159 * radius * radius;
    }
};

// Another derived class
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }

    double area() override {
        return width * height;
    }
};

int main() {
    // Shape* shape1 = new Circle(5.0);
    // Shape* shape2 = new Rectangle(4.0, 6.0);
    shared_ptr<Shape> shape1 = make_shared<Circle>(5.0);
    shared_ptr<Shape> shape2 = make_shared<Rectangle>(4.0, 6.0);

    shape1->draw();
    cout << "Area: " << shape1->area() << endl;

    shape2->draw();
    cout << "Area: " << shape2->area() << endl;

    // delete shape1;
    // delete shape2;

    return 0;
}