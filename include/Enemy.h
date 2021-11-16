/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: Enemy.h
 */
#ifndef DUNGEON_ENEMY_H
#define DUNGEON_ENEMY_H

#include <iostream>
#include "Sprite.h"

class Enemy : public Sprite {
    int moveCounter = 0; // 영웅 이동 회수 기록 변수

public:
    // 괴물 객체 생성자
    Enemy(int x, int y, int& value) : Sprite(x, y, 'E', value) {}

    // Sprite 가상 메서드
    void move(char d) {}

    // 괴물 객체 동적 이동 메서드
    void move(int hero_x, int hero_y);
};

#endif // DUNGEON_ENEMY_H