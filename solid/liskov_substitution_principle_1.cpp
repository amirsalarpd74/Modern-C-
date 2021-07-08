#include <iostream>
#include <memory>

/**  ++ Advantage ++
 *      Does not have Overhead of polymorphism 
 * 
 *   ++ Disadvantage
 *      Violation of OCP principle.
 */

// Liskov Substitution Principle

// Shape is an base class
class Shape
{
public:
    enum class ShapeType
    {
        Rectangle,
        Triangle
    };

    Shape(ShapeType shape_type)
    : shape_type(shape_type)
    {
    }

    virtual void draw()
    {
    }

    ShapeType get_shape_type()
    {
        return shape_type;
    }

private:
    ShapeType shape_type;
};

class Triangle : public Shape
{
    public:
    Triangle(ShapeType shape_type)
    : Shape(shape_type)
    {
    }

    ~Triangle() = default;

    void draw() override
    {
        printf("\tTriangle \t /_\\ \n");
    }
};

class Rectangle : public Shape
{
    public:
    Rectangle(ShapeType shape_type)
    : Shape(shape_type)
    {
    }

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
        // Violation of OCP principle.
        switch (shape_pointer->get_shape_type())
        {
        case Shape::ShapeType::Rectangle:
            static_pointer_cast<Rectangle>(shape_pointer)->draw();
            break;
        case Shape::ShapeType::Triangle:
            static_pointer_cast<Triangle>(shape_pointer)->draw();
        default:
            break;
        }
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
        static auto shape_pointer = std::make_shared<Rectangle>(Rectangle(Shape::ShapeType::Rectangle)); // static is so bad only for behavior class
        return shape_pointer;
    }
};

class TriangleFactory : public AbstractShapeFactory
{
    ShapePointer create_shape() override
    {
        static auto shape_pointer = std::make_shared<Triangle>(Triangle(Shape::ShapeType::Triangle)); // static is so bad only for behavior class
        return shape_pointer;
    }
};

// Main
int main()
{
    Drawing drawing;
    AbstractShapeFactory* shape_factory;

    shape_factory = new TriangleFactory(); // input
    drawing.set_shape(shape_factory->create_shape());
    drawing.draw();

    shape_factory = new RectangleFactory(); // input
    drawing.set_shape(shape_factory->create_shape());
    drawing.draw();
}