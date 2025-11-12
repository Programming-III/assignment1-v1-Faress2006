class Mammal : public Animal {
private:
    string furColor;

public:
    Mammal(string n, int a, bool hungry, string color);
    void display() override;
};
