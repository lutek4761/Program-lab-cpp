#include<iostream>
#include "Napis.h"
#include "Data.h"
#include "Pracownik.h"

using namespace std;



int main() {
	Data d1(1, 1, 2000);
	Napis imie1;
	Napis naziwsko1;
	imie1.Ustaw("a");
	naziwsko1.Ustaw("b");
	Pracownik p1;
	p1.Imie(imie1.Zwroc());
	p1.Nazwisko(naziwsko1.Zwroc());
	cout<<p1.SprawdzImie("b");
	
	return 0;
}