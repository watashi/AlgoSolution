#include <set>
#include <map>
#include <list>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

const int INF = 1000000007;
const string GIVE_UP = "GIVE UP";

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

inline int A(int d) { return d << 1; }
inline int B(int d) { return A(d) ^ 1; }
inline int R(int i) { return i ^ 5; }
inline int RA(int d) { return R(A(d)); }
inline int RB(int d) { return R(B(d)); }

inline bool test(int i, int j) {
    return ((i >> j) & 1) != 0;
}

struct Tile {
    bool chain[8];
    int contact[8];
    int x, y, rot;

    Tile() {
    }

    Tile(const vector<int>& tile): rot(0) {
        fill(chain, chain + 8, false);
        for (int i = 0; i < 8; i += 2) {
            contact[tile[i]] = tile[i + 1];
            contact[tile[i + 1]] = tile[i];
        }
    }

    int operator[](int i) const {
        return contact[i];
    }

    bool hasChain() const {
        return find(chain, chain + 8, true) < chain + 8;
    }

    void clearChain() {
        fill(chain, chain + 8, false);
    }

    void input(int i) {
        if (chain[i]) {
            chain[i] = false;
        } else {
            chain[contact[i]] ^= true;
        }
    }

    void rotate() {
        static int pair[8];
        copy(contact, contact + 8, pair);
        // std::rotate(contact, contact + 2, contact + 8);
        rot = (rot + 1) % 4;
        for (int i = 0; i < 8; ++i) {
            contact[(i + 2) & 7] = (pair[i] + 2) & 7;
        }
    }

    string toString() const {
        static char buf[80];
        sprintf(buf, "%d %d %d", x, y, rot);
        return buf;
    }
};

struct TwistedGame {
    int N, M, score;
    map<pair<int, int>, Tile> done;
    list<pair<int, int> > chain;

    int flag;

    template<bool Update>
    int gao(int& x, int& y, int& z) {
        int ret = 0;
        while (true) {
            int d = z >> 1;
            x += dx[d];
            y += dy[d];
            z = R(z);
            if (done.count(make_pair(x, y)) == 0) {
                break;
            }
            Tile& tile = done[make_pair(x, y)];
            if (tile.chain[z]) {
                flag |= 1;
                if (Update) {
                    tile.chain[z] = false;
                }
                return ret;
            } else if (tile.chain[tile[z]]) {
                ++ret;
                flag |= 1;
                if (Update) {
                    tile.chain[tile[z]] = false;
                }
                return ret;
            } else {
                ++ret;
                z = tile[z];
            }
        }
        return ret;
    }

    template<bool Update>
    int place(Tile& tile) {
        int add = 0, sub = 0;

        for (int d = 0; d < 4; ++d) {
            if (done.count(make_pair(tile.x + dx[d], tile.y + dy[d])) == 0) {
                continue;
            }
            Tile& base = done[make_pair(tile.x + dx[d], tile.y + dy[d])];
            for (int i = 0; i < 2; ++i) {
                int j = i == 0 ? RA(d) : RB(d);
                int k = i == 0 ? A(d) : B(d);
                if (base.chain[j]) {
                    if (Update) {
                        base.chain[j] = false;
                    }
                    if (tile.chain[k]) {
                        ++sub;
                    } else {
                        ++add;
                    }
                    tile.input(k);
                }
            }
        }

        vector<int> v;
        while (true) {
            int k = find(tile.chain, tile.chain + 8, true) - tile.chain;
            if (k == 8) {
                break;
            } else {
                tile.chain[k] = false;
            }
            int x = tile.x, y = tile.y, z = k;
            if (Update) {
                // fprintf(stderr, "+++ %d %d %d\n", x, y, z);
            }
            flag = 0;
            int tmp = gao<Update>(x, y, z);
            add += tmp;
            if (tmp == 0) {
                v.push_back(R(z));
            } else if (test(flag, 0)) {
                --sub;
            } else if (x == tile.x && y == tile.y) {
                if (tile.chain[z]) {
                    ++sub;
                } else if (tile.chain[tile[z]]) {
                    ++sub;
                    ++add;
                } else {
                    ++add;
                }
                tile.input(z);
            } else if (Update) {
                int d = z >> 1;
                // fprintf(stderr, "--- %d %d %d\n", x, y, z);
                x += dx[d];
                y += dy[d];
                z = R(z);
                // fprintf(stderr, "=== %d %d %d\n", x, y, z);
                done[make_pair(x, y)].chain[z] = true;
                if (find(chain.begin(), chain.end(), make_pair(x, y)) == chain.end()) {
                    chain.push_back(make_pair(x, y));
                }
            }
        }
        if (Update) {
            for (int i = 0; i < (int)v.size(); ++i) {
                tile.chain[v[i]] = true;
            }
        }

        return add == 0 ? -INF : add - (N - M) / 2 * sub;
    }

