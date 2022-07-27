#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, N,n, ac;
	cin >> T;
	while(T--) {
		cin >> N;
		n = 0;
		ac = 1;
		i = 1;
		while (i<=N) {
//		for(i=1;i<=N;i+=ac) {
			n++;
			if (i >= ac*9) {
				ac = ac * 10 + 1;
				i = ac;
			} else {
				i += ac;
			}
		}
		cout << n << '\n';
	}
	return 0;
}
