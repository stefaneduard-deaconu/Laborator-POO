#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student{
private:
    string nume, prenume;
    int grupa, semigrupa;
    vector<int> note;
public:
    Student();
    Student(string, string, int, int, vector<int>);
    Student operator+=(int);
    friend istream& operator>> (istream& is, Student& a) {
        int n, x;
        cout << "Numele: ";
        getline(is, a.nume);
        cout<<"Prenumele: ";
        getline(is, a.prenume);
        cout << "Grupa: ";
        is >> a.grupa;
        cout << "Semigrupa: ";
        is >> a.semigrupa;
        cout << "Numarul de note: ";
        is >> n;
        cout << "Notele: ";
        for (int i = 0; i < n; i++)
        {
            is >> x;
            a.note.push_back(x);
        }
        cout << endl;
        return is;
    };
    friend ostream& operator<<(ostream& os, Student& a) {
        os << "Numele este " << a.nume << endl << "Prenumele este " << a.prenume << endl <<
            "Grupa " << a.grupa << endl << "Semigrupa " << a.semigrupa << endl;
        os << "Notele: ";
        for (auto nota : a.note)
        {
            os << nota << " ";
        }
        os << endl<<endl;
        return os;
    }
};

Student::Student() {
    grupa = semigrupa = 0;
}

Student::Student(string nume, string prenume, int grupa, int semigrupa, vector<int> note)
{
    this->nume = nume;
    this->prenume = prenume;
    this->grupa = grupa;
    this->semigrupa = semigrupa;
    this->note = note;
}

Student Student::operator+=(int notaNoua) {
    note.push_back(notaNoua);
    return *this;
}
int main()
{
    Student s;
    cin >> s;
    cout << s;
    s += 10;
    cout << s;
    return 0;
}
