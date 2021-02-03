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
	//���캯��������HTML����
	hHtmlParse (std::string& data);
	//��ȡ��ҳ�ı��뷽ʽ
	bool GetCharset (std::string& s);
	//���õ�ǰ����λ��
	bool SetPos (const char* find);
	//���õ�ǰ����λ�ã��������Ŀ��λ�ã�
	bool SetPos_LastOf (const char* find);
	//�����Ƿ����Ŀ��λ�ã�������µ�ǰλ��
	bool find (const char* find);
	//ƥ��һ���ַ�����ʹ��sscanf_s��ȡ
	bool MatchString (const char* match, std::string& s);
	//��ȡ��ǰ����IP��ַ
	static bool GetLocalIp (std::string& ip);
	//��ѯĳ��ַ��ĳ������Ϣ
	static bool GetAddrMessage (const wchar_t* addr, std::string& data);
	//�ؼ���������ȡlpURLָ��ĵ�ַ��HTML���룬������data��
	static bool UrlGetHtml (LPCWSTR lpURL, std::string& data);
};
 
#endif
