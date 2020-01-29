#include<iostream>
#include "ListaPracownikow.h"
#include<fstream>
#include <conio.h>
using namespace std;




int main() {
	int znak;
	ListaPracownikow lista;

	while (1) {
		cout << "1. Dodaj pracownika" << endl;
		cout << "2. Usun pracownika" << endl;
		cout << "3. Szukaj" << endl;
		cout << "4. Wypisz pracownikow" << endl;
		cout << "5. Zapis do pliku" << endl;
		cout << "6. Wczytaj z pliku" << endl;
		cout << "7. Wyjscie" << endl;
		cout << endl;
		znak = _getch();
		switch (znak)
		{
		case 49: {
			Pracownik p;
			p.Wpisz();
			lista.Dodaj(p);
		}break;
		case 50: {
			Pracownik p;
			p.Wpisz();
			lista.Usun(p);
		}break;
		case 51: {
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
		case 52:
		{
			lista.WypiszPracownikow();
		}
			break;
		case 53:
		{
			ofstream file;
			file.open("dane.txt", std::ios::binary | std::ios::app);
			if (file.good())
			{
				file.write(reinterpret_cast <char*>(&lista), sizeof(lista));
				file.close();
			}
		}	break;
		case 54:
		{
			std::fstream file;
			file.open("dane.txt", std::ios::binary | std::ios::in);
			if (file.good())
			{
				file.read(reinterpret_cast <char*>(&lista), 256); // 256- tak wiem- Ÿle.
				file.close();
			}
		}break;
		case 55:
		{
			exit(0);
		}break;

		}
		cout << endl;
	}
	
	return 0;
}