                //    BSEF19M011                     FAHEEM KHALID
#include<iostream>
#include"Set.h"
using namespace std;
int main()
{
	Set<int>* d;
	d = new Set<int>;
	Set<int>* d2;
	d2 = new Set<int>;

	d->Insert(21);
	d->Insert(22);
	d->Insert(23);
	d->Insert(24);

	cout << "Set 1 before remove function called:" << endl;
	d->print();

	d->remove(21);
	cout << endl;
	cout << "Set 1 is :" << endl;
	d->print();

	d->Ismember(23);
	cout << endl;

	d2->Insert(23);
	d2->Insert(24);
	d2->Insert(25);
	d2->Insert(26);
	d2->Insert(27);
	d2->Insert(28);

	cout << "Set 2 is :" << endl;
	d2->print();

	d->intersection(d2);
	cout << endl;
	d->Issubset(d2);
	d->Union(d2);

	return 0;
}