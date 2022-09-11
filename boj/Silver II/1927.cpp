#include <bits/stdc++.h>
using namespace std;
int h[100001];
int h_size;
void insert(int x) {
	int p = h_size++;
	while (p && x < h[(p-1)/2]) {
		h[p] = h[(p-1)/2];
		p = (p-1) / 2;
	}
	h[p] = x;
}
int erase() {
	if (!h_size) return 0;
	int r = h[0];
	h[0] = h[--h_size];
	int c, t, p = 0;
	while ((p*2+1 < h_size && h[p*2+1] < h[p]) || (p*2+2 < h_size && h[p*2+2] < h[p])) {
		c = p*2+2 < h_size && h[p*2+1] > h[p*2+2] ? p*2+2 : p*2+1;
		t = h[c];
		h[c] = h[p];
		h[p] = t;
		p = c;
	}
	return r;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, v;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> v;
		if (v)
			insert(v);
		else
			cout << erase() << "\n";
	}

	return 0;
}
