/*
 * ���� ����
 * �ۼ�: 1�� ������, ��ȣ��, ������
 * ����: Board.h
 */
#ifndef DUNGEON_BOARD_H
#define DUNGEON_BOARD_H

#include <iostream>

class Board {
	char* board;        // ���� ���带 ��Ÿ�� ������
	int width, height;  // ���� ������ ����, ����

public:
    // ���� ���� ������
    Board(int value);

    // ���� ���� �Ҹ���
    ~Board() { delete board; }

    // 
    void setValue(int r, int c, char shape) { board[r * width + c] = shape; }

    // ���� ��� �޼���
    void printBoard();

    // ���� �ʱ�ȭ �޼���
    void clearBoard();
};

#endif //DUNGEON_BOARD_H