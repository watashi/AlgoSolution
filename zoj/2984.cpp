// solution by whatashya @ zju

#include <cstdio>
#include <cstring>

const char* Roshambo[11][4] = {
    {"cs", "Kamen", "Nuzky", "Papir"},
    {"en", "Rock", "Scissors", "Paper"},
    {"fr", "Pierre", "Ciseaux", "Feuille"},
    {"de", "Stein", "Schere", "Papier"},
    {"hu", "Ko", "Ollo", "Papir"},
    {"hu", "Koe", "Olloo", "Papir"},
    {"it", "Sasso", "Forbice", "Carta"},
    {"it", "Roccia", "Forbice", "Rete"},
    {"jp", "Guu", "Choki", "Paa"},
    {"pl", "Kamien", "Nozyce", "Papier"},
    {"es", "Piedra", "Tijera", "Papel"}
};

const int roshambo[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 1, -1},
    {0, -1, 0, 1},
    {0, 1, -1, 0}
};

int trans (char const* const type, char const* const str)
{
    for (int i = 0; i < 11; i++)
        if(strcmp(Roshambo[i][0], type) == 0)
            for (int j = 1; j <= 3; j++)
                if(strcmp(Roshambo[i][j], str) == 0)
                    return j;
    return 0;
}

class Player
{
public:
    char name[22], type[4];
    int pts;
    inline void cget()
    {
        scanf("%s%s", type, name);
        pts = 0;
    }
    inline void cput()
    {
        printf("%s: %d point%s\n", name, pts, (pts == 1) ? "" : "s");
    }
}a, b;

char buf[22];

int main(void)
{
    int ri = 0;
    int aa, bb;

    do {
        a.cget();
        b.cget();
        while(true) {
            scanf("%s", buf);
            if(buf[0] == '-' || buf[0] == '.')
                break;
            aa = trans(a.type, buf);
            scanf("%s", buf);
            bb = trans(b.type, buf);
            if(roshambo[aa][bb] == 1)
                ++a.pts;
            else if(roshambo[aa][bb] == -1)
                ++b.pts;
        }
        printf("Game #%d:\n", ++ri);
        a.cput();
        b.cput();
        if(a.pts > b.pts) printf("WINNER: %s\n", a.name);
        else if(a.pts < b.pts) printf("WINNER: %s\n", b.name);
        else printf("TIED GAME\n");
        printf("\n");
    }while(buf[0] != '.');

    return 0;
}

/*
real    0m0.078s
user    0m0.077s
sys     0m0.015s
*/

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2948290   2008-06-12 15:48:54     Accepted    2984    C++     00:00.08    392K    Re:ReJudge

// 2012-09-07 01:52:21 | Accepted | 2984 | C++ | 30 | 180 | watashi | Source
