#include <iostream>

class Charger35V {
public:
    virtual void charge35V() {
        std::cout << "charge with 35V" << std::endl;
    }
};

class Charger5V {
public:
    void charge5V() {
        std::cout << "charge with 5V" << std::endl;
    }
};

class Charger : public Charger35V {
public:
    Charger() {
        if (mCharger5V == nullptr) {
            mCharger5V = new Charger5V();
        }
    }

    void charge35V() override {
        std::cout << "voltage step down to 5V" << std::endl;
        mCharger5V->charge5V();
    }

private:
    Charger5V* mCharger5V = nullptr;
};

int main() {
    Charger35V* charger = new Charger();
    charger->charge35V();
    return 0;
}