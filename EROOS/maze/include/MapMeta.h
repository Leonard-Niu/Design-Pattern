#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

enum Direction {
    North,
    Sorth,
    East,
    West,
};

class IMapSite {
public:
    // site change
    virtual void enter() = 0;
};

class Room:public IMapSite {
public:
    Room(int id);
    IMapSite* getSide(Direction direction);
    void setSide(Direction direction, IMapSite* site);

    virtual void enter();
private:
    static const int SIDE_NUM = 4;
    int mRoomID;
    IMapSite* mSide[4];
};

class Wall:public IMapSite {
public:
    Wall();

    virtual void enter();
};

// two-way
class Door:public IMapSite {
public:
    Door();
    Door(Room* src, Room* dst);
    Room* getDstRoom(Room* src);

    virtual void enter();
private:
    Room* mSrc = nullptr;
    Room* mDst = nullptr;
    bool mIsOpen;
};