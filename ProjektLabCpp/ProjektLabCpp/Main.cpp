#include<iostream>
#include "WirtualnaTablicaPracownikow.h"
#include "Kierownik.h"
#include<fstream>
#include <conio.h>
using namespace std;




int main() {
	Pracownik* ptr;
	int znak;
	WirtualnaTablicaPracownikow lista(20);

	while (1) {
		cout << "1. Dodaj pracownika" << endl;
		cout << "2. Dodaj kierownika" << endl;
		cout << "3. Usun" << endl;
		cout << "4. Szukaj" << endl;
		cout << "5. Wypisz pracownikow" << endl;
		cout << "6. Wyjscie" << endl;
		cout << endl;
		znak = _getch();
		switch (znak)
		{
		case 49: {
			ptr = new Pracownik;
			ptr->Wpisz();
			lista.Dodaj(*ptr);
			delete ptr;
		}break;
		case 50: {
			ptr = new Kierownik;
			ptr->Wpisz();
			lista.Dodaj(*ptr);
			delete ptr;
		}break;
		case 51: {
			ptr = new Pracownik;
			ptr->Wpisz();
			lista.Usun(*ptr);
			delete ptr;
		}break;
		case 52: {
			Napis imie;
			Napis nazwisko;
			cout << "Podaj imie: ";
			imie.Wpisz();
			cout << "Podaj nazwisko: ";
			nazwisko.Wpisz();
			const Pracownik* p = lista.Szukaj(nazwisko.Zwroc(), imie.Zwroc());
			cout << endl;
			p->Wypisz();
		}break;
		case 53:
		{
			lista.WypiszPracownikow();
		}
			break;
		case 54:
		{
			exit(0);
		}break;

		}
		cout << endl;
	}
	
	return 0;
}