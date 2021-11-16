/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: Trap.h
 */
#ifndef DUNGEON_TRAP_H
#define DUNGEON_TRAP_H

#include "Sprite.h"

class Trap : public Sprite {
public:
    // 보물 객체 생성자
    Trap(int x, int y, int &value) : Sprite(x, y, 'T', value) { }

    // 보물 객체 이동 메서드
    void move(char d) {}
};

#endif // DUNGEON_TRAP_H