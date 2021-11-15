/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: Enemy.cpp
 */
#include "../include/Enemy.h"

void Enemy::move(int hero_x, int hero_y) {
	if (moveCounter++ % 3 != 0) { return; }
	int result_w = abs(x - hero_x);
	int result_h = abs(y - hero_y);
	if (result_w > result_h) {
		if (x < hero_x) {
			if (able(x + 1, y, boardValue)) { x += 1; }
		}
		else {
			if (able(x - 1, y, boardValue)) { x -= 1; }
		}
	}
	else {
		if (y < hero_y) {
			if (able(x, y + 1, boardValue)) { y += 1; }
		}
		else {
			if (able(x, y - 1, boardValue)) { y -= 1; }
		}
	}
}