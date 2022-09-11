#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n[10], j, i, cnt = 0;
	for (i=0;i<10;i++) {
		cin >> n[i];
		n[i] %= 42;
	}
	for (i=0;i<10;i++) {
		cnt++;
		cout << n[i] << "\n";
		for (j=0;j<i;j++) {
			if (n[i] == n[j]) {
			cout << "cnt--\n";
				cnt--;
				break;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}
