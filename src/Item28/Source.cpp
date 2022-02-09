#include<iostream>
class Point { // class for representing points
public:
	Point(int x, int y):x_(x),y_(y){}
	void setX(int newVal);
	void setY(int newVal);
private:
	int x_, y_;
};

void Point::setX(int newVal) {
	x_ = newVal;
}

void Point::setY(int newVal) {
	y_ = newVal;
}

struct RectData { // Point data for a Rectangle
	Point ulhc; // ulhc = ¡° upper left-hand corner¡±
	Point lrhc; // lrhc = ¡° lower right-hand corner¡±
};
class Rectangle {
public:
	const Point& upperLeft() const { return pData->ulhc; }
	const Point& lowerRight() const { return pData->lrhc; }
private:
	std::shared_ptr<RectData> pData; // see Item13 for info on shared_ptr
};

class GUIObject { 
	public:
		GUIObject(){}
		~GUIObject(){}
};
// returns a rectangle by value;  
//  see Item3 for why return type is const
const Rectangle  boundingBox(const GUIObject& obj) {
	return Rectangle();
}


int main() {
	std::cout << "Item 28: Avoid returning ¡°handles¡± to object internals." << std::endl;

	{
		// Now consider how a client might use this function:
		GUIObject* pgo = new GUIObject(); // make pgo point to
		// get a ptr to the upper
		const Point* pUpperLeft = &(boundingBox(*pgo).upperLeft()); // left point of its bounding box
		// It's is dangerous. pUpperLeft will dangle by the end of statement that created it!
		printf("%p", pUpperLeft);
	}
	

	return 0;
}