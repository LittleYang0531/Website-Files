#include<bits/stdc++.h>
#include<conio.h>
#include"hHtmlParse.h"
#include"hHtmlParse.cpp"
using namespace std;
wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
{
    wchar_t* wString=new wchar_t[4096];
    MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
    return wString;
}
string GetPassword()
{
	char input[8192];
	char in=0;int k=-1;
	while (in!=13)
	{
		in=getch();
		if (in==8&&k>0) k--;
		else input[++k]=in;
	}
	return input;
}
int main()
{
	time_t start,end,addition=0;
	start=clock();
	SetConsoleTitle("MySQL Manager Powered by LittleYang");
	cout<<"Starting MySQL Manager..."<<endl;
	string page,match;
	page.resize(512,0);
	match.resize(512,0);
	if (!hHtmlParse::UrlGetHtml(convertCharArrayToLPCWSTR(((string)"http://www.littleyang.ml/execute?code=aaa").c_str()),page))
	{
		cout<<"Failed to Connect the Database!"<<endl;
		cout<<"Trying to Reconnect:"<<endl;
		int failtime=0;
		while (!hHtmlParse::UrlGetHtml(convertCharArrayToLPCWSTR(((string)"http://www.littleyang.ml/execute?code=aaa").c_str()),page))
		{
			cout<<"#"<<++failtime<<":Failed to Connect the Database!"<<endl;
		}
	}
	cout<<"Connect the Database Successfully!"<<endl;
	cout<<"Server Address:64.69.43.237"<<endl;
	string ip;ip.resize(255);char ipandress[255];
	if (!hHtmlParse::GetLocalIp(ip))
	{
		cout<<"Failed to Get Local Ip Address!"<<endl;
		cout<<"Trying to Reconnect:"<<endl;
		int failtime=0;
		while (!hHtmlParse::GetLocalIp(ip))
		{
			cout<<"#"<<++failtime<<":Failed to Get Local Ip Address!"<<endl;
		}
	}
	for (int i=0;i<ip.size();i++) ipandress[i]=ip[i];
	cout<<"Local Ip Address:"<<ipandress<<endl;
	string UserName,Password,re; 
	end=clock();
	addition+=end-start;
	time_t aaa;
	while (re!="The Login was Successful!")
	{
		cout<<"Account Name:";
		getline(cin,UserName);
		cout<<"Account Password:";
		Password=GetPassword();
		cout<<endl;
		start=clock();
		if (!hHtmlParse::UrlGetHtml(convertCharArrayToLPCWSTR(((string)"http://www.littleyang.ml/api/login?UserName="+UserName+"&Password="+Password).c_str()),page))
		{
			cout<<"Failed to Login Your Account!"<<endl;
			cout<<"Trying to Reconnect:"<<endl;
			int failtime=0;
			while (hHtmlParse::UrlGetHtml(convertCharArrayToLPCWSTR(((string)"http://www.littleyang.ml/api/login?UserName="+UserName+"&Password="+Password).c_str()),page))
			{
				cout<<"#"<<++failtime<<":Failed to Login Your Account!"<<endl;
			}
		}
		hHtmlParse hp (page);
		hp.SetPos ("<div style='font-family:monospace'>");
		hp.MatchString ("	%[^<]", match); 
		char result1[1024]="";
		for (int i=0;i<match.size();i++) result1[i]=match[i];
		cout<<result1<<endl;
		re=result1;
		match.resize(512,0);	
		end=clock();
		aaa=end-start;
	}
	addition+=aaa;
	start=clock();
	if (!hHtmlParse::UrlGetHtml(convertCharArrayToLPCWSTR(((string)"http://www.littleyang.ml/execute?code=aaa").c_str()),page))
	{
		cout<<"Failed to Get Your Authority!"<<endl;
		cout<<"Trying to Reconnect:"<<endl;
		int failtime=0;
		while (!hHtmlParse::UrlGetHtml(convertCharArrayToLPCWSTR(((string)"http://www.littleyang.ml/execute?code=aaa").c_str()),page))
		{
			cout<<"#"<<++failtime<<":Failed to Get Your Authority!"<<endl;
		}
	}
	match.resize(512,0);
	hHtmlParse hp (page);
	hp.SetPos ("<div style='font-family:monospace'>");
	hp.MatchString ("	%[^<]", match); 
	char result2[1024]="";string re1;
	for (int i=0;i<match.size();i++) result2[i]=match[i];
	re1=result2;
	end=clock();
	addition+=end-start;
	cout<<"Login Account Cost "<<addition<<" ms(Reference:2500ms)"<<endl;
	if (re1=="The Login was Successful!")
	{
		cout<<"You might not Have Enough Authority to Use It!"<<endl;
		system("pause");
		return 0;
	}
	while (1)
	{
		SetConsoleTitle(("Account:"+UserName+"  LocalAddress:"+ipandress+"  ServerAddress:64.69.43.237 - MySQL Manager Powered by LittleYang").c_str());
		cout<<ipandress<<">";
		string code;
		getline(cin,code);	
		start=clock();
		if (!hHtmlParse::UrlGetHtml(convertCharArrayToLPCWSTR(((string)"http://www.littleyang.ml/execute?code="+code).c_str()),page))
		{
			cout<<"Failed to Connect the Database!"<<endl;
			cout<<"Trying to Reconnect:"<<endl;
			int failtime=0;
			while (!hHtmlParse::UrlGetHtml(convertCharArrayToLPCWSTR(((string)"http://www.littleyang.ml/execute?code=aaa").c_str()),page))
			{
				cout<<"#"<<++failtime<<":Failed to Connect the Database!"<<endl;
			}
		}
		match.resize(512,0);
		hHtmlParse hp (page);
		hp.SetPos ("<body>");
		hp.MatchString ("	%[^<]", match); 
		end=clock();
		char result[1024]="";
		for (int i=0;i<match.size();i++) result[i]=match[i];
		cout<<result<<endl;
		cout<<"Modify Database Cost "<<end-start<<" ms(Reference:700ms)"<<endl;
	}
}
