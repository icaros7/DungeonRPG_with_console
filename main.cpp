/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 파일: main.cpp
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <random>
#include <conio.h>

#include "include/Sprite.h"
#include "include/Hero.h"
#include "include/Enemy.h"
#include "include/Treasure.h"
#include "include/Trap.h"
#include "include/Board.h"

using namespace std;

/// <summary>
/// 둘 중 더 작은 수 반환 메서드
/// </summary>
/// <param name="x">int 형 값1</param>
/// <param name="y">int 형 값1</param>
/// <returns>int 형 더 작은 값</returns>
int smallNum(int x, int y) {
    if (x >= y) return y;
    else return x;
}

/// <summary>
/// 실시간 키 입력을 위한 conio.h/_kbhit 메서드 사용
/// </summary>
/// <returns>입력 키</returns>
int getCommand() {
    if (_kbhit()) {
        return _getch();
    }

    return -1;
}

void printResult(int resultCode) {
    string result = resultCode == 0 ? "성공하셨습니다!" : "실패하셨습니다...";

    system("cls");
    cout << "-----------------" << endl;
    cout << result << endl;
    cout << "-----------------" << endl;
    system("pause");
}

int main() {
    vector<Sprite*> list;   // 전체 스프라이트 리스트 저장용 포인터 저장 벡터
    vector<Enemy*> eList;
    int value;              // 게임 보드 초기화 용 입력 버퍼 변수
    random_device rd;       // 난수 생성을 위한 random_device 객체
    mt19937 gen(rd());      // 32비트 난수 생성 엔진 초기화

    do {
        cout << "보드 크기를 입력 하시오 (최소 9, 최대 21): ";
        cin >> value;
    } while (value > 21 || value < 9);

    uniform_int_distribution<int> distr(0, value - 1);              // 난수 생성 분포 설정
    int enemyNum = (value * 21) / 81;

    Board board(value);                                             // 새로운 게임 보드 생성
    do {
        for (auto& e : list) { delete e; }
        for (auto& e : eList) { delete e; }
        list.clear();
        list.push_back(new Hero(distr(gen), distr(gen), value));    // 영웅 객체 랜덤 위치 생성
        list.push_back(new Treasure(distr(gen), distr(gen), value));       // 보물 객체 랜덤 위치 생성
        list.push_back(new Trap(distr(gen), distr(gen), value));           // 함정 객체 랜덤 위치 생성
        for (int i = 0; i < enemyNum; i++) { eList.push_back(new Enemy(distr(gen), distr(gen), value));}
    } while (list[0]->checkCollision(list[1], list[2], eList[0]));   // 각자의 위치가 겹치지 않을 때 탈출

    system("cls");      // 콘솔 출력창 초기화
    cout << "이 게임의 목표는 함정(T)이나 괴물(E)를 만나지 않고 보물(T)에 도달 하는 것이다.";
    cout << "함정과 보물은 같은 문자 (T)로 표현 되므로 50%의 확률로 신중하게 선택을 해야한다." << endl;
    cout << "괴물은 주인공이 3번을 움직이면 1번 주인공을 향해 움직인다.\n" << endl;
    cout << "주인공은 a, s, d, w키를 이용하여 움직일 수 있다.\n" << endl;
    system("pause");    // press key to continue

    while (true) {
        system("cls");  // 콘솔 출력창 초기화

        board.clearBoard();
        for (auto& e : list) { board.setValue(e->getY(), e->getX(), e->getShape()); }
        for (auto& e : eList) { board.setValue(e->getY(), e->getX(), e->getShape()); }
        board.printBoard();

        char direction;
        cout << "\n조작키: w 위로, s 아래로, a 왼쪽으로, d 오른쪽으로, c 종료";
        while(true) {
            direction = getCommand();

            if (!(direction == 'a' || direction == 's' || direction == 'd' || direction == 'w' || direction == 'c')) { continue; }
            else break;
        }

        if (direction == 'c') { break; }
        for (auto& e : list) { e->move(direction); }
        for (auto& e : eList) { e->move(list[0]->getX(), list[0]->getY()); }

        // TODO: break가 아닌 다음 스테이 진행시 활용하기
        if (list[0]->checkCollision(list[1])) {
            printResult(0);
            break;
        }
        if (list[0]->checkCollision(list[2])) {
            printResult(1);
            break;
        }
        for (auto& i : eList) {
            if (list[0]->checkCollision(i)) {
                printResult(1);
                break;
            }
        }
    };

    for (auto& e : list) { delete e; }
    for (auto& e : eList) { delete e; }
    list.clear();
    return 0;
}
