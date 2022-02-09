#pragma once
#include<iostream>
namespace WebBrowserStuff {

	class WebBookmark
	{
	public:
		WebBookmark():marked_(false){}
		~WebBookmark(){}
		void MakeBookmark() {}
		void ClearBookmark();
	private:
		bool marked_;
	};

}