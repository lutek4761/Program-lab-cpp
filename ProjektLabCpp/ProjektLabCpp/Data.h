
#pragma once
#include <iostream>
using namespace std;

class Data
{
private:
	int m_nDzien, m_nMiesiac, m_nRok;
public:
	Data();
	Data(const Data& wzorzec);
	Data(int d, int m, int r);
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz() const;
	void Wpisz();
	void Koryguj();
	int Porownaj(const Data& wzor) const;
	friend  ostream& operator<<(ostream& wy, const Data& d) {
		return wy << d.Dzien() << "-" << d.Miesiac() << "-" << d.Rok();
	}
	friend istream& operator>>(istream& we, Data& d) {
		return we >> d.m_nDzien >> d.m_nMiesiac >> d.m_nRok;

	}
	Data& operator=(const Data& wzor);
};


