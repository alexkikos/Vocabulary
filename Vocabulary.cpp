#include "Vocabulary.h"
int Vocabulary::count = 0;
bool Vocabulary::result = false;
void Vocabulary::AddWord(InfoVoc*& head, string en, string ru, int count)
{
	InfoVoc* temp = new InfoVoc(en, ru, count);
	if (!head) head = temp;
	else
	{
		InfoVoc* first = head;
		while (first)
		{
			if (en < first->eng_word)
			{
				if (!first->left)
				{
					first->left = temp;
					first = temp->left;
				}
				else
					first = first->left;
			}
			else
			{
				if (!first->right)
				{
					first->right = temp;
					first = temp->right;
				}
				else
					first = first->right;
			}
		}
	}
}

void Vocabulary::AddWord_Count(InfoVoc*& head, string en, string ru, int count)
{
	InfoVoc* temp = new InfoVoc(en, ru, count);	
	if (!head)
	{
		head = temp;
		return;
	}
	else
		if (count < head->count) AddWord_Count(head->left, en, ru, count);
		else
			AddWord_Count(head->right, en, ru, count);
}


void Vocabulary::AddName(string en, string ru, int count)
{
	AddWord(root, en, ru, count);
}

void Vocabulary::Show()
{
	ShowTree(root);
}

void Vocabulary::FindTop(int top)
{
	while (count_tree)  Delete(count_tree, count_tree->eng_word);//чищу значения во втором дереве, которое выстраивается исходя из счетчиков обращений
	NewTree(root);
	count = 0;
	result = false;
	Top(count_tree, top);
	if (result == false) cout << "\nNo TOP";
}

void Vocabulary::Unpopular(int top)
{
	while (count_tree) Delete(count_tree, count_tree->eng_word);//чищу значения во втором дереве, которое выстраивается исходя из счетчиков обращений
	NewTree(root);//выстариваю новое дерево исходя из счетчиков обращений
	count = 0;
	result = false;
	Unpopu(count_tree, top);
	if (result == false) cout << "\nNo unpopular";
}

void Vocabulary::ChangeTranslate(string what_find, string on_what_change)
{
	result = false;
	ChangeWord(root, what_find, on_what_change);
	if (result == false) cout << "\nCant find this word for traslate\n";
}

void Vocabulary::ShowTranslateFromEn(string word)
{
	result = false;
	ShowTranslateWord(root, word);
	if (result == false) cout << "\nCant find this word\n";
}

void Vocabulary::DeleteTree(string en_word)
{
	 Delete(root, en_word);

}

void Vocabulary::DeleteALL()
{
	while (root)
	{
		Delete(root, root->eng_word);
	}
}

void Vocabulary::Menu()
{
	char a = ' ';
	string s, s1;
	int n;
	cout << "1. Add word" << endl;
	cout << "2. Find word" << endl;
	cout << "3. Show current vocabulary" << endl;
	cout << "4. Show top 5 word" << endl;
	cout << "5. Show top 5 unpopullar" << endl;
	cout << "6. Change translation" << endl;
	cout << "7. Delete All" << endl;
	cout << "8. Delete word" << endl;
	cout << "9. Exit" << endl;
	while (a != '9')
	{
		cin >> a;
		switch (a)
		{
		case '1':
			cout << "\n Enter egn word: ";
			cin >> s;
			cout << "\n Enter translation: ";
			cin >> s1;
			cout << "\nEnter number of calls: ";
			cin >> n;
			AddName(s, s1, n);
			break;
		case '2':

			cout << "\n Enter word for find eng/ru: ";
			cin >> s;
			ShowTranslateFromEn(s);
			break;
		case '3': Show(); break;
		case '4':
			cout << "\nEnter amount of words: ";
			cin >> n;
			FindTop(n);
			break;
		case '5':
			cout << "\nEnter amount of words: ";
			cin >> n;
			Unpopular(n);
			break;
		case '6':
			cout << "\nEnter word what need change: ";
			cin >> s;
			cout << "\nEnter word on what change: ";
			cin >> s;
			ChangeTranslate(s, s1);
			break;
		case '7': DeleteALL(); break;
		case '8':
			cout << "\nEnter eng word for delete: ";
			cin >> s;
			DeleteTree(s);
			break;
		default:
			break;
		}
	}
}

void Vocabulary::ShowTree(InfoVoc* tmp)
{
	if (tmp)
	{
		ShowTree(tmp->left);
		cout << tmp->eng_word << " " << tmp->ru_word << " : " << " количество обращений: " << tmp->count << endl;
		ShowTree(tmp->right);
	}

}

void Vocabulary::Top(InfoVoc* head, int top)
{
	if (head)
	{
		Top(head->right, top);
		if (count == top) { result = true; return; }
		cout << head->eng_word << "=" << head->ru_word << " количество обращений " << head->count << endl;
		count++;
		Top(head->left, top);
	}
}

void Vocabulary::Unpopu(InfoVoc* head, int top)
{
	if (head)
	{
		Unpopu(head->left, top);
		if (count == top) { result = true; return; }
		cout << head->eng_word << " " << head->ru_word << " количество обращений " << head->count << endl;
		count++;
		Unpopu(head->right, top);
	}
}

void Vocabulary::ChangeWord(InfoVoc* head, string what_find, string on_what_change)
{
	if (!head) return;
	else
	{
		if (head)
		{
			ChangeWord(head->left, what_find, on_what_change);
			if (head->ru_word == what_find) { head->ru_word = on_what_change; result = true; return; }
			ChangeWord(head->right, what_find, on_what_change);
		}
	}
}

void Vocabulary::ShowTranslateWord(InfoVoc* head, string word)
{
	if (head)
	{
		if (head->eng_word == word or head->ru_word == word)
		{
			cout << "Translate = " << head->eng_word << "=" << head->ru_word << endl;
			result = true;
			++head->count;
			return;
		}
		ShowTranslateWord(head->left, word);
		ShowTranslateWord(head->right, word);
	}
}

void Vocabulary::NewTree(InfoVoc* head)
{
	if (head)
	{
		NewTree(head->left);
		NewTree(head->right);
		AddWord_Count(count_tree, head->eng_word, head->ru_word, head->count);
	}
}

void Vocabulary::Delete(InfoVoc*& head, string word)
{
	InfoVoc* temp;
	InfoVoc* next;
	if (!head) return;
	else
	{
		if (word < head->eng_word)
			Delete(head->left, word);
		else
			if (word > head->eng_word)
				Delete(head->right, word);
			else
			{
				temp = head;
				if (!head->right)
					head = head->left;
				else
					if (!head->left)
						head = head->right;
					else
					{
						next = head->left;
						if (next->right)
						{
							while (next->right->right)
							{
								next = next->right;
							}
							head->count = next->right->count;
							head->eng_word = next->right->eng_word;
							head->ru_word = next->right->ru_word;

							temp = next->right;
							next->right = next->right->left;

						}
						else
						{
							head->count = next->count;
							head->eng_word = next->eng_word;
							head->ru_word = next->ru_word;
							temp = next;
							head->left = head->left->left;
						}
					}

				delete temp;
			}
	}
}




Vocabulary::Vocabulary()
{
	root = nullptr;
	count_tree = nullptr;
}

Vocabulary::~Vocabulary()
{
	while (root)  Delete(root, root->eng_word);
	while (count_tree)  Delete(count_tree, count_tree->eng_word);
	delete count_tree;
	delete root;
}

