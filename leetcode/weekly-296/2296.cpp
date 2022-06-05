class TextEditor {
public:
  TextEditor() {
    cur = s.begin();
  }

  void addText(string text) {
    cur = s.insert(cur, text.begin(), text.end());
    advance(cur, text.size());
  }

  int deleteText(int k) {
    auto tmp = left(k);
    int ret = distance(tmp, cur);
    cur = s.erase(tmp, cur);
    return ret;
  }

  string cursorLeft(int k) {
    cur = left(k);
    auto tmp = left(10);
    return string(tmp, cur);
  }

  string cursorRight(int k) {
    for (int i = 0; i < k && cur != s.end(); ++i, ++cur) {
    }
    auto tmp = left(10);
    return string(tmp, cur);
  }

private:
  list<char>::iterator left(int k) {
    auto ret = cur;
    for (int i = 0; i < k && ret != s.begin(); ++i, --ret) {
    }
    return ret;
  }

  list<char> s;
  list<char>::iterator cur;
};
