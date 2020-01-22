#include "Vocabulary.h"

int main()
{
	setlocale(LC_ALL, "");
	Vocabulary my;
	string s;
	my.AddName("alex", "александр", 10);
	my.AddName("flash", "молния", 2);
	my.AddName("count", "количество", 3);
	my.AddName("music", "музыка", 4);
	my.AddName("autor", "автор", 8);
	my.AddName("apple", "yabloko", 1);
	my.AddName("flowers", "цветы", 16);
	my.AddName("peag", "свинья", 19);
	my.AddName("gun", "оружие", 33);
	my.AddName("teacher", "учитель", 24);
	my.AddName("candy", "конфета", 18);
	my.ChangeTranslate("учитель", "67");//если вводить с консоли ру символов не видит, поэтому демонстрация замены ру перевода только тут
	my.Menu();
	system("pause");
	return 0;
}