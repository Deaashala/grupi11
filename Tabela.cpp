#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Struktura për të ruajtur të dhënat e një ekipi
struct Ekipi {
    string emri;
    int piket;
    int fitore;
    int barazime;
    int humbje;
    int golaShenuar;
    int golaPesuar;
};

// Funksioni për të inicializuar një ekip
void inicializoEkipin(Ekipi& ekip, string emri) {
    ekip.emri = emri;
    ekip.piket = 0;
    ekip.fitore = 0;
    ekip.barazime = 0;
    ekip.humbje = 0;
    ekip.golaShenuar = 0;
    ekip.golaPesuar = 0;
}

// Funksioni për të regjistruar një ndeshje
void regjistroNdeshje(Ekipi& ekip1, Ekipi& ekip2, int gola1, int gola2) {
    ekip1.golaShenuar += gola1;
    ekip1.golaPesuar += gola2;
    ekip2.golaShenuar += gola2;
    ekip2.golaPesuar += gola1;

    if (gola1 > gola2) { // Fitoi ekipi 1
        ekip1.fitore++;
        ekip1.piket += 3;
        ekip2.humbje++;
    }
    else if (gola2 > gola1) { // Fitoi ekipi 2
        ekip2.fitore++;
        ekip2.piket += 3;
        ekip1.humbje++;
    }
    else { // Barazim
        ekip1.barazime++;
        ekip2.barazime++;
        ekip1.piket += 1;
        ekip2.piket += 1;
    }
}

// Funksioni për të shfaqur tabelën e kampionatit në mënyrë të rregulluar
void shfaqTabelen(const Ekipi ekipet[], int numriEkipeve) {
    cout << "\n===== TABELA E KAMPIONATIT =====\n";
    cout << left << setw(15) << "Ekipi"
        << setw(6) << "Pikë"
        << setw(4) << "F"
        << setw(4) << "B"
        << setw(4) << "H"
        << setw(6) << "GS"
        << setw(6) << "GP" << endl;
    cout << "-------------------------------------------\n";

    for (int i = 0; i < numriEkipeve; i++) {
        cout << left << setw(15) << ekipet[i].emri
            << setw(6) << ekipet[i].piket
            << setw(4) << ekipet[i].fitore
            << setw(4) << ekipet[i].barazime
            << setw(4) << ekipet[i].humbje
            << setw(6) << ekipet[i].golaShenuar
            << setw(6) << ekipet[i].golaPesuar << endl;
    }
}

// Funksioni kryesor
int main() {
    const int numriEkipeve = 3; // Mund ta rritësh sipas nevojës
    Ekipi ekipet[numriEkipeve];
    string emri;
    int opsion;

    // Regjistrojmë ekipet
    for (int i = 0; i < numriEkipeve; i++) {
        cout << "Vendosni emrin e ekipit " << i + 1 << ": ";
        cin >> emri;  // Përdorim cin >> për emra të një fjalë
        inicializoEkipin(ekipet[i], emri);
    }

    // Regjistrimi i ndeshjeve
    do {
        cout << "\n1. Regjistro një ndeshje";
        cout << "\n2. Shfaq tabelën e kampionatit";
        cout << "\n3. Dil nga programi";
        cout << "\nZgjidhni një opsion: ";
        cin >> opsion;

        if (opsion == 1) {
            int e1, e2, g1, g2;
            cout << "Zgjidhni ekipin 1 (0-" << numriEkipeve - 1 << "): ";
            cin >> e1;
            cout << "Zgjidhni ekipin 2 (0-" << numriEkipeve - 1 << "): ";
            cin >> e2;
            cout << "Vendosni golat për " << ekipet[e1].emri << ": ";
            cin >> g1;
            cout << "Vendosni golat për " << ekipet[e2].emri << ": ";
            cin >> g2;

            if (e1 >= 0 && e1 < numriEkipeve && e2 >= 0 && e2 < numriEkipeve && e1 != e2) {
                regjistroNdeshje(ekipet[e1], ekipet[e2], g1, g2);
                cout << "Ndeshja u regjistrua me sukses!\n";
            }
            else {
                cout << "Zgjedhje e pavlefshme! Provo përsëri.\n";
            }
        }
        else if (opsion == 2) {
            shfaqTabelen(ekipet, numriEkipeve);
        }
        else if (opsion != 3) {
            cout << "Opsion i pavlefshëm! Provo përsëri.\n";
        }
    } while (opsion != 3);

    cout << "Programi përfundoi.\n";
    return 0;
}
