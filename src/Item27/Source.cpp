#include<iostream>
#include<vector>
class Window { // base class
public:
	virtual void onResize() { std::cout << "Call Window onResize." << std::endl; } // base onResize impl
};
class SpecialWindow : public Window { // derived class
public:
	virtual void onResize() { // derived onResize impl;
		// then call its onResize; this doesn¡¯t work!
		//static_cast<Window>(*this).onResize(); // cast *this to Window,
		Window::onResize();
		// do SpecialWindow-
	} // specific stuff

	void blink(const std::string& str) { std::cout << "Called SpecialWindow blink is by " << str << std::endl; }
};


int main() {
	std::cout << "Item 27: Minimize casting." << std::endl;
	{
		typedef // see Item 13 for info
			std::vector<std::shared_ptr<Window> > VPW; // on std::shared_ptr
		VPW winPtrs;
		auto* ptr = new Window();
		winPtrs.emplace_back(ptr);
		for (VPW::iterator iter = winPtrs.begin(); // undesirable code:
			iter != winPtrs.end(); // uses dynamic_cast
			++iter) {
			if (SpecialWindow* psw = dynamic_cast<SpecialWindow*>(iter->get()))
				psw->blink("Window");
		}
	}
	// Try to do this instead:
	{
		typedef std::vector<std::shared_ptr<SpecialWindow> > VPSW;
		VPSW winPtrs;
		auto* ptr = new SpecialWindow();
		winPtrs.emplace_back(ptr);
		for (VPSW::iterator iter = winPtrs.begin(); // better code: uses
			iter != winPtrs.end(); // no dynamic_cast
			++iter)
			(*iter)->blink("SpecialWindow");
	}
	return 0;
}