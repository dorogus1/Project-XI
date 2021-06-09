#include<iostream>
using namespace std;
int x[10], n;

void Afis(int k)
{
    for (int i = 1; i <= k; i++)
        cout << x[i] << " ";
    cout << endl;
}

int valid(int k) {
    for (int i = 1; i < k; ++i)
        if (x[k] == x[i])
            return 0;
    return 1;
}

int Solutie(int k)
{
    return k == n;
}

void per(int k) {
    for (int i = 1; i <= n; ++i)
    {
        x[k] = i;
        if (valid(k))
            if (Solutie(k))
                Afis(k);
            else
                per(k + 1);
    }
}


int  p;


int Sol(int k)
{
    return k == p;
}

void aranjamente(int k) {
    for (int i = 1; i <= n; ++i)
    {
        x[k] = i;
        if (valid(k))
            if (Sol(k))
                Afis(k);
            else
                aranjamente(k + 1);
    }
}



void combinari(int k) {
    for (int i = x[k - 1] + 1; i <= n; ++i)
    {
        x[k] = i;
        if (Sol(k))
            Afis(k);
        else
            combinari(k + 1);
    }
}

int valide(int k) {
    for (int i = 1; i < k; ++i)
        if (x[k] == x[i] || x[k] - x[i] == k - i)
            return 0;
    return 1;
}

void dame(int k) {
    for (int i = 1; i <= n; ++i)
    {
        x[k] = i;
        if (valide(k) == 1)
            if (Solutie(k) == 1)
                Afis(k);
            else
                dame(k + 1);
    }
}

#include <conio.h>
int m, k, NrSol;
bool buna;
bool v[100][100];
bool EsteBuna(int k)
{
    int i;
    bool atac;
    atac = false; i = 1;
    while (i < k && !atac)
    {
        if (x[i] == x[k] && v[i][k] == 1)
            atac = true;
        else
            i++;
    }
    return !atac;
}

void ScrieSolutia()
{
    int i;
    cout << "Solutia numarul " << NrSol << ": " << endl;
    for (i = 1; i <= n; i++)
        cout << " Tara nr. " << i << " se coloreaza in culoarea " << x[i] << endl;
    cout << endl;
}

void scriere()
{
    for (int i = 1; i <= n; i++)
    {
        cout << "f(" << i << ")=" << x[i];
        cout << "\n";
    }
    cout << "\n";
}
int val(int k)
{
    for (int i = 1; i < k; i++)
        if (x[k] == x[i]) return 0;
    return 1;
}
void back(int k)
{
    int i;
    for (i = 1; i <= m; i++)
    {
        x[k] = i;
        if (val(k))
            if (k == n) scriere();
            else
                back(k + 1);
    }


}

void afisare()
{
    for (int i = 1; i <= n; i++)
    {
        cout << "f(" << (i) << ")=" << x[i];
        cout << "\n";
    }
    cout << "\n";
}
int vd(int k)
{
    int sw = 1, i, ap[20] = { 0 };
    for (i = 1; i <= k; i++)
        ap[x[i]] = 1;
    for (i = 1; i <= m; i++)
        if (ap[i] == 0) sw = 0;
    return sw;
}
void backk(int k)
{
    for (int i = 1; i <= m; i++)
    {
        x[k] = i;
        if (k == n)
        {
            if (vd(k))
                afisare();
        }
        else backk(k + 1);
    }
}




int nr_sol, st[50];
char c[6] = { ' ','a','r','v','b','n' };
int valid(int i, int j)
{
    int da = 1;
    if (st[i] == st[j]) da = 0;
    if ((st[i] == 3) && (st[j] == 4)) da = 0;
    if ((st[i] == 4) && (st[j] == 3)) da = 0;
    return da;
}
void afiseaza()
{
    int nr_r = 0, j;
    for (j = 1; j <= n; j++)
        if (st[j] == 2) nr_r++;
    if (nr_r <= n / 3)
    {
        nr_sol++;
        for (j = 1; j <= n; j++)
            cout << c[st[j]] << " ";
        cout << "\n";
    }
}
void bacck(int k)
{
    int i;
    for (i = 1; i <= 5; i++)
        if (nr_sol == 0)
        {
            st[k] = i;
            if (valid(k, k - 1))
                if (k == n)
                {
                    if (valid(n, 1))
                        afiseaza();
                }
                else bacck(k + 1);
        }
}






