#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    long n;
    cin >> n;
    vector<int> array(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    if (n == 2) {
        cout << -1;
        return 0;
    }

    vector<long> F(n, LONG_MIN);
    F[0] = array[0];

    for (int i = 0; i < n; i++) {
        if (F[i] == LONG_MIN) continue;

        if (i + 2 < n) {
            if (F[i] + array[i + 2] > F[i + 2]) {
                F[i + 2] = F[i] + array[i + 2];
            }
        }

        if (i + 3 < n) {
            if (F[i] + array[i + 3] > F[i + 3]) {
                F[i + 3] = F[i] + array[i + 3];
            }
        }
    }

    if (F[n - 1] != LONG_MIN) {
        cout << F[n - 1] << endl;


        vector<int> path;
        int current = n - 1;
        path.push_back(current + 1);

        while (current > 0) {

            if (current - 2 >= 0 && F[current - 2] != LONG_MIN &&
                F[current] == F[current - 2] + array[current]) {
                current = current - 2;
            }
            else if (current - 3 >= 0 && F[current - 3] != LONG_MIN &&
                F[current] == F[current - 3] + array[current]) {
                current = current - 3;
            }
            else {

                break;
            }
            path.push_back(current + 1);
        }


        if (path.back() != 1) {
            path.push_back(1);
        }


        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
    }
    else {
        cout << -1;
    }

    return 0;
}