#include "Napis.h"

Napis::Napis(const char* nap)
{
	m_nDl = strlen(nap);
	m_pszNapis = new char[m_nDl];
	strcpy_s(m_pszNapis, m_nDl, nap);
	
}

Napis::Napis(const Napis& wzor)
{
	m_nDl = strlen(wzor.Zwroc());
	m_pszNapis = new char[m_nDl];
	strcpy_s(m_pszNapis, m_nDl, wzor.Zwroc());
	
}

Napis::~Napis()
{
	delete[] m_pszNapis;
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
}

int Napis::SprawdzNapis(const char* por_napis) const
{
	return strcmp(por_napis, m_pszNapis);
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
