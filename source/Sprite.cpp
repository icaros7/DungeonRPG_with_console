/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: Sprite.cpp
 */
#include "../include/Sprite.h"

/// <summary>
/// 스프라이트 끼리의 충돌 유무 검사 메서드
/// </summary>
/// <param name="other">Sprite 타입 피검사자</param>
/// <returns>충돌 유무 bool 타입 반환</returns>
bool Sprite::checkCollision(Sprite* other) {
    if (x == other->getX() && y == other->getY()) { return true; }
    else { return false; }
}

/// <summary>
/// 스프라이트 끼리의 충돌 유무 검사 메서드
/// </summary>
/// <param name="other1">Sprite 타입 피검사자1</param>
/// <param name="other2">Sprite 타입 피검사자2</param>
/// <returns></returns>
bool Sprite::checkCollision(Sprite* other1, Sprite* other2, Sprite* other3) {
    if (checkCollision(other1) || checkCollision(other2) || checkCollision(other3)) return true;

    return false;
}

/// <summary>
/// 이동 가능 구역 확인 메서드
/// </summary>
/// <param name="x">int 형 x 좌표</param>
/// <param name="y">int 형 y 좌표</param>
/// <param name="value">int 형 맵 크기</param>
/// <returns></returns>
bool Sprite::able(int x, int y, int& value) {
    if (x < 0 || x >= value || y < 0 || y >= value) {
        return false;
    }
    return true;
}