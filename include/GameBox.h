#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <random>
#include <conio.h>

#include "Sprite.h"
#include "Board.h"

using namespace std;

class GameBox
{
private:
	vector<Sprite*> list;
	random_device rd;
	Board* board;

	int width, height;

public:
	GameBox();
	~GameBox();

	// 더 작은 수 반환 메서드
	int smallNum(int x, int y);

	// 실시간 키 입력 메서드
	int getCommand();

	// 게임 시작 메서드
	void gameStart();
};

