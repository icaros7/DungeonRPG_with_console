/*
 * ���� ����
 * �ۼ�: 1�� ������, ��ȣ��, ������
 * ����: Hero.cpp
 */
#include "../include/Hero.h"

/// <summary>
/// ���� ��ü ���� �̵� �޼���
/// </summary>
/// <param name="d">����� Ű �Է�</param>
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
/// ���� ��ü �浹 ���� �˻� �޼���
/// </summary>
/// <param name="other">���� ��ü</param>
/// <returns>�浹 ���� ��ȯ</returns>
bool Hero::checkCollision(Enemy* other) {
    if (x == other->getX() && y == other->getY()) { return true; }
    return false;
}