class Reptile : public Animal {
private:
    bool isVenomous;

public:
    Reptile(string n, int a, bool hungry, bool venom);
    void display() override;
};

