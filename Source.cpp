#include "Vocabulary.h"

int main()
{
	setlocale(LC_ALL, "");
	Vocabulary my;
	string s;
	my.AddName("alex", "���������", 10);
	my.AddName("flash", "������", 2);
	my.AddName("count", "����������", 3);
	my.AddName("music", "������", 4);
	my.AddName("autor", "�����", 8);
	my.AddName("apple", "yabloko", 1);
	my.AddName("flowers", "�����", 16);
	my.AddName("peag", "������", 19);
	my.AddName("gun", "������", 33);
	my.AddName("teacher", "�������", 24);
	my.AddName("candy", "�������", 18);
	my.ChangeTranslate("�������", "67");//���� ������� � ������� �� �������� �� �����, ������� ������������ ������ �� �������� ������ ���
	my.Menu();
	system("pause");
	return 0;
}