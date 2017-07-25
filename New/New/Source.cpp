#include <iostream>
#include <fstream>

#include <string>
#include <cstring>
#include <ctime>
#include <conio.h>
#include <cstdio>
#include <Windows.h>
#include <iomanip>

using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


const int maxLength = 200;
unsigned int length = 0;

struct Hesab {
	string ID;
	string PIN;
	double Balance;
};

Hesab Account[maxLength];

enum TransactionStatus {
	SUCCESS,
	NO_BALANCE,
	WRONG_PIN,
	WRONG_PAYER_ID,
	WRONG_RECEIVER_ID
};

void loadFromFile();
void saveToFile();

string Get_Random_Number(int length);
string Create_Your_PIN();
Hesab Create_New_Account(Hesab *arr);
Hesab Increase_Your_Balance(Hesab *arr, int i);
Hesab Decrease_Your_Balance(Hesab *arr, int i);
Hesab Operattions_On_Account(Hesab *arr);
Hesab Money_Transfer(Hesab *arr, int length);
void Check_Your_Balance(Hesab *arr);
void Back_to_Menu();

void hideCursor(bool is_visible = false) {
	CONSOLE_CURSOR_INFO info;
	info.bVisible = is_visible;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

/*
Yeni hesab acmaq.
Istifadeci pini deyishmek istediyi baresinde
secim cap olunur. deyishmek istemedikde, tesadufu pin cap olunur

Hesaba pul daxil etmek ve hesabdan pul cixartmaq
istifadeci hesab nomresini ve pini daxil edir,
hesabdan pul cixartmaq ve ya balansi artirmaq baresinde secim edir
meblegi daxil edir
pul artir/azalir

Bir hesabdan obiri hesaba pul kocurmek
Hesab sahibi oz id-ini ve pinini yigmalidir;
Hesab sahibi meblegi ve ikinci hesabin id-ni daxil
etmelidir;
Hesab sahibinin balansinda pul varsa, kocurmeni
yerine yetiririk;
Butun kocurmeler baresinde melumat yazilmalidir fayla;
Vaxt, hesab sahibinin id-i, ikinci hesab, mebleg,
tranzaksiyanin statusu

Hesabin balansini yoxlamaq
Hesab sahibi id ve pini yigir, balans cap olunur

Hesabda aparilan tranzaksiyalar baresinde melumat;
Hesab sahibi id ve pini yigir, kecirdiyi tranzaksiyalari
cap etme usullarini gorur;
SUCCESS, WRONG, ALL
-> THIS_DAY, THIS_WEEK, THIS_MONTH, ALL


PS Program ishini dayandirdigda butun hesablar fayla yazilir,
ishe salinanda ise fayldan oxunmalidir

PSS Pin kod daxil olunanda getch funksiyasinan istifade etmek lazim,
pin kod evezine konsola ulduzlar cap etmek
*/

int main() {

	loadFromFile();
	hideCursor();
	string Menu[5] = { "1. CREATE NEW ACCOUNT", "2. OPERATIONS ON ACCOUNT", "3. CHECK YOUR BALANCE", "4. MONEY TRANSFER", "5. EXIT" };
	int pointer = 0, key = 0;
	while (true) {
		SetConsoleCursorPosition(h, { 0, 0 });
		SetConsoleTextAttribute(h, 91);
		printf("%s\n\n", "MAIN MENU");
		for (int i = 0; i < 5; i++) {
			if (i == pointer) {
				SetConsoleTextAttribute(h, 298);
				cout << Menu[i] << endl;
			}
			else {
				SetConsoleTextAttribute(h, 15);
				cout << Menu[i] << endl;
			}
		}
		Sleep(100);
		key = getch();
		if (key == 224) {
			key = getch();
			if (key == 72) {
				pointer--;
				if (pointer == -1)
					pointer = 4;
			}
			else if (key == 80) {
				pointer++;
				if (pointer == 5)
					pointer = 0;
			}
		}
		else if (key == 13) {
			switch (pointer) {
			case 0: {
				system("cls");
				Create_New_Account(Account);
				Back_to_Menu(); break;
			}
			case 1: {
				Operattions_On_Account(Account);
				Back_to_Menu();
				break;
			}
			case 2: {
				Check_Your_Balance(Account);
				Back_to_Menu();
				break;
			}
			case 3: {
				Money_Transfer(Account, length);
				Back_to_Menu();
				break;
			}
			case 4:
				saveToFile();
				exit(0);
			}
		}
	}
	return 0;
}

void saveToFile() {
	if (Account[0].ID[0] != '\0')
	{
		0;
	}
	ofstream fout("text.txt");
	for (int i = 0; i < length; i++) {
		fout << Account[i].ID << ' ' << Account[i].PIN << ' ' << Account[i].Balance << endl;
	}
	/*fout << Account[length - 1].ID << " " << Account[length - 1].PIN << " " << Account[length - 1].Balance;
	fout.close();*/

}

void loadFromFile() {
	ifstream fin("text.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> Account[length].ID >> Account[length].PIN >> Account[length].Balance;
			if (!fin.eof())
			{
				length++;
			}
		}
	}
	fin.close();

}

