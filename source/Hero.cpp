/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: Hero.cpp
 */
#include "../include/Hero.h"

/// <summary>
/// 영웅 객체 정적 이동 메서드
/// </summary>
/// <param name="d">사용자 키 입력</param>
void Hero::move(char d) {
    switch (d) {
    case 'a':
        if (able(x - 1, y, boardValue)) { x -= 1; }
        break;
    case 'w':
        if (able(x, y - 1, boardValue)) { y -= 1; }
        break;
    case 's':
        if (able(x, y + 1, boardValue)) { y += 1; }
        break;
    case 'd':
        if (able(x + 1, y, boardValue)) { x += 1; }
        break;
    }
}

/// <summary>
/// 괴물 객체 충돌 유무 검사 메서드
/// </summary>
/// <param name="other">괴물 객체</param>
/// <returns>충돌 유무 반환</returns>
bool Hero::checkCollision(Enemy* other) {
    if (x == other->getX() && y == other->getY()) { return true; }
    return false;
}