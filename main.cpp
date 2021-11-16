/*
 * ���� ����
 * �ۼ�: 1�� ������, ��ȣ��, ������
 * ����: main.cpp
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <random>
#include <conio.h>

#include "include/Sprite.h"
#include "include/Hero.h"
#include "include/Treasure.h"
#include "include/Trap.h"
#include "include/Board.h"

using namespace std;

// �� �� �� ���� �� ��ȯ �޼���
int smallNum(int x, int y) {
    if (x >= y) return y;
    else return x;
}

// �ǽð� Ű �Է��� ���� conio.h/_kbhit �޼��� ���
int getCommand() {
    if (_kbhit()) {
        return _getch();
    }

    return -1;
}

// ��� ��� �޼���
void printResult(int resultCode) {
    string result = resultCode == 0 ? "�����ϼ̽��ϴ�!" : "�����ϼ̽��ϴ�...";

    system("cls");
    cout << "-----------------" << endl;
    cout << result << endl;
    cout << "-----------------" << endl;
    system("pause");
}

// ���� �޸� �Ҵ� ���� �޼���
void deleteFor(vector<Sprite*>& list, vector<Enemy*>& eList) {
    for (auto& e : list) { delete e; }
    for (auto& e : eList) { delete e; }
    list.clear();
    eList.clear();
}

// ���� ��� �޼���
void printHelp() {
    system("cls");      // �ܼ� ���â �ʱ�ȭ
    cout << "�� ������ ��ǥ�� ����(T)�̳� ����(E)�� ������ �ʰ� ����(T)�� ���� �ϴ� ���̴�." << endl;
    cout << "������ ������ ���� ���� (T)�� ǥ�� �ǹǷ� 50%�� Ȯ���� �����ϰ� ������ �ؾ��Ѵ�." << endl;
    cout << "������ ���ΰ��� 3���� �����̸� 1�� ���ΰ��� ���� �����δ�.\n" << endl;
    cout << "���ΰ��� a, s, d, wŰ�� �̿��Ͽ� ������ �� �ִ�.\n" << endl;
    system("pause");    // press key to continue
}

// ��Ʈ�� ��� �޼���
void printIntro() {
    cout << "����������������������������������������������������������������������������������" << endl;
    cout << "��\t����RPG ����\t\t\t��" << endl;
    cout << "��\t\t\t\t\t��" << endl;
    cout << "��\t����: ������, ��ȣ��, ������\t��" << endl;
    cout << "����������������������������������������������������������������������������������" << endl;
    system("pause");
}

int main() {
    vector<Sprite*> list;   // ��ü ��������Ʈ ����Ʈ ����� ������ ���� ����
    vector<Enemy*> eList;   // ���� ��ü ����Ʈ ����� ������ ���� ����
    int value;              // ���� ���� �ʱ�ȭ �� �Է� ���� ����
    char direction;         // Ű �Է� �� �Է� ���� ����
    random_device rd;       // ���� ������ ���� random_device ��ü
    mt19937 gen(rd());      // 32��Ʈ ���� ���� ���� �ʱ�ȭ

    printIntro();
    printHelp();

    do {
        cout << "���� ũ�⸦ �Է� �Ͻÿ� (�ּ� 9, �ִ� 21): ";
        cin >> value;
    } while (value > 21 || value < 9);

    Board board(value);                                // ���ο� ���� ���� ����
    uniform_int_distribution<int> distr(0, value - 1); // ���� ���� ���� ����
    do {
        deleteFor(list, eList);
        list.push_back(new Hero(distr(gen), distr(gen), value));            // ���� ��ü ���� ��ġ ����
        list.push_back(new Treasure(distr(gen), distr(gen), value));        // ���� ��ü ���� ��ġ ����
        list.push_back(new Trap(distr(gen), distr(gen), value));            // ���� ��ü ���� ��ġ ����
        for (int i = 0; i < ((value * 21) / 81); i++) { eList.push_back(new Enemy(distr(gen), distr(gen), value));}
    } while (list[0]->checkCollision(list[1], list[2], eList[0]));          // ������ ��ġ�� ��ġ�� ���� �� Ż��

    while (true) {
        system("cls");  // �ܼ� ���â �ʱ�ȭ

        board.clearBoard();
        for (auto& e : list) { board.setValue(e->getY(), e->getX(), e->getShape()); }
        for (auto& e : eList) { board.setValue(e->getY(), e->getX(), e->getShape()); }
        board.printBoard();

        cout << "\n����Ű: w ����, s �Ʒ���, a ��������, d ����������, c ����";
        while(true) {
            direction = getCommand();

            if (!(direction == 'a' || direction == 's' || direction == 'd' || direction == 'w' || direction == 'c')) { continue; }
            else break;
        }

        if (direction == 'c') { break; }
        for (auto& e : list) { e->move(direction); }
        for (auto& e : eList) { e->move(list[0]->getX(), list[0]->getY()); }

        // TODO: break�� �ƴ� ���� ������ ����� Ȱ���ϱ�
        if (list[0]->checkCollision(list[1])) { printResult(0); break; }
        if (list[0]->checkCollision(list[2])) { printResult(1); break; }
        for (auto& i : eList) {
            if (list[0]->checkCollision(i)) { printResult(1); break; }
        }
    };

    deleteFor(list, eList);
    return 0;
}
