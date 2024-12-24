#include <iostream>
#include <vector>
#include <string>
class Animal
{
public:
    Animal(std::string name, std::string species) : name(name), species(species) {}
    virtual void displayInfo()
    {
        std::cout << "Name: " << name << ", Species: " << species << std::endl;
    }

protected:
    std::string name;
    std::string species;
};
class Lion : public Animal
{
public:
    Lion(std::string name) : Animal(name, "Lion") {}
    void displayInfo() override