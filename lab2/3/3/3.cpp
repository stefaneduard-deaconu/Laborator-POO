#include <iostream>
#include <string>
using namespace std;
class Tablou {
private:
    string mesaj;
    int lungime, latime, pret;
public:
    Tablou() {
        mesaj = "";
        lungime = latime = pret = 0;
    }
    Tablou(string _mesaj, int _lungime, int _latime, int _pret) {
        mesaj = _mesaj;
        lungime = _lungime;
        latime = _latime;
        pret = _pret;
    }
    void citeste() {
        string _mesaj;
        getline(cin, _mesaj);
        mesaj = _mesaj;
        int _lungime, _latime, _pret;
        cin >> _lungime;
        cin.get();
        cin >> _latime;
        cin.get();
        cin>> _pret;
        cin.get();
        lungime = _lungime;
        latime = _latime;
        pret = _pret;
    }
    int getLen(){
        return mesaj.size();
    }
    string getMesaj() {
        return mesaj;
    }
}tablouri[50];
int main()
{
    int n, i,max=0;
    string nume;
    cin >> n;
    cin.get();
    for (i = 0; i < n; i++)
        tablouri[i].citeste();
    for (i = 0; i < n; i++)
        if (tablouri[i].getLen() > max)
        {
            max = tablouri[i].getLen();
            nume = tablouri[i].getMesaj();
        }
    cout << nume<< " "<<max;
    return 0;
}
