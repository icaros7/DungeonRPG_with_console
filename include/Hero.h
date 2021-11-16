/*
 * ���� ����
 * �ۼ�: 1�� ������, ��ȣ��, ������
 * ����: Hero.h
 */
#ifndef DUNGEON_HERO_H
#define DUNGEON_HERO_H

#include <iostream>
#include "Sprite.h"
#include "Enemy.h"

class Hero : public Sprite {
public:
    // ���� ��ü ������
    Hero(int x, int y, int &value) : Sprite(x, y, 'H', value) {}

    // ���� ��ü ��� �޼���
    void draw() { std::cout << getShape(); }
    
    // ���� ��ü ���� �̵� �޼���
    void move(char d);

    // ���� ��ü �浹 ���� �˻� �޼���
    bool checkCollision(Enemy* other);
};

#endif // DUNGEON_HERO_H