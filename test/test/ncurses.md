- [ ] # "ncurses.h"

"ncurses" 包含 "stdio.h"

[使用手册](http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html)

# 安装

```bash
$ sudo apt install libncurses5-dev
```

编译时添加链接:
```bash
编译命令
g++ a.cpp -o a -l ncurses
```

## 函数列表

### 1.初始化函数

#### raw()和cbreak()

这两个函数用来关闭行缓冲,即读入后不会等待回车(好像也不会回显字符)。raw()模式读入字符不带信号，cbreak()会带信号,所以raw()可以读入'CTRL-C','CTRL-Z'

#### echo()和noecho()
回显与不回显

#### keypad()

允许读入方向键和'F1','F2',等符号


**使用**

```cpp
keypad(stdscr,TRUE);
ch=getch();
if(ch==KEY_F(1))
    printw("F1 key pressed");
```

#### halfdelay()
halfdelay()函数开启halfdelay模式，即在等待一段时间(你设定的)后还未读入到字符的话就执行别的语句

### 2.窗口输出

#### printw()

单个窗口输出，类似printf(),输出重定向到**stdscr**

```cpp
printw("Hi There!");
refresh();
```

#### refresh()
刷新窗口到屏幕

#### wprintw()

多窗口输出
```cpp
wprintw(win,"Hi There!!!");
wrefresh(win);
```
第一个参数是窗口，第二个是字符串

#### mvprintw(y,x,string)

移动到(y,x)然后打印string

#### mvwprintw(win,y,x,string)

移动到win窗口的(y,x然后打印)

#### addch()和addstr()

addch():打印单个字符(带属性)

addstr():打印字符串

立即打印到光标当前位置

形如' addch(ch | A_BOLD | A_UNDERLINE); '来设置属性

或用attrset(),attron(),attroff().

#### mvaddch(),waddch(),wvwaddch()

mvaddch(row,col,ch)
mvaddch()移动光标到row行col列然后输出字符
相当于
```cpp
move(row,col);
addch(ch);
```

其他类似

getmaxyx(stdscr,row,col);等到行数和列数
```cpp
int row,col;
getmaxyx(stdscr,row,col);
```

getmaxyx()是一个宏

### 输入函数

#### getch(),scanw(),getstr(string),mvscanw(),wgetstr()

getch() 得到一个字符

scanw() 得到一个格式后的输入，类似scanf

getstr(string) 得到字符串

这些函数若没有使用raw()或cbreak()将会等待回车

## 属性

attron(ATTR);开启属性

attroff(ATTR);关闭属性

### 属性定义

```
A_NORMAL 正常显示(无高亮)
A_STANDOUT 终端最好的高亮模式
A_UNDERLINE 下划线
A_REVERSE 反色（背景白了）
A_BLINK 一闪一闪的
A_DIM 半亮，没原来那么亮了
A_BOLD 加粗
A_PROTECT 保护模式
A_INVIS 看不见或闪的模式
A_ALTCHARSET 备选字符集
A_CHARTEXT 位掩码
COLOR_PAIR(n) 第n颜色对 
```

所有的属性可以通过或运算一起使用

attrset 和 attron的区别为attrset设置属性而attron开关它，所有attrset会完全覆盖原来的属性

可以用 standend()来设置回普通模式即attrset(A_NORMAL)

attr_get()得到当前窗口的属性和颜色对

以上函数都可以在前面加'w'来设置窗口属性

#### chgat()

不移动光标地设置一群字符的属性

-1设置为到最后一行

```
chgat(-1,ATTR,0,NULL);
```
从当前行到最后一行设置为某个属性

## 窗口

newwin() 函数分配窗口并且更新数据显示的结构，返回一个'WINDOW'结构体的指针

delwin() 销毁一个窗口，释放分配的内存

box()给窗口画一个边框

#### 鼠标操作

```cpp
mousemask(mmask_t newmask , /* The events you want to listen to */
            mmask *oldmmask) /* The old events mask                */
```
```

                Name            Description
       ---------------------------------------------------------------------
       BUTTON1_PRESSED          mouse button 1 down
       BUTTON1_RELEASED         mouse button 1 up
       BUTTON1_CLICKED          mouse button 1 clicked
       BUTTON1_DOUBLE_CLICKED   mouse button 1 double clicked
       BUTTON1_TRIPLE_CLICKED   mouse button 1 triple clicked
       BUTTON2_PRESSED          mouse button 2 down
       BUTTON2_RELEASED         mouse button 2 up
       BUTTON2_CLICKED          mouse button 2 clicked
       BUTTON2_DOUBLE_CLICKED   mouse button 2 double clicked
       BUTTON2_TRIPLE_CLICKED   mouse button 2 triple clicked
       BUTTON3_PRESSED          mouse button 3 down
       BUTTON3_RELEASED         mouse button 3 up
       BUTTON3_CLICKED          mouse button 3 clicked
       BUTTON3_DOUBLE_CLICKED   mouse button 3 double clicked
       BUTTON3_TRIPLE_CLICKED   mouse button 3 triple clicked
       BUTTON4_PRESSED          mouse button 4 down
       BUTTON4_RELEASED         mouse button 4 up
       BUTTON4_CLICKED          mouse button 4 clicked
       BUTTON4_DOUBLE_CLICKED   mouse button 4 double clicked
       BUTTON4_TRIPLE_CLICKED   mouse button 4 triple clicked
       BUTTON_SHIFT             shift was down during button state change
       BUTTON_CTRL              control was down during button state change
       BUTTON_ALT               alt was down during button state change
       ALL_MOUSE_EVENTS         report all button state changes
       REPORT_MOUSE_POSITION    report mouse movement

```

KEY_MOUSE 为读入后的数值
getmouse()返回发生的鼠标事件
```cpp
  typedef struct
    {
        short id;         /* ID to distinguish multiple devices */
        int x, y, z;      /* event coordinates */
        mmask_t bstate;   /* button state bits */
    }   
    getmouse(&event)
```
### getyx(win,y,x)
