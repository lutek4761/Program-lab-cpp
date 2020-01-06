
#pragma once
#include <iostream>
using namespace std;
class Data
{
private:
	int m_nDzien, m_nMiesiac, m_nRok;
public:
	Data();
	Data(int d, int m, int r);
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz() const;
	void Wpisz();
	void Koryguj();
	int Porownaj(const Data& wzor) const;
};

