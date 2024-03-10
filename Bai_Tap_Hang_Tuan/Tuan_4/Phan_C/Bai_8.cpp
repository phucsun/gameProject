#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> patients(N);
    for (int i = 0; i < N; ++i) {
        cin >> patients[i];
    }

    sort(patients.begin(), patients.end());

    long long total_wait_time = 0;
    for (int i = 0; i < N; ++i) {
        total_wait_time += patients[i] * (N - i - 1);
    }

    cout << total_wait_time << endl;

    return 0;
}

