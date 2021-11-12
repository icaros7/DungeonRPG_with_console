/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: Hero.cpp
 */
#include "Hero.h"

/// <summary>
/// 영웅 객체 정적 이동 메서드
/// </summary>
/// <param name="d">사용자 키 입력</param>
void Hero::move(char d) {
    switch (d) {
    case 'a':
        x -= 1;
        break;
    case 'w':
        y -= 1;
        break;
    case 's':
        y += 1;
        break;
    case 'd':
        x += 1;
        break;
    }
}