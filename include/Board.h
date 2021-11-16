/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: Board.h
 */
#ifndef DUNGEON_BOARD_H
#define DUNGEON_BOARD_H

#include <iostream>

class Board {
	char* board;        // 게임 보드를 나타낼 포인터
	int width, height;  // 게임 보드의 넓이, 높이

public:
    // 게임 보드 생성자
    Board(int value);

    // 게임 보드 소멸자
    ~Board() { delete board; }

    // 
    void setValue(int r, int c, char shape) { board[r * width + c] = shape; }

    // 보드 출력 메서드
    void printBoard();

    // 보드 초기화 메서드
    void clearBoard();
};

#endif //DUNGEON_BOARD_H