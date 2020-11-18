#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Input(int* a, const int size) {
    for
        (int i = 0; i < size; i++)

    {
        cout << "a[" << i << "] = "
            ;
        cin >> a[i];

    }
    cout << endl;
}

void Sort(int* a, const int size) // метод вибору
{
    for (int i = 0; i < size - 1; i++) // індекс початку невпорядкованої частини
    {
        int min = a[i]; // пошук мінімального елемента
        int imin = i; // невпорядкованої частини
        for (int j = i + 1; j < size; j++)
            if (min > a[j])
            {
                min = a[j];
                imin = j;
            }
        a[imin] = a[i]; // обмін місцями мінімального та першого
        a[i] = min; // елементів невпорядкованої частини
    }
}
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
    cout << endl;
}

int max(int* a, const int size)//пошук максимального
{
    int max = 0;
    for (int i = 1; i < size; i++)
        if (a[i] > a[max])
            max = i;
    return max;
}
int min(int* a, const int size)//пошук мінімального
{
    int min = 0;
    for (int i = 1; i < size; i++)
        if (a[i] < a[min])
            min = i;
    return min;
}
int Sum(int* a, const int size)//Сумa додатних елементів масиву
{
    int S = 0;

    for (int i = 0; i < size; i++)
        if (a[i] > 0)
            S += a[i];
    return S;
}

int S1(int* a, const int size, int max_v, int min_v)
{
    int p = 1;
    for (int i = 0; i < size; i++)
    {
        if ((a[i] == a[min_v] && a[i + 1] == a[max_v]) || (a[i] == a[max_v] && a[i + 1] == a[min_v]))
            return p;
        if (a[i] == a[min_v])
        {
            for (i = i + 1; i < max_v; i++)
                p *= a[i];
            i = size + 1;
        }
        else;
        if (a[i] == a[max_v])
        {
            for (i = i + 1; i < min_v; i++)
                p *= a[i];
            i = size + 1;
        }
        else;
    }

    return p;
}

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    const int n = 5;
    int a[n];
    int Low = -10;
    int High = 10;
    Input(a, n);
    Print(a, n);
    Sort(a, n);
    Print(a, n);


    cout << "S = " << Sum(a, n) << endl;

    int max_v = max(a, n);
    int min_v = min(a, n);


    cout << "max = " << a[max_v] << endl;//вивід макс
    cout << "min = " << a[min_v] << endl;//вивід мін
    int p = S1(a, n, max_v, min_v);
    if (p == 1)
        cout << "ne mae elementiv v promishky " << endl;
    else
        cout << "S1 = " << p << endl;

    Sort(a, n);

    return 0;
}