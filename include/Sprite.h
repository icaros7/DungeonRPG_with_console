/*
 * ���� ����
 * �ۼ�: 1�� ������, ��ȣ��, ������
 * ����: Sprite.h
 */
#ifndef DUNGEON_SPRITE_H
#define DUNGEON_SPRITE_H

class Sprite {
protected:
    int x, y;       // ���� ��ġ
    char shape;     // ��Ÿ�� ����
    int boardValue; // ���� ũ�� ����

public:
    // ������
    Sprite(int x, int y, char shape, int &value) : x(x), y(y), shape(shape), boardValue(value) {}

    // �Ҹ���
    virtual ~Sprite() {}

    // Virtual ������ move �޼���
    virtual void move(char d) = 0;

    // getter
    char getShape() { return shape; }
    int getX() { return x; }
    int getY() { return y; }

    // ��������Ʈ ������ �浹 ���� �˻� �޼���
    bool checkCollision(Sprite* other);
    bool checkCollision(Sprite* other1, Sprite* other2, Sprite* other);

    // �� �̵� ���� ���� Ȯ�� �޼���
    bool able(int x, int y, int& value);
};

#endif // DUNGEON_SPRITE_H