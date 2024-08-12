//
// Created by wck on 24-8-7.
//
#include <random>
#include "iostream"
#include "../base.h"
#include "easyx.h"
#include "conio.h"

using namespace std;
int GAME_MAP[ROW][COL];


int get_map_rand(int size) {
    // 随机产生一个数
    random_device rd;
    mt19937 r_eng(rd());
    uniform_int_distribution<int> dis(0, size);
    return dis(r_eng);
}


void move() {
    int ch = _getch();

    switch (ch) {
        case 72:
            up();
            break;
        case 80:
            down();
            break;
        case 75:
            left();
            break;
        case 77:
            right();
            break;

    }
}

void up() {
    for (int i = 0; i < COL; i++) {
        int temp_array[ROW] = {};
        int index = 0;
        for (int j = 0; j < ROW; j++) {
            if (GAME_MAP[j][i] != 0) {
                temp_array[index++] = GAME_MAP[j][i];
            }
        }

        // 合并相邻相同的数
        for (int j = 0; j < index - 1; j++) {
            if (temp_array[j] == temp_array[j + 1]) {
                temp_array[j] *= 2;
                temp_array[j + 1] = 0;
                j++;  // 跳过下一个已合并的数
            }
        }

        // 将非零值移到前面
        int k = 0;
        for (int j = 0; j < index; j++) {
            if (temp_array[j] != 0) {
                GAME_MAP[k++][i] = temp_array[j];
            }
        }

        // 其余填充0
        while (k < ROW) {
            GAME_MAP[k++][i] = 0;
        }
    }

    map_add_number(1);
}

void down() {
    for (int i = 0; i < COL; i++) {
        int temp_array[ROW] = {};
        int index = 0;
        for (int j = ROW - 1; j >= 0; j--) {
            if (GAME_MAP[j][i] != 0) {
                temp_array[index++] = GAME_MAP[j][i];
            }
        }

        for (int j = 0; j < index - 1; j++) {
            if (temp_array[j] == temp_array[j + 1]) {
                temp_array[j] *= 2;
                temp_array[j + 1] = 0;
                j++;
            }
        }

        int k = ROW - 1;
        for (int j = 0; j < index; j++) {
            GAME_MAP[k--][i] = temp_array[j];
        }

        while (k >= 0) {
            GAME_MAP[k--][i] = 0;
        }
    }

    map_add_number(1);
}

void left() {
    for (int i = 0; i < ROW; i++) {
        int temp_array[COL] = {};
        int index = 0;
        for (int j = 0; j < COL; j++) {
            if (GAME_MAP[i][j] != 0) {
                temp_array[index++] = GAME_MAP[i][j];
            }
        }

        for (int j = 0; j < index - 1; j++) {
            if (temp_array[j] == temp_array[j + 1]) {
                temp_array[j] *= 2;
                temp_array[j + 1] = 0;
                j++;
            }
        }

        int k = 0;
        for (int j = 0; j < index; j++) {
            if (temp_array[j] != 0) {
                GAME_MAP[i][k++] = temp_array[j];
            }
        }

        while (k < COL) {
            GAME_MAP[i][k++] = 0;
        }
    }

    map_add_number(1);
}

void right() {
    for (int i = 0; i < ROW; i++) {
        int temp_array[COL] = {};
        int index = 0;
        for (int j = COL - 1; j >= 0; j--) {
            if (GAME_MAP[i][j] != 0) {
                temp_array[index++] = GAME_MAP[i][j];
            }
        }

        for (int j = 0; j < index - 1; j++) {
            if (temp_array[j] == temp_array[j + 1]) {
                temp_array[j] *= 2;
                temp_array[j + 1] = 0;
                j++;
            }
        }

        int k = COL - 1;
        for (int j = 0; j < index; j++) {
            GAME_MAP[i][k--] = temp_array[j];
        }

        while (k >= 0) {
            GAME_MAP[i][k--] = 0;
        }
    }

    map_add_number(1);
}

int create_number() {
    // 随机产生一个数
    random_device rd;
    mt19937 r_eng(rd());
    uniform_int_distribution<int> dis(1, 100);
    return dis(r_eng) < 80 ? 2 : 4;
}


bool check_has_position(int times) {
    // 检查是否够生成位置
    int max = 0;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (GAME_MAP[i][j] == 0) {
                max++;
            }
            if (max >= times) {
                return true;
            }
        }
    }
    return false;
}

void map_add_number(int times) {
    if (check_has_position(times)) {
        // 随机产生数 放到数组里面
        int number = 0;
        while (true) {
            if (number == times) {
                break;
            }
            int r = get_map_rand(ROW - 1);
            int c = get_map_rand(COL - 1);
            if (GAME_MAP[r][c] == 0) {
                GAME_MAP[r][c] = create_number();
                number++;
            }
        }
    } else {
        cout << "can not add number to game" << endl;
    }

}


void init() {
    map_add_number(2);
}

bool is_win(){
    for (auto & i : GAME_MAP) {
        for (int j : i) {
            if(j>=1024){
                return true;
            }
        }
    }
    return false;
}

bool is_fail() {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            // 如果有0，说明还有空格，游戏继续
            if (GAME_MAP[i][j] == 0) {
                return false;
            }
            // 如果当前格子和右边相邻格子相同，则游戏继续
            if (j < COL - 1 && GAME_MAP[i][j] == GAME_MAP[i][j + 1]) {
                return false;
            }
            // 如果当前格子和下边相邻格子相同，则游戏继续
            if (i < ROW - 1 && GAME_MAP[i][j] == GAME_MAP[i + 1][j]) {
                return false;
            }
        }
    }
    // 如果没有空格且没有相邻的相同数字，则游戏失败
    return true;
}


void draw() {
    setbkcolor(RGB(187, 173, 160));
    cleardevice();
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            int x = j * GRID_WIDTH + (j + 1) * INTERVAL;
            int y = i * GRID_HEIGHT + (i + 1) * INTERVAL;
            int value = GAME_MAP[i][j];
            // 查询颜色
            auto color_m = color_map.find(value);
            // 设置格子颜色
            setfillcolor(color_m->second);
            solidroundrect(x, y, x + GRID_WIDTH, y + GRID_HEIGHT, 5, 5);
            // 如果格子的值大于0 则添加到网格中
            if (value > 0) {
                string number_str = to_string(value);
                // 计算文本的宽度和高度，以便居中显示
                int hspace = (GRID_WIDTH - textwidth(number_str.c_str())) / 2;
                int vspace = (GRID_HEIGHT - textheight(number_str.c_str())) / 2;
                // 绘制整个字符串
                setbkmode(1);
                outtextxy(x + hspace, y + vspace, number_str.c_str());
            }

        }
    }


}