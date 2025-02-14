#include <iostream>
#include <string>

using namespace std;

// Struktura për të ruajtur të dhënat e një ekipi
struct Ekipi {
    string emri;
    int gola;
};

// Funksioni për të inicializuar ekipet
void inicializoEkipin(Ekipi &ekip, string emri) {
    ekip.emri = emri;
    ekip.gola = 0;
}

// Funksioni për të regjistruar një gol
void shenoGol(Ekipi &ekip) {
    ekip.gola++;
}

// Funksioni për të shfaqur rezultatin e ndeshjes
void shfaqRezultatin(const Ekipi &ekip1, const Ekipi &ekip2) {
    cout << "\n===== REZULTATI =====\n";
    cout << ekip1.emri << " " << ekip1.gola << " - " << ekip2.gola << " " << ekip2.emri << endl;
    
    if (ekip1.gola > ekip2.gola)
        cout << "Fituesi: " << ekip1.emri << " 🎉" << endl;
    else if (ekip2.gola > ekip1.gola)
        cout << "Fituesi: " << ekip2.emri << " 🎉" << endl;
    else
        cout << "Ndeshja përfundoi në barazim! 🤝" << endl;
}

// Funksioni kryesor
int main() {
    Ekipi ekipi1, ekipi2;
    string emri1, emri2;
    int opsion;

    // Marrim emrat e ekipeve nga përdoruesi
    cout << "Vendosni emrin e ekipit 1: ";
    getline(cin, emri1);
    cout << "Vendosni emrin e ekipit 2: ";
    getline(cin, emri2);

    // Inicializojmë ekipet
    inicializoEkipin(ekipi1, emri1);
    inicializoEkipin(ekipi2, emri2);

    // Simulimi i ndeshjes
    do {
        cout << "\n1. Shëno gol për " << ekipi1.emri;
        cout << "\n2. Shëno gol për " << ekipi2.emri;
        cout << "\n3. Përfundo ndeshjen";
        cout << "\nZgjidhni një opsion: ";
        cin >> opsion;

        switch (opsion) {
            case 1:
                shenoGol(ekipi1);
                break;
            case 2:
                shenoGol(ekipi2);
                break;
            case 3:
                shfaqRezultatin(ekipi1, ekipi2);
                break;
            default:
                cout << "Opsion i pavlefshëm! Provo përsëri.\n";
        }
    } while (opsion != 3);

    return 0;
}
