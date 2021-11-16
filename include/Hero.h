/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: Hero.h
 */
#ifndef DUNGEON_HERO_H
#define DUNGEON_HERO_H

#include <iostream>
#include "Sprite.h"
#include "Enemy.h"

class Hero : public Sprite {
public:
    // 영웅 객체 생성자
    Hero(int x, int y, int &value) : Sprite(x, y, 'H', value) {}

    // 영웅 객체 출력 메서드
    void draw() { std::cout << getShape(); }
    
    // 영웅 객체 정적 이동 메서드
    void move(char d);

    // 괴물 객체 충돌 유무 검사 메서드
    bool checkCollision(Enemy* other);
};

#endif // DUNGEON_HERO_H