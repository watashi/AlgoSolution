class Solution {
  struct Node {
    using Value = pair<int, int>;
    using Ptr = std::unique_ptr<Node>;

    int priority;
    Value value;
    Ptr left;
    Ptr right;

    int size = 1;
    long long sum = 0;

    Node(int priority, const Value& value): priority(priority), value(value) {
    }

    void updateStat() {
      size = 1;
      sum = (long long)value.first * value.second;
      if (left) {
        size += left->size;
        sum += left->sum;
      }
      if (right) {
        size += right->size;
        sum += right->sum;
      }
    }

    static Ptr create(const Value& value) {
      auto leaf = std::make_unique<Node>(rand(), value);
      leaf->updateStat();
      return leaf;
    }

    Ptr detachLeft() {
      return std::move(left);
    }

    Ptr detachRight() {
      return std::move(right);
    }

    static Ptr rotateRight(Ptr root) {
      Ptr left = root->detachLeft();
      Ptr right = left->detachRight();
      root->left = std::move(right);
      root->updateStat();
      left->right = std::move(root);
      left->updateStat();
      return left;
    }

    static Ptr rotateLeft(Ptr root) {
      Ptr right = root->detachRight();
      Ptr left = right->detachLeft();
      root->right = std::move(left);
      root->updateStat();
      right->left = std::move(root);
      right->updateStat();
      return right;
    }

    static Ptr insert(Ptr root, const Value& value) {
      if (!root) {
        return create(value);
      }
      if (value < root->value) {
        root->left = insert(root->detachLeft(), value);
        if (root->left->priority > root->priority) {
          return rotateRight(std::move(root));
        }
      }
      else if (value > root->value) {
        root->right = insert(root->detachRight(), value);
        if (root->right->priority > root->priority) {
          return rotateLeft(std::move(root));
        }
      }
      root->updateStat();
      return root;
    }

    static Ptr erase(Ptr root, const Value& value) {
      if (!root) {
        return root;
      }
      if (value < root->value) {
        root->left = erase(root->detachLeft(), value);
        root->updateStat();
        return root;
      }
      else if (value > root->value) {
        root->right = erase(root->detachRight(), value);
        root->updateStat();
        return root;
      }
      else if (!root->left) {
        return root->detachRight();
      }
      else if (!root->right) {
        return root->detachLeft();
      }
      else if (root->left->priority >= root->right->priority) {
        return erase(rotateRight(std::move(root)), value);
      }
      else {
        return erase(rotateLeft(std::move(root)), value);
      }
    }
  };

  void dump(const Node::Ptr& root) {
    if (root) {
      dump(root->left);
      printf("(%d,%d) ", root->value.first, root->value.second);
      dump(root->right);
    }
  }

  static long long query(const Node::Ptr& root, int n) {
    if (!root) {
      return 0;
    }
    else if (root->size <= n) {
      return root->sum;
    }
    else {
      long long ret = 0;
      if (root->right) {
        ret += query(root->right, n);
        n -= root->right->size;
      }
      if (n > 0) {
        ret += (long long)root->value.first * root->value.second;
        n -= 1;
      }
      if (n > 0) {
        ret += query(root->left, n);
      }
      return ret;
    }
  }
  
public:
  vector<long long> findXSum(vector<int>& nums, int k, int x) {
    map<int, int> c;
    for (int i = 0; i < k; ++i) {
      ++c[nums[i]];
    }
    Node::Ptr treap;
    for (const auto& i : c) {
      treap = Node::insert(std::move(treap), make_pair(i.second, i.first));
    }

    vector<long long> ret;
    // dump(treap); puts("");
    ret.push_back(query(treap, x));
    for (int i = k; i < (int)nums.size(); ++i) {
      const int head = nums[i - k];
      const int tail = nums[i];
      if (head != tail) {
        const int chead = c[head]--;
        const int ctail = c[tail]++;
        treap = Node::erase(std::move(treap), make_pair(chead, head));
        if (chead > 1) {
          treap = Node::insert(std::move(treap), make_pair(chead - 1, head));
        }
        if (ctail > 0) {
          treap = Node::erase(std::move(treap), make_pair(ctail, tail));
        }
        treap = Node::insert(std::move(treap), make_pair(ctail + 1, tail));
      }
      // dump(treap); puts("");
      ret.push_back(query(treap, x));
    }
    return ret;
  }
};
