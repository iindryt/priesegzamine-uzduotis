#ifndef TEXT_ANALYSIS_H_INCLUDED
#define TEXT_ANALYSIS_H_INCLUDED

#include "mylib.h"


// Funkcija pasalina skyrybos zenklus, pavercia visas raides i mazasias
string pakeistas_zodis(const string& zodis);

// Atspausdina zodzius ir ju pasikartojimu kieki (>1)
void spausdinimas_zodziu_kiekis(const map<string, int>& zodziu_kiekis);

// Atspausdina zodzius ir eiluciu numerius (cross-reference)
void spausdinimas_zodziu_eil(
    const map<string, pair<int, set<int>>>& zodziu_eil
);

// Grazina vartotojo pasirinkima del URL spausdinimo
string pasirinkimas_url();

// Spausdina visus rastus URL adresus
void spausdinimas_url(ostream& out, const set<string>& url_set);

// Pasirenka kur spausdinti URL rezultatus
void url_paskirstymas(const string& pasirinkimas, const set<string>& url_set);

// Pagrindine teksto analizes funkcija
void failo_tvarkymas();

#endif
