#include <iostream>
#include <string>
using namespace std;
class Filme {
private:
    string titlu;
    unsigned likes;
public:
    Filme() {
        titlu = "";
        likes = 0;
    }
    Filme(string _titlu, unsigned _likes) {
        titlu = _titlu;
        likes = _likes;
    }
    void citeste()
    {
        string _titlu;
        unsigned _likes;
        getline(cin, _titlu);
        titlu = _titlu;
        cin >> _likes;
        cin.get();
        likes = _likes;
    }
    unsigned getLikes() {
        return likes;
    }

    string getTitlu(){
        return titlu;
    }
};

void afisarePopulare(int n, Filme filme[], int k)
{
    int i, j;
    Filme aux;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (filme[i].getLikes() > filme[j].getLikes())
            {
                aux = filme[i];
                filme[i] = filme[j];
                filme[j] = aux;
            }
    for (i = n - 1; i >= n-k; i--)
        cout << filme[i].getTitlu()<<endl;
}
int main()
{
    int n,i;
    Filme filme[50];
    cin >> n;
    cin.get();
    for (i = 0; i < n; i++)
    {
        filme[i].citeste();
    }
    afisarePopulare(n, filme, 3);
    return 0;
}