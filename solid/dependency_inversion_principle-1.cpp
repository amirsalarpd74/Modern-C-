#include <iostream>
#include <memory>

/**  ++ Advantage ++
 *      Extensible without modification --> OCP principle.
 *      DIP principle has been observed.
 * 
 *   ++ Disadvantage
 *       Overhead of polymorphism is too high to pay.
 */

/**********************************************
 * Higher-level
 * providing some coherent set of services though a well-defined and controlled interface
 */

// Controlled interface
class ButtonServer
{
    public:
    virtual void turn_off() = 0;
    virtual void turn_on() = 0;
};

typedef std::shared_ptr<ButtonServer> ObjectPointer;

class Button
{
public:
    Button(ObjectPointer object_pointer)
    : object_pointer(object_pointer)
    {
    }

    void poll()
    {
        button ? object_pointer->turn_on() : object_pointer->turn_off();
    }
  
    void on()
    {
        button = true;
    }

    void off()
    {
        button = false;
    }

private:
    ObjectPointer object_pointer;
    bool button;
};

/******************************************
 * Lower-level
 */

class Lamp : public ButtonServer
{
public:

    void turn_off() override
    {
        printf("Lamp turn OFF. \n");
    }

    void turn_on() override
    {
        printf("Lamp turn ON. \n");
    }
};

class Tv : public ButtonServer
{
public:

    void turn_off() override
    {
        printf("TV turn OFF. \n");
    }

    void turn_on() override
    {
        printf("TV turn ON. \n");
    }
};

// main
int main()
{
    Button button(std::make_shared<Lamp>());
    button.on();
    button.poll();

    button= Button(std::make_shared<Tv>());
    button.on();
    button.poll();
}
