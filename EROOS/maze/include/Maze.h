#pragma once

#include "./MapMeta.h"

class Maze {
public:
    Maze();

    void addRoom(Room* room);
    Room* getRoom(int id) const;
};