int main()
{
    cout << "Lista probleme pentru proiect" << endl;
    cout << "I. permutari de n" << endl;
    cout << "II. aranjamente de n" << endl;
    cout << "III. combinari de n" << endl;
    cout << "IV. Problema celor n dame" << endl;
    cout << "V. Problema colorarilor hartilor " << endl;
    cout << "VI. Sa se genereze toate functiile injective f:{1,2,…,n}--> {1,2,…,m}. " << endl;
    cout << "VII. Sa se genereze toate functiile surjective f:{1,2,…,n}--> {1,2,…,m}. " << endl;
    cout << "VIII. Se dau margele de 5 culori: alb, rosu, verde, albastru, negru. Numarul margelelor de fiecare culoare se considera nelimitat. Sa se afiseze toate colierele de n margele care se pot forma, respectand urmatoarele conditii:- nu poate fi plasata o margea verde langa o margea albastra;- nu pot fi plasate margele vecine de aceeasi culoare;- numarul margelelor rosii nu poate depasi o treime din numarul total de margele din colier Indicatii: culorile margelelor se modificã astfel: alb cu 'a', albastru cu 'b', rosu cu 'r', verde cu 'v', negru cu 'n'." << endl;
 
    for (int a1 = 1; a1 <= 8; a1++) {
        int a;
   
        cin >> a; /*daca vrei sa opresti programul alegi a>8*/
        switch (a)
        {
        case 1:
            cout << "Metodata Backtrancking; Elemente de combinatorica" << endl;
            cout << "Metoda backtracking construieste progresiv vectorul solutiei, pornind de la primul element si adaugand la vector urmatoarele elemente-cu revenire la elemeentul anterior din vector- in caz de insucces. Elementul care trebuie adaugat se cauta in multome, printre elementele care respecta conditiile interne." << endl;
            cout << "I. permutari de n" << endl;
            cin >> n;
            per(1);
            break;
        case 2:
            cout << "II. aranjamente de n" << endl;
            cin >> n >> p;
            aranjamente(1);
            break;
        case 3:
            cout << "III. combinari de n" << endl;
            cin >> n >> p;
            combinari(1);
            break;
        case 4:
            cout << "IV. Problema celor n dame" << endl;
            cout << "Fiind o tabla de sah cu dimenesiuni nXn, se cer toate solutile de arankare a n dame, astfel incat sa nu se afle doua dame pe aceasi linie, coloana, diagonala(damele sa nu se atatace reciproc" << endl;
            cin >> n;
            dame(1);
            break;
        case 5:
            cout << "V. Problema colorarilor hartilor " << endl;
            cout << "Fiind dat o harta cu n tari, se cer toate solutile de colorale a hartii, utilizand cel mult 4 culori, astfel incat doua tari cu frontiera comuna sa fie colorate diferit " << endl;
            int i, j;
            cout << "Dati numarul de culori: "; cin >> m;
            cout << "Dati numarul de tari: "; cin >> n;
            for (i = 1; i <= n; i++)
                v[i][i] = 0;
            for (i = 1; i <= n - 1; i++)
                for (j = i + 1; j <= n; j++)
                {
                    cout << "Este tara " << i << " vecina cu tara " << j << " alege Da=1 sau Nu=0 ";
                    cin >> v[i][j];
                    v[j][i] = v[i][j];
                }
            k = 1; x[k] = 0;
            while (k > 0)
            {
                buna = 0;
                while (x[k] < m && !buna)
                {
                    x[k] = x[k] + 1;
                    if (EsteBuna(k))
                        buna = 1;
                }
                if (buna)
                    if (k == n)
                    {
                        NrSol++;
                        ScrieSolutia();
                    }
                    else
                    {
                        k++;
                        x[k] = 0;
                    }
                else
                    k = k - 1;
            }
            cout << "Total: " << NrSol << " solutii." << endl;
            break;
        case 6:
            cout << "VI. Sa se genereze toate functiile injective f:{1,2,…,n}--> {1,2,…,m}. " << endl;
            cout << "n="; cin >> n; cout << "m="; cin >> m;
            if (m < n) cout << "Nu exista functii injective." << endl;
            else back(1);
            break;
        case 7:
            cout << "VII. Sa se genereze toate functiile surjective f:{1,2,…,n}--> {1,2,…,m}. " << endl;
            cout << "n="; cin >> n;
            cout << "m="; cin >> m;
            if (m > n)
                cout << "Nu exista functii surjective." << endl;
            else backk(1);
            break;
        case 8:
            cout << "VIII. Se dau margele de 5 culori: alb, rosu, verde, albastru, negru. Numarul margelelor de fiecare culoare se considera nelimitat. Sa se afiseze toate colierele de n margele care se pot forma, respectand urmatoarele conditii:- nu poate fi plasata o margea verde langa o margea albastra;- nu pot fi plasate margele vecine de aceeasi culoare;- numarul margelelor rosii nu poate depasi o treime din numarul total de margele din colier Indicatii: culorile margelelor se modificã astfel: alb cu 'a', albastru cu 'b', rosu cu 'r', verde cu 'v', negru cu 'n'." << endl;
            cout << "Nr de margele din colier="; cin >> n;
            bacck(1);
            if (nr_sol == 0)
                cout << "Problema nu are solutii" << endl;
            cout << endl;
            break;
        }
        
    }

    cout << "Sfarsit";

        return 0;
}

