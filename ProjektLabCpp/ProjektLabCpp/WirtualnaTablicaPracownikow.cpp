#include "WirtualnaTablicaPracownikow.h"
WirtualnaTablicaPracownikow::WirtualnaTablicaPracownikow(int roz) {
	m_nRozmiarTablicy = roz;
	m_nLiczbaPracownikow = 0;
	tablica = new Pracownik * [m_nRozmiarTablicy];
	for(int i=0;i< m_nRozmiarTablicy;i++)tablica[i] = new Pracownik;
	
}
WirtualnaTablicaPracownikow::~WirtualnaTablicaPracownikow() {
	for (int i = 0; i < m_nLiczbaPracownikow; i++)
		delete tablica[i];
	delete[] tablica;
}
void WirtualnaTablicaPracownikow::Dodaj(const Pracownik& p) {

	if (m_nLiczbaPracownikow == m_nRozmiarTablicy) return;
	
	m_nLiczbaPracownikow++;
	int i;
	for (i = 0; i < m_nLiczbaPracownikow; i++) {
		
		if (tablica[i]->Porownaj(p) == 0) { m_nLiczbaPracownikow--; return; }
		if (tablica[i]->Porownaj(p) == 1) {
			
			if (i + 1 < m_nLiczbaPracownikow)
				for (int j = m_nLiczbaPracownikow; j > i; j--)
					tablica[j] = tablica[j - 1];
			break;
		}

	}

	tablica[i] = p.KopiaObiektu();
}

void WirtualnaTablicaPracownikow::Usun(const Pracownik& p) {
	if (m_nLiczbaPracownikow == 0) return;
	for (int i = 0; i < m_nLiczbaPracownikow; i++) {
		if (tablica[i]->Porownaj(p) == 0) {
			m_nLiczbaPracownikow--;
			for (i; i < m_nLiczbaPracownikow; i++)
				tablica[i] = tablica[i + 1];
			break;
		}
	}
}

void WirtualnaTablicaPracownikow::WypiszPracownikow() const {
	for (int i = 0; i < m_nLiczbaPracownikow; i++)
	{
		tablica[i]->Wypisz();
		cout << endl;
	}
}

const Pracownik* WirtualnaTablicaPracownikow::Szukaj(const char* nazwisko, const char* imie) {
	for (int i = 0; i < m_nLiczbaPracownikow; i++) {
		if (!strcmp(tablica[i]->Imie(), imie) && !strcmp(tablica[i]->Nazwisko(), nazwisko)) {
			return tablica[i];
		}
	}
	return nullptr;
}