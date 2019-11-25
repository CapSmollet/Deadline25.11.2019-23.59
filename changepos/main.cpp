/*Напишите программу перебирающую все перестановки массива букв в лексикографическом порядке.
 * Программа должна работать не более чем за O(n!*n) шагов.*/
#include <iostream>
#include <algorithm>

using namespace std;

string Next_Permutation(string x)
{
    int i = 0, n = int(x.size());
    while (i < n - 1 && x[i] >= x[i + 1])
    {
        i++;
    }
    if (i == n - 1)
        return x;
    int l = i + 1;
    while (l < n && x[l] > x[i])
    {
        l++;
    }
    l--;
    swap(x[l], x[i]);
    reverse(x.begin() + i + 1, x.end());
    return x;
}

int main() {
    string s;
    cin >> s;
    while (s != Next_Permutation(s))
    {
        s = Next_Permutation(s);
        if (s != Next_Permutation(s))
            cout << Next_Permutation(s) << '\n';
    }
    return 0;
}