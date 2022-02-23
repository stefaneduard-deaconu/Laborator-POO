#include <iostream>
#include <string>
using namespace std;
class Carte {
private:
    string titlu;
    int pag, paga;
public:
    Carte() {
        titlu = "";
        pag = paga = 0;
    }
    Carte(string _titlu, int _pag, int _paga) {
        titlu = _titlu;
        pag = _pag;
        paga = _paga;
    }
    void citeste() {
        string _titlu;
        int _pag, _paga;
        getline(cin, _titlu);
        titlu = _titlu;
        cin >> _paga;
        cin.get();
        paga = _paga;
        cin >> _pag;
        cin.get();
        pag = _pag;
    }
    int getPaginaMaxima() {
        return pag;
    }
    void setPaginaCurenta(int x) {
        if (x <= pag)
            paga = x;
        else
            cout << "Nu poti sari la pagina " << x << " din "<< pag <<" deoarece nu exista";
    }
    void afiseaza() {
        cout << "Cartea cu titlul " << titlu << " este deschisa la pagina " << paga << " din " << pag <<endl;
    }
};
int main()
{
    Carte c;
    c.citeste();
    c.afiseaza();
    c.setPaginaCurenta(30);
    c.afiseaza();
    c.setPaginaCurenta(c.getPaginaMaxima() + 1);
    return 0;
}