#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <conio.h>

using namespace std;

chrono::milliseconds oneFrame(300);
chrono::milliseconds a(2000);

class Robot {
    public:
        int l;
        int c;
        int dir;
        char icon;

        Robot() {
            l = 8;
            c = 4;
            dir = 0;
            icon = 'C';
        }

        void MoveUp() {
            l--;
            dir = 1;
        }
        void MoveLeft() {
            c--;
            dir = 2;
        }
        void MoveDown() {
            l++;
            dir = 3;
        }
        void MoveRight() {
            c++;
            dir = 4;
        }
};

int main() {
    start:
    Robot robot;
    vector< pair<int, int> > coords;
    int dist = 0;
    char maze[10][10] = { {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                          {'*', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '*'},
                          {'*', ' ', ' ', ' ', '.', ' ', ' ', ' ', ' ', '*'},
                          {'*', '.', '.', '.', '.', ' ', ' ', ' ', ' ', '*'},
                          {'*', '.', ' ', ' ', '.', ' ', '.', '.', '.', '*'},
                          {'*', '.', ' ', ' ', '.', ' ', '.', ' ', '.', '*'},
                          {'*', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
                          {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '*'},
                          {'*', ' ', ' ', ' ', '.', '.', '.', '.', '.', '*'},
                          {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'} };

    while (true) {
        system("cls");

        if (coords.size() > 0) {
            maze[coords[coords.size() - 1].first][coords[coords.size() - 1].second] = '.';
        }

        maze[robot.l][robot.c] = robot.icon;
        coords.push_back(make_pair(robot.l, robot.c));

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << maze[i][j] << ' ';
            }
            cout << endl;
        }

        cout << endl;
        cout << coords[coords.size() - 1].second << ", " << coords[coords.size() - 1].first << endl;
        cout << endl;

        if (robot.dir == 1) {
            if (maze[robot.l][robot.c - 1] == '.' && maze[robot.l][robot.c - 1] != '*') {
                robot.MoveLeft();
            }
            else if (maze[robot.l - 1][robot.c] == '.' && maze[robot.l - 1][robot.c] != '*' || maze[robot.l - 1][robot.c] == '#') {
                robot.MoveUp();
            }
            else if (maze[robot.l][robot.c + 1] == '.' && maze[robot.l][robot.c + 1] != '*') {
                robot.MoveRight();
            }
            else if (maze[robot.l + 1][robot.c] == '.' && maze[robot.l + 1][robot.c] != '*') {
                robot.MoveDown();
            }
        }
        else if (robot.dir == 2) {
            if (maze[robot.l + 1][robot.c] == '.' && maze[robot.l + 1][robot.c] != '*') {
                robot.MoveDown();
            }
            else if (maze[robot.l][robot.c - 1] == '.' && maze[robot.l][robot.c - 1] != '*') {
                robot.MoveLeft();
            }
            else if (maze[robot.l - 1][robot.c] == '.' && maze[robot.l - 1][robot.c] != '*') {
                robot.MoveUp();
            }
            else if (maze[robot.l][robot.c + 1] == '.' && maze[robot.l][robot.c + 1] != '*') {
                robot.MoveRight();
            }
        }
        else if (robot.dir == 3) {
            if (maze[robot.l][robot.c + 1] == '.' && maze[robot.l][robot.c + 1] != '*') {
                robot.MoveRight();
            }
            else if (maze[robot.l + 1][robot.c] == '.' && maze[robot.l + 1][robot.c] != '*') {
                robot.MoveDown();
            }
            else if (maze[robot.l][robot.c - 1] == '.' && maze[robot.l][robot.c - 1] != '*') {
                robot.MoveLeft();
            }
            else if (maze[robot.l - 1][robot.c] == '.' && maze[robot.l - 1][robot.c] != '*') {
                robot.MoveUp();
            }
        }
        else if (robot.dir == 4) {
            if (maze[robot.l - 1][robot.c] == '.' && maze[robot.l - 1][robot.c] != '*') {
                robot.MoveUp();
            }
            else if (maze[robot.l][robot.c + 1] == '.' && maze[robot.l][robot.c + 1] != '*') {
                robot.MoveRight();
            }
            else if (maze[robot.l + 1][robot.c] == '.' && maze[robot.l + 1][robot.c] != '*') {
                robot.MoveDown();
            }
            else if (maze[robot.l][robot.c - 1] == '.' && maze[robot.l][robot.c - 1] != '*') {
                robot.MoveLeft();
            }
        }
        else if (robot.dir == 0) {
            if (maze[robot.l][robot.c - 1] == '.' && maze[robot.l][robot.c - 1] != '*') {
                robot.MoveLeft();
            }
            else if (maze[robot.l + 1][robot.c] == '.' && maze[robot.l + 1][robot.c] != '*') {
                robot.MoveDown();
            }
            else if (maze[robot.l][robot.c + 1] == '.' && maze[robot.l][robot.c + 1] != '*') {
                robot.MoveRight();
            }
            else if (maze[robot.l - 1][robot.c] == '.' && maze[robot.l - 1][robot.c] != '*') {
                robot.MoveUp();
            }
        }

        if (maze[robot.l][robot.c] == '#') {
            robot.l = 8;
            robot.c = 4;
        }

        this_thread::sleep_for(oneFrame);
    }

    return 0;
}
