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
    {
        std::cout << "Lion - " << name << std::endl;
    }
};
class Elephant : public Animal
{
public:
    Elephant(std::string name) : Animal(name, "Elephant") {}
    void displayInfo() override
    {
        std::cout << "Elephant - " << name << std::endl;
    }
};
class Zoo
{
public:
    void addAnimal(Animal *animal)
    {
        animals.push_back(animal);
    }
    void displayAnimals()
    {
        for (auto animal : animals)
        {
            animal->displayInfo();
        }
    }
    ~Zoo()
    {
        for (auto animal : animals)
        {
            delete animal;
        }
    }

private:
    std::vector<Animal *> animals;
};
int main()
{
    Zoo zoo;
    zoo.addAnimal(new Lion("Simba"));
    zoo.addAnimal(new Elephant("Dumbo"));

    std::cout << "Animals in the Zoo:" << std::endl;
    zoo.displayAnimals();

    return 0;
}