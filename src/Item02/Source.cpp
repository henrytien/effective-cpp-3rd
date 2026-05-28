#include <iostream>
#include "Header.h"

GamePalyer::GamePalyer() {
	b = new int[5]{ 4,5,67,7 };
	memset(scores, 0, sizeof(scores));
}

GamePalyer::~GamePalyer() {
	delete b;
}

void GamePalyer::update_score(int a[], int n) {
	for (int i = 0; i < n; ++i)
	{
		scores[i] = a[i];
	}
}
template <typename T, size_t n>
void findSize(T(&arr)[n])
{
	std::cout << "sizeof of array: " << sizeof(T) * n << " count: " << n << std::endl;
}

int main() {

	std::cout << "Item 2: Prefer consts, enums, and inlines to #defines.\n";

	GamePalyer* player = new GamePalyer;
	int a[5] = { 1,3,4,5,6 };
	//int* b = new int[] {3, 4, 45, 5, 6};
	findSize(a);
	if (NULL != player)
	{
		player->update_score(player->b, 5);
		auto res = player->get_score();
		for (int i = 0; i < 5; ++i)
		{
			std::cout << "res: " << res[i] << std::endl;
		}
	}
	delete player;
	std::cout << "Hello Henry!" << std::endl;

	return 0;
}
