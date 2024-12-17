#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<list<int>> table;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int size) {
        this->size = size;
        table.resize(size);
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (*it == key) {
                chain.erase(it);
                return;
            }
        }
    }

    bool search(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];
        for (int val : chain) {
            if (val == key) {
                return true;
            }
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            for (int val : table[i]) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(7);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(25);

    cout << "Hash Table after insertion:" << endl;
    ht.display();

    cout << "Searching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 30: " << (ht.search(30) ? "Found" : "Not Found") << endl;

    ht.remove(15);
    cout << "Hash Table after deleting 15:" << endl;
    ht.display();

    return 0;
}
