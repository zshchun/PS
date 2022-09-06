#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull pow(ull base, ull exp, ull mod) {
	__int128 r = 1;
	__int128 b = base;
	__int128 e = exp;
	while (e) {
		if (e & 1)
			r = r * b % mod;
		e >>= 1;
		b *= b % mod;
	}
	return r;
}
int main() {
	cout << pow(99, 5000, 128) << "\n";
	return 0;
}
