class StockPrice {
public:
    StockPrice() {

    }

    void update(int timestamp, int price) {
        auto it = t2p.find(timestamp);
        if (it == t2p.end()) {
            t2p.emplace(timestamp, price);
            prices.emplace(price, timestamp);
        } else {
            auto p = it->second;
            if (price != p) {
                it->second = price;
                prices.erase(make_pair(p, timestamp));
                prices.emplace(price, timestamp);
            }
        }
    }

    int current() {
        return t2p.rbegin()->second;
    }

    int maximum() {
        return prices.rbegin()->first;
    }

    int minimum() {
        return prices.begin()->first;
    }

    map<int, int> t2p;
    set<pair<int, int>> prices;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
