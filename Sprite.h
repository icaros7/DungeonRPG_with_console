/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: Sprite.h
 */
#pragma once

class Sprite {
protected:
    int x, y;       // 현재 위치
    char shape;     // 나타낼 문자

public:
    // 생성자
    Sprite(int x, int y, char shape) : x(x), y(y), shape(shape) {}

    // 소멸자
    virtual ~Sprite() {}

    // Virtual 형태의 move 메서드
    virtual void move(char d) = 0;

    // getter
    char getShape() { return shape; }
    int getX() { return x; }
    int getY() { return y; }

    // 스프라이트 끼리의 충돌 유무 검사 메서드
    bool checkCollision(Sprite* other);
    bool checkCollision(Sprite* other1, Sprite* other2, Sprite* other3);
};