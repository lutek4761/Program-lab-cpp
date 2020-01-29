
#include "ListaPracownikow.h"
#include<iostream>
ListaPracownikow::ListaPracownikow()
	:m_nLiczbaPracownikow(0)
{
}

void ListaPracownikow::Dodaj(const Pracownik& p) {

	if (m_nLiczbaPracownikow == 20) return;
	
	m_nLiczbaPracownikow++;
	int i;
	for (i = 0; i < m_nLiczbaPracownikow; i++) {
		
		if (m_pTablica[i].Porownaj(p) == 0) {m_nLiczbaPracownikow--; return;}
		if (m_pTablica[i].Porownaj(p) == 1) {
			
			if (i + 1 < m_nLiczbaPracownikow)
				for (int j = m_nLiczbaPracownikow; j > i; j--)
					m_pTablica[j] = m_pTablica[j - 1];
			break;
		}
		
	}
	m_pTablica[i] = p;



}
void ListaPracownikow::Usun(const Pracownik& p) {
	if (m_nLiczbaPracownikow == 0) return;
	for (int i = 0; i < m_nLiczbaPracownikow; i++) {
		if (m_pTablica[i].Porownaj(p) == 0) {
			m_nLiczbaPracownikow--;
			for (i; i < m_nLiczbaPracownikow; i++)
				m_pTablica[i] = m_pTablica[i + 1];
			break;
		}
	}
}

void ListaPracownikow::WypiszPracownikow() const
{
	for (int i = 0; i < m_nLiczbaPracownikow; i++) {
		m_pTablica[i].Wypisz();
	}
}

const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie) const
{
	for (int i = 0; i < m_nLiczbaPracownikow; i++) {
		if (!strcmp(m_pTablica[i].Imie(), imie) && !strcmp(m_pTablica[i].Nazwisko(), nazwisko)) {
			return &m_pTablica[i];
		}
	}
	return nullptr;
}
