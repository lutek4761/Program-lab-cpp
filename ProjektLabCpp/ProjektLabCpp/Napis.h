#pragma once
#include<iostream>
#include<string.h>

using namespace std;

class Napis
{
private:
	char *m_pszNapis;
	int m_nDl;
public:
	Napis(const char* nap = "");
	Napis(const Napis & wzor);
	const char* Zwroc() const;
	void Ustaw(const char* nowy_napis);
	void Wypisz() const;
	void Wpisz();
	int SprawdzNapis(const char* por_napis) const;
	Napis& operator=(const Napis& wzor);
	bool operator==(const Napis& wzor) const;
	friend ostream& operator<<(ostream& wy, const Napis& p) {
		return wy << p.m_pszNapis;
	}
	friend istream& operator>>(istream& we, Napis& p) {
		return we >> p.m_pszNapis;
	}

};

