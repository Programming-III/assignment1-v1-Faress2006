class Bird : public Animal {
private:
    float wingSpan;

public:
    Bird(string n, int a, bool hungry, float span);
    void display() override;
};

