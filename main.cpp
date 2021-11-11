/*
 * 던전 게임
 * 작성: 1팀 강지수, 이호민, 정수빈
 * 
 * 해야할 일
 * - 맵 외부 탈출 제한
 * - 맵 크기 확인 조건문 확인
 * - H move()시 E 위치도 H쪽으로 1칸 이동 구현
 * - isFail bool값 활용
 * 
 * 제안 사항
 * - 맵 스테이지 생성
 * - H의 char 값을 다른 것으로 바꿔보기
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <random>
#include <conio.h>

using namespace std;

class Sprite {
protected:
    int x, y;       // 현재 위치
    char shape;     // 나타낼 문자

public:
    /// 생성자
    Sprite(int x, int y, char shape) : x(x), y(y), shape(shape) {}

    /// 소멸자
    virtual ~Sprite() {}

    /// Virtual 형태의 move 메서드
    /// \param d
    virtual void move(char d) = 0;

    // getter
    char getShape() { return shape; }
    int getX() { return x; }
    int getY() { return y; }

    /// 스프라이트 끼리의 충돌 유무 검사 메서드
    /// \param other Sprite 타입 피검사자
    /// \return 충돌 유무 bool 타입 반환
    bool checkCollision(Sprite* other) {
        if (x == other->getX() && y == other->getY()) { return true; }
        else { return false; }
    }
    bool checkCollision(Sprite* other1, Sprite* other2, Sprite* other3) {
        if (checkCollision(other1) || checkCollision(other2) || checkCollision(other3)) return true;

        return false;
    }
};

class Hero : public Sprite {
public:
    /// 영웅 객체 생성자
    /// \param x 영웅 객체 x 위치
    /// \param y 영웅 객체 y 위치
    Hero(int x, int y) : Sprite(x, y, 'H') {}

    /// 영웅 객체 출력 메서드
    void draw() { cout << getShape(); }

    /// 영웅 객체 정적 이동 메서드
    /// \param d 사용자 키 입력
    void move(char d) {
        switch (d) {
        case 'a':
            x -= 1;
            break;
        case 'w':
            y -= 1;
            break;
        case 's':
            y += 1;
            break;
        case 'd':
            x += 1;
            break;
        }
    }
};

class Treasure : public Sprite {
public:
    /// 보물 객체 생성자
    /// \param x 보물 객체 x 위치
    /// \param y 보물 객체 y 위치
    Treasure(int x, int y) : Sprite(x, y, 'T') { }

    /// 보물 객체 동적 이동 메서드
    /// \param d 사용자 키 입력
    void move(char d) {}
};

class Enemy : public Sprite {
public:
    /// 괴물 객체 생성자
    /// \param x 괴물 객체 x 위치
    /// \param y 괴물 객체 y 위치
    Enemy(int x, int y) : Sprite(x, y, 'E') { }

    /// 괴물 객체 동적 이동 메서드
    /// \param d 사용자 키 입력
    void move(char d) {
    } // TODO: 랜덤 이벤트 발생
};

class Trap : public Sprite {
public:
    /// 함정 객체 생성자
    /// \param x 보물 객체 x 위치
    /// \param y 보물 객체 y 위치
    Trap(int x, int y) : Sprite(x, y, 'T') { }

    /// 보물 객체 동적 이동 메서드
    /// \param d 사용자 키 입력
    void move(char d) {}
};

class Board {
    char* board;        // 게임 보드를 나타낼 포인터
    int width, height;  // 게임 보드의 넓이, 높이

public:
    /// 게임 보드 생성자
    /// \param w 게임 보드의 int 형 넓이
    /// \param h 게임 보드의 int 형 높이
    Board(int w, int h) : width(w), height(h) {
        board = new char[width * height];   // 새 보드 생성
        clearBoard();                       // 보드 초기화
    }

    ~Board() { delete board; } // 동적 메모리 할당 해제 소멸자

    ///
    /// \param r
    /// \param c
    /// \param shape
    void setValue(int r, int c, char shape) { board[r * width + c] = shape; }

    /// 보드 출력 메서드
    void printBoard() {
        for (int i = 0; i < height; i++) {
            cout << "\t";
            for (int j = 0; j < width; j++) { cout << board[i * width + j]; }
            cout << endl;
        }
    }

    /// 보드 초기화 메서드
    void clearBoard() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) { board[i * width + j] = '.'; }
        }
    }
};

int smallNum(int x, int y) {
    if (x >= y) return y;
    else return x;
}

int getCommand() {
    if (_kbhit()) {
        return _getch();
    }

    return -1;
}

int main() {
    vector<Sprite*> list;  // 전체 스프라이트 리스트 저장용 포인터 저장 벡터
    int width, height;      // 게임 보드 초기화 용 입력 버퍼 변수
    random_device rd;       // 난수 생성을 위한 random_device 객체
    mt19937 gen(rd());      // 32비트 난수 생성 엔진 초기화

    do {
        cout << "보드 크기를 입력 하시오 (최대 값 30)" << endl;

        cout << "가로: ";
        cin >> width;
        cout << "세로: ";
        cin >> height;

        cout << endl;
    } while ((width < 0 || width > 31) && (height < 0 || height > 31));

    uniform_int_distribution<int> distr(0, smallNum(width - 1, height - 1)); // 난수 생성 분포 설정

    Board board(height, width);                                     // 새로운 게임 보드 생성
    do { // TODO: while 조건문 수정
        for (auto& e : list) { delete e; }
        list.clear();
        list.push_back(new Hero(distr(gen), distr(gen)));           // 영웅 객체 랜덤 위치 생성
        list.push_back(new Treasure(distr(gen), distr(gen)));       // 보물 객체 랜덤 위치 생성
        list.push_back(new Enemy(distr(gen), distr(gen)));          // 괴물 객체 랜덤 위치 생성
        list.push_back(new Trap(distr(gen), distr(gen)));           // 함정 객체 랜덤 위치 생성
    } while (list[0]->checkCollision(list[1], list[2], list[3]));     // 각자의 위치가 겹치지 않을 때 탈출

    system("cls"); // 콘솔 출력창 초기화
    cout << "이 게임의 목표는 함정(T)이나 괴물(E)를 만나지 않고 보물(T)에 도달 하는 것이다.";
    cout << "함정과 보물은 같은 문자 (T)로 표현 되므로 50%의 확률로 신중하게 선택을 해야한다.\n" << endl;
    cout << "주인공은 a, s, d, w키를 이용하여 움직일 수 있다.\n" << endl;

    system("pause"); // press key to continue

    bool isFail; // 게임 실패 유무 확인
    do {
        system("cls"); // 콘솔 출력창 초기화

        board.clearBoard();
        for (auto& e : list) { board.setValue(e->getY(), e->getX(), e->getShape()); }
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

        // TODO: isFail 유무를 통하여 단순 break; 가 아닌 다음 스테이 진행시 활용하기
        if (list[0]->checkCollision(list[1])) {
            system("cls");
            cout << "-----------------" << endl;
            cout << "성공하였습니다!" << endl;
            cout << "-----------------" << endl;
            system("pause");
            break;
        }

        if (list[0]->checkCollision(list[2])) {
            system("cls");
            cout << "-----------------" << endl;
            cout << "죽었습니다!" << endl;
            cout << "-----------------" << endl;
            system("pause");
            break;
        }
        if (list[0]->checkCollision(list[3])) {
            system("cls");
            cout << "-----------------" << endl;
            cout << "죽었습니다!" << endl;
            cout << "-----------------" << endl;
            system("pause");
            break;
        }

        isFail = false;
    } while (!isFail);

    for (auto& e : list) { delete e; }
    list.clear();
    return 0;
}