    string add(const Tile& tile) {
        done[make_pair(tile.x, tile.y)] = tile;
        return tile.toString();
    }

    int init(int N, vector<int> firstTile) {
        Tile tile(firstTile);
        tile.x = tile.y = N;
        add(tile);
        this->N = N;
        this->M = 1;
        this->score = 0;
        return 0;
    }

    string placeSecondTile(Tile tile2) {
        Tile tile1 = done[make_pair(N, N)];
        int bestScore = -1, bestD = -1;
        Tile bestTile;
        for (int r = 0; r < 4; ++r) {
            for (int d = 0; d < 4; ++d) {
                int score = 0;
                if (tile1[A(d)] != B(d)) {
                    score += 10;
                    if ((tile1[A(d)] ^ tile1[B(d)]) == 1) {
                        score += 1;
                    }
                }
                if (tile2[RA(d)] != RB(d)) {
                    score += 10;
                    if ((tile2[RA(d)] ^ tile2[RB(d)]) == 1) {
                        score += 1;
                    }
                }
                if (bestScore < score) {
                    bestScore = score;
                    bestD = d;
                    bestTile = tile2;
                    bestTile.x = tile1.x + dx[d];
                    bestTile.y = tile1.y + dy[d];
                }
            }
            tile2.rotate();
        }
        tile1.input(A(bestD));
        tile1.input(B(bestD));
        chain.push_back(make_pair(tile1.x, tile1.y));
        done[make_pair(tile1.x, tile1.y)] = tile1;
        bestTile.input(RA(bestD));
        bestTile.input(RB(bestD));
        chain.push_back(make_pair(bestTile.x, bestTile.y));
        return add(bestTile);
    }

    string placeGeneralTile(Tile tile) {
        int bestScore = -INF;
        Tile bestTile;
        for (list<pair<int, int> >::iterator it = chain.begin(); it != chain.end(); ) {
            Tile base = done[*it];
            if (base.hasChain()) {
                // fprintf(stderr, "(%d, %d) = (%d, %d)\n", it->first, it->second, base.x, base.y);
                for (int d = 0; d < 4; ++d) {
                    tile.x = base.x + dx[d];
                    tile.y = base.y + dy[d];
                    if (done.count(make_pair(tile.x, tile.y)) > 0) {
                        continue;
                    }
                    for (int r = 0; r < 4; ++r) {
                        tile.clearChain();
                        int score = place<false>(tile);
                        // fprintf(stderr, "%d %d %d: %d\n", tile.x, tile.y, r, score);
                        if (bestScore < score) {
                            bestScore = score;
                            bestTile = tile;
                        }
                        tile.rotate();
                    }
                }
                ++it;
            } else {
                it = chain.erase(it);
            }
        }
        bestTile.clearChain();
        place<true>(bestTile);
        chain.push_back(make_pair(bestTile.x, bestTile.y));
        return add(bestTile);
    }

    string placeTile(vector<int> tile) {
        string ret = GIVE_UP;

        ++M;
        if (M == 2) {
            /*
            string ret = placeSecondTile(tile);
            for (auto p: done) {
                fprintf(stderr, "(%d,%d)", p.first.first, p.first.second);
                for (int i = 0; i < 8; ++i) {
                    fprintf(stderr, " %d", (int)p.second.chain[i]);
                }
                fprintf(stderr, "\n");
            }
            return ret;
            */
            ret = placeSecondTile(tile);
        } else {
            ret = placeGeneralTile(tile);
        }

        /*
        for (auto p: chain) {
            Tile t = done[p];
            if (false && t.hasChain()) {
                fprintf(stderr, "[%d, %d]", t.x, t.y);
                for (int i = 0; i < 8; ++i) {
                    if (t.chain[i]) {
                        fprintf(stderr, " %d", i);
                    }
                }
                fprintf(stderr, "\n");
            }
        }
        */

        return ret;
    }
};

#ifdef __WATASHI__
int main() {
    int n;
    string ret;
    TwistedGame tg;
    vector<int> p(8);

    FILE* tee = fopen("data/input", "w");
    FILE* log = fopen("log.log", "w");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (scanf("%d", &p[j]) == EOF) {
                goto LAST;
            } else {
                fprintf(tee, "%d%c", p[j], j == 7 ? '\n' : ' ');
            }
        }
        if (i == 0) {
            tg.init(n, p);
        } else {
            ret = tg.placeTile(p);
            fprintf(log, ">> %s\n", ret.c_str());
            fflush(log);
            // fprintf(stderr, ">> %s\n\n", ret.c_str());
            puts(ret.c_str());
            fflush(stdout);
        }
    }
LAST:
    fprintf(stderr, "score = %d\n", tg.score);
    fclose(tee);
    fclose(log);

    return 0;
}
#endif
