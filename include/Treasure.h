/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: Treasure.h
 */
#pragma once
#include "Sprite.h"

class Treasure : public Sprite {
public:
    // 보물 객체 생성자
    Treasure(int x, int y, int& value) : Sprite(x, y, 'T', value) { }

    // 보물 객체 동적 이동 메서드
    void move(char d) {}
};

