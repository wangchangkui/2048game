#include "iostream"
#include "config/base.h"
#include "easyx/include/easyx.h"
#include "easyx/include/graphics.h"

using namespace std;



int main() {

    initgraph(ROW*GRID_WIDTH+(ROW+1)*INTERVAL,COL*GRID_HEIGHT+(COL+1)*INTERVAL,EW_SHOWCONSOLE);

    init();

    while (true){
        draw();
        move();
        // 是否胜利
        if(is_win()){
            cout<<"game over you win";
            break;
        }
        // 是否失败
        if(is_fail()){
            cout<<"game over you fail";
            break;
        }

    }



    return 0;
}
