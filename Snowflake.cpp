#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

const int screen_width = 50;
const int screen_height = 20;
const char snowflakes[] = { 'x', '+', '*' };
const int snowflakes_count = 100;

struct Snowflake {
    int x, y;
    char symbol;
};

void setCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawSnowflake(Snowflake flake) {
    setCursorPosition(flake.x, flake.y);
    std::cout << flake.symbol;
}

void updateSnowflakePosition(Snowflake& flake) {
    flake.y += abs(rand() % 3 - 1);
    flake.x += rand() % 3 - 1;
    if (flake.y >= screen_height) {
        flake.y = 0;
        flake.x = rand() % screen_width;
    }
}

int main() {
    srand(time(NULL));

    Snowflake snowflakesArray[snowflakes_count];

    for (int i = 0; i < snowflakes_count; i++) {
        snowflakesArray[i].x = rand() % screen_width;
        snowflakesArray[i].y = rand() % screen_height;
        snowflakesArray[i].symbol = snowflakes[rand() % 3];
    }


    while (true) {
        system("cls");


        for (int i = 0; i < snowflakes_count; i++) {
            drawSnowflake(snowflakesArray[i]);
            updateSnowflakePosition(snowflakesArray[i]);
        }

        std::cout.flush();

        Sleep(100);
    }

    return 0;
}