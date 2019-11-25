#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, num;
vector <pair <int, string>> vec;

int main()
{
    string in;
    cin >> n >> k;
    vec.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> in;
        num = in[0] - '0';
        for (int j = 1; j < int(in.size()); ++j)
        {
            if (in[j] != '0')
                num *= in[j] - '0';
        }
        vec[i].first = num;
        vec[i].second = in;
    }
    sort(vec.begin(), vec.end());
    int i = n - 1;
    while (vec[i].first >= k)
    {
           cout << vec[i].second << ' ';
           i--;
    }
    return 0;
}
/*Программа эффективна потому что она перебирает не все варианты благодаря использованию быстрой функции sort (она
 позваляет смотреть только подходящие варианты и не сравнивать с неподходящими) и парному массиву, который записывет в
 себя сразу же готовые для сравнения с k числами
*/