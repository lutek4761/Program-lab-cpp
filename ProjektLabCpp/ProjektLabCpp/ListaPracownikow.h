#include "Pracownik.h"
#pragma once
class ListaPracownikow
{
private:
	Pracownik m_pTablica[20];
	int m_nLiczbaPracownikow;
public:
	ListaPracownikow();
	void Dodaj(const Pracownik& p);
	void Usun(const Pracownik& p);
	void WypiszPracownikow()  const;
	const Pracownik* Szukaj(const char* nazwisko, const char* imie)const;
};
