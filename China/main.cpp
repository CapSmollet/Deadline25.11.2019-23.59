/*Напишите программу, находящую все простые числа Ченя не превосходящие n. Программа должна работать не более
чем за O(n*log log n) шагов
 */
#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> p;
vector <bool> vec;
bool count(int x)
{
    int counter = 0;
    for (int i = 0; i < int(p.size()); i++)
    {
        while (x % p[i] == 0)
        {
            x /= p[i];
            counter++;
            if (counter > 2)
                return false;
        }
    }
    return true;
}

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
            }
            p.push_back(i);
        }
    }
    int m = p.size();
    for (int i = 0; i < m; i++)
    {
        if ((i + 1 != m && p[i] + 2 == p[i + 1]) || count(p[i] + 2))
        {
            cout << p[i] << ' ';
        }
    }
    return 0;
}