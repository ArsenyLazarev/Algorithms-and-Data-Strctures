#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n;
    int* mas = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    cin >> k;
    int* quest = new int[k];
    for (int i = 0; i < k; i++) {
        cin >> quest[i];
    }
    for (int i = 0; i < k; i++) {
        int x = quest[i];

        // Бинарный поиск нижней границы - O(log n)
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mas[mid] < x) left = mid + 1;
            else right = mid;
        }
        int l = left;

        // Бинарный поиск верхней границы - O(log n)
        left = 0; right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mas[mid] <= x) left = mid + 1;
            else right = mid;
        }
        int r = left;

        int b = (l < n && mas[l] == x) ? 1 : 0;
        cout << b << " " << l << " " << r << endl;
    }
}