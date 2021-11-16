/*
 * ���� ����
 * �ۼ�: 1�� ������, ��ȣ��, ������
 * ����: Treasure.h
 */
#ifndef DUNGEON_TREASURE_H
#define DUNGEON_TREASURE_H

#include "Sprite.h"

class Treasure : public Sprite {
public:
    // ���� ��ü ������
    Treasure(int x, int y, int& value) : Sprite(x, y, 'T', value) { }

    // ���� ��ü ���� �̵� �޼���
    void move(char d) {}
};

#endif // DUNGEON_TREASURE_H