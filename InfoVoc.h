#pragma once
#include <string>
using namespace std;

struct InfoVoc
{
private:
	string eng_word;
	string ru_word;
	int count;
	InfoVoc* left, *right;
	explicit InfoVoc(string eng_word, string ru_word, int count)
	{
		this->eng_word = eng_word;
		this->ru_word = ru_word;
		this->count = count;
		left = nullptr;
		right = nullptr;
	}
public:
	~InfoVoc() { left = right = nullptr; };
	friend class Vocabulary;
};