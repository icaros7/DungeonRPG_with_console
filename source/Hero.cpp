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
/// 이동 가능 구역 확인 메서드
/// </summary>
/// <param name="x">int 형 x 좌표</param>
/// <param name="y">int 형 y 좌표</param>
/// <param name="value">int 형 맵 크기</param>
/// <returns></returns>
bool Hero::able(int x, int y, int &value) {
    if (x < 0 || x >= value || y < 0 || y >= value) {
        return false;
    }
    return true;
}