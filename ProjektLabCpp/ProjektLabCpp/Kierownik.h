#pragma once
#include "Napis.h"
#include "Pracownik.h"
class Kierownik : public Pracownik
{
private:
	Napis m_NazwaDzialu;
	int m_nLiczbaPracownikow;
public:
	Kierownik(const char* imie = "", const char* nazwisko = "", Data dataUrodzenia = Data(), int m_nLiczbaPracownikow = 0, Napis m_NazwaDzialu = "");
	Kierownik(const Kierownik& k);
	Kierownik& operator= (Kierownik& k);
	bool operator== (const Kierownik& k) const;

	virtual void Wpisz();
	virtual void Wypisz() const;
	virtual Pracownik* KopiaObiektu()const;
};

