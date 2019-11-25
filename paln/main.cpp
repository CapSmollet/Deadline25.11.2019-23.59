/*
 Напишите эффективную программу, находящую все числа длины n являющиеся палиндромами. В комментариях напишите, почему перебор - эффективный
 */
#include <iostream>

using namespace std;

int n;

void find_pal(string x, int i, int j)
{
    if (i == j)
    {
        for (int k = 0; k <= 8; k++)
        {
            x[i]++;
            cout << x << '\n';
        }
        return;
    }
    cout << x << '\n';
    if (x[i] - '0' < 9)
    {
        x[i]++;
        x[j]++;
        find_pal(x, i, j);
        x[i]--;
        x[j]--;
    }
    if (j - i == 1)
    {
        return;
    }
    if (i + 1 != j - 1)
    {
        x[i + 1]++;
        x[j - 1]++;
    }
    find_pal(x, i + 1, j - 1);
}

int main() {
    string s;
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++)
    {
        s[i] = '0';
    }
    s[n - 1]++;
    s[0]++;
    find_pal(s, 0, n - 1);
    /*Программа эффективна потому что идёт только по палиндромам, не перебирая все варианты числа длины n, а также я
    использую строку которая сильно увеличивает допустимую длину.
     */
    return 0;
}