#include "../include/MapMeta.h"
#include "../include/Maze.h"
#include "../include/MazeGame.h"

int main(int argc, char **argv) {
    Room *room1 = new Room(1);
    Room *room2 = new Room(2);
    Door *door1_2 = new Door(room1, room2);
    Door *door = new Door();
    return 0;
}