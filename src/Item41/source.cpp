#include<iostream>
class NastyWidget;
class Widget {
public:
	Widget() :data_(0) {}
	virtual ~Widget() {}
	virtual std::size_t size() const { return sizeof(Widget); }
	virtual void normalize() {}
	void swap(Widget& other) {} // see Item25
	int get_data() const { return data_; }
private:
	int data_;
};



class NastyWidget {
public:
	NastyWidget() {}
	virtual ~NastyWidget() {}
	virtual std::size_t size() const { return sizeof(NastyWidget); };
	virtual void normalize() {}
	void swap(NastyWidget& other) {} // see Item25
};


bool operator==(const Widget& lhs, const NastyWidget& rhs)
{
	return lhs.size() == rhs.size();
}
bool operator!=(const Widget& lhs, const NastyWidget& rhs)
{
	return !(lhs == rhs);
}

NastyWidget nasty_widget;
template<typename T>
void DoProcessing(T& w)
{
	if (w.size() > 10 && w != nasty_widget) {
		T temp(w);
		temp.normalize();
		temp.swap(w);
	}
}

int main() {
	std::cout << "Item 41: Understand implicit interfaces and compiletime polymorphism.\n";

	Widget t;
	DoProcessing<Widget>(t);
	return 0;
}