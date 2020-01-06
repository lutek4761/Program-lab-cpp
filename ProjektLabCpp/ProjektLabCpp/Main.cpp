#include<iostream>
#include"Napis.h"

using namespace std;


int main()
{
	Napis napis;


	napis.Ustaw("aaaa");
	Napis napis2;
	napis2.Ustaw("bbb");
	cout<<napis.SprawdzNapis(napis2.Zwroc());

#include "Data.h"

int main() {
	Data d;
	d.Ustaw(1,1,2000);
	d.Koryguj();
	d.Wypisz();
	cout << endl <<  d.Porownaj(Data(11, 1, 200));
	return 0;
}