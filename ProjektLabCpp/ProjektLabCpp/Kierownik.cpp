#include "Kierownik.h"

Kierownik::Kierownik(int m_nLiczbaPracownikow = 0, Napis m_NazwaDzialu = "") 
	:m_nLiczbaPracownikow(m_nLiczbaPracownikow), m_NazwaDzialu(m_NazwaDzialu)
{}
Kierownik::Kierownik(Kierownik& k) 
	:m_nLiczbaPracownikow(k.m_nLiczbaPracownikow), m_NazwaDzialu(k.m_NazwaDzialu)
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
void Kierownik::WypiszDane() {
	Pracownik::WypiszDane();
	cout << " " << m_NazwaDzialu << " L. prac: " << m_nLiczbaPracownikow;
}
Pracownik* Kierownik::KopiaObiektu() {
	return new Kierownik(*this);
}