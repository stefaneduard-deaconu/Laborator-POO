#include <iostream>
#include <math.h>
using namespace std;
typedef struct date {
    int an, luna, zi, ora;
};
typedef struct eveniment {
    date inceput, sfarsit;
    char nume[100];
};
void citireeveniment(eveniment v[], int i)
{
    cin >> v[i].inceput.zi >> v[i].inceput.luna >> v[i].inceput.an >> v[i].inceput.ora >> v[i].sfarsit.zi >>
        v[i].sfarsit.luna >> v[i].sfarsit.an >> v[i].sfarsit.ora >> v[i].nume;
}
int comparadate(date a, date b)
{
    if (a.an < b.an)
        return 1;
    else if (a.an > b.an)
        return 0;
    else
        if (a.luna < b.luna)
            return 1;
        else if (a.luna > b.luna)
            return 0;
        else
            if (a.zi < b.zi)
                return 1;
            else if (a.zi > b.zi)
                return 0;
            else
                if (a.ora < b.ora)
                    return 1;
                else if (a.ora > b.ora)
                    return 0;
                else
                    return 2; // datele sunt egale
}
void afisareeveniment(eveniment v[], int i)
{
    cout << v[i].inceput.zi << "." << v[i].inceput.luna << "." << v[i].inceput.an << " " << v[i].inceput.ora << ":00 - " << v[i].sfarsit.zi
        << "." << v[i].sfarsit.luna << "." << v[i].sfarsit.an << " " << v[i].sfarsit.ora << ":00 " << v[i].nume;
}

void sortareevenimente(eveniment v[], int n)
{   // sortarea se face dupa data de inceput, iar in caz de egalitate, dupa data de sfarsit
    eveniment aux;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (!comparadate(v[i].inceput, v[j].inceput))
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
            else if (comparadate(v[i].inceput, v[j].inceput) == 2)
                if (!comparadate(v[i].sfarsit, v[j].sfarsit))
                {
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }

}

int main()
{
    int n, i;
    eveniment d[100], x;
    cin >> n;
    for (i = 1; i <= n; i++)
        citireeveniment(d, i);
    sortareevenimente(d, n);
    afisareeveniment(d, 1);
    cout << endl;
    x = d[1];
    for (i = 2; i <= n; i++)
        if (!comparadate(d[i].inceput, x.sfarsit))
        {
            afisareeveniment(d, i);
            cout << endl;
            x = d[i];
        }
    return 0;
}