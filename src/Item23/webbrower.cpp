#include<iostream>
#include"webbrower.h"
#include "webbrowerbookmarks.h"
namespace WebBrowserStuff {

	void WebBrowser::ClearCache() {
		std::cout << "ClearCache " << std::endl;
	}

	void WebBrowser::ClearHistory() {
		std::cout << "ClearHistory " << std::endl;
	}

	void WebBrowser::RemoveCookies() {
		std::cout << "RemoveCookies " << std::endl;
	}

	void ClearWebBrowser(WebBrowser& wb) {
		wb.ClearCache();
		wb.ClearHistory();
		wb.RemoveCookies();
	}

	void ClearBrowserBookmark(WebBookmark& wbb) {
		wbb.ClearBookmark();
	}

	void ClearEverything(WebBrowser& wb, WebBookmark& wbb) {
		ClearWebBrowser(wb);
		ClearBrowserBookmark(wbb);
	}
}
	
int main() {
	std::cout << "Item 23: Prefer non-member non-friend functions to member functions." << std::endl;

	WebBrowserStuff::WebBrowser web;
	WebBrowserStuff::WebBookmark wbb;
	ClearEverything(web, wbb);
	return 0;
}