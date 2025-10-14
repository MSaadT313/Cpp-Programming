#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Shape {
protected:
    float position;
    string color;
    float borderThickness;

public:
    Shape(float pos, string clr, float bt) : position(pos), color(clr), borderThickness(bt) {}
    virtual ~Shape() {}
    virtual void draw() = 0;
    virtual float calculateArea() = 0;
    virtual float calculatePerimeter() = 0;
    float getPosition() const { return position; }
    void setPosition(float pos) { position = pos; }
    string getColor() const { return color; }
    void setColor(string clr) { color = clr; }
    float getBorderThickness() const { return borderThickness; }
    void setBorderThickness(float bt) { borderThickness = bt; }
};

class Circle : public Shape {
private:
    float radius;
    float centerX, centerY;

public:
    Circle(float x, float y, float rad, string clr, float bt) 
        : Shape(0, clr, bt), radius(rad), centerX(x), centerY(y) {}
    
    float calculateArea() override { 
        return M_PI * radius * radius; 
    }
    
    float calculatePerimeter() override { 
        return 2 * M_PI * radius; 
    }
    
    void draw() override { 
        cout << "Drawing Circle at (" << centerX << ", " << centerY 
             << "), Radius: " << radius << ", Color: " << color 
             << ", Border Thickness: " << borderThickness << endl; 
    }
};

class Rectangle : public Shape {
private:
    float width;
    float height;
    float topLeftX, topLeftY;

public:
    Rectangle(float x, float y, float w, float h, string clr, float bt) 
        : Shape(0, clr, bt), width(w), height(h), topLeftX(x), topLeftY(y) {}
    
    float calculateArea() override { 
        return width * height; 
    }
    
    float calculatePerimeter() override { 
        return 2 * (width + height); 
    }
    
    void draw() override { 
        cout << "Drawing Rectangle at (" << topLeftX << ", " << topLeftY 
             << "), Width: " << width << ", Height: " << height 
             << ", Color: " << color << ", Border Thickness: " << borderThickness << endl; 
    }
};

class Triangle : public Shape {
private:
    float side1, side2, side3;
    float x1, y1, x2, y2, x3, y3;

public:
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3, string clr, float bt)
        : Shape(0, clr, bt), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
        side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    }
    
    float calculateArea() override {
        float s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    
    float calculatePerimeter() override { 
        return side1 + side2 + side3; 
    }
    
    void draw() override { 
        cout << "Drawing Triangle with vertices (" << x1 << ", " << y1 << "), (" 
             << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << "), Color: " 
             << color << ", Border Thickness: " << borderThickness << endl; 
    }
};

int main() {
    Circle c1(10, 10, 5, "red", 2);
    Rectangle r1(20, 30, 10, 5, "blue", 1);
    Triangle t1(0, 0, 3, 0, 0, 4, "green", 1);

    c1.draw();
    cout << "Area of Circle: " << c1.calculateArea() << endl;
    cout << "Perimeter of Circle: " << c1.calculatePerimeter() << endl;

    r1.draw();
    cout << "Area of Rectangle: " << r1.calculateArea() << endl;
    cout << "Perimeter of Rectangle: " << r1.calculatePerimeter() << endl;

    t1.draw();
    cout << "Area of Triangle: " << t1.calculateArea() << endl;
    cout << "Perimeter of Triangle: " << t1.calculatePerimeter() << endl;

    return 0;
}