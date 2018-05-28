#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
int FileOpenError() {
	cout << "Сan't create the file or file is busy. Exiting program...\n";
	system("pause");
	exit(1);
}
class AddressBook
{
private:
	string book_name;
	string lastname, firstname, phonenumber, email;
public:
	AddressBook(string book_name) {
		ofstream adbook;
		adbook.open(book_name, ios::in);
		if (!adbook.is_open()) {
			FileOpenError();
		}
		else {
			cout << "File Successfully Opened!";
			adbook.close();
		}
	}
	void read(string book_name) {
		ifstream adbook;
		adbook.open(book_name, ios_base::in);    // открыть файл на чтение
		string str;            // статический буфер строки
							   // Считывать и отображать строки в цикле, пока не eof
		while (getline(adbook, str))
		{
			cout << str << '\n';
		}
		adbook.close();
	}
	void append(string book_name) {
		cout << "\nEnter firstname: "; cin >> firstname;
		cout << "\nEnter lastname: "; cin >> lastname;
		cout << "\nEnter phonenumber: "; cin >> phonenumber;
		cout << "\nEnter email: "; cin >> email;
		ofstream adbook;
		adbook.open(book_name, ios_base::in | ios_base::out | ios_base::app);
		adbook << firstname << "\t" << lastname << "\t" << phonenumber << "\t" << email << endl;
		adbook.close();
	}
	void rewrite(string book_name) {
		ofstream adbook;
		adbook.open(book_name, ios_base::in | ios_base::out | ios_base::trunc);
		adbook.close();
		append(book_name);
	}
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	string book_name;
	cout << "Enter a filename for addressbook: "; cin >> book_name;
	AddressBook book(book_name);
	cout << "\n\n" << "Select menu item: \n";
	cout << "1. Read the file\n";
	cout << "2. Append line to the file\n\n";
	cout << "5. Rewrite file\n";
	cout << "9. Exit\n";
	cout << "Item: ";
	int n;
	cin >> n; cout << endl;
	switch (n) {
	case 1: { book.read(book_name); break; }
	case 2: { book.append(book_name); break; }
	case 5: { book.rewrite(book_name); break; }
	case 9: { cout << "Выход из программы\n"; exit(1); }
	}
	system("pause");
	return 0;
}