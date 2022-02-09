#include "Header.h"
FileSystem::FileSystem()
{
}

FileSystem::~FileSystem()
{
}

std::size_t FileSystem::numDisks() const {
	return 40000;
}

FileSystem& FileSystem::tfs() {
	static FileSystem fs;
	return fs;
}
//FileSystem tfs;

int main() {
	//FileSystem file;
	//tfs = file;
	Directory tempDir("d");

	std::cout << "Henry!" << std::endl;
}