#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
int VanGo[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int Map[36][36];
bool in(int x,int y)
{
	return x>0&&x<=35&&y>0&&y<=35;
}
void coord(int x,int y)
{
	COORD pos;HANDLE hOut;
	pos.X=y;
	pos.Y=x;
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut,pos);
}
void Change(int lastx,int lasty,int startx,int starty)
{
	coord(lastx,lasty*2);
	cout<<"  ";
	coord(startx,starty*2);
	cout<<"█";
}
int main()
{
	srand(time(NULL));
	int headx=18,heady=19,tailx=18,taily=17,direction=2,length=3;
	int goalx,goaly;bool ifgoal=0;
	coord(0,0);
	for (int i=0;i<37;i++) cout<<"█";
	for (int i=0;i<37;i++)
	{
		coord(i,0);
		cout<<"█";
		coord(i,72);
		cout<<"█";
	}
	coord(36,0);
	for (int i=0;i<37;i++) cout<<"█";
	Map[18][18]=Map[18][19]=Map[18][17]=2;
	coord(18,34);
	for (int i=0;i<3;i++) cout<<"█";
	coord(38,2);
	cout<<"scores:0"<<endl;
	getch();
	while (1)
	{
		Map[headx][heady]=direction;
		while (!ifgoal)
		{
			goalx=rand()%35+1;
			goaly=rand()%35+1;
			if (Map[goalx][goaly]==0)
			{
				ifgoal=1;
				coord(goalx,goaly*2);
				cout<<"●";
			}
		}
		headx+=VanGo[direction-1][0];heady+=VanGo[direction-1][1];
		if (Map[headx][heady]!=0||!in(headx,heady))
		{
			Sleep(100);
			MessageBox(NULL,"Game Over!","Finished",MB_OK);
			coord(39,0);
			return 0;
		}
		if (headx==goalx&&heady==goaly)
		{
			ifgoal=0;
			coord(headx,heady*2);
			cout<<"█";
			coord(38,2);
			cout<<"scores:"<<++length-3<<endl;
		}
		else
		{
			Change(tailx,taily,headx,heady);
			int beforex=tailx,beforey=taily;
			tailx+=VanGo[Map[beforex][beforey]-1][0];taily+=VanGo[Map[beforex][beforey]-1][1];
			Map[beforex][beforey]=0;
		}
		if (kbhit())
		{
			char change=getch();
			switch(change)
			{
				case 'A':case 'a':direction=4;break;
				case 'S':case 's':direction=1;break;
				case 'D':case 'd':direction=2;break;
				case 'W':case 'w':direction=3;break;
			}
		}
		Sleep(100);
	}
}
