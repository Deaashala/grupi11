#include <iostream>
#include <string>

using namespace std;

// Struktura për të ruajtur të dhënat e një ekipi
struct Ekipi {
    string emri;
    int gola;
    int kartonVerdh;
    int kartonKuq;
};

// Funksioni për të inicializuar ekipet
void inicializoEkipin(Ekipi &ekip, string emri) {
    ekip.emri = emri;
    ekip.gola = 0;
    ekip.kartonVerdh = 0;
    ekip.kartonKuq = 0;
}

// Funksioni për të regjistruar një gol
void shenoGol(Ekipi &ekip) {
    ekip.gola++;
}

// Funksioni për të regjistruar një karton të verdhë
void shenoKartonVerdh(Ekipi &ekip) {
    ekip.kartonVerdh++;
}

// Funksioni për të regjistruar një karton të kuq
void shenoKartonKuq(Ekipi &ekip) {
    ekip.kartonKuq++;
}

// Funksioni për të shfaqur raportin e ndeshjes
void shfaqRezultatin(const Ekipi &ekipi1, const Ekipi &ekipi2) {
    cout << "\n===== RAPORTI I NDESHJES =====\n";
    cout << ekipi1.emri << " " << ekipi1.gola << " - " << ekipi2.gola << " " << ekipi2.emri << endl;
    cout << ekipi1.emri << " (Kartonë: " << ekipi1.kartonVerdh << " të verdhë, " << ekipi1.kartonKuq << " të kuq)" << endl;
    cout << ekipi2.emri << " (Kartonë: " << ekipi2.kartonVerdh << " të verdhë, " << ekipi2.kartonKuq << " të kuq)" << endl;

    if (ekipi1.gola > ekipi2.gola)
        cout << "Fituesi: " << ekipi1.emri << endl;
    else if (ekipi2.gola > ekipi1.gola)
        cout << "Fituesi: " << ekipi2.emri << endl;
    else
        cout << "Ndeshja përfundoi në barazim! " << endl;
}

// Funksioni kryesor
int main() {
    Ekipi ekipi1, ekipi2;
    string emri1, emri2;

    // Përdorim cin >> për të marrë emra të ekipeve (një fjalë)
    cout << "Vendosni emrin e ekipit 1: ";
    cin >> emri1;  // Lexon vetëm një fjalë

    cout << "Vendosni emrin e ekipit 2: ";
    cin >> emri2;  // Lexon vetëm një fjalë

    inicializoEkipin(ekipi1, emri1);
    inicializoEkipin(ekipi2, emri2);

    // Shembuj për të shtuar një gol
    shenoGol(ekipi1);
    shenoGol(ekipi2);
    shenoKartonVerdh(ekipi1);
    shenoKartonKuq(ekipi2);

    // Shfaq raportin
    shfaqRezultatin(ekipi1, ekipi2);

    return 0;
}
