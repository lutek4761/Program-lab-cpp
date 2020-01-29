#pragma once
#include "Napis.h"
#include "Pracownik.h"
class Kierownik : public Pracownik
{
private:
	Napis m_NazwaDzialu;
	int m_nLiczbaPracownikow;
public:
	Kierownik(int m_nLiczbaPracownikow = 0, Napis m_NazwaDzialu = "");
	Kierownik(Kierownik& k);
	Kierownik& operator= (Kierownik& k);
	bool operator== (const Kierownik& k) const;
	virtual void WypiszDane();
	virtual Pracownik* KopiaObiektu();
	friend ostream& operator<<(ostream& wy, const Kierownik& p) {
		wy << p << " ";
		return wy << p.m_NazwaDzialu << " L. prac: " << p.m_nLiczbaPracownikow;
	}
	friend istream& operator>>(istream& we, Kierownik& p) {
		we >> p;
		return we >> p.m_NazwaDzialu >> p.m_nLiczbaPracownikow;
	}
};

