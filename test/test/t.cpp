/*******************************
Author:Morning_Glory
LANG:C++
Created Time:2019年09月22日 星期日 20时19分42秒
*******************************/
#include <iostream>
#include <fstream>
#include <ncurses.h>
using namespace std;
int YR,JR;
ifstream fin;
ofstream fout;
void save()
{
    fout.open("calculator");
    fout<<YR<<' '<<JR;
}
void show()
{
    printw("YR: %d\n",YR);
    printw("JR: %d\n",JR);
}
int main()
{
    initscr();
    raw();
    noecho();
    keypad(stdscr,TRUE);
    fin.open("calculator");
    fin>>YR>>JR;
    printw("Please input the type[s(how)/i(nsert)]\n");
    char s;
    while((s=getch())!='i' and s!='s' and s!='S' and s!='I' and s!=(char)(26) and s!=(char)(3))continue;
    if(s==(char)(26) or s==(char)(3)){save();return 0;}
    while(true)
    {
        while((s=getch())!='i' and s!='s' and s!='S' and s!='I' and s!=(char)(26) and s!=(char)(3))continue;
        if(s==(char)(26) or s==(char)(3)){save();return 0;}
        if (s=='s' or s=='S'){
            show();
        }
        else{
            printw("who?[y(r)/j(r)\n");
            while((s=getch())!='y' and s!='Y' and s!='j' and s!='J')continue;
            if (s=='Y' or s=='y')	++YR;
            else	++JR;
            show();
        }
        printw("continue?[y/n]\n");
        while((s=getch())!='y' and s!='Y' and s!='n' and s!='N')continue;
        if (s=='N' or s=='n'){
            save();
            break;
        }
        printw("Please input the type[s(how)/i(nsert)]\n");
    }
    save();
    return 0;
}

/*
               *********                       
              ************                     
              *************                    
             **  ***********                   
            ***  ****** *****                  
            *** *******   ****                 
           ***  ********** ****                
          ****  *********** ****               
        *****   ***********  *****             
       ******   *** ********   *****           
       *****   ***   ********   ******         
      ******   ***  ***********   ******       
     ******   **** **************  ******      
    *******  ********************* *******     
    *******  *********************** ******    
   *******  ****** ***************** *******   
   *******  ****** ****** *********   ******   
   *******    **  ******   ******     ******   
   *******        ******    *****     *****    
    ******        *****     *****     ****     
     *****        ****      *****     ***      
      *****      ****        ***      *        
        **       ****        ****              
*/
