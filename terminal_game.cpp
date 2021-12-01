#include <iostream>
#include <string>
#include <vector>
#include "terminal_text.h"
#include "terminal_game.h"

CVec::CVec() {
    x = 0;
    y = 0;
}

CVec::CVec(int newX, int newY) {
    x = newX;
    y = newY;
} 

void CVec::operator+=(CVec toAdd) {
    x += toAdd.x;
    y += toAdd.y;
}

void CVec::operator-=(CVec toSubtract) {
    x -= toSubtract.x;
    y -= toSubtract.y;
}

CVec CVec::operator+(CVec toAdd) {
    CVec finalValue;
    finalValue.x = x + toAdd.x;
    finalValue.y = y + toAdd.y;
    return finalValue;
}

CVec CVec::operator-(CVec toAdd) {
    CVec finalValue;
    finalValue.x = x - toAdd.x;
    finalValue.y = y - toAdd.y;
    return finalValue;
}

void CVec::operator=(CVec newValue) {
    x = newValue.x;
    y = newValue.y;
}

const CVec left (-1,0);
const CVec right (1,0);
const CVec up (0,-1);
const CVec down (0,1);

MovableObject::MovableObject (int newBounds) {
    bounds = newBounds;
}

MovableObject::MovableObject (int newBounds, CVec startingPosition) {
    bounds = newBounds;
    position = startingPosition;
}

void MovableObject::moveLeft() {
    if (position.x > 0) {
        position += left;
    }
}

void MovableObject::moveRight() {
    if (position.x < bounds-1) {
        position += right;
    }
}

void MovableObject::moveUp() {
    if (position.y > 0) {
        position += up;
    }
}

void MovableObject::moveDown() {
    if (position.y < bounds-1) {
        position += down;
    }
}

Field::Field (int startingBounds) {
    bounds = startingBounds;
    for (int c; c < bounds; c++) {
        std::vector<std::string> column;
        for (int r; r < bounds; r++) {
            column.push_back(empty);
        }
        field.push_back(column);
    }
}

void Field::drawField() {
    std::string outputField = " " + underlined;
    for (int l; l < bounds*2; l++) {
        outputField += " ";
    }
    outputField += toDefault;
    outputField += "\n";
    for (int c; c < bounds; c++) {
        std::vector<std::string> column = field[c];
        outputField += "| ";
        for (int r; r < bounds; r++) {
            outputField += column[r];
            outputField += " ";
        }
        outputField += "|\n";
    }
    outputField += " ";
    outputField += strickenThrough;
    for (int l; l < bounds*2; l++) {
        outputField += " ";
    }
    outputField += toDefault;
    outputField += "\n";
    std::cout << outputField;
}

void Field::addCharacters(std::vector<std::vector<CVec>> positions, std::vector<std::string> characters) {
    for (int t; t < positions.size(); t++) {
        std::vector<CVec> typePositions = positions[t];
        std::string character = characters[t];
        for (int p; p < typePositions.size(); p++) {
            CVec position = typePositions[p];
            field[position.x][position.y] = character;
        }
    }
}

std::string Field::getAt(CVec at) {
    return field[at.x][at.y];
}