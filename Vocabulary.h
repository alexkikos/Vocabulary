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
	int static count;//������ ��� ������ ����� + ������ �������� � �����.���������
	bool static result;//���������� ������ ������ ���������� ��� ������ � ���������

	void AddWord(InfoVoc*& head, string en, string ru, int count);//��������� �� ������, ����� �� ���������� ��������� ������
	void AddWord_Count(InfoVoc*& head, string en, string ru, int count);//��������� �� ������, ����� �� ���������� ��������� ������, 2 ������ ��� ���������� �� �������� ���������
	void ShowTree(InfoVoc* tmp);
	void Top(InfoVoc* head, int top);
	void Unpopu(InfoVoc* head, int top);
	void ChangeWord(InfoVoc* head, string what_find, string on_what_change);
	void ShowTranslateWord(InfoVoc* head, string word);
	void NewTree(InfoVoc* head);//����� ��� �������� ������ ������ ��� ��������� ��������� ���������
	void Delete(InfoVoc*& head, string word);
public:

	void AddName(string en, string ru, int count);//���������� �����
	void Show();//����������� ���� ���� �� �����������
	void FindTop(int top);//�������� ��� � ����
	void Unpopular(int top);//�������� ����� �� ����������
	void ChangeTranslate(string what_find, string on_what_change);//�������� ������� ����� �� ������ �����
	void ShowTranslateFromEn(string word);//����� �� ������ ����� ���� � ���������� ��� ��������
	void DeleteTree(string en_word);
	void DeleteALL();
	void Menu();
	Vocabulary();
	~Vocabulary();

};

