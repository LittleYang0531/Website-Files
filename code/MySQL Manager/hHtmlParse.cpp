#include "hHtmlParse.h"
 
hHtmlParse::hHtmlParse (std::string& data) {
	this->data = data;
	this->p = 0;
}
 
bool hHtmlParse::GetCharset (std::string& s) {
	this->SetPos ("charset=");
	return this->MatchString ("%*[\"]%[^\"]", s);
}
 
bool hHtmlParse::SetPos (const char* find) {
	int t = this->data.find (find, p);
	if (-1 == t) return false;
	this->p = t + strlen (find);
	return true;
}
 
bool hHtmlParse::SetPos_LastOf (const char* find) {
	int t = this->data.rfind (find);
	if (-1 == t) return false;
	this->p = t + strlen (find);
	return true;
}
 
bool hHtmlParse::find (const char* find) {
	int t = this->data.find (find, p);
	return t != -1;
}
 
bool hHtmlParse::MatchString (const char* match, std::string& s) {
	return sscanf (&data.c_str () [p], match, const_cast<char*>(s.c_str ()), s.capacity ()) > 0;
}
 
bool hHtmlParse::GetLocalIp (std::string& ip) {
	std::string page, match;
	page.resize (512);
	match.resize(16);
	if (!hHtmlParse::UrlGetHtml (L"http://2021.ip138.com/", page)) return false;
	hHtmlParse hp (page);
	hp.SetPos ("<title>");
	hp.MatchString ("%*[^0-9]%[0-9.]", match);
	ip.clear ();
	ip = match.c_str ();
	return true;
}
 
bool hHtmlParse::GetAddrMessage (const wchar_t* addr, std::string& data) {
	data.clear ();
	std::wstring link = L"http://www.ip138.com/ips138.asp?ip=";
	std::string page, match;
	link += addr;
	page.resize (16384);
	match.resize (64);
	if (!hHtmlParse::UrlGetHtml (link.c_str (), page)) return false;
	hHtmlParse hp (page);
	hp.SetPos_LastOf ("<table");
	hp.SetPos ("<td");
	hp.SetPos ("<td");
	bool b = true;
	if (hp.find (">>")) {
		b = false;
		hp.SetPos (">>");
		hp.MatchString ("%*[^0-9]%[0-9.]", match);
		data = match.c_str ();
	}
	hp.SetPos ("<ul");
	while (hp.find ("<li")) {
		hp.SetPos ("£º");
		hp.MatchString ("%[^<]", match);
		if (b) b = false; else data += "\n";
		data += match.c_str ();
	}
	return true;
}
 
bool hHtmlParse::UrlGetHtml (LPCWSTR lpURL, std::string& data) {
	HINTERNET hSession = InternetOpenW (L"netdisk", NULL, NULL, NULL, INTERNET_FLAG_NO_CACHE_WRITE);
	if (!hSession) return FALSE;
	HINTERNET hFile = InternetOpenUrlW (hSession, lpURL, NULL, NULL, INTERNET_FLAG_RELOAD, NULL);
	if (!hFile) {
		InternetCloseHandle (hSession); return FALSE;
	}
	DWORD dwW = 0, dwR = 0;
	int capacity = data.capacity ();
	do {
		dwW += dwR;
		if (dwW != 0 && dwR == 0) break;
		if (dwW + 1024 >= capacity) data.resize (capacity *= 2);
	} while (InternetReadFile (hFile, (LPVOID) (data.c_str () + dwW), 1024, &dwR));
	const_cast<char*>(data.c_str ()) [dwW] = '\0';
	InternetCloseHandle (hFile);
	InternetCloseHandle (hSession);
	return TRUE;
}
