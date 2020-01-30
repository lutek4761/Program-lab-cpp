#include "Kierownik.h"

Kierownik::Kierownik(const char* imie, const char* nazwisko, Data dataUrodzenia, int m_nLiczbaPracownikow, Napis m_NazwaDzialu)
	:Pracownik(imie, nazwisko, dataUrodzenia), m_nLiczbaPracownikow(m_nLiczbaPracownikow), m_NazwaDzialu(m_NazwaDzialu)
{
	
}
Kierownik::Kierownik(const Kierownik& k) 
	:Pracownik(k), m_nLiczbaPracownikow(k.m_nLiczbaPracownikow), m_NazwaDzialu(k.m_NazwaDzialu)
{}
Kierownik& Kierownik::operator= (Kierownik& k) {
	if (this == &k)return *this;
	this->~Kierownik();
	new(this) Kierownik(k);
	return *this;
}
bool Kierownik::operator== (const Kierownik& k) const {
	return k == *this and k.m_nLiczbaPracownikow == m_nLiczbaPracownikow and !k.m_NazwaDzialu.SprawdzNapis(this->m_NazwaDzialu.Zwroc());
}
void Kierownik::Wpisz()
{
	Pracownik::Wpisz();
	cout << "Podaj nazwe dzialu: ";
	cin >> m_NazwaDzialu;
	cout << "Podaj liczbe pracownikow: ";
	cin >> m_nLiczbaPracownikow;
}
void Kierownik::Wypisz()const {
	Pracownik::Wypisz();
	cout <<"Nazwa dzialu: "<< m_NazwaDzialu << endl << "Liczba pracownikow: " << m_nLiczbaPracownikow << endl;
}
Pracownik* Kierownik::KopiaObiektu()const {
	return new Kierownik(*this);
}

