/*
	SpellNode-Editor
	By:

	Hassan bin Aman		221490
	Sharjeel Iftikhar	221534
	Muhammad Huzaifa	221564

	( DSA End semester project)
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h> 
using namespace std;

class Node {
public:
	Node* before;
	Node* after;
	char Data;
	Node* below;
	Node* above;
	Node(char Data)
	{
		this->Data = Data;
		before = nullptr;
		after = nullptr;
		below = nullptr;
		above = nullptr;
	}
	~Node()
	{}
};
class Doublylinkedlist
{
private:
	Node* head;
	Node* tail;
	Node* line;
	Node* cursor;
public:
	Doublylinkedlist()
	{
		Node* NewNode = new Node('|');
		head = NewNode;
		tail = NewNode;
		line = NewNode;
		cursor = NewNode;
	}
	void Insert(char data)
	{
		Node* temp = cursor;
		while(temp->after)
		{ 
			temp = temp->after;
		}
		Node* NewNode = new Node(temp->Data);
		NewNode->before = temp;
		temp->after = NewNode;
		if (temp->above)
		{
			if (temp->above->after)
			{
				NewNode->above = temp->above->after;
				NewNode->above->below = NewNode;
			}
		}
		if (temp->below)
		{
			if (temp->below->after)
			{
				NewNode->below = temp->below->after;
				NewNode->below->above = NewNode;
			}
		}
		while (temp != cursor)
		{
			temp->Data = temp->before->Data;
			temp = temp->before;
		}
		temp->Data = data;
		cursor = cursor->after;
	}
	void Moveright()
	{
		if (cursor->after)
		{
			cursor->Data = cursor->after->Data;
			cursor->after->Data = '|';
			cursor = cursor->after;
		}
		else
		{
			Node* NewNode = new Node('|');
			cursor->Data = ' ';
			cursor->after = NewNode;
			NewNode->before = cursor;
			if (cursor->above)
			{
				if (cursor->above->after)
				{
					cursor->above->after->below = NewNode;
					NewNode->above = cursor->above->after;
				}
			}
			if (cursor->below)
			{
				if (cursor->below->after)
				{
					cursor->below->after->after = NewNode;
					NewNode->below = cursor->below->after;
				}
			}
			cursor = NewNode;
		}
	}
	void Moveabove()
	{
		if (line->above == nullptr)
			return;
		else if (cursor->above)
		{
			line = line->above;
			cursor = cursor->above;
			Insert('|');
			cursor = cursor->before->below;
			if (cursor->before == nullptr && cursor->after == nullptr)
			{
				cursor->Data = ' ';
				cursor = cursor->above;
				return;
			}
			else if (cursor->after == nullptr)
			{
				Node* temp = cursor;
				if (temp->below)
				{
					temp->below->above = nullptr;

				}
				if (temp->above)
				{
					temp->above->below = nullptr;

				}
				if (temp->before)
				{
					temp->before->after = nullptr;

				}
				cursor = cursor->above;
				delete temp;	
			}
			else
			{
				cursor = cursor->after;
				Delete();
				cursor = cursor->above;
			}
			
		}
		else
		{
			line = line->above;
			Node* temp = line;
			while (temp->after)
			{
				temp = temp->after;
			}
			Node* NewNode = new Node('|');
			temp->after = NewNode;
			NewNode->before = temp;
			if (temp->below)
			{
				if (temp->below->after)
				{
					temp->below->after->above = NewNode;
					NewNode->below = temp->below->after;
				}
			}
			if (temp->above)
			{
				if (temp->above->after)
				{
					temp->above->after->below = NewNode;
					NewNode->above = temp->above->after;
				}
			}
			if (cursor->before == nullptr && cursor->after == nullptr)
			{
				cursor->Data = ' ';
				cursor == NewNode;
				return;
			}
			else if (cursor->after == nullptr)
			{
				Node* temp = cursor;
				if (temp->below)
				{
					temp->below->above = nullptr;

				}
				if (temp->above)
				{
					temp->above->below = nullptr;

				}
				if (temp->before)
				{
					temp->before->after = nullptr;

				}
				cursor = NewNode;
				delete temp;
			}
			else
			{
				cursor = cursor->after;
				Delete();
				cursor = NewNode;
			}
		}
	}
	void Movebelow()
	{
		if (line->below == nullptr)
		{
			Node* NewNode = new Node('|');
			line->below = NewNode;
			NewNode->above = line;
			line = NewNode;
			tail = NewNode;
			if (cursor->after)
			{
				cursor = cursor->after;
				Delete();
			}
			else
			{
				Node* temp = cursor;
				if (temp->below)
				{
					temp->below->above = nullptr;

				}
				if (temp->above)
				{
					temp->above->below = nullptr;

				}
				if (temp->before)
				{
					temp->before->after = nullptr;

				}
				cursor = NewNode;
				delete temp;
			}
			cursor = NewNode;
		}
		else if (cursor->below)
		{
			line = line->below;
			cursor = cursor->below;
			Insert('|');
			cursor = cursor->before->above;
			if (cursor->before == nullptr && cursor->after == nullptr)
			{
				cursor->Data = ' ';
				cursor = cursor->below;
				return;
			}
			else if (cursor->after == nullptr)
			{
				Node* temp = cursor;
				if (temp->below)
				{
					temp->below->above = nullptr;

				}
				if (temp->above)
				{
					temp->above->below = nullptr;

				}
				if (temp->before)
				{
					temp->before->after = nullptr;

				}
				cursor = cursor->below;
				delete temp;
			}
			else
			{
				cursor = cursor->after;
				Delete();
				cursor = cursor->below;
			}
		}
		
		else
		{
			line = line->below;
			Node* temp = line;
			while (temp->after)
			{
				temp = temp->after;
			}
			Node* NewNode = new Node('|');
			temp->after = NewNode;
			NewNode->before = temp;
			if (temp->below)
			{
				if (temp->below->after)
				{
					temp->below->after->above = NewNode;
					NewNode->below = temp->below->after;
				}
			}
			if (temp->above)
			{
				if (temp->above->after)
				{
					temp->above->after->below = NewNode;
					NewNode->above = temp->above->after;
				}
			}
			if (cursor->before == nullptr && cursor->after == nullptr)
			{
				cursor->Data = ' ';
				cursor == NewNode;
				return;
			}
			else if (cursor->after == nullptr)
			{
				Node* temp = cursor;
				if (temp->below)
				{
					temp->below->above = nullptr;

				}
				if (temp->above)
				{
					temp->above->below = nullptr;

				}
				if (temp->before)
				{
					temp->before->after = nullptr;

				}
				cursor = NewNode;
				delete temp;
			}
			else
			{
				cursor = cursor->after;
				Delete();
				cursor = NewNode;
			}
		}
	}
	void Moveleft()
	{
		if (cursor->before)
		{
			cursor->Data = cursor->before->Data;
			cursor->before->Data = '|';
			cursor = cursor->before;
		}
	}
	void Print()
	{
		Node* temp = head;
		while (temp)
		{
			Node* temp2 = temp;
			while (temp2 != nullptr)
			{
				cout << temp2->Data;
				temp2 = temp2->after;
			}
			cout << endl;
			temp = temp->below;
		}
	}
	void Find(char data)
	{
		Node* temp = head;
		while (temp)
		{
			Node* temp2 = temp;
			while (temp2)
			{
				if (temp2->Data == data)
				{
					cout << temp2->Data;
					if (temp2->above)
						cout << temp2->above->Data;
					if (temp2->below)
						cout << temp2->below->Data;
					if (temp2->before)
						cout << temp2->before->Data;
					if (temp2->after)
						cout << temp2->after->Data;

				}
				temp2 = temp2->after;
			}
			cout << endl;
			temp = temp->below;
		}

	}
	string Saving()
	{
		string Save="";
		Node* temp = head;
		while (temp)
		{
			Node* temp2 = temp;
			while (temp2)
			{
				if (temp2 != cursor)
				{
					Save += temp2->Data;
				}
				temp2 = temp2->after;
			}
			temp = temp->below;
		}
		return Save;

	}
	void Delete()
	{
		if (cursor->before==nullptr)
		{
			return;
		}
		Node* temp = cursor->before;
		cursor = cursor->before;
		while (temp->after)
		{
			temp->Data = temp->after->Data;
			temp = temp->after;
		}
		if (temp->above)
		{
			temp->above->below = nullptr;
		}
		if (temp->below)
		{
			temp->below->above = nullptr;
		}
		if (temp->before)
		{
			temp->before->after = nullptr;
		}
		temp->above = nullptr;
		temp->below = nullptr;
		temp->after = nullptr;
		temp->before = nullptr;
		
		delete temp;

	}
	~Doublylinkedlist()
	{}
};
void SpellChecker(vector<string> Dictionary, string text)
{
	string temp;
	int hl = 0;
	cout << "Here are the alternatives for given word:\n";
	cout << "\n After Letter Substitution:\n";
	for (int i = 0; i < text.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			temp = text;
			temp[i] = char(97 + j);
			for (int k = 0; k < Dictionary.size(); k++)
			{
				if (Dictionary[k] == temp)
				{
					cout << Dictionary[k] << ", ";
					hl = 1;
				}
			}
		}
	}
	cout << "\nAter Letter Omission:\n";
	for (int i = 0; i < text.size(); i++)
	{
		temp = text;
		int count = 0;
		for (int j = 0; j < text.size(); j++)
		{
			if (i != j)
			{
				temp[count] = text[j];
				count++;
			}
		}
		temp.pop_back();

		for (int k = 0; k < Dictionary.size(); k++)
		{
			if (Dictionary[k] == temp)
			{
				cout << Dictionary[k] << ", ";
				hl = 1;
			}
		}
	}
	cout << "\n After Inserting a letter:\n";
	for (int j = 0; j <= text.size(); j++)
	{
		temp = text;
		temp += 't';
		for (int k = temp.size() - 1; k > j; k--)
		{
			temp[k] = temp[k - 1];
		}
		for (int k = 0; k < 26; k++)
		{
			temp[j] = char(97 + k);
			for (int k = 0; k < Dictionary.size(); k++)
			{
				if (Dictionary[k] == temp)
				{
					cout << Dictionary[k] << ", ";
					hl = 1;
				}
			}
		}
	}
	cout << "\nAfter Letter Reversal:\n";
	for (int i = 0; i < text.size() - 1; i++)
	{
		temp = text;
		char t = text[i];
		temp[i] = temp[i + 1];
		temp[i + 1] = t;
		for (int k = 0; k < Dictionary.size(); k++)
		{
			if (Dictionary[k] == temp)
			{
				cout << Dictionary[k] << ", ";
				hl = 1;
			}
		}
	}
	if (hl == 0)
		cout << "\nYou are a hopeless speller!\n";
}
void clearScreen() {
	system("cls");
}
int main()
{
	char ch='\0';
	string line;
	string word="";
	Doublylinkedlist text;
	vector<string> Dictionary;
	ifstream file("dictionary.txt");
	if (file) {
		string line;
		while (getline(file, line)) {
			Dictionary.push_back(line);
		}
		file.close();
	}
	
	while (true) {
		clearScreen();
		if(word!="")
		SpellChecker(Dictionary, word);
		cout << "Text Notepad" << endl;
		cout << "-------------" << endl;
		text.Print();

		ch = _getch();

		if (ch == 12) { // Ctrl + L (Load)
			ifstream file("Save.txt");
			if (file) {
				while (getline(file, line)) {
					for (int i = 0; i < line.size(); i++)
					{
						text.Insert(line[i]);
					}
				}
				file.close();
			}
			else {
				cout << "File not found or unable to open." << endl;
			}
		}

		if (ch == 19) { // Ctrl + S (Save)
			ofstream file("Save.txt");
			if (file) {
				file << text.Saving();
				file.close();
				cout << "Text saved successfully." << endl;
			}
			else {
				cout << "Unable to open or create the file for saving." << endl;
			}
		}

		if (ch == 32) //space key
		{
			word = "";
		}

		if (ch == 8) { // Backspace (Delete)
			text.Delete();
			if(word.size()!=0)
			word.pop_back();
		}
		
		else if (ch == 27) { // ESC (Quit)
			cout << "Allah Hafiz Exiting the program.\n";
			break;
		}
		else if (ch == 75) { // Left Arrow
			text.Moveleft();
			word = "";
		}
		else if (ch == 77) { // Right Arrow
			text.Moveright();
			word = "";
		}
		else if (ch == 72) { // Above Arrow
			text.Moveabove();
			word = "";
		}
		else if (ch == 80) { // below Arrow
			text.Movebelow();
			word = "";
		}
		else {
			if (ch != '�')
			{
			text.Insert(ch);
			if(ch!=32)
			word += ch;
			}
		}
	}
	return 0;
}
