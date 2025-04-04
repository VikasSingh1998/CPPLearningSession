#include <iostream>
#include <memory>
#include <string>
//=======================================================
class VendingMachine; // Forwared Decleration of class to resolve the circular dependdency.
//=======================================================

class VendingMachineState
{
public:
    virtual void selectItem(VendingMachine *machine, const std::string &item) = 0;
    virtual void insertMoney(VendingMachine *machine, double amount) = 0;
    virtual void dispenseItem(VendingMachine *machine) = 0;
    virtual const char *getStateName() const = 0;
};
//=======================================================
// Concrete state class
class IdleState : public VendingMachineState
{
public:
    void selectItem(VendingMachine *machine, const std::string &item) override;
    void insertMoney(VendingMachine *machine, double amount) override
    {
        std::cout << "NO Item Selecte. Please select an item first." << std::endl;
    }
    void dispenseItem(VendingMachine *machine) override
    {
        std::cout << "NO Item Selecte. Can not dispense." << std::endl;
    }
    const char *getStateName() const override
    {
        return "Idle";
    }
    // create the IdleStateInstance and return it as a singleton instance.
    // we will create only one instance of the IdleState ans use always.
    static VendingMachineState &getInstance()
    {
        static IdleState idle_state_instance;
        return idle_state_instance;
    }

private:
    IdleState() = default;
};

class SelectingItemState : public VendingMachineState
{
public:
    void selectItem(VendingMachine *machine, const std::string &item) override
    {
        std::cout << "Item Selected is : " << item << std::endl;
    }
    void insertMoney(VendingMachine *machine, double amount) override
    {
        std::cout << "NO Item Selecte. Please select an item first." << std::endl;
    }
    void dispenseItem(VendingMachine *machine) override
    {
        std::cout << "NO Item Selecte. Can not dispense." << std::endl;
    }
    const char *getStateName() const override
    {
        return "Selecting Item";
    }
    // create the IdleStateInstance and return it as a singleton instance.
    // we will create only one instance of the IdleState ans use always.
    static VendingMachineState &getInstance()
    {
        static SelectingItemState select_item_state_instance;
        return select_item_state_instance;
    }

private:
    SelectingItemState() = default;
};
//=======================================================
int main()
{

    return 0;
}
