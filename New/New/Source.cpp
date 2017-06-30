#include <iostream>
#include <Windows.h>
using namespace std;

#define eger if

struct Contact
{
	int age = 20;
	char name[100] = {"Salafan"};
	char surname[100] = { "Gaflan" };
};


void main()
{
	Contact **firma = new Contact*[3];
	firma[0] = new Contact{20, "Hebraloid Injenera Garina 123", "Chlenopes"};
	FILE* f;
	f = fopen("ujal.bin", "wb");
	char eblo[1000] = { "Hebraloid Injenera Garina 123" };
	char gandila[1000];
	fwrite(firma[0], sizeof(Contact), 1, f);
	fclose(f);


	Contact ** xren = new Contact*[3];
	FILE* a = fopen("ujal.bin", "rb");
	xren[0] = new Contact;
	fread(xren[0], sizeof(Contact), 1, a);
	fclose(a);
	
	cout << xren[0]->age << endl;
	cout << xren[0]->name << endl;
	cout << xren[0]->surname << endl;
	



	//cout << getenv("USERPROFILE") << endl;
}