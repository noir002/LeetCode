
class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->min_freq = 0;
    }

    int get(int key) {
        if (key_to_val.find(key) == key_to_val.end()) return -1;
        update_freq(key);
        return key_to_val[key];
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (key_to_val.count(key)) {
            key_to_val[key] = value;
            update_freq(key);
            return;
        }

        if (key_to_val.size() == capacity) {
            int evict_key = freq_to_keys[min_freq].back();
            freq_to_keys[min_freq].pop_back();
            key_to_val.erase(evict_key);
            key_to_freq.erase(evict_key);
            key_to_iter.erase(evict_key);
            if (freq_to_keys[min_freq].empty()) {
                freq_to_keys.erase(min_freq);
            }
        }

        key_to_val[key] = value;
        key_to_freq[key] = 1;
        freq_to_keys[1].push_front(key);
        key_to_iter[key] = freq_to_keys[1].begin();
        min_freq = 1;
    }

private:
    int capacity;
    int min_freq;
    unordered_map<int, int> key_to_val;
    unordered_map<int, int> key_to_freq;
    unordered_map<int, list<int>> freq_to_keys;
    unordered_map<int, list<int>::iterator> key_to_iter;

    void update_freq(int key) {
        int freq = key_to_freq[key];
        freq_to_keys[freq].erase(key_to_iter[key]);

        key_to_freq[key] = freq + 1;
        freq_to_keys[freq + 1].push_front(key);
        key_to_iter[key] = freq_to_keys[freq + 1].begin();

        if (freq_to_keys[freq].empty()) {
            freq_to_keys.erase(freq);
            if (min_freq == freq) min_freq++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
