/*
 * ���� ����
 * �ۼ�: 1�� ������, ��ȣ��, ������
 * ����: Trap.h
 */
#ifndef DUNGEON_TRAP_H
#define DUNGEON_TRAP_H

#include "Sprite.h"

class Trap : public Sprite {
public:
    // ���� ��ü ������
    Trap(int x, int y, int &value) : Sprite(x, y, 'T', value) { }

    // ���� ��ü �̵� �޼���
    void move(char d) {}
};

#endif // DUNGEON_TRAP_H