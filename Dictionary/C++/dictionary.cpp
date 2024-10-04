#include <iostream>
#include <vector>
using namespace std;

template <typename Tkey, typename Tvalue>
class KeyValuePair {
    private:
        Tkey key;
    public:
        Tvalue value;

        KeyValuePair(Tkey key, Tvalue value) {
            this->key = key;
            this->value = value;
        }

        Tkey getKey() {
            return this->key; 
        }

};

template <typename Tkey, typename Tvalue>
class Dictionary {
    private:
        vector<KeyValuePair<Tkey, Tvalue>> entries;

    public:
        Dictionary() {}

        void set(Tkey key, Tvalue value) {
            for (auto &entry : entries) {
                if (entry.getKey() == key) {
                    entry.value = value;
                    return;
                }
            }

            this->entries.push_back(KeyValuePair<Tkey, Tvalue>(key, value));
        }

        bool remove(Tkey key) {
            for (auto it = this->entries.begin(); it != this->entries.end(); ++it) {
                if (it->getKey() == key) {
                    this->entries.erase(it);
                    return true;
                }
            }
            return false;
        }

        Tvalue get(Tkey key) {
            for (auto &entry : entries) {
                if (entry.getKey() == key) {
                    return entry.value;
                }
            } 
            throw runtime_error("Key not found");
        }

        int size() {
            return this->entries.size();
        }

        bool isEmpty() {
            return this->entries.size() != 0;
        }

        void print() {
            for (int x = 0; x <= this->entries.size() -1; x++) {
                cout << "Key: " << this->entries.at(x).getKey() << '\t' << "Value: " << this->entries.at(x).value;
                cout << endl;
            }
        }
};
