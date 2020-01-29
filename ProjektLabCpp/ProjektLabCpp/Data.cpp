
#include "Data.h"
Data::Data() 
	: m_nDzien(1), m_nMiesiac(1), m_nRok(2000)
{
	Koryguj();
}
Data::Data(const Data & wzorzec)
{
	m_nDzien = wzorzec.m_nDzien;
	m_nMiesiac = wzorzec.m_nMiesiac;
	m_nRok = wzorzec.m_nRok;
}
Data::Data(int d, int m, int r)
	: m_nDzien(d), m_nMiesiac(m), m_nRok(r)
{}
void Data::Ustaw(int d, int m, int r) {
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	Koryguj();
}
int Data::Dzien() const {
	return m_nDzien;
}
int Data::Miesiac() const {
	return m_nMiesiac;
}
int Data::Rok() const {
	return m_nRok;
}
void Data::Wypisz() const{
	cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok << endl;
}
void Data::Wpisz() {
	cin >> m_nDzien >> m_nMiesiac >> m_nRok;
	Koryguj();
}
void Data::Koryguj() {
	if (m_nDzien < 0) m_nDzien = 1;
	if (m_nMiesiac < 0) m_nMiesiac = 1;
	if (m_nMiesiac > 12) m_nMiesiac = 12;
	if (((m_nMiesiac < 8 and m_nMiesiac % 2 == 1)or(m_nMiesiac >=8 and m_nMiesiac % 2 == 0)) and m_nDzien > 31) m_nDzien = 31;
	if (((m_nMiesiac < 7 and m_nMiesiac % 2 == 0) or (m_nMiesiac >= 7 and m_nMiesiac % 2 == 1)) and m_nDzien > 30) m_nDzien = 30;
	if (m_nRok % 4 == 0 and m_nRok % 100 != 0 and m_nRok % 400 != 0) { // jest przestepny
		if (m_nMiesiac == 2 and m_nDzien > 29) m_nDzien = 29;
	}
	else {
		if (m_nMiesiac == 2 and m_nDzien > 28) m_nDzien = 28;
	}
	
}
int Data::Porownaj(const Data& wzor) const {
	if (wzor.m_nDzien == m_nDzien and wzor.m_nMiesiac == m_nMiesiac and wzor.m_nRok == m_nRok) return 0;
	if (wzor.m_nRok > m_nRok or (wzor.m_nRok == m_nRok and wzor.m_nMiesiac > m_nMiesiac) or 
		(wzor.m_nRok == m_nRok and wzor.m_nMiesiac == m_nMiesiac and wzor.m_nDzien > m_nDzien)) return -1;
	return 1;
}

Data& Data::operator=(const Data& wzor)
{
	if (this == &wzor)return *this;
	this->~Data();
	new(this) Data(wzor);
	return *this;
}

