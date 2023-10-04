static const int fast_io = []()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return 0;
}();

struct node {
	int key, data;
	node* next;

	node(int key, int data): key(key), data(data), next(NULL) {}

};

const int cap = 10000;

class MyHashMap {
public:

	node* mem[cap];

	MyHashMap() {
		for (int i = 0; i < cap; i++)
			mem[i] = NULL;
	}

	void put(int key, int value) {
		int search = key % cap;
		if (mem[search] == NULL) {
			mem[search] = new node(key, value);
		}
		else {
			node* curr = mem[search];

			while (curr->next && curr->key != key) {
				curr = curr->next;
			}
			if (curr->key == key)
				curr->data = value;
			else
				curr->next = new node(key, value);
		}
	}

	int get(int key) {
		int search = key % cap;
		node* curr = mem[search];
		if (curr == NULL)
			return -1;
		while (curr) {
			if (curr->key == key)
				return curr->data;
			curr = curr->next;
		}
		return -1;
	}

	void remove(int key) {
		int search = key % cap;
		node* curr = mem[search];
		node* prev = NULL;
		while (curr) {
			if (curr->key == key) {
				if (prev == NULL) {
					node* next = curr->next;
					mem[search] = next;
				}
				else {
					prev->next = curr->next;
				}
				delete curr;
				break;
			}
			prev = curr;
			curr = curr->next;
		}
	}
};