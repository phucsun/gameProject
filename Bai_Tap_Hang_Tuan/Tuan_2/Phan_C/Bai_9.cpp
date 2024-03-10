#include <iostream>
#include <cstdio>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int a = 1e9;
  int b = 1e9;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    a = min(a, x);
    b = min(b, y);
  }
  cout << 1LL * a * b << endl;
}

int main() {
	solve();
 	return 0;
}
