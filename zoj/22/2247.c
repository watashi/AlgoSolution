#include <stdio.h>
int info(int z[3])
{
    if(z[0]<z[1]&&z[1]<z[2]) return 1;
    if(z[0]<z[2]&&z[2]<z[1]) return 2;
    if(z[1]<z[0]&&z[0]<z[2]) return 3;
    if(z[2]<z[0]&&z[0]<z[1]) return 4;
    if(z[1]<z[2]&&z[2]<z[0]) return 5;
    if(z[2]<z[1]&&z[1]<z[0]) return 6;
}
void trans(char card[4],int *face,int *suit)
{
    switch(card[0]){
    case 'T':*face=10;break;
    case 'J':*face=11;break;
    case 'Q':*face=12;break;
    case 'K':*face=13;break;
    default:*face=card[0]-'0';break;
    }
    switch(card[1]){
    case 'H':*suit=0;break;
    case 'C':*suit=1;break;
    case 'D':*suit=2;break;
    case 'S':*suit=3;break;
    }
}
int main()
{
    char card[4],tmp;
    int re,i,face,suit,f,s,z[3];

    scanf("%d",&re);
    while(re--){
        scanf("%s",card);
        trans(card,&face,&suit);
        tmp=card[1];
        for(i=0;i<3;i++){
            scanf("%s",card);
            trans(card,&f,&s);
            z[i]=f+13*s;
        }
        face+=info(z);
        if(face>13) face-=13;
        switch(face){
        case 10:card[0]='T';break;
        case 11:card[0]='J';break;
        case 12:card[0]='Q';break;
        case 13:card[0]='K';break;
        default:card[0]='0'+face;break;
        }
        card[1]=tmp;
        card[2]='\0';
        printf("%s\n",card);
    }
}
/* //Really ture??It's really magical. */

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2601017 2007-09-08 14:57:02 Accepted 2247 C 00:00.01 388K ¤ï¤¿¤· */

// 2012-09-07 01:17:02 | Accepted | 2247 | C | 0 | 160 | watashi | Source
