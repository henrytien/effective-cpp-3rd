#include<iostream>
class Person {
public:
	void eat() const { std::cout << "Call Person::eat()\n"; }

private:
	void f() {}
};
class Student : private Person {
public:
	void study() const { std::cout << "Call Person::study()\n"; }
};                             // inheritance is now private anyone can eat
void eat(const Person& p) {
	p.eat();
}
void study(const Student& s) {  // only students study
	s.study();
}

class Timer {
public:
	explicit Timer(int tickFrequency) :frequency_(tickFrequency) {}
	virtual void OnTick() const;  // automatically called for each tick
private:
	int frequency_;
};

void Timer::OnTick() const {
	std::cout << "Call Timer::OnTick()\n";
}

class Widget : private Timer {
public:
	Widget(int tick) :Timer(tick) {}
	void Tick() { OnTick(); }
private:
	virtual void OnTick() const;  // look at Widget usage data, etc.
};

void Widget::OnTick() const {
	std::cout << "Widget::OnTick()\n";
}

// https://stackoverflow.com/questions/2362097/why-is-the-size-of-an-empty-class-in-c-not-zero
class Empty {
};
class HoldsAnInt : private Empty { // should need only space for an int
private:
	char x;
	Empty e;
};


int main() {
	std::cout << "Item 39: Use private inheritance judiciously.\n";

	Person p;
	Student s;
	eat(p);

	//eat(s);

	Widget w(100);
	w.Tick();


	std::cout << "HoldsAnInt size: " << sizeof(HoldsAnInt) << std::endl;


	return 0;
}