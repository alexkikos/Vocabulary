#pragma once
#include "InfoVoc.h"
#include <iostream>
#include <xstring>
#include <string.h>
using namespace std;
class Vocabulary
{
	InfoVoc* root;
	InfoVoc* count_tree;
	int static count;//служит для отбора топов + точкой остановы в соотв.рекурсияъ
	bool static result;//обратаываю ошибки статик переменной при работе с рекурсией

	void AddWord(InfoVoc*& head, string en, string ru, int count);//указатель по ссылке, чтобы не возвращать постояноо голову
	void AddWord_Count(InfoVoc*& head, string en, string ru, int count);//указатель по ссылке, чтобы не возвращать постояноо голову, 2 дерево для построения по счетчику обращений
	void ShowTree(InfoVoc* tmp);
	void Top(InfoVoc* head, int top);
	void Unpopu(InfoVoc* head, int top);
	void ChangeWord(InfoVoc* head, string what_find, string on_what_change);
	void ShowTranslateWord(InfoVoc* head, string word);
	void NewTree(InfoVoc* head);//метод для создания нового дерева для обработки счетчиков обращений
	void Delete(InfoVoc*& head, string word);
public:

	void AddName(string en, string ru, int count);//добавление слова
	void Show();//отображение всех слов по возрастанию
	void FindTop(int top);//показать топ Т слов
	void Unpopular(int top);//показать самые не популярные
	void ChangeTranslate(string what_find, string on_what_change);//заменить перевод слова на другое слово
	void ShowTranslateFromEn(string word);//поиск по дереву слова англ и распечатка его перевода
	void DeleteTree(string en_word);
	void DeleteALL();
	void Menu();
	Vocabulary();
	~Vocabulary();

};

