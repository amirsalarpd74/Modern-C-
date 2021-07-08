#include <iostream>
#include <memory>

/**  ++ Advantage ++
 *       Extensible without modification --> OCP principle
 *   
 *   ++ Disadvantage
 *       Overhead of polymorphism is too high to pay.
 */

// Liskov Substitution Principle
// Shape is an Interface and only has behavior
class Shape
{
public:
    virtual void draw() = 0;
};

class Triangle : public Shape
{
    public:
    Triangle() = default;
    ~Triangle() = default;

    void draw() override
    {
        printf("\tTriangle \t /_\\ \n");
    }
};

class Rectangle : public Shape
{
    public:
    Rectangle() = default;
    ~Rectangle() = default;

    void draw() override
    {
        printf("\tRectangle \t |==| \n");
    }
};

typedef std::shared_ptr<Shape> ShapePointer;

class Drawing
{
public:
    void set_shape(ShapePointer t_shape_pointer)
    {
        shape_pointer = t_shape_pointer;
    }

    void draw()
    {
        return shape_pointer->draw();
    }

private:
    ShapePointer shape_pointer;
};

// Creational Pattern (Abstract Factory)
class AbstractShapeFactory
{
public:
    virtual ShapePointer create_shape() = 0;
};

class RectangleFactory : public AbstractShapeFactory
{
    ShapePointer create_shape() override
    {
        static auto shape_pointer = std::make_shared<Rectangle>(); // static is so bad only for behavior class
        return shape_pointer;
    }
};

class TriangleFactory : public AbstractShapeFactory
{
    ShapePointer create_shape() override
    {
        static auto shape_pointer = std::make_shared<Triangle>(); // static is so bad only for behavior class
        return shape_pointer;
    }
};

int main()
{
    Drawing drawing;
    AbstractShapeFactory* shape_factory;

    shape_factory = new TriangleFactory(); // input
    drawing.set_shape(shape_factory->create_shape());
    drawing.draw(); // Specify draw function run-time -> polymorphism

    shape_factory = new RectangleFactory(); // input
    drawing.set_shape(shape_factory->create_shape());
    drawing.draw(); // Specify draw function run-time -> polymorphism
}