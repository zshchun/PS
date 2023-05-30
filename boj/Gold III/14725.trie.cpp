#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

struct Trie {
	map<string, Trie*> child;
	int depth;

	Trie(int d) {
		depth = d;
	}

	~Trie() {
		for (auto it = child.begin(); it != child.end(); it++) {
			delete it->second;
		}
	}

	void insert(vector<string> &s) {
		Trie *cur = this;
		int d = depth + 1;
		for (string &t : s) {
			if (cur->child.find(t) == cur->child.end()) {
				cur->child[t] = new Trie(d);
			}
			d++;
			cur = cur->child[t];
		}
	}

	void find() {
		for (auto it = child.begin(); it != child.end(); it++) {
			for (int i=0;i<depth;i++)
				cout << "--";
			cout << it->first << endl;
			it->second->find();
		}
		return;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll N, K, i, j;
	cin >> N;
	Trie *trie = new Trie(0);

	for (i=0;i<N;i++) {
		cin >> K;
		vector<string> s(K);
		for (j=0;j<K;j++) {
			cin >> s[j];
		}
		trie->insert(s);
	}

	trie->find();

	return 0;
}
