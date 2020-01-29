#include "Napis.h"
#include "Data.h"
#pragma once
class Pracownik
{
private:
	Napis m_Imie, m_Nazwisko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;
public:
	Pracownik(const char* imie="", const char* nazwisko="", Data dataUrodzenia=Data());
	Pracownik(const Pracownik& wzorzec);
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
	int ZwrocId()const { return m_nIDZatrudnienia; }
	Pracownik& operator=(const Pracownik& wzorzec);

	friend ostream& operator<<(ostream& wy, const Pracownik& p) {
		return wy << p.m_Imie << " "<<p.m_Nazwisko << " " << p.m_DataUrodzenia;
	}
	friend istream& operator>>(istream& we, Pracownik& p) {
		return we >> p.m_Imie >> p.m_Nazwisko >> p.DataUrodzenia;
	}

	virtual void WypiszDane();
	virtual Pracownik* KopiaObiektu();
};

