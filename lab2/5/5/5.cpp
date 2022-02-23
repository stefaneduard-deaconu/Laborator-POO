#include <iostream>
#include <string>
using namespace std;
class Banca {
private:
    int nrclienti;
    class Client {
    private:
        int id, suma;
    public:
        Client() {
            id = suma = 0;
        }
        Client(int _id, int _suma) {
            id = _id;
            suma = _suma;
        }
        int getId() {
            return id;
        }
        int getSuma() {
            return suma;
        }
        void setId(int x) {
            id = x;
        }
        void setSuma(int x) {
            suma = x;
        }

    }c[50];
public:
    Banca() {
        nrclienti = 0;
    }
    Banca(int _nrclienti) {
        nrclienti = _nrclienti;
    }
    void citireClienti() {
        int _id, _suma;
        for (int i = 0; i < nrclienti; i++) {
            cin >> _id >> _suma;
            c[i].setId(_id);
            c[i].setSuma(_suma);
        }
    }
    int total() {
        int s = 0;
        for (int i = 0; i < nrclienti; i++) {
            s += c[i].getSuma();
        }
        return s;
    }
    int pesteMie() {
        int nr = 0;
        for (int i = 0; i < nrclienti; i++) {
            nr += c[i].getSuma() >= 1000;
        }
        return nr;
    }
    int procentPesteSuta() {
        int nr = 0;
        for (int i = 0; i < nrclienti; i++) {
            nr += c[i].getSuma() >= 100;
        }
        return (float)nr*100 / nrclienti;
    }
}b;
int main()
{
    int x;
    cin >> x;
    b = Banca(x);
    b.citireClienti();
    cout << b.total()<<endl;
    cout << b.pesteMie() << endl;
    cout << b.procentPesteSuta();
    return 0;
}
