#include<iostream>
#include<ncurses.h>
int main()
{
    initscr();
    raw();
    start_color();
    init_pair(1,COLOR_CYAN,COLOR_BLACK);
    printw("Hello world!\n");
    mvchgat(0,0,-1,A_BLINK,1,NULL);
    //char ch;
    //attron(COLOR_PAIR(2));
    //attroff(COLOR_PAIR(2));
    refresh();
    getch();
    endwin();
}
