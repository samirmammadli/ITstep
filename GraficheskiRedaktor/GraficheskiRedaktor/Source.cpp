#include "Functions.h"

void main()
{
	int field_size = 30;
	int size = field_size * field_size;
	COLORS(DEFAULT, BLACK);


	matrix **field = new matrix*[size];
	for (int i = 0; i < size; i++)
	{
		field[i] = new matrix;
	}

	for (int i = 0; i < size; i++)
	{
		COLORS(field[i]->fgg, field[i]->bgg);
		cout << field[i]->symbol;
		if (i % field_size == 0)
		{
			cout << endl;
		}
	}
}