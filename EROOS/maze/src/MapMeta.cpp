#include "../include/MapMeta.h"

Room::Room(int id) {
    this->mRoomID = id;
    for (int idx = 0; idx < this->SIDE_NUM; ++idx) {
        this->mSide[idx] = new Wall();
    }
}

IMapSite* Room::getSide(Direction direction) {
    return this->mSide[direction];
}

void Room::setSide(Direction direction, IMapSite* site) {
    this->mSide[direction] = site;
}

void Room::enter() {

}

Wall::Wall() {

}

void Wall::enter() {

}

Door::Door() {
    this->mSrc = nullptr;
    this->mDst = nullptr;
}

Door::Door(Room* src, Room* dst) {
    this->mSrc = src;
    this->mDst = dst;
}

Room* Door::getDstRoom(Room* src) {
    if (src == this->mSrc) {
        return this->mDst;
    } else if (src == this->mDst) {
        return this->mSrc;
    } else {
        return nullptr;
    }
}

void Door::enter() {
    
}