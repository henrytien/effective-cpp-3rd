#pragma once
namespace WebBrowserStuff {
	class WebBrowser {
	public:
		WebBrowser() {}
		~WebBrowser() {}
		void ClearCache();
		void ClearHistory();
		void RemoveCookies();
	};
}