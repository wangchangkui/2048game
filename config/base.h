//
// Created by Lenovo on 24-8-7.
//

#ifndef INC_2048GAME_BASE_H
#define INC_2048GAME_BASE_H

#include <map>

#define ROW 4
#define COL 4
#define GRID_WIDTH 100
#define GRID_HEIGHT 100
#define INTERVAL 15
const std::map<unsigned int,int> color_map{
    {0,0xcdc1b4},
    {2,0xff0777},
    {4,0x8b07ff},
    {8,0x0718ff},
    {16,0x0796ff},
    {32,0x07ffdf},
    {64,0x59ff07},
    {128,0xb4ff07},
    {256,0xfffa07},
    {512,0xffc007},
    {1024,0xff4e07},
    {2056,0xff0707}};

/**
 * 获得一个2048 2 或者4 随机数
 * 2的概率为 80%
 * 4的概率未 20%
 * @return rand
 */
int create_number();


/**
 * 格子网上移动
 */
void up();


/**
 * 格子向下移动
 */
void down();

/**
 * 向左移动
 */
void left();



/**
 * 向右移动
 */
void right();
/**
 * 移动格子
 */
void move();

/**
 * 往格子里面添加一个随机数
 * @param times 添加多少次
 */
void map_add_number(int times);


/**
 * 检查是否满足添加次数的随机数到网格中
 * @param times  次数
 * @return  bool
 */
bool check_has_position(int times);

/**
 * 随机获取一个数组长度的 随机数
 * @return 随机数
 */
int get_map_rand(int size);


/**
 * 初始化游戏
 */
void init();

/**
 * 显示游戏
 */
void draw();


/**
 * 是否赢得游戏
 * @return
 */
bool is_win();

/**
 * 是否失败
 * @return
 */
bool is_fail();

#endif //INC_2048GAME_BASE_H
