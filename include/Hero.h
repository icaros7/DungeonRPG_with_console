/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: Hero.h
 */
#pragma once
#include <iostream>
#include "Sprite.h"

class Hero : public Sprite {
    int boardValue; // able 메서드 구현을 위한 맵 크기 할당

public:
    // 영웅 객체 생성자
    Hero(int x, int y, int &value) : Sprite(x, y, 'H'), boardValue(value) {}

    // 영웅 객체 출력 메서드
    void draw() { std::cout << getShape(); }
    
    // 영웅 객체 정적 이동 메서드
    void move(char d);

    // 맵 이동 가능 구역 확인 메서드
    bool able(int x, int y, int &value);
};

