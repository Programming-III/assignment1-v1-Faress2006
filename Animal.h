#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string name;
    int age;
    bool isHungry;

public:
    Animal(string n = "", int a = 0, bool hungry = false);
    virtual ~Animal() {}

    virtual void display();
    void feed();

    string getName() const;
    int getAge() const;
    bool getHungry() const;
};

// ---- Subclasses ----

class Mammal : public Animal {
private:
    string furColor;

public:
    Mammal(string n, int a, bool hungry, string color);
    void display() override;
};

class Bird : public Animal {
private:
    float wingSpan;

public:
    Bird(string n, int a, bool hungry, float span);
    void display() override;
};

class Reptile : public Animal {
private:
    bool isVenomous;

public:
    Reptile(string n, int a, bool hungry, bool venom);
    void display() override;
};

#endif

