#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

const int maxLength = 200;
unsigned int length = 5;


enum TransactionStatus {
	SUCCESS,
	NO_BALANCE,
	WRONG_PIN,
	WRONG_PAYER_ID,
	WRONG_RECEIVER_ID
};


struct Hesab {
	string ID;
	string PIN;
	double Balance;
};


Hesab Account[maxLength] = {
	{ "543634", "4325", 100.3 },
	{ "934675", "1280", 15000 },
	{ "442685", "5082", 1023.84 },
	{ "222011", "8624", 1004.23 },
	{ "276590", "3684", 1056.01 }
};


string Get_Random_Number(int length) {
	srand(time(0));
	string random_number = "";
	for (int i = 0; i < length; i++) {
		random_number += to_string(rand() % 10);
	}
	return random_number;
}


string Create_Your_PIN() {
	char pin[4];
	for (int i = 0; i < 4; i++) {
		pin[i] = getch();
		cout << '*';
	}
	pin[4] = '\0';

	return pin;
}


Hesab Create_New_Account(Hesab *arr) {
	bool duplicate = false;
	string temp_number = " ";
	char answer;
	temp_number = Get_Random_Number(6);
	do {
		for (int i = 0; i < length; i++) {
			if (temp_number == arr[i].ID) {
				duplicate = true;
			}
			else {}
		}
	} while (duplicate == true);

	arr[length].ID = temp_number;
	arr[length].Balance = 0.0;
	length++;
	return *arr;
}


void hideCursor(bool is_visible = false)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = is_visible;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void backMenu() {
	SetConsoleCursorPosition(h, { 0, 5 });
	int pointer = 0, key = 0;
	string menu[2] = { "Back to Main Menu", "EXIT" };
	while (true) {
		SetConsoleCursorPosition(h, { 0, 5 });
		for (int i = 0; i < 2; i++)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(h, 10);
				cout << menu[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(h, 15);
				cout << menu[i] << endl;
			}
		}
		key = getch();
		if (key == 224)
		{
			key = getch();
			if (key == 72) {
				pointer--;
				if (pointer == -1)
				{
					pointer = 1;
				}
			}
			else if (key == 80)
			{
				pointer++;
				if (pointer == 2)
				{
					pointer = 0;
				}
			}
			
		}
		else if (key == 13)
		{
			switch (pointer) {
			case 0: system("cls");
				return;
			case 1: exit(0); break;
			}
		}
	}
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

	hideCursor();
	string Menu[3] = { "CREATE NEW ACCOUNT", "PUT/WITHDRAW MONEY TO/FROM YOUR ACCOUNT", "EXIT" };
	int pointer = 0;
	int key = 0;
	while (true)
	{
		SetConsoleCursorPosition(h, { 0, 0 });
		//system("cls");
		printf("     ");
		SetConsoleTextAttribute(h, 91);
		printf("%s\n\n", "MAIN MENU");
		for (int i = 0; i < 3; i++)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(h, 10);
				cout << Menu[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(h, 15);
				cout << Menu[i] << endl;
			}
		}
		Sleep(100);
		key = getch();
		if (key == 224)
		{
			key = getch();
			if (key == 72) {
				pointer--;
				if (pointer == -1)
				{
					pointer = 2;
				}
			}
			else if (key == 80)
			{
				pointer++;
				if (pointer == 3)
				{
					pointer = 0;
				}
			}

		}
		else if (key == 13)
		{
			switch (pointer) {
			case 0: 
				system("cls");
				Sleep(100);
				Create_New_Account(Account);
				cout << "\nYour Account ID : " << Account[length - 1].ID << endl;
				printf("Your Balance    : %.2f AZN\n\n", Account[length - 1].Balance);
				backMenu();
				break; 
			case 1: break;
			case 2: exit(0);
			}
		}
	}
	//


	return 0;
}


