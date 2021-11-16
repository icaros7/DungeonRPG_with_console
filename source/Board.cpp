/*
 * ���� ����
 * �ۼ�: 1�� ������, ��ȣ��, ������
 * ����: Board.cpp
 */
#include "../include/Board.h"

/// <summary>
/// ���� ��ü ������
/// </summary>
/// <param name="w">int �� ���� ���� ũ��</param>
/// <param name="h">int �� ���� ���� ũ��</param>
Board::Board(int value) : width(value), height(value) {
    board = new char[width * height];   // �� ���� ����
    clearBoard();                       // ���� �ʱ�ȭ
}

/// <summary>
/// ���� ��� �޼���
/// </summary>
void Board::printBoard() {
    for (int i = 0; i < height; i++) {
        std::cout << "\t";
        for (int j = 0; j < width; j++) { std::cout << board[i * width + j]; }
        std::cout << std::endl;
    }
}

/// <summary>
/// ���� ����� �޼���
/// </summary>
void Board::clearBoard() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) { board[i * width + j] = '.'; }
    }
}