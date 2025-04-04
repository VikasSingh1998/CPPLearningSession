// We will create a basic FSM with two states: LightOff and LightOn.
#include <bits/stdc++.h>
using namespace std;
//===================================================================
class Light; // Forward declaration to resolve circular dependency

//====================================================================
// First, we define an abstract LightState class that will act as an interface for all states.
class LightState
{
public:
    virtual void toggle(Light *light) = 0;
    virtual ~LightState(){};
    // By including a virtual destructor in LightState, you ensure that
    // any derived class, like LightOff or LightOn, will have its destructor
    // called properly when deleted through a LightState pointer.
    //=----or we can say----
    // The virtual destructor ensures that derived class destructors are called
    // correctly when a derived object is deleted through a base class pointer.
};
//======================================================================
// now implement the concreate class
/*
 * Next, we define concrete state classes for each light state.
 * Each state class implements the LightState interface and
 * follows the singleton pattern to avoid unnecessary memory allocation.
 */

// create LightOff State
class LightOff : public LightState
{
public:
    void toggle(Light *light) override;
    static LightState &getInstance()
    {
        static LightOff instance; // Only one instance is created and reused
        return instance;
    }
    // The getInstance method implements the Singleton pattern, ensuring only one instance of LightOff exists.

private:
    LightOff() {} // Private constructor to prevent direct instantiation
    // The constructor is private to prevent creating additional instances.
};

// create the light on state
class LightOn : public LightState
{
public:
    void toggle(Light *light) override;
    static LightState &getInstance()
    {
        static LightOn instance;
        return instance;
    }

private:
    LightOn(){}; //
};
// Here we are using the singleton design pattern
/*
 The Singleton pattern ensures that a class has only one instance and
 provides a global point of access to that instance. In the context of
 finite state machines (FSM), it ensures that each state class
 (like LightOff and LightOn) only has one instance throughout the program.
-----------------
Global Access: Provides a global point of access to the state instance,
making it easy to switch states without creating new objects.
-----------------
How SIngleton Class Works
When you declare a static local variable inside a method, that variable
is initialized only once, and its lifetime extends across the entire runtime
of the program. Subsequent calls to the method return the same instance.
---------------------
 */
//===================================================================
// Implement the light class
class Light
{
public:
    // when we will create the oject of the Light class, constructor will be invoked and it will create an instance of Light which will be "OFF" initially.
    Light()
    {
        currentState = &LightOff::getInstance();
        // So, the currentstate of the light is off.
    }
    void toggle()
    {
        currentState->toggle(this); // It will call the toggle method of the current state.
        //"this" is passed as an argumnet, which is a pointer to the current "Light" object.
        // The toggle method of the current state (either LightOff or LightOn) will handle the state transition by changing the currentState.
    }
    void setState(LightState &newState)
    {
        currentState = &newState;
    }

private:
    LightState *currentState; // It is pointer to the currentstate of the light.
    // This pointer allows the "Light" object to call the appropriate state toggle method.
};
/**
 * "Light" is the context class that maintains a reference to the current state (currentState).
 * The constructor initializes the "currentState" to "LightOff's" instance.
 * "toggle" delegates the state transition to the current state's toggle method.
 */
//====================================================================
// State Method Implementations

// WHen Light is OFF --> then if we will toggel --> Light will be ON.
void LightOff::toggle(Light *light)
{
    std::cout << "Light is now ON" << std::endl;
    light->setState(LightOn::getInstance());
    // Calls the setState method of the Light object.
    // Passes the singleton instance of LightOn as the new state.
    // The Light object’s currentState is updated to point to the LightOn instance, effectively changing the state from LightOff to LightOn.
}

// When Light is ON -> then if will toggle --> then Light will be "ON".
void LightOn::toggle(Light *light)
{
    std::cout << "Light is now OFF" << std::endl;
    light->setState(LightOff::getInstance());
}
/*
LightOff::toggle changes the state to LightOn.
LightOn::toggle changes the state back to LightOff.
*/
// ==============================================
int main()
{
    Light light;
    light.toggle(); // Turns the light on
    light.toggle(); // Turns the light off
    return 0;
}
/*
Output
==========
Light is now ON
Light is now OFF
*/
/*
Code flow
==========
A Light object is created, initializing its state to LightOff.
Calling light.toggle() on the Light object switches its state to LightOn.
Calling light.toggle() again switches its state back to LightOff.
---------------------------------
*/

