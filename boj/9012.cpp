#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, i, state;
	unsigned long j;
	string l;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> l;
		state = 0;
		for (j=0;j<l.size();j++) {
			if (l[j] == '(') {
				state++;
			} else if (l[j] == ')') {
				state--;
				if (state<0) break;
			}
		}
		if (!state) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