string Get_Random_Number(int length) {
	srand(time(0));
	string random_number = "";
	for (int i = 0; i < length; i++)
		random_number += to_string(rand() % 10);
	return random_number;
}

string Create_Your_PIN() {
	char pin[5];
	bool onlyNumbers = false;
	SetConsoleCursorPosition(h, { 0, 2 });
	system("cls");
	do {
		SetConsoleCursorPosition(h, { 0, 3 });
		cout << "\nType Your PIN : ";
		for (int i = 0; i < 4; i++) {
			pin[i] = getch();
			cout << '*';
			if (pin[i] >= 48 && pin[i] <= 57)
				onlyNumbers = true;
			else {
				onlyNumbers = false;
				system("cls");
				SetConsoleCursorPosition(h, { 0, 1 });
				cout << "***PLEASE TYPE ONLY NUMBERS***";
				break;
			}
		}
	} while (!onlyNumbers);
	pin[4] = '\0';
	return pin;
}

Hesab Create_New_Account(Hesab *arr) {
	bool duplicate = false, pinChoice = false;
	string temp_number = "";
	char answer;
	char pin_choice;
	do {
		temp_number = Get_Random_Number(6);
		for (int i = 0; i < length; i++) {
			if (temp_number == arr[i].ID)
				duplicate = true;
		}
	} while (duplicate == true);

	arr[length].ID = temp_number;
	arr[length].Balance = 0.0;
	length++;

	cout << "Would you want to create your PIN ?" << endl;
	string menu[2] = { "- Yes"," - No" };
	short pointer = 0, key = 0;

	while (true) {
		SetConsoleCursorPosition(h, { 1, 2 });
		for (int i = 0; i < 2; i++) {
			if (i == pointer) {
				SetConsoleTextAttribute(h, 298);
				cout << menu[i] << endl;
			}
			else {
				SetConsoleTextAttribute(h, 15);
				cout << menu[i] << endl;
			}
		}
		key = getch();
		if (key == 224) {
			key = getch();
			if (key == 72) {
				pointer--;
				if (pointer == -1)
					pointer = 0;
			}
			else if (key == 80) {
				pointer++;
				if (pointer == 2)
					pointer = 1;
			}
		}
		else if (key == 13) {
			switch (pointer) {
			case 0: {
				Account[length - 1].PIN = Create_Your_PIN();
				pinChoice = true;
				break;
			}
			case 1: {
				Account[length - 1].PIN = Get_Random_Number(4);
				pinChoice = true;
				break;
			}
			}
			break;
		}
	}
	system("cls");
	cout << "\nYour Account ID : " << Account[length - 1].ID << endl;
	cout << "Your PIN        : " << Account[length - 1].PIN << endl;
	printf("Your Balance    : %.2f AZN\n\n", Account[length - 1].Balance);
	return *arr;
}

Hesab Increase_Your_Balance(Hesab *arr, int i) {
	system("cls");
	double money = 0.0;
	cout << "ENTER AMOUNT : "; cin >> money;
	arr[i].Balance += money;
	SetConsoleCursorPosition(h, { 0, 4 });
	SetConsoleTextAttribute(h, 6);
	cout << "TRANSACTION COMPLETED SUCCESSFULLY" << endl;
	cout << "YOUR BALANCE : " << arr[i].Balance << endl << endl;
	return *arr;
}

Hesab Decrease_Your_Balance(Hesab *arr, int i) {
	system("cls");
	double money = 0.0;
	cout << "ENTER AMOUNT : "; cin >> money;
	if (arr[i].Balance >= money) {
		arr[i].Balance -= money;
		SetConsoleCursorPosition(h, { 0, 4 });
		SetConsoleTextAttribute(h, 6);
		cout << "TRANSACTION COMPLETED SUCCESSFULLY\n\n" << endl;
		cout << "YOUR BALANCE : " << arr[i].Balance << endl << endl;
	}
	else {
		SetConsoleCursorPosition(h, { 0, 4 });
		SetConsoleTextAttribute(h, 6);
		cout << "NO ENOUGH FUNDS ON YOUR ACCOUNT\n\n";
		cout << "YOUR BALANCE : " << arr[i].Balance << endl << endl;
	}
	return *arr;
}

