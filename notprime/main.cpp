/*Напишите программу находящую первые n составных чисел.
Программа должна работать не более чем за O(n*log log n) шагов.
*/
#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> c;
vector <bool> vec;

int main() {
    cin >> n;
    vec.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (!vec[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                vec[j] = true;
                c.push_back(j);
            }
        }
    }
    int m = c.size();
    for (int i = 0; i < m; i++)
    {
        cout << c[i] << ' ';
    }
    return 0;
}