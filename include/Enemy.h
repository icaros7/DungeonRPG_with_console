/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: Enemy.h
 */
#pragma once
#include <iostream>
#include "Sprite.h"

class Enemy : public Sprite {
public:
    // 괴물 객체 생성자
    Enemy(int x, int y) : Sprite(x, y, 'E') {}

    // 괴물 객체 동적 이동 메서드
    void move(char d);
};

