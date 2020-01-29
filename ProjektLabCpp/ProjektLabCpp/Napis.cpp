#include "Napis.h"

Napis::Napis(const char* nap)
{
	m_nDl = strlen(nap) + 1;
	m_pszNapis = new char[m_nDl];
	strcpy_s(m_pszNapis, m_nDl, nap);
	m_pszNapis[m_nDl - 1] = '\0';
}

Napis::Napis(const Napis& wzor)
{
	m_nDl = strlen(wzor.Zwroc()) + 1;
	m_pszNapis = new char[m_nDl];
	strcpy_s(m_pszNapis, m_nDl, wzor.Zwroc());
	m_pszNapis[m_nDl - 1] = '\0';
}

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
	m_nDl = strlen(m_pszNapis) + 1;
}

int Napis::SprawdzNapis(const char* por_napis) const
{
	if (strlen(por_napis) == 0 && strlen(m_pszNapis) != 0)return -1;
	if (strlen(por_napis) != 0 && strlen(m_pszNapis) == 0)return 1;
	return -strcmp(por_napis, m_pszNapis);
}

Napis& Napis::operator=(const Napis& wzor)
{
	if (this == &wzor)return *this;
	this->~Napis();
	new(this) Napis(wzor);
	return *this;
}

bool Napis::operator==(const Napis& wzor) const
{
	if (this == &wzor)return true;
	else return false;
}
