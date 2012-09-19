#include <set>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    int n;
    bool flag = false;
    char buf[80];
    set<string> st;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        st.insert(buf);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        flag ^= st.count(buf) > 0;
        printf("%s %s\n", st.count(buf) == 0 ?
            "Unknown" : flag ? "Opened by" : "Closed by", buf);
    }

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Submission Date
//#486516 	watashi 	A 	: Accepted 	C++ 	00:00 sec 	1096 KB 	Sun Sep 16 14:11:50

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#489320 	watashi 	2440 	: Accepted 	C++ 	00:00 sec 	1096 KB 	672 Bytes 	Wed Sep 19 15:18:15

