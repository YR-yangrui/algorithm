/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月15日 星期二 15时04分11秒
*******************************/
#include<fstream>
#include<ostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<unistd.h>
using namespace std;
int main()
{
        std::ofstream outfile("test.txt");
        for(int n=0;n<100;n++)
        {
                outfile<<n;
                //sleep(1000);
                //outfile.flush();
        }
        outfile.close();
        return 0;
}

