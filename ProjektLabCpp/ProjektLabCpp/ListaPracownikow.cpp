#include "ListaPracownikow.h"
ListaPracownikow::ListaPracownikow() 
	:m_nLiczbaPracownikow(0)
{}

void ListaPracownikow::Dodaj(const Pracownik& p) {
	if (m_nLiczbaPracownikow == 20) return;
	m_nLiczbaPracownikow++;
	for (int i = 0; i < m_nLiczbaPracownikow; i++) {
		if (m_pTablica[i].Porownaj(p) == 0) return;
		if ((m_pTablica[i].Porownaj(p) > 0)) {
			for (int j = m_nLiczbaPracownikow - 1; j >= i; j--) 
				m_pTablica[j + 1] = m_pTablica[j];
			m_pTablica[i] = p;
			break;
		}
	}
}
void ListaPracownikow::Usun(const Pracownik& p) {

}