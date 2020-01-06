#include "Napis.h"

const char* Napis::Zwroc() const
{
	return m_pszNapis;
}

void Napis::Ustaw(const char* nowy_napis)
{
	int i = 0;
	while (nowy_napis[i] != '\0')m_pszNapis[i++] = nowy_napis[i];
	m_pszNapis[i] = '\0';
}

void Napis::Wypisz() const
{
	cout << m_pszNapis << endl;
}

void Napis::Wpisz()
{
	cin >> m_pszNapis;
}

int Napis::SprawdzNapis(const char* por_napis) const
{
	return strcmp(por_napis, m_pszNapis);
}
