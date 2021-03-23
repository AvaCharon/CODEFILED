#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int main(void)
{
    int Width = 15;
    int Size = Width*Width;
    int *map=calloc(Size,4);//calloc返回不固定的地址,从而得到随机数种子
    int zuobiao[2]={0};
    int length=3;
    int move='D';
    int food,timemove;//缓冲动作
    int i;
    int * p;
    for(timemove=map[1]=-1;timemove-27;Sleep(100))//Ese键的ascii码值为27，循环后延迟100ms
    {
        if(_kbhit())
        {
            timemove=_getch()&95;//获取并转化为大写
            timemove-65&&timemove-68&&timemove-83&&timemove-87||(move^timemove)&20^4&&(move=timemove);
            //检测输入是否为指定的字符（WASD）                    判定新旧动作是否冲突    更新动作
        }
        p=zuobiao + !!(move&2);//指定坐标轴
        *p +=move/3&2;//更新坐标
        *p=(--*p+Width)%Width;//越界处理，去另一边
        food=!system("cls");//清屏复位，system()正常返回0
        *(p=map+*zuobiao+zuobiao[1]*Width)>0&&(timemove=27);//使p指向蛇头坐标，并判定蛇头是否触碰蛇身，是则退出
        for(;*p&&(map[i = rand()%Size]||(--map[i],++length,--food)););//食物判定
        //撞到蛇身  直到找到一个空地       空地-1，蛇身长度+1，食物1
        for(i=0,*p=1;i<Size;++i%Width||_cputs("|\n"))//遍历地图
        //    蛇头赋值                  最后输出换行
        {
            _cputs(map[i]>0?map[i]-=food,"()":map[i]?"00":" ");//打印地图元素
        //判断地图是否为空地；蛇身-1（吃到不变），在其后输出（）表示蛇身；判断是否为食物 （00）
        }
    }
    return 0;
}