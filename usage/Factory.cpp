#include <iostream>
#include <memory>

class Car {
public:
    virtual void Brand() = 0;
};

class TeslaCar : public Car {
public:
    virtual void Brand() override {
        std::cout << "Brand Tesla" << std::endl;
    }
};

class BYDCar : public Car {
public:
    virtual void Brand() override {
        std::cout << "Brand BYD" << std::endl;
    }
};

class ICarFactory {
public:
    virtual Car* create() = 0;

    void destory(Car* car) {
        if (car != nullptr) {
            delete car;
            car = nullptr;
        }
    }
};

class BYDCarFactory : public ICarFactory {
public:
    Car* create() override {
        return new BYDCar();
    }
};

class TeslaCarFactory : public ICarFactory {
public:
    Car* create() override {
        return new TeslaCar();
    }
};

template<typename T>
class CarFactory {
public:
    Car* create() {
        return new T();
    }

    void destory(T* car) {
        if (car != nullptr) {
            delete car;
            car = nullptr;
        }
    }
};

void test1() {
    ICarFactory* fac1 = new BYDCarFactory();
    Car* car1 = fac1->create();

    ICarFactory* fac2 = new TeslaCarFactory();
    Car* car2 = fac2->create();

    fac1->destory(car1);
    fac2->destory(car2);

    CarFactory<BYDCar>* fac = new CarFactory<BYDCar>();
    Car* car = fac->create();
}

int main() {
    test1();
    return 0;
}