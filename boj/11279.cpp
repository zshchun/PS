#include <bits/stdc++.h>
using namespace std;
typedef struct heap {
	int data[100001];
	int size;
} heap;
heap h;
void insert(heap *h, int x) {
	int p = (h->size)++;
	while (p && h->data[(p-1)/2] < x) {
		h->data[p] = h->data[(p-1)/2];
		p = (p-1)/2;
	}
	h->data[p] = x;
}
int erase(heap *h) {
	if (!h->size) return 0;
	int ret = h->data[0];
	h->data[0] = h->data[--h->size];
	int p = 0;
	while(p*2+1 < h->size) {
		int c = p*2+1;
		if (c+1 < h->size && h->data[c] < h->data[c+1])
			c++;
		if (h->data[c] < h->data[p]) break;
		int t = h->data[c];
		h->data[c] = h->data[p];
		h->data[p] = t;
		p = c;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, v;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> v;
		if (v)
			insert(&h, v);
		else
			cout << erase(&h) << '\n';
	}
	return 0;
}
