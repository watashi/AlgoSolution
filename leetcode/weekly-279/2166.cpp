class Bitset {
public:
    Bitset(int size): v(size), c(0), f(false) {

    }

    void fix(int idx) {
        if (v[idx] != !f) {
            v[idx] = !f;
            c += 1;
        }
    }

    void unfix(int idx) {
        if (v[idx] != f) {
            v[idx] = f;
            c -= 1;
        }
    }

    void flip() {
        c = v.size() - c;
        f = !f;
    }

    bool all() {
        return c == v.size();
    }

    bool one() {
        return c > 0;
    }

    int count() {
        return c;
    }

    string toString() {
        std::string s;
        s.reserve(v.size());
        for (bool b: v) {
            s.push_back(b == f ? '0' : '1');
        }
        return s;
    }

private:
    vector<bool> v;
    size_t c;
    bool f;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
