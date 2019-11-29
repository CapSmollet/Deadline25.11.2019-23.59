/* Напишите эффективную функцию, выписывающую из массива длины n все элементы, у которых количество двоек в троичной записи меньше k.
 * Функция должна возвращать общее количество двоек в троичной записи всех чисел массива. В комментариях напишите, почему перебор - эффективный
 * Перебор эффективный, потому что не существует более эффективного
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, in;
vector <int> vec;

bool cmp(int a, int b)
{
    if (a > b)
        return true;
}
int counter(int x)
{
    int num = 0;
    while (x % 3 != x)
    {
        if (x % 3 == 2)
            num++;
        x /= 3;
    }
    if (x % 3 == 2)
        num++;
    return num;
}
int del_and_sum(vector <int>& x)
{
    int sum = 0;
    sort(x.begin(), x.end(), cmp);
    int i = 0;
    while (x[i] >= k)
    {
        i++;
    }
    x.resize(i);
    for (int j = 0; j < i; j++)
    {
        sum += x[j];
    }
    return sum;
}

int main()
{
    cin >> n >> k;
    vec.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> in;
        vec[i] = counter(in);
    }
    cout << del_and_sum(vec);
    return 0;
}