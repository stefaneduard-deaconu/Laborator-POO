#include <iostream>
using namespace std;
int main()
{
    int n, v[100], i, j, k = 0, aux, ok, l, numitor[100] = { 0 }, numarator[100] = { 0 };
    float vi[100] = { float(0) };
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> v[i];
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++)
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    for (i = n; i >= 2; i--)
        for (j = i - 1; j >= 1; j--)
        {
            ok = 0;
            for (l = 1; l <= k && !ok; l++)
                if (vi[l] == (float)v[i] / v[j])
                    ok = 1;
            if (!ok)
            {
                vi[++k] = (float)v[i] / v[j];
                cout << v[i] << "/" << v[j] << " ";
                numitor[k] = v[j];
                numarator[k] = v[i];
            }
        }
    cout << endl;
    for (i = 1; i < k; i++)
        for (j = i + 1; j <= k; j++)
            if ((float)numarator[i] / numitor[i] > (float)numarator[j] / numitor[j])
            {
                aux = numarator[i];
                numarator[i] = numarator[j];
                numarator[j] = aux;
                aux = numitor[i];
                numitor[i] = numitor[j];
                numitor[j] = aux;
            }
    for (i = 1; i <= k; i++)
        cout << numarator[i] << "/" << numitor[i] << " ";
}