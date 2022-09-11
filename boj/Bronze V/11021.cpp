#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, n, a, b;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (i=1;i<=n;i++) {
		cin >> a >> b;

		cout << "Case #" << i << ": " << a + b << "\n"; 
	}

	return 0;
}
