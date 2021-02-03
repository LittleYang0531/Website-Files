#ifndef __H_HTML_PARSE_H__
#define __H_HTML_PARSE_H__
 
#pragma once

#include <Windows.h>
#include <WinInet.h>
#include <string>
#include <cstdio>
 
class hHtmlParse {
	std::string data;
	int p;
public:
	//构造函数，传入HTML代码
	hHtmlParse (std::string& data);
	//获取网页的编码方式
	bool GetCharset (std::string& s);
	//设置当前解析位置
	bool SetPos (const char* find);
	//设置当前解析位置（反向查找目标位置）
	bool SetPos_LastOf (const char* find);
	//查找是否存在目标位置，不会更新当前位置
	bool find (const char* find);
	//匹配一串字符串，使用sscanf_s获取
	bool MatchString (const char* match, std::string& s);
	//获取当前电脑IP地址
	static bool GetLocalIp (std::string& ip);
	//查询某地址或某域名信息
	static bool GetAddrMessage (const wchar_t* addr, std::string& data);
	//关键函数，获取lpURL指向的地址的HTML代码，并存入data中
	static bool UrlGetHtml (LPCWSTR lpURL, std::string& data);
};
 
#endif
