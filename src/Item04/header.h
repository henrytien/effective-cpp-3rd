#pragma once
#include<iostream>
class FileSystem
{
public:
	FileSystem();
	~FileSystem();
	std::size_t numDisks() const; // one of many member functions
	FileSystem& tfs();
private:
	
};

//extern FileSystem tfs;

class Directory
{
public:
	Directory(const std::string& str);
	~Directory();
	Directory& tempDir();
private:
	std::string _name;
};