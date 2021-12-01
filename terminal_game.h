#ifndef TERMINALGAME_H
#define TERMINALGAME_H

#include <iostream>
#include <string>
#include <vector>
#include "terminal_text.h"
#include "terminal_game.h"

struct CVec {
    int x;
    int y;
    CVec();
    CVec(int, int);
    void operator += (CVec);
    void operator -= (CVec);
    CVec operator + (CVec);
    CVec operator - (CVec);
    void operator = (CVec);
};

struct MovableObject {
    CVec position;
    MovableObject(int);
    MovableObject(int, CVec);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    protected:
        int bounds;
};

struct Field {
    Field(int);
    void drawField();
    void addCharacters(std::vector<std::vector<CVec>>, std::vector<std::string>);
    std::string getAt(CVec);
    protected:
        std::string empty = ".";
        int bounds;
        std::vector<std::vector<std::string>> field;
};

#endif