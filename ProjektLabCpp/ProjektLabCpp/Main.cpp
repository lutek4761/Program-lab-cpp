#include<iostream>
#include"Napis.h"

using namespace std;


#include "Data.h"

int main() {
	Data d;
	d.Ustaw(1, 1, 2000);
	cin >> d;
	d.Koryguj();
	cout << d;
	return 0;
}