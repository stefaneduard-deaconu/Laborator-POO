#include <iostream>
#include <string>
using namespace std;
class IntervalOrar {
private:
	int oi, of, mi, mf;
public:
	IntervalOrar() {
		oi = of = mi = mf = 0;
	}
	IntervalOrar(int _oi, int _mi, int _of, int _mf) {
		oi = _oi;
		of = _of;
		mi = _mi;
		mf = _mf;
	}
	void setInterval(int ora_inceput, int minut_inceput, int ora_final, int minut_final) {
		oi = ora_inceput;
		mi = minut_inceput;
		of = ora_final;
		mf = minut_final;
	}
	int getOraInceput() {
		return oi;
	}
	int getOraFinal() {
		return of;
	}
	int getMinutInceput() {
		return mi;
	}
	int getMinutFinal() {
		return mf;
	}
};

class Camin {
private:
	string nume;
	int nrcamere,k;
	IntervalOrar v[50];
public:
	Camin() {
		nume = "";
		nrcamere = k = 0;
		for (int i = 0; i < k; i++)
			v[i] = IntervalOrar(0, 0, 0, 0);
	}
	Camin(string _nume, int _nrcamere, int _k, IntervalOrar _v[]) {
		nume = _nume;
		nrcamere = _nrcamere;
		k = _k;
		for (int i = 0; i < k; i++)
			v[i] = _v[i];
	}

	void setNume(string s) {
		nume = s;
	}
	void setNrCamere(int x) {
		nrcamere = x;
	}
	void setIntervale(int x, IntervalOrar a[]) {
		k = x;
		for (int i = 0; i < k; i++)
			v[i] = a[i];
	}
	string getNume() {
		return nume;
	}
	int getNrCamere() {
		return nrcamere;
	}
	int getK() {
		return k;
	}
	int getInceput(int k) {
		return v[k].getOraInceput() + (float)v[k].getMinutInceput()/100;
	}
	int getFinal(int k) {
		return v[k].getOraFinal() + (float)v[k].getMinutFinal() / 100;
	}
};
int main() {

	int n,i,camere, k, oi, of, mi, mf, j;
	string name;
	cout << "Dati numarul n de camine: ";
	cin >> n;
	cin.get();
	Camin v[50];
	for (i = 0; i < n; i++)
	{
		cout << "Dati numele caminului " << i << ": ";
		getline(cin, name);
		cout << "Dati numarul de camere si numarul de intervale de liniste ale caminului " << i << ": ";
		cin >> camere >> k;
		cin.get();
		IntervalOrar x[50];
		for (j = 0; j < k; j++)
		{
			cout << "Dati intervalul orar: " << j << ": ";
			cin >> oi >> mi >> of >> mf;
			cin.get();
			x[j] = IntervalOrar(oi, mi, of, mf);
		}
		v[i] = Camin(name, camere, k, x);
	}
	float a, b,c,d;
	float timpi[50];
	for (i = 0; i < n; i++)
		timpi[i] = 24.0;
	for(i=0;i<n;i++)
		for (j = 0; j < v[i].getK(); j++)
		{
			a = v[i].getInceput(j);
			b = v[i].getFinal(j);
			if (b < a)
				b += 24;
			timpi[i] -= (b - a);
		}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if (timpi[i] < timpi[j])
			{
				swap(timpi[i], timpi[j]);
				swap(v[i], v[j]);
			}
	if (n < 3)
		cout << "Nu exista 3 camine.";
	else
		for (i = 0; i < 3; i++)
			cout << v[i].getNume();
	return 0;
}