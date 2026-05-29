#include<iostream>
#include<memory>

class Widget {
public:
	Widget():priority_(new int) {}
	~Widget() {}
	void SetPriority(const int n) {
		*priority_ = n;
	}
	int Priority() {
		return *priority_;
	}
	void ProcessWidget(std::shared_ptr<Widget> ptr, int priority);
private:
	int* priority_;
};

void Widget::ProcessWidget(std::shared_ptr<Widget> ptr, int priority) {
	if (ptr == NULL)
	{
		return;
	}
	else
	{
		ptr->SetPriority(priority);
	}
}



int main() {
	std::cout << "Item 17: Store newed objects in smart pointers in standalone statements." << std::endl;

	Widget yawen;
	yawen.ProcessWidget(std::shared_ptr<Widget>(new Widget), 10); // This call may leak resources.

	
	std::shared_ptr<Widget> ptr(new Widget);  // This call won't leak.
	yawen.ProcessWidget(ptr, 10);

	return 0;
}