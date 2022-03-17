#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ConstructionProduct {
    float pret_per_unitate;
    int cantitate;
    string unitate_masura,nume;
public:
    ConstructionProduct();
    ConstructionProduct(int, float, string,string);
    ConstructionProduct operator++(int x){
        ConstructionProduct cpy = *this;
        cantitate++;
        return *this;
    }
    ConstructionProduct operator+=(int x) {
        ConstructionProduct cpy = *this;
        cantitate += x;
        return *this;
    }
    friend void chitanta(vector<ConstructionProduct> v);
    friend istream& operator>> (istream& is, ConstructionProduct& a) {
        cout << "Nume produs: ";
        is >> a.nume;
        cout << "Cantitate: ";
        is >> a.cantitate;
        cout << "Pret per unitate: ";
        is >> a.pret_per_unitate;
        is.get();
        cout << "Unitate de masura: ";
        getline(is, a.unitate_masura);
        return is;
    }
    friend ostream& operator<<(ostream& os, ConstructionProduct& a){
        os <<"Nume produs: "<<a.nume<<endl<<"Cantitate: " << a.cantitate << endl << "Pret per unitate : " << a.pret_per_unitate << endl << "Unitate de masura : " << a.unitate_masura << endl << endl;
        return os;
    }
};

ConstructionProduct::ConstructionProduct() {
    pret_per_unitate = 0;
    cantitate = 0.0;
}

ConstructionProduct::ConstructionProduct(int cantitate, float pret_per_unitate, string unitate_masura,string nume) {
    this->cantitate = cantitate;
    this->pret_per_unitate = pret_per_unitate;
    this->unitate_masura = unitate_masura;
    this->nume = nume;
}

void chitanta(vector<ConstructionProduct> v) {
    cout << "Chitanta renovare:" << endl;
    int i = 1;
    float total = 0.0;
    for (auto produs : v) {
        cout << "1. " << produs.nume << " (buc) x " << produs.cantitate << endl <<
            produs.cantitate << " x "<<produs.pret_per_unitate<<" = "<<(float)produs.cantitate*produs.pret_per_unitate<<" RON"<<endl;
        total += (float)produs.cantitate * produs.pret_per_unitate;
    }
    cout << "Total: " << total << " RON" << endl << endl;
}
int main()
{
    vector<ConstructionProduct> v;
    ConstructionProduct x;
    int n,i;
    cout << "n= ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    chitanta(v);
    v[0]++;
    cout << v[0];
    v[1] += 5;
    cout << v[1];
    return 0;
}
