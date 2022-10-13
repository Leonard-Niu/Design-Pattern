#include <iostream>

using namespace std;

class Apple {

};

class Apple1 : public Apple {
public:
    Apple1() {
        std::cout << "Apple1" << std::endl;
    }
};

class Apple2 : public Apple {
public:
    Apple2() {
        std::cout << "Apple2" << std::endl;
    }
};

class Banana {

};

class Banana1 : public Banana {
public:
    Banana1() {
        std::cout << "Banana1" << std::endl;
    }
};

class Banana2 : public Banana {
public:
    Banana2() {
        std::cout << "Banana2" << std::endl;
    }
};

// product
class Salad {
public:
    void setApple(Apple* apple) {
        mApple = apple;
    }

    void setBanana(Banana* banana) {
        mBanana = banana;
    }

private:
    Apple* mApple = nullptr;
    Banana* mBanana = nullptr;
};

// builder
class ISaladBuilder {
public:
    virtual void buildApple() = 0;
    virtual void buildBanana() = 0;

    Salad* build() {
        return mSalad;
    }

protected:
    Salad* mSalad = nullptr;
};

class SaladBuilder1 : public ISaladBuilder {
public:
    SaladBuilder1() {
        mSalad = new Salad();
    }

    virtual void buildApple() {
        mSalad->setApple(new Apple1());
    }

    virtual void buildBanana() {
        mSalad->setBanana(new Banana1());
    }
};

// director
class SaladDirector {
public:
    static Salad* construct(ISaladBuilder* saladBuilder) {
        saladBuilder->buildApple();
        saladBuilder->buildBanana();
        return saladBuilder->build();
    }
};

void SaladTest() {
    ISaladBuilder* saladBuilder1 = new SaladBuilder1();
    Salad* salad = SaladDirector::construct(saladBuilder1);
}

class Car {
public:
    void setCamera(string camera) {
        mCamera = camera;
    }
    
    void setEngine(string engine) {
        mEngine = engine;
    }

    void setBrand(string brand) {
        mBrand = brand;
    }
private:
    std::string mCamera;
    std::string mEngine;
    std::string mBrand;
};

class ICarBuilder {
public:
    ICarBuilder() {
        mCar = new Car();
    }

    virtual void buildCamera() = 0;
    virtual void buildEngine() = 0;
    virtual void buildBrand() = 0;

    Car* build() {
        return mCar;
    }

protected:
    Car* mCar;
};

class ElecCarBuilder : public ICarBuilder {
public:
    virtual void buildEngine() {
        mCar->setEngine("Electirc Car");
    }
};

class GasCarBuilder : public ICarBuilder {
public:
    virtual void buildEngine() {
        mCar->setEngine("Gasoline Car");
    }
};

class BYDCarBuilder : public ElecCarBuilder {
public:
    virtual void buildBrand() {
        mCar->setBrand("BYD");
    }
};

class BYDKhanCarBuilder : public BYDCarBuilder {
public:
    virtual void buildCamera() {
        mCar->setCamera("unsupported");
    }
};

class CarDirector {
public:
    static Car* construct(ICarBuilder* carBuilder) {
        carBuilder->buildBrand();
        carBuilder->buildCamera();
        carBuilder->buildEngine();
        return carBuilder->build();
    }
};

void CatTest() {
    ICarBuilder* carBuidler = new BYDKhanCarBuilder();
    Car* car = CarDirector::construct(carBuidler);
}

int main() {
    CatTest();
    return 0;
}
