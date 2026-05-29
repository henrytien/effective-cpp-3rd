#include<iostream>
#include<vector>
#include<random>
class SpeedDataCollection {
public:
	void add_value(int speed); // add a new data value
	double AverageSoFar() const; // return average speed
private:
	std::vector<int> speed_;
};

void SpeedDataCollection::add_value(int speed) {
	speed_.emplace_back(speed);
}

auto average = [](const std::vector<int>& v) ->double {
	double sum{};
	for (const auto& x : v)
	{
		sum += x;
	}
	return sum / v.size();
};

double SpeedDataCollection::AverageSoFar() const {
	return average(speed_);
}

template<typename T> 
T random(T range_from, T rang_to) {
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution<T> distr(range_from, rang_to);
	return distr(generator);
}
int main() {

	std::cout << "Item 22: Declare data members private." << std::endl;
	SpeedDataCollection yawen;
	/*srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		yawen.add_value(rand());
	}*/
	std::cout << "score: ";
	for (int i = 0; i < 10; i++)
	{
		int n = random<int>(60, 100);
		std::cout << n << " ";
		yawen.add_value(n);
	}
	std::cout << "\n";
	std::cout << "Average score: " << yawen.AverageSoFar() << std::endl;
	return 0;
}