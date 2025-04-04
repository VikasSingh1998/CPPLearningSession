#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

// define the state
enum class TrafficLightState
{
    Red,
    Green,
    Yellow
    // we can treate Red, Green and Yellow as different state.
};

class TrafficLight
{
private:
    TrafficLightState state;

public:
    // when we will create the object of the TrafficLight, its state will be set to red.
    // This ensures that the traffic light starts in the Red state by default.
    TrafficLight()
    {
        state = TrafficLightState::Red;
    }

    // now we have to update the state of the traffic light
    void update()
    {
        switch (state)
        {
        case TrafficLightState::Red:
        {
            cout << "Red Light is ON" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
            state = TrafficLightState::Green;
            break;
        }

        case TrafficLightState::Yellow:
        {
            cout << "Yellow Light is ON" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
            state = TrafficLightState::Red;
            break;
        }

        case TrafficLightState::Green:
        {
            cout << "Green Light is ON" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
            state = TrafficLightState::Yellow;
            break;
        }
        default:
        {
            break;
        }
        }
    }
};

int main()
{
    TrafficLight light1;
    int i = 0;
    while (i < 5)
    {
        i++;
        light1.update();
    }
    return 0;
}
