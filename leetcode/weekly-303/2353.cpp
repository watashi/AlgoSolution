class FoodRatings {
public:
  FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    int n = (int)foods.size();
    for (int i = 0; i < n; ++i) {
      f2c.emplace(foods[i], make_pair(-ratings[i], cuisines[i]));
      c2f[cuisines[i]].insert(make_pair(-ratings[i], foods[i]));
    }
  }

  void changeRating(string food, int newRating) {
    newRating = -newRating;
    auto& p = f2c[food];
    auto c = p.second;
    c2f[c].erase(make_pair(p.first, food));
    p.first = newRating;
    c2f[c].insert(make_pair(p.first, food));
  }

  string highestRated(string cuisine) {
    return c2f[cuisine].begin()->second;
  }

  unordered_map<string, pair<int, string>> f2c;
  unordered_map<string, set<pair<int, string>>> c2f;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
