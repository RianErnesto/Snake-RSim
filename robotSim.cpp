#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <conio.h>

using namespace std;

chrono::milliseconds oneFrame(300);

class Robot{
    public:
        int l;
        int c;
        int dir;
        char icon;

        Robot(){
            l = 8;
            c = 4;
            dir = 0;
            icon = 'C';
        }

        void MoveUp(){
            l--;
            dir = 1;
        }
        void MoveLeft(){
            c--;
            dir = 2;
        }
        void MoveDown(){
            l++;
            dir = 3;
        }
        void MoveRight(){
            c++;
            dir = 4;
        }
};

//void PrintMaze();

int main(){
    Robot robot;
    vector< pair<int, int> > coords;
    vector< pair<int, int> > possiblePaths;
        char maze[10][10] = {{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                     {'*', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '*'},
                     {'*', ' ', ' ', ' ', '.', ' ', ' ', ' ', ' ', '*'},
                     {'*', '.', '.', '.', '.', ' ', ' ', ' ', ' ', '*'},
                     {'*', '.', ' ', ' ', '.', ' ', '.', '.', '.', '*'},
                     {'*', '.', ' ', ' ', '.', ' ', '.', ' ', '.', '*'},
                     {'*', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
                     {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '*'},
                     {'*', ' ', ' ', ' ', '.', '.', '.', '.', '.', '*'},
                     {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}};

    while(true){
        system("cls");

        if(coords.size() > 0){
            maze[coords[coords.size()-1].first][coords[coords.size()-1].second] = '.';
        }
        

        maze[robot.l][robot.c] = robot.icon;
        coords.push_back(make_pair(robot.l, robot.c));

        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                cout << maze[i][j] << ' ';
            }
            cout << endl;
        }

        cout << endl;
        cout << coords[coords.size()-1].first << ", " << coords[coords.size()-1].second << endl;
        cout << endl;

        if(maze[robot.l-1][robot.c] == '#'){
            break;
        }

        if(robot.dir == 1){
            if(maze[robot.l][robot.c-1] == '.' && maze[robot.l][robot.c-1] != '*'){
                robot.MoveLeft();
            } else if(maze[robot.l-1][robot.c] == '.' && maze[robot.l-1][robot.c] != '*'){
                robot.MoveUp();
            } else if(maze[robot.l][robot.c+1] == '.' && maze[robot.l][robot.c+1] != '*'){
                robot.MoveRight();
            } else if(maze[robot.l+1][robot.c] == '.' && maze[robot.l+1][robot.c] != '*'){
                robot.MoveDown();
            }
        } else if(robot.dir == 2){
            if(maze[robot.l+1][robot.c] == '.' && maze[robot.l+1][robot.c] != '*'){
                robot.MoveDown();
            } else if(maze[robot.l][robot.c-1] == '.' && maze[robot.l][robot.c-1] != '*'){
                robot.MoveLeft();
            } else if(maze[robot.l-1][robot.c] == '.' && maze[robot.l-1][robot.c] != '*'){
                robot.MoveUp();
            } else if(maze[robot.l][robot.c+1] == '.' && maze[robot.l][robot.c+1] != '*'){
                robot.MoveRight();
            }
        } else if(robot.dir == 3){
            if(maze[robot.l][robot.c+1] == '.' && maze[robot.l][robot.c+1] != '*'){
                robot.MoveRight();
            } else if(maze[robot.l+1][robot.c] == '.' && maze[robot.l+1][robot.c] != '*'){
                robot.MoveDown();
            } else if(maze[robot.l][robot.c-1] == '.' && maze[robot.l][robot.c-1] != '*'){
                robot.MoveLeft();
            } else if(maze[robot.l-1][robot.c] == '.' && maze[robot.l-1][robot.c] != '*'){
                robot.MoveUp();
            }
        } else if(robot.dir == 4){
            if(maze[robot.l-1][robot.c] == '.' && maze[robot.l-1][robot.c] != '*'){
                robot.MoveUp();
            } else if(maze[robot.l][robot.c+1] == '.' && maze[robot.l][robot.c+1] != '*'){
                robot.MoveRight();
            } else if(maze[robot.l+1][robot.c] == '.' && maze[robot.l+1][robot.c] != '*'){
                robot.MoveDown();
            } else if(maze[robot.l][robot.c-1] == '.' && maze[robot.l][robot.c-1] != '*'){
                robot.MoveLeft();
            }
        } else if(robot.dir == 0){
            if(maze[robot.l][robot.c-1] == '.' && maze[robot.l][robot.c-1] != '*'){
                robot.MoveLeft();
            } else if(maze[robot.l+1][robot.c] == '.' && maze[robot.l+1][robot.c] != '*'){
                robot.MoveDown();
            } else if(maze[robot.l][robot.c+1] == '.' && maze[robot.l][robot.c+1] != '*'){
                robot.MoveRight();
            } else if(maze[robot.l-1][robot.c] == '.' && maze[robot.l-1][robot.c] != '*'){
                robot.MoveUp();
            }
        }

        this_thread::sleep_for(oneFrame);
    }

    cout << endl;

    for(int i = 0; i < coords.size(); i++){
        for(int j = 0; j < coords.size(); j++){
            if(maze[coords[i].first][coords[i].second+1] == '.' || maze[coords[i].first][coords[i].second-1] == '.' || maze[coords[i].first+1][coords[i].second] == '.' || maze[coords[i].first-1][coords[i].second] == '.'){
                if(maze[coords[i].first][coords[i].second+1] != maze[coords[j].first][coords[j].second] || maze[coords[i].first][coords[i].second-1] != maze[coords[j].first][coords[j].second] ||maze[coords[i].first+1][coords[i].second] != maze[coords[j].first][coords[j].second] || maze[coords[i].first-1][coords[i].second] != maze[coords[j].first][coords[j].second]){
                    possiblePaths.push_back(make_pair(coords[i].first, coords[i].second));
                }
            }
        }
    }

    if(possiblePaths.size() > 0){
        cout << "robot found other possible paths" << endl;
        for(int i = 0; i < possiblePaths.size(); i++){
            cout << possiblePaths[i].first << ", " << possiblePaths[i].second << endl;
        }
        system("pause");
        system("cls");
    }

    return 0;
}

//void PrintMaze(){
    
//}