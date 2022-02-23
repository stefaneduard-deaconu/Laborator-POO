#include <iostream>
#include <string>
using namespace std;
class Bilet {
private:
    string nume;
    bool clasa;
public:
    Bilet() {
        nume = "";
        clasa = 0;
    }
    Bilet(string _nume, bool _clasa) {
        nume = _nume;
        clasa = _clasa;
    }
    void citeste(string _nume) {
        getline(cin, _nume);
        nume = _nume;
    }

    string getNume() {
        return nume;
    }
    bool getClasa() {
        return clasa;
    }

    void afiseaza(){
        cout << nume << endl;
    }
};

void statisticazboruri(int n, Bilet bilete[]) {
    int da = 0;
    for (int i = 0; i < n; i++)
        if (bilete[i].getClasa() == true)
            da++;
    cout << "Avem " << da << " bilete la clasa I, dar si " << n - da << " la alte clase.";
}
int main()
{
    int n,i;
    string numele;
    Bilet bilete[] = { Bilet("Popescu Leuras",true),Bilet("Manolescu Alexandra", true),
    Bilet("Popescu Madalina", false) };
    statisticazboruri(3, bilete);
    return 0;
}