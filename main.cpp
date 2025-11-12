#include <iostream>
#include "Animal.h"
#include "Enclosure.h"
#include "Visitor.h"
using namespace std;


Animal::Animal(string n, int a, bool hungry) {
    name = n;
    age = a;
    isHungry = hungry;
}

void Animal::display() {
    cout << "Name: " << name << ", Age: " << age
         << ", Hungry: " << (isHungry ? "Yes" : "No") << endl;
}

void Animal::feed() {
    if (isHungry) {
        cout << name << " is being fed. Now it's not hungry.\n";
        isHungry = false;
    } else {
        cout << name << " is not hungry.\n";
    }
}

string Animal::getName() const { return name; }
int Animal::getAge() const { return age; }
bool Animal::getHungry() const { return isHungry; }

Mammal::Mammal(string n, int a, bool hungry, string color)
    : Animal(n, a, hungry) {
    furColor = color;
}

void Mammal::display() {
    Animal::display();
    cout << "Type: Mammal, Fur Color: " << furColor << endl;
    cout << "----------------------------------\n";
}

Bird::Bird(string n, int a, bool hungry, float span)
    : Animal(n, a, hungry) {
    wingSpan = span;
}

void Bird::display() {
    Animal::display();
    cout << "Type: Bird, Wing Span: " << wingSpan << " meters" << endl;
    cout << "----------------------------------\n";
}

Reptile::Reptile(string n, int a, bool hungry, bool venom)
    : Animal(n, a, hungry) {
    isVenomous = venom;
}

void Reptile::display() {
    Animal::display();
    cout << "Type: Reptile, Venomous: " << (isVenomous ? "Yes" : "No") << endl;
    cout << "----------------------------------\n";
}

// ===== Enclosure =====
Enclosure::Enclosure(int cap) {
    capacity = cap;
    currentCount = 0;
    animals = new Animal*[capacity];
}

Enclosure::~Enclosure() {
    for (int i = 0; i < currentCount; i++) {
        delete animals[i];
    }
    delete[] animals;
}

void Enclosure::addAnimal(Animal* a) {
    if (currentCount < capacity) {
        animals[currentCount++] = a;
        cout << a->getName() << " added to enclosure.\n";
    } else {
        cout << "Enclosure is full!\n";
    }
}

void Enclosure::displayAnimals() {
    cout << "\n=== Enclosure Animals ===\n";
    for (int i = 0; i < currentCount; i++) {
        animals[i]->display();
    }
}

Visitor::Visitor(string name, int tickets) {
    visitorName = name;
    ticketsBought = tickets;
}

void Visitor::displayInfo() {
    cout << "\n=== Visitor Information ===\n";
    cout << "Visitor Name: " << visitorName << endl;
    cout << "Tickets Bought: " << ticketsBought << endl;
    cout << "===========================\n";
}

int main() {
    Enclosure zoo(3);

    Mammal* m = new Mammal("Lion", 5, true, "Golden");
    Bird* b = new Bird("Eagle", 3, false, 2.5);
    Reptile* r = new Reptile("Cobra", 2, true, true);

    zoo.addAnimal(m);
    zoo.addAnimal(b);
    zoo.addAnimal(r);

    zoo.displayAnimals();

    Visitor v("Fares Abouzeid", 2);
    v.displayInfo();

    return 0;
}
