/*
To implement a traffic light system with states for red, green, and yellow,
and that changes state every 10 seconds, we can extend the finite state machine
(FSM) pattern used in the previous light example.
This will involve creating classes for each traffic light state and using
a timer mechanism to change states automatically.
*/
#include <bits/stdc++.h>
#include <thread>
#include <chrono>

class TrafficLight; // Forwared decleration to resolve the circular dependency
//==============================================================================
// We will create a Interface(Abstract Class) "TrafficLightState"
class TrafficLightState
{
public:
    virtual void change(TrafficLight *light) = 0; // pure virtual function.
                                                  /*
                                                  This function will be overridden by each concrete state class
                                                  (e.g., RedLight, GreenLight, YellowLight) to change the state of the
                                                  TrafficLight instance from one state to another.
                                                  */

    virtual const char *getStateName() const = 0;
    /*
     ==> virtual indicates that this function is intended to be overridden in derived classes.
     ==> The char* type is used to represent strings in C/C++. The const before char* means the
         content of the string cannot be modified through this pointer.
     ==> Example: When you call this function, you might get a string like "Red", "Green",
         or "Yellow" representing the current state name.

     ==> const (at the end of the function declaration)
         It assures the compiler and users of the class that calling this function will not alter
         any member variables of the class. It makes the function usable on const instances of the class.

     ==> Pure Virtual Function: The = 0 syntax marks this function as a pure virtual function.
         Purpose: It means this function must be overridden in any non-abstract derived class.
         The base class TrafficLightState is abstract and cannot be instantiated.
    */

    virtual ~TrafficLightState() {}
    // this is the virtual distructor.
};
//=======================================================================================================
// Concrete State Class
/*
1. Each concrete state class inherits from "TrafficLightState" and implements the "change" function.
2. The change function in each state class transitions the TrafficLight instance to the appropriate next state.
*/
class RedLight : public TrafficLightState
{
public:
    void change(TrafficLight *light) override;
    const char *getStateName() const override
    {
        return "RED";
    }
    // create one Instance of the RED light and return it always(Singleton Pattern)
    static TrafficLightState &getInstance()
    {
        static RedLight redLightInstance;
        return redLightInstance;
    }

private:
    RedLight() {}
    // Private constructor to prevent direct instantiation
    // The constructor is private to prevent creating additional instances.
};
class GreenLight : public TrafficLightState
{
public:
    void change(TrafficLight *light) override;
    const char *getStateName() const override
    {
        return "GREEN";
    }
    // create one Instance of the RED light and return it always(Singleton Pattern)
    static TrafficLightState &getInstance()
    {
        static GreenLight greenLightInstance;
        return greenLightInstance;
    }

private:
    GreenLight() {}
};
class YellowLight : public TrafficLightState
{
public:
    void change(TrafficLight *light) override;
    const char *getStateName() const override
    {
        return "YELLOW";
    }
    // create one Instance of the RED light and return it always(Singleton Pattern)
    static TrafficLightState &getInstance()
    {
        static YellowLight yellowLightInstance;
        return yellowLightInstance;
    }

private:
    YellowLight() {}
};
//=========================================================================================================
/*
Traffic Light Class:
----------------------
The TrafficLight class manages the current state of the traffic light.
It has a pointer to the current TrafficLightState and methods to change and set the state.
*/
class TrafficLight
{
public:
    TrafficLight()
    {
        currentState = &RedLight::getInstance();
        printCurrentState();
    }
    void change()
    {
        currentState->change(this);
    }
    void setState(TrafficLightState &newState)
    {
        currentState = &newState;
        printCurrentState();
    }

private:
    void printCurrentState()
    {
        std::cout << "Traffic Light is now: " << currentState->getStateName() << std::endl;
    }
    TrafficLightState *currentState;
};
// ==========================================================================================================
// State Transition Implementation
void RedLight::change(TrafficLight *light)
{
    std::cout << "Light is changing RED -> GREEN " << std::endl;
    light->setState(GreenLight::getInstance());
}
void GreenLight::change(TrafficLight *light)
{
    std::cout << "Light is changing GREEN -> YELLOW " << std::endl;
    light->setState(YellowLight::getInstance());
}

void YellowLight::change(TrafficLight *light)
{
    std::cout << "Light is changing YELLOW -> RED " << std::endl;
    light->setState(RedLight::getInstance());
}
//=================================================================================================
int main()
{
    TrafficLight trafficLight;
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        trafficLight.change();
    }
    return 0;
}
/*output
================
Traffic Light is now: RED
Light is changing RED -> GREEN
Traffic Light is now: GREEN
Light is changing GREEN -> YELLOW
Traffic Light is now: YELLOW
Light is changing YELLOW -> RED
Traffic Light is now: RED
Light is changing RED -> GREEN
Traffic Light is now: GREEN
*/