Hesab Operattions_On_Account(Hesab *arr) {
	string menu[2] = { "INCREASE YOUR BALANCE", "WITHDRAW MONEY FROM ACCOUNT" };
	string account_ID = "";
	string pin;
	int pointer = 0, key = 0;
	bool found = false;
	system("cls");
	cout << "ENTER YOUR ACCOUNT ID : "; cin >> account_ID;
	cout << "ENTER YOUR PIN :"; cin >> pin;
	for (int i = 0; i < length; i++) {
		if (account_ID == arr[i].ID  && pin == arr[i].PIN) {
			while (true) {
				system("cls");
				SetConsoleCursorPosition(h, { 0, 0 });
				for (int i = 0; i < 2; i++) {
					if (i == pointer) {
						SetConsoleTextAttribute(h, 11);
						cout << menu[i] << endl;
					}
					else {
						SetConsoleTextAttribute(h, 15);
						cout << menu[i] << endl;
					}
				}
				key = getch();
				if (key == 224) {
					key = getch();
					if (key == 72) {
						pointer--;
						if (pointer == -1)
							pointer = 1;
					}
					else if (key == 80) {
						pointer++;
						if (pointer == 2)
							pointer = 0;
					}
				}
				else if (key == 13) {
					switch (pointer) {
					case 0: {
						Increase_Your_Balance(Account, i);
						break; }
					case 1: {
						Decrease_Your_Balance(Account, i);
						break; }
					}
					break;
				}
			}
			found = true;
			break;
		}
	}
	if (found != true) {
		system("cls");
		SetConsoleTextAttribute(h, 12);
		cout << "\nWRONG ID!!! PLEASE TRY AGAIN:\n" << endl;
		SetConsoleTextAttribute(h, 11);
	}

	return *arr;
}

Hesab Money_Transfer(Hesab *arr, int length)
{
	string source_account_ID = "";
	string destination_account_ID = "";
	string pin = "";
	double amount = 0.0;
	short int source = 0;
	short int destination = 0;
	bool found_source = false;
	bool found_dest = false;
	system("cls");
	cout << "ENTER YOUR ACCOUNT ID : "; cin >> source_account_ID;
	cout << "ENTER PIN : "; cin >> pin;
	for (int i = 0; i < length; i++) {
		if (source_account_ID == arr[i].ID && pin == arr[i].PIN) {
			source = i;
			found_source = true;
			break;
		}
	}
	if (!found_source) {
		system("cls");
		SetConsoleCursorPosition(h, { 0, 0 });
		cout << "***WRONG ACCOUNT ID or PIN***\n";
		cout << "      PLEASE TRY AGAIN\n\n";
		return *arr;
	}

	system("cls");
	cout << "ENTER OTHER ACCOUNT ID : "; cin >> destination_account_ID;
	for (int j = 0; j < length; j++) {
		if (destination_account_ID == arr[j].ID) {
			destination = j;
			found_dest = true;
			break;
		}
	}
	if (!found_dest) {
		system("cls");
		SetConsoleCursorPosition(h, { 0, 2 });
		cout << "***ENTERED ACCOUNT IS NOT EXIST***\n\n";
		cout << "      PLEASE TRY AGAIN\n\n";
		return *arr;
	}

	cout << "ENTER AMOUNT : "; cin >> amount;
	if (arr[source].Balance >= amount) {
		arr[source].Balance -= amount;
		arr[destination].Balance += amount;
		system("cls");
		SetConsoleCursorPosition(h, { 0, 2 });
		cout << "***TRANSACTION COMPLETED SUCCESSFULLY***";
	}
	else {
		system("cls");
		cout << "***NOT ENOUGH FUNDS ON YOUR ACCOUNT***";
	}

	return *arr;
}

void Check_Your_Balance(Hesab *arr) {
	system("cls");
	string account_ID = "";
	string pin;
	bool found = false;
	cout << "ENTER YOUR ACCOUNT ID : "; cin >> account_ID;
	cout << "ENTER YOUR PIN : ";  cin >> pin;
	for (int i = 0; i < length; i++) {
		if (account_ID == arr[i].ID && pin == arr[i].PIN) {
			system("cls");
			cout << "ACCOUNT DETAILS : \n\n";
			cout << "ACCOUNT ID : " << arr[i].ID << endl;
			cout << "BALANCE    : " << arr[i].Balance << endl;
			found = true;
		}
	}

	if (!found) {
		system("cls");
		SetConsoleCursorPosition(h, { 0, 4 });
		SetConsoleTextAttribute(h, 6);
		cout << "***WRONG ID NUMBER OR PIN***" << endl;
		cout << "  ***PLEASE TRY AGAIN***" << endl;
		return;
	}
}

void Back_to_Menu() {
	int pointer = 0, key = 0;
	string menu[2] = { "Back to Main Menu", "EXIT" };
	while (true) {
		SetConsoleCursorPosition(h, { 0, 15 });
		for (int i = 0; i < 2; i++) {
			if (i == pointer) {
				SetConsoleTextAttribute(h, 11);
				cout << menu[i] << endl;
			}
			else {
				SetConsoleTextAttribute(h, 15);
				cout << menu[i] << endl;
			}
		}
		key = getch();
		if (key == 224) {
			key = getch();
			if (key == 72) {
				pointer--;
				if (pointer == -1)
					pointer = 1;
			}
			else if (key == 80) {
				pointer++;
				if (pointer == 2)
					pointer = 0;
			}

		}
		else if (key == 13) {
			switch (pointer) {
			case 0: system("cls");
				return;
			case 1: {
				saveToFile();
				exit(0);
			}
			}
		}
	}
}
