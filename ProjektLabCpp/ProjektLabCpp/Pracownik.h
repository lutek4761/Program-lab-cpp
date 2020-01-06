#include "Napis.h"
#include "Data.h"
#pragma once
class Pracownik
{
private:
	Napis m_Imie, m_Nazwisko;
	Data m_DataUrodzenia;
public:
	~Pracownik();
	const char* Imie() const;
	const char* Nazwisko() const;
	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wypisz() const;
	void Wpisz();
	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;
	int Porownaj(const Pracownik& wzorzec) const;
};

