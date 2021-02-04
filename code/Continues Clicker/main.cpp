#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
int main(int argc,char* argv[])
{
        int n,t,d;			
	//n:点击次数
	//t:间隔时间
	//d:要点击的键
	cout<<"请输入要连续点击的次数:";
	cin>>n;//输入点击次数 
	cout<<"请输入每两次点击的间隔时间:";
	cin>>t;//输入间隔时间 
	cout<<"请按下要连续点击的键:";
	while(GetKeyState(1)>=0&&GetKeyState(2)>=0)
	{
		if(GetKeyState(1)<0) d=1;//判断如果是鼠标左键按下 
		else d=2;//否则就是鼠标右键按下 
	};//循环直到鼠标左右键按下 
	if(GetKeyState(1)<0) d=1;//判断如果是鼠标左键按下 
	else d=2;//否则就是鼠标右键按下 
	system("cls");//清空屏幕 
	time_t start,end;//计时，好算速度 
	for (int i=1;i<=n;i++)
	{
		if(GetKeyState(83)<0)//如果'S'键按下
		{
			while(GetKeyState(83)<0) ;//循坏直到'S'键被松开
			while(GetKeyState(83)>=0) ;//循环直到'S'键被按下，再继续连点 
			while(GetKeyState(83)<0) ;//等'S'键松开了之后再继续执行 
		} 
		start=clock();//获取此次循坏开始时的时间 
		if (d==1) mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);//鼠标左键按下	
		else mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);//鼠标右键按下 
		Sleep(t/2);//平分两次间隔时间 
		if (d==1) mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);//鼠标左键抬起
		else mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);//鼠标右键抬起 
		Sleep(t/2);//平分两次间隔时间
		end=clock();//获取此次循环结束时的时间 
		cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";//使光标在此列的最前端
		cout<<"当前速度:"<<1000*3600/(end-start)<<"次/小时";//计算速度(单位:次/小时)
		cout<<"     ";//清空后面还有的内容 
	} 
	return 0;
}
