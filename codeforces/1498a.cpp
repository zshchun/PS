#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//int gcd(int a, int b) { }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, n, s, v;
	cin >> T;
	while(T--) {
		cin >> n;
		while (1) {
			s = 0;
			v = n;
			while (v){
				s += v % 10;
				v /= 10;
			}
			if (__gcd(n, s) != 1) break;
			n++;
		}
		cout << n << '\n';
	}
	return 0;
}
