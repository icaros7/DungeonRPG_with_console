/*
 * ���� ����
 * �ۼ�: 1�� ������, ��ȣ��, ������
 * ����: Sprite.cpp
 */
#include "../include/Sprite.h"

/// <summary>
/// ��������Ʈ ������ �浹 ���� �˻� �޼���
/// </summary>
/// <param name="other">Sprite Ÿ�� �ǰ˻���</param>
/// <returns>�浹 ���� bool Ÿ�� ��ȯ</returns>
bool Sprite::checkCollision(Sprite* other) {
    if (x == other->getX() && y == other->getY()) { return true; }
    else { return false; }
}

/// <summary>
/// ��������Ʈ ������ �浹 ���� �˻� �޼���
/// </summary>
/// <param name="other1">Sprite Ÿ�� �ǰ˻���1</param>
/// <param name="other2">Sprite Ÿ�� �ǰ˻���2</param>
/// <returns></returns>
bool Sprite::checkCollision(Sprite* other1, Sprite* other2, Sprite* other3) {
    if (checkCollision(other1) || checkCollision(other2) || checkCollision(other3)) return true;

    return false;
}

/// <summary>
/// �̵� ���� ���� Ȯ�� �޼���
/// </summary>
/// <param name="x">int �� x ��ǥ</param>
/// <param name="y">int �� y ��ǥ</param>
/// <param name="value">int �� �� ũ��</param>
/// <returns></returns>
bool Sprite::able(int x, int y, int& value) {
    if (x < 0 || x >= value || y < 0 || y >= value) {
        return false;
    }
    return true;
}