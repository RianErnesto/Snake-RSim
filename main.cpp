#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

vector< pair<int, int> > coord;   // Add snakes new coordinates to vector

struct Coordinates{
    int x;
    int y;
};

class Snake{
    public:
        char apple;
        char snake;
        Coordinates xy;

        Snake(){
            apple = '6';
            snake = '#';
            xy.x = 10;
            xy.y = 10;
        }
        void MoveUp(){
            xy.x--;
        }
        void MoveRight(){
            xy.y++;
        }
        void MoveDown(){
            xy.x++;
        }
        void MoveLeft(){
            xy.y--;
        }
};

void Menu();

chrono::milliseconds tenFrames(100);

int main()
{
    Snake snake;

    unsigned const int size = 20;
    int appleNum = 0;
    int applesEaten = 0;
    int dir;
    int randomX;
    int randomY;
    char matrix[size][size];
    char usrInput;

    Menu();

    srand(time(NULL));

    coord.push_back(make_pair(snake.xy.x, snake.xy.y));
    
    while(true){
        // Creates matrix
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(i == 0 || i == size-1 || j == 0 || j == size-1){
                    matrix[i][j] = '*';
                } else {
                    matrix[i][j] = ' ';
                }
            }
        }

        if(appleNum == 0){
            randomX = rand() % 18;
            randomX++;
            randomY = rand() % 18;
            randomY++;
            appleNum = 1;
        }

        if(matrix[coord[coord.size()-1].first][coord[coord.size()-1].second] == matrix[randomX][randomY] && appleNum == 0){
            randomX = rand() % 18;
            randomX++;
            randomY = rand() % 18;
            randomY++;
            appleNum = 1;
        }

        matrix[randomX][randomY] = snake.apple;

        for(int i = 0; i < applesEaten+1; i++){
            matrix[coord[i].first][coord[i].second] = snake.snake;
        }

        system("cls");

        // Prints matrix
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }

        if(kbhit() == true){
            usrInput = getch();
        }

        if((usrInput == 'w' || usrInput == 'W') && dir != 3){
            snake.MoveUp();
            dir = 1;
        } else if((usrInput == 'a' || usrInput == 'A') && dir != 4){
            snake.MoveLeft();
            dir = 2;
        } else if((usrInput == 's' || usrInput == 'S') && dir != 1){
            snake.MoveDown();
            dir = 3;
        } else if((usrInput == 'd' || usrInput == 'D') && dir != 2){
            snake.MoveRight();
            dir = 4;
        } else {
            if(dir == 1){
                snake.MoveUp();
            } else if(dir == 2){
                snake.MoveLeft();
            } else if(dir == 3){
                snake.MoveDown();
            } else if(dir == 4){
                snake.MoveRight();
            }
        }

        coord[applesEaten].first = snake.xy.x;
        coord[applesEaten].second = snake.xy.y;

        if(coord[applesEaten].first == randomX && coord[applesEaten].second == randomY){
            matrix[randomX][randomY] = ' ';
            appleNum = 0;
            applesEaten++;
            if(dir == 1){
                coord.push_back(make_pair(snake.xy.x+1, snake.xy.y));
            }
            else if(dir == 2){
                coord.push_back(make_pair(snake.xy.x, snake.xy.y+1));
            }
            else if(dir == 3){
                coord.push_back(make_pair(snake.xy.x-1, snake.xy.y));
            }
            else if(dir == 4){
                coord.push_back(make_pair(snake.xy.x, snake.xy.y-1));
            }
        }

        if(matrix[coord[applesEaten].first][coord[applesEaten].second] == '*'){
            cout << "You lost :(" << endl;
            system("pause");
            system("cls");
            exit(0);
        }

        this_thread::sleep_for(tenFrames);
    }

    return 0;
}










void Menu(){
    char choice;

    do{
        system("cls");
        cout << "    SNAKE GAME" << endl;
        cout << "####################";
        cout << "     1- PLAY" << endl;
        cout << "     2- EXIT" << endl;
        cout << "####################";
        choice = getch();

        if(choice == '1'){
            break;
        }

        else if(choice == '2'){
            system("cls");
            cout << "EXITING GAME" << endl;
            exit(0);
        }
    }while(true);

}