#pragma once
#include <iostream>
#include <vector>
#include "Field.hpp"

const int height = 7;
const int length = 7;

class PlayingField {

private:
	Field playingField[height][length];

public:
	PlayingField();
	void showField();
	void showEnemiesField();
	void occupyField(int xPos, int yPos);
	Field::State getFieldState(int xPos, int yPos);
	void createField();
	void setFieldState(Field::State newState, int xPos, int yPos);
	int getHeight();
	int getLength();
};