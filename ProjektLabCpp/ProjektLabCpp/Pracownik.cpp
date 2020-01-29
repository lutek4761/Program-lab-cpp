
#include "Pracownik.h"
static int idPracownika = -20;
Pracownik::Pracownik(const char* imie, const char* nazwisko, Data dataUrodzenia)
	:m_Imie(imie), m_Nazwisko(nazwisko), m_DataUrodzenia(dataUrodzenia), m_nIDZatrudnienia(idPracownika++)
{
	
}

Pracownik::Pracownik(const Pracownik& wzorzec)
	: m_nIDZatrudnienia(idPracownika++)
{
	m_Imie = wzorzec.m_Imie;
	m_Nazwisko = wzorzec.m_Nazwisko;
	m_DataUrodzenia = wzorzec.m_DataUrodzenia;
	
}
const char* Pracownik::Imie() const {
	return m_Imie.Zwroc();
}
const char* Pracownik::Nazwisko() const {
	return m_Nazwisko.Zwroc();
}
void Pracownik::Imie(const char* nowe_imie) {
	m_Imie.Ustaw(nowe_imie);
}
void Pracownik::Nazwisko(const char* nowe_nazwisko) {
	m_Nazwisko.Ustaw(nowe_nazwisko);
}
void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok) {
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}
void Pracownik::Wypisz() const {
	cout << m_nIDZatrudnienia << endl;
	m_Imie.Wypisz();
	m_Nazwisko.Wypisz();
	m_DataUrodzenia.Wypisz();
}
void Pracownik::Wpisz() {
	cout << "Podaj imie pracownika: ";
	m_Imie.Wpisz();
	cout << "Podaj nazwisko pracownika: ";
	m_Nazwisko.Wpisz();
	cout << "Podaj date urodzenia pracownika: ";
	m_DataUrodzenia.Wpisz();
}
int Pracownik::SprawdzImie(const char* por_imie) const {
	return m_Imie.SprawdzNapis(por_imie);
}
int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const {
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}
int Pracownik::Porownaj(const Pracownik& wzorzec) const {
	if (m_Imie.SprawdzNapis(wzorzec.Imie()) == 0 and m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) == 0 
		and m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia) == 0) 
		return 0;
	if (m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) > 0 or 
		((m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) == 0) and (m_Imie.SprawdzNapis(wzorzec.Imie()) > 0)) or
		((m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) == 0) and (m_Imie.SprawdzNapis(wzorzec.Imie()) == 0) and (m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia) > 0)))
		return 1;
	return -1;
}

Pracownik& Pracownik::operator=(const Pracownik& wzorzec)
{
	if (this == &wzorzec)return *this;
	this->~Pracownik();
	new(this) Pracownik(wzorzec);
	return *this;
}

void Pracownik::WypiszDane() {
	Wypisz();
}

Pracownik* Pracownik::KopiaObiektu() {
	return new Pracownik(*this);
}

