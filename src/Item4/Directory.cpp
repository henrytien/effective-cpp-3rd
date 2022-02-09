#include "Header.h"


Directory::Directory(const std::string& str) :_name(str)
{
	FileSystem fs;
	std::size_t disks = fs.tfs().numDisks();
}

Directory::~Directory()
{
}

Directory& Directory::tempDir() {
	static Directory td("local static");
	return td;
}

