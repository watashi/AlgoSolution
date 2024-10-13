#include <ext/pb_ds/assoc_container.hpp>

class Solution {
  template<typename Node_CItr, typename Node_Itr, typename _Cmp_Fn, typename _Alloc>
  struct NodeUpdate {
    struct Metadata {
      int size;
      long long sum;
    };

    using metadata_type = Metadata;

    virtual Node_CItr node_begin() const = 0;

    virtual Node_CItr node_end() const = 0;

    void operator()(Node_Itr it, Node_CItr end) {
      const auto& value = **it;
      auto& metadata = it.m_p_nd->get_metadata();
      metadata.size = 1;
      metadata.sum = (long long)value.first * value.second;
      for (auto child : { it.get_l_child(), it.get_r_child() }) {
        if (child != end) {
          metadata.size += child.get_metadata().size;
          metadata.sum += child.get_metadata().sum;
        }
      }
    }
    
    void dump(Node_CItr it, Node_CItr end, int indent) const {
      if (it != end) {
        dump(it.get_l_child(), end, indent + 2);
        const auto& value = **it;
        auto metadata = it.get_metadata();
        printf("%*s(%d, %d) [%d] %lld\n", indent, "", value.first, value.second, metadata.size, metadata.sum);
        dump(it.get_r_child(), end, indent + 2);
      }
    }

    void dump() const {
      dump(node_begin(), node_end(), 0);
      puts("");
    }

    long long query(Node_CItr it, Node_CItr end, int n) const {
      if (it == end) {
        return 0;
      }
      if (it.get_metadata().size <= n) {
        return it.get_metadata().sum;
      }
      long long ret = 0;
      auto r = it.get_r_child();
      if (r != end) {
        ret += query(r, end, n);
        n -= r.get_metadata().size;
      }
      if (n > 0) {
        const auto& value = **it;
        ret += (long long)value.first * value.second;
        n -= 1;
      }
      if (n > 0) {
        ret += query(it.get_l_child(), end, n);
      }
      return ret;
    }

    long long query(int n) const {
      // dump();
      return query(node_begin(), node_end(), n);
    }
  };

  using Tree = __gnu_pbds::tree<
    std::pair<int, int>,
    __gnu_pbds::null_type,
    std::less<std::pair<int, int>>,
    __gnu_pbds::rb_tree_tag,
    NodeUpdate>;

public:

  vector<long long> findXSum(vector<int>& nums, int k, int x) {
    map<int, int> c;
    for (int i = 0; i < k; ++i) {
      ++c[nums[i]];
    }

    Tree t;
    for (const auto& i : c) {
      t.insert(make_pair(i.second, i.first));
    }

    vector<long long> ret;
    ret.push_back(t.query(x));
    for (int i = k; i < (int)nums.size(); ++i) {
      const int head = nums[i - k];
      const int tail = nums[i];
      if (head != tail) {
        const int chead = c[head]--;
        const int ctail = c[tail]++;
        t.erase(make_pair(chead, head));
        if (chead > 1) {
          t.insert(make_pair(chead - 1, head));
        }
        if (ctail > 0) {
          t.erase(make_pair(ctail, tail));
        }
        t.insert(make_pair(ctail + 1, tail));
      }
      ret.push_back(t.query(x));
    }
    return ret;
  }
};
