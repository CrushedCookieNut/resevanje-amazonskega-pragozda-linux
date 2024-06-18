#include "include/leaderboard.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void ldb::pridobiPodatke() {
    ldb imeLestvice;
    ifstream data_i("lestvica.bin", ios::binary);
    if (data_i.is_open()) {
        leaderboard tmp;
        while (data_i.read((char *)&tmp, sizeof(tmp))) {
            imeLestvice.lestvica.push_back(tmp);
        }
        data_i.close();
    } else {
        cout << "pridobiPodatke datoteka no work!" << endl;
    }
    for (int i=0;i<imeLestvice.lestvica.size();i++) {
        cout << i+1 << ". " << imeLestvice.lestvica.at(i).ime << " " << imeLestvice.lestvica.at(i).tocke << endl;
    }
}

void ldb::vpisiPodatke(char ime[], int tocke) {
    leaderboard tmp, tmp2;
    strcpy(tmp.ime, ime);
    tmp.tocke = tocke;

    ifstream data_i("lestvica.bin", ios::binary);
    ofstream data_o("lestvica_copy.bin", ios::binary | ios::app);

    if (!data_i.is_open() || !data_o.is_open()) {
        cout << "Error opening files!" << endl;
        return;
    }

    bool zeVpisano = false;

    while (data_i.read((char *)&tmp2, sizeof(tmp2))) {
        if (tmp.tocke > tmp2.tocke && !zeVpisano) {
            data_o.write((char *)&tmp, sizeof(tmp));
            zeVpisano = true;
        }
        data_o.write((char *)&tmp2, sizeof(tmp2));
    }

    if (!zeVpisano) {
        data_o.write((char *)&tmp, sizeof(tmp));
    }

    data_i.close();
    data_o.close();

    remove("lestvica.bin");
    rename("lestvica_copy.bin", "lestvica.bin");
}
