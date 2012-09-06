/*
~~~~src~~~~
#define A else
#define B strlen(d)
#define C char
#define D d[I]
#define E break;
#define F(x) for(x)
#define G continue;
#define H H
#define I I
#define J J
#define K K
#define L L
#define M memset(r,'0',sizeof(r))
#define N N
#define O O
#define P printf
#define Q(x) return x
#define R r[I]
#define S(x) x<0?0:x
#define T int
#define U 1<<12
#define V T I,J,K
#define W(x) while(x)
#define X(x) if(x)
#define Y fgets(d,U,stdin)
#define Z void
C d[U], r[U]; T N; T L(){ V; F( I=N-1; I>=N/2; I--) X(!(D-48)) D=57; A{ D--; E;}
X((I<<1)<N) Q(0); F( I=J=0; (I<<1)<N; I++){ K=R+D+J-96; J=K/10; R=K%10+48;}W(J){
K=R+J-48; J=K/10;R=K%10+48; I++;} Q(1);} Z O(){V;F(I=U-1;I;I--) X(R-48)E;I=S(I);
W(I >= 0){P("%c",R); I--;}P("%c",10);}int main(){V;W(Y){N=B;d[--N]=0;X(N > U-2){
P("0\n");G;}X(N-(N>>1)-(N>>1)){d[N++]='0';d[N]=0;}M;W(L());O();}}
*/

/*
~~~~g++ -E 1584.cpp~~~~
# 1 "1584.cpp"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "1584.cpp"
# 98 "1584.cpp"
char d[1<<12], r[1<<12]; int N; int L(){ int I,J,K; for(I=N-1; I>=N/2; I--) if(!(d[I]-48)) d[I]=57; else{ d[I]--; break;;}
if((I<<1)<N) return 0; for(I=J=0; (I<<1)<N; I++){ K=r[I]+d[I]+J-96; J=K/10; r[I]=K%10+48;}while(J){
K=r[I]+J-48; J=K/10;r[I]=K%10+48; I++;} return 1;} void O(){int I,J,K;for(I=1<<12 -1;I;I--) if(r[I]-48)break;;I=I<0?0:I;
while(I >= 0){printf("%c",r[I]); I--;}printf("%c",10);}int main(){int I,J,K;while(fgets(d,1<<12,stdin)){N=strlen(d);d[--N]=0;if(N > 1<<12 -2){
printf("0\n");continue;;}if(N-(N>>1)-(N>>1)){d[N++]='0';d[N]=0;}memset(r,'0',sizeof(r));while(L());O();}}
*/

/*
~~~~[vim]~~~~
:'<,'>s/;/;\r/gc
gg=G
# 1 "1584.cpp"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "1584.cpp"
# 98 "1584.cpp"
char d[1<<12], r[1<<12];
int N;
int L(){ int I,J,K;
    for(I=N-1;
            I>=N/2;
            I--) if(!(d[I]-48)) d[I]=57;
    else{ d[I]--;
        break;
        ;
    }
    if((I<<1)<N) return 0;
    for(I=J=0;
            (I<<1)<N;
            I++){ K=r[I]+d[I]+J-96;
        J=K/10;
        r[I]=K%10+48;
    }while(J){
        K=r[I]+J-48;
        J=K/10;
        r[I]=K%10+48;
        I++;
    } return 1;
} void O(){int I,J,K;
    for(I=1<<12 -1;
            I;
            I--) if(r[I]-48)break;
    ;
    I=I<0?0:I;

    while(I >= 0){printf("%c",r[I]);
        I--;
    }printf("%c",10);
}int main(){int I,J,K;
    while(fgets(d,1<<12,stdin)){N=strlen(d);
        d[--N]=0;
        if(N > 1<<12 -2){
            printf("0\n");
            continue;
            ;
        }if(N-(N>>1)-(N>>1)){d[N++]='0';
            d[N]=0;
        }memset(r,'0',sizeof(r));
        while(L());
        O();
    }}
*/

/*
char d[1<<12], r[1<<12];
int N;
int L(){
    int I,J,K;
                                    // [--]
    for(I=N-1; I>=N/2; I--)         // foreach char in d[length/2:end)
        if(!(d[I]-48))              //   if '0'->'9'
            d[I]=57;                //   else 'a'->'a-1' break
        else{
            d[I]--;
            break;
            ;
        }

    if((I<<1)<N)                    // last half all '0'
        return 0;




                                    // d[0:length/2) [addition] r
    for(I=J=0; (I<<1)<N; I++){      // foreach char in d[0:length/2)
        K=r[I]+d[I]+J-96;           // k = tod(r) + tod(d) + j
        J=K/10;                     // j = k / 10
        r[I]=K%10+48;               // r = toc(k / 10)
    }
    while(J){
        K=r[I]+J-48;                // ...
        J=K/10;
        r[I]=K%10+48;
        I++;
    }
    return 1;                       // return 1
}

void O(){
    int I,J,K;

    for(I=1<<12 -1; I; I--)         // r.trimright('0')
        if(r[I]-48)
            break;
    ;
    I=I<0?0:I;                      // noop;

    while(I >= 0){                  // r = r.reverse()
        printf("%c",r[I]);          // cout << r
        I--;
    }
    printf("%c",10);                // cout << '\n'
}

int main(){
    int I,J,K;

    while(fgets(d,1<<12,stdin)){    // getline(cin, str)
        N=strlen(d);
        d[--N]=0;                   // str = str.substr(0, str.length() - 1)
        if(N > 1<<12 -2){           // if str.length() > (1 << 12 - 2)
            printf("0\n");          //   then puts("0")
            continue;               //   endif
            ;
        }
        if(N-(N>>1)-(N>>1)){d[N++]='0';
            d[N]=0;                 // if str.length() % 2 == 1
        }                           //   then str = str + "0"
                                    // endif
        memset(r,'0',sizeof(r));    // r = "0000000 ... 00000"
        while(L())                  // while L()
            ;
        O();                        // O()
    }
}
*/

import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    private static final int MAX_LEN = 1 << 12;

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s;
        while ((s = in.readLine()) != null) {
            if (s.length() > 1024) {    // 1 << 12 - 2 -> 1 << (12 - 2)
                System.out.println(0);
                continue;
            }
            StringBuffer str = new StringBuffer(s);
            if (str.length() % 2 == 1) {
                str.append('0');
            }
            BigInteger a = new BigInteger(str.substring(str.length() / 2));
            str = str.reverse();
            BigInteger b = new BigInteger(str.substring(str.length() / 2));
            System.out.println(a.multiply(b));
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1833089   2009-04-14 09:37:52     Accepted    1584    Java    0   439     watashi@Zodiac

// 2012-09-07 00:54:57 | Accepted | 1584 | Java | 70 | 633 | watashi | Source
