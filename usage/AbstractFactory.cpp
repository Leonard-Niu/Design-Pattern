#include <iostream>

class Factory;
class ApFactory;
class BoFactory;

class Apple;
class ApApple;
class BoApple;

class Banana;
class ApBanana;
class BoBanana;

class Fruit {
public:
    Fruit(Apple* apple, Banana* banana) {
        this->mApple = apple;
        this->mBanana = banana;
    }

private:
    Apple* mApple = nullptr;
    Banana* mBanana = nullptr;
};

class Apple {
public:
    virtual void x() = 0;
};

class ApApple : public Apple {
public:
    ApApple() {
        std::cout << "create ApApple" << std::endl;
    }

    virtual void x() {

    }
};

class BoApple : public Apple {
public:
    BoApple() {
        std::cout << "create BoApple" << std::endl;
    }

    virtual void x() {

    }
};

class Banana {
public:
    virtual void x() = 0;
};

class ApBanana : public Banana {
public:
    ApBanana() {
        std::cout << "create ApBanana" << std::endl;
    }

    virtual void x() {

    }
};

class BoBanana : public Banana {
public:
    BoBanana() {
        std::cout << "create BoBanana" << std::endl;
    }

    virtual void x() {
        
    }
};

class Factory {
public:
    // ensure interface stable! hard to add new widget like orange
    virtual Apple* createApple() = 0;
    virtual Banana* createBanana() = 0;

    Fruit* create() {
        return new Fruit(createApple(), createBanana());
    }
};

class ApFactory : public Factory {
public:
    virtual Apple* createApple() {
        return new ApApple();
    }

    virtual Banana* createBanana() {
        return new ApBanana();
    }
};

class BoFactory : public Factory {
public:
    virtual Apple* createApple() {
        return new BoApple();
    }

    virtual Banana* createBanana() {
        return new BoBanana();
    }
};

int main() {
    Factory* factory = new BoFactory();
    Fruit* fruit = factory->create();
    return 0;
}