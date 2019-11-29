/*Напишите программу находящую праймориал числа.
Программа должна работать не более чем за O(n*log log n) шагов.
*/
#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1;
vector <int> c;
vector <bool> vec;

int main() {
    cin >> n;
    vec.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (!vec[i])
        {
            ans *= i;
            for (int j = i * i; j <= n; j += i)
            {
                vec[j] = true;
            }
        }
    }
    cout << ans;
    return 0;
}