class FrequencyTracker {
public:
    FrequencyTracker() {
        cnt.clear();
        fre.clear();
    }
    
    void add(int number) {
        auto& v = cnt[number];
        if (v > 0) {
            --fre[v];
        }
        ++v;
        ++fre[v];
    }
    
    void deleteOne(int number) {
        if (cnt.count(number) != 0) {
            auto& v = cnt[number];
            --fre[v];
            --v;
            ++fre[v];
            if (v == 0) {
                cnt.erase(number);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return fre[frequency] > 0;
    }
    
    unordered_map<int, int> cnt;
    unordered_map<int, int> fre;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
