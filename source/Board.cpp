/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: Board.cpp
 */
#include "../include/Board.h"

/// <summary>
/// 보드 객체 생성자
/// </summary>
/// <param name="w">int 형 보드 가로 크기</param>
/// <param name="h">int 형 보드 세로 크기</param>
Board::Board(int value) : width(value), height(value) {
    board = new char[width * height];   // 새 보드 생성
    clearBoard();                       // 보드 초기화
}

/// <summary>
/// 보드 출력 메서드
/// </summary>
void Board::printBoard() {
    for (int i = 0; i < height; i++) {
        std::cout << "\t";
        for (int j = 0; j < width; j++) { std::cout << board[i * width + j]; }
        std::cout << std::endl;
    }
}

/// <summary>
/// 보드 지우기 메서드
/// </summary>
void Board::clearBoard() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) { board[i * width + j] = '.'; }
    }
}