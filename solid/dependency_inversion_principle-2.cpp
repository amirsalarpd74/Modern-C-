#include <iostream>
#include <memory>

/**********************************************
 * Higher-level
 * providing some coherent set of services though a well-defined and controlled interface
 */

/**  ++ Advantage ++
 *      Does not have Overhead of polymorphism.
 *      Extensible without modification --> OCP principle.
 *      DIP principle has been observed.
 * 
 *   ++ Disadvantage
 */

// Controlled interface
// Zero-cost abstractions
template <typename T>
concept Switchable = requires(T t)
{
    {t.turn_off()};
    {t.turn_on()};
};

template <Switchable SwitchObject>
class Button
{
public:
    typedef std::shared_ptr<SwitchObject> SwitchObjectPointer;
    
    Button(SwitchObjectPointer object_pointer)
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
    SwitchObjectPointer object_pointer;
    bool button;
};

/******************************************
 * Lower-level
 */

class Lamp
{
public:

    void turn_off()
    {
        printf("Lamp turn OFF. \n");
    }

    void turn_on()
    {
        printf("Lamp turn ON. \n");
    }
};

class Tv
{
public:

    void turn_off()
    {
        printf("TV turn OFF. \n");
    }

    void turn_on()
    {
        printf("TV turn ON. \n");
    }
};

// main
int main()
{
    Button button1(std::make_shared<Lamp>());
    button1.on();
    button1.poll();

    Button button2(std::make_shared<Tv>());
    button2.off();
    button2.poll();
}
