#include<iostream>
#include <cstring>
#include <string>

class TextBlock
{
public:
	TextBlock(std::string str);
	~TextBlock();

	// operator[] for const objects
	const char& operator[](std::size_t position) const {
		return text[position];
	}
	// operator[] for non-const objects
	char& operator[](std::size_t position) {
		//return text[position];
		return const_cast<char&>(static_cast<TextBlock const&>(*this)[position]);
	}
	void print(const TextBlock& ctb) {
		std::cout << ctb[0] << std::endl;
	}
	void printConst(const TextBlock& ctb) const {
		std::cout << "printConst: " << ctb[0] << std::endl;
	}
	void test();
private:
	std::string text;

};

TextBlock::TextBlock(std::string str) :text(str)
{
}

TextBlock::~TextBlock()
{
}

void TextBlock::test() {
	// calls non-const TextBlock::operator[]
	TextBlock tb("Hello");
	std::cout << tb[0] << std::endl;

	// calls non-const TextBlock::operator[]
	const TextBlock ctb("World");
	std::cout << ctb[0] << std::endl;

	tb.print(tb);
	ctb.printConst(tb);
}

class CTextBlock
{
public:
	CTextBlock(std::string const& str);
	~CTextBlock();

	char& operator[](std::size_t position) const {
		return pText[position];
	}
	std::size_t length() const;
	void print(const CTextBlock& cctb) {
		std::cout << cctb.pText << std::endl;
	}
	void test();
private:

	void log(const char* msg) {
		std::cout << "[" << this << "]" << msg << std::endl;
	}
	char* pText;
	mutable std::size_t textLength;
	mutable bool lengthValid; // 
};

CTextBlock::CTextBlock(std::string const& str) :pText(const_cast<char*>(str.c_str())),
textLength(0), lengthValid(false)
{
}

CTextBlock::~CTextBlock()
{
}

std::size_t CTextBlock::length() const { 
	if (!lengthValid)
	{
		textLength = strlen(pText);
		lengthValid = true;
	}
	return textLength;
}
void CTextBlock::test() {
	const CTextBlock cctb("Hello");
	char* pc = &cctb[0];
	*pc = 'C';
	print(cctb);
}
int main() {
	std::cout << "Item 3: Use const whenever possible.\n";

	TextBlock tb("Hello");
	tb.test();
	/*CTextBlock cctb("Hello");
	cctb.test();*/

	std::cout << "Hello Henry~" << std::endl;
	return 0;
}