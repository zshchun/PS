#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pa;
class LRUCache {
	int cap = 0;
	int tick = 0;
	vector<int> valid; // key, tick
	vector<int> kv; // key, value
	map<int,int> m; // tick, key
	void update(int key) {
		int &t = this->valid[key];
		if (t >= 0) {
			this->m.erase(t);
			this->valid[key] = this->tick;
			this->m[t] = key;
		}
	}

public:
	LRUCache(int capacity) {
		valid.resize(10001);
		kv.resize(10001);
		fill_n(valid.begin(), 10001, -1);
		this->cap = capacity;
	}

	int get(int key) {
		this->tick++;
		this->update(key);
		if (valid[key] >= 0)
			return kv[key];
		return -1;
	}

	void put(int key, int value) {
		this->tick++;
		this->update(key);
		this->valid[key] = this->tick;
		this->kv[key] = value;
		this->m[this->tick] = key;
		this->update(key);
		if (m.size() > this->cap) {
			int k = m.begin()->second;
			this->valid[k] = -1;
			m.erase(m.begin());
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
