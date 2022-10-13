#include <iostream>

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

int main() {
    ISaladBuilder* saladBuilder1 = new SaladBuilder1();
    Salad* salad = SaladDirector::construct(saladBuilder1);
    return 0;
}
