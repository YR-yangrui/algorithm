/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年06月17日 星期一 21时32分01秒
 *******************************/
#include<iostream>
#include<cstdio>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<ncurses.h>
std::ifstream fin("word.txt");
const int Max_Size=5000;
std::string s[Max_Size];
int cnt;
void read()
{
    cnt=1;
    while(getline(fin,s[cnt]))
        ++cnt;
    --cnt;
    fin.clear();
}

void Random_Selection(WINDOW* win,int rp)
{
    while(rp--)
    {
        int choice=rand()%cnt+1;
        std::cout<<s[choice]<<std::endl;
        wprintw(win,"%s\n",s[choice].c_str());
        wprintw(win,"press '?' to get translate,'enter' to continue.\n");
        int ch=getch();
        if(ch=='?')
        {
            //std::string call="sdcv -u 朗道英汉字典5.0 ";
            std::string call="trans ";
            call+=s[choice];
            std::system(call.c_str());
        }
        while(ch!='\n')ch=getch();
    }
}
void print_menu(WINDOW* menu_win)
{
    box(menu_win,0,0);
    wrefresh(menu_win);
}
int startx,starty;
const int HEIGHT=10;
const int WIDTH=10;
int main()
{
    srand(time(0));
    initscr();
    noecho();
    cbreak();
    read();
    WINDOW * menu_win;
    starty=20;
    startx=50;
    menu_win=newwin(HEIGHT,WIDTH,starty,startx);
    print_menu(menu_win);
    keypad(menu_win,TRUE);
    wprintw(menu_win,"请输入抽查次数:");
    wrefresh(menu_win);
    //std::cout<<"请输入抽查次数:";
    int rp;
    scanw("%d",&rp);
    wprintw(menu_win,"开始抽查！（输入q退出)\n");
    wrefresh(menu_win);
    //std::cout<<"开始抽查！（输入q退出)\n";
    Random_Selection(menu_win,rp);
    return 0;
}
