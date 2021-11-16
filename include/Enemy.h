/*
 * ���� ����
 * �ۼ�: 1�� ������, ��ȣ��, ������
 * ����: Enemy.h
 */
#ifndef DUNGEON_ENEMY_H
#define DUNGEON_ENEMY_H

#include <iostream>
#include "Sprite.h"

class Enemy : public Sprite {
    int moveCounter = 0; // ���� �̵� ȸ�� ��� ����

public:
    // ���� ��ü ������
    Enemy(int x, int y, int& value) : Sprite(x, y, 'E', value) {}

    // Sprite ���� �޼���
    void move(char d) {}

    // ���� ��ü ���� �̵� �޼���
    void move(int hero_x, int hero_y);
};

#endif // DUNGEON_ENEMY_H