#include <stdio.h>
#include <string.h>
int main()
{
	const struct{
		char letter,morse[6];
		int len;
	}morse[30]={
		{'A',".-",2},{'B',"-...",4},{'C',"-.-.",4},{'D',"-..",3},{'E',".",1},
		{'F',"..-.",4},{'G',"--.",3},{'H',"....",4},{'I',"..",2},{'J',".---",4},
		{'K',"-.-",3},{'L',".-..",4},{'M',"--",2},{'N',"-.",2},{'O',"---",3},	
		{'P',".--.",4},{'Q',"--.-",4},{'R',".-.",3},{'S',"...",3},{'T',"-",1},	
		{'U',"..-",3},{'V',"...-",4},{'W',".--",3},{'X',"-..-",4},{'Y',"-.--",4},
		{'Z',"--..",4},{'_',"..--",4},{'.',"---.",4},{',',".-.-",4},{'?',"----",4}},
		*p=morse;
	int ri,repeat,i,j,k,n,sum,length[144];/*length[30] not enough*/
	char msg[144],code[400],*pc=code;/*the same are msg and code*/

	scanf("%d\n",&repeat);	
	for(ri=1;ri<=repeat;ri++){
		gets(msg);
		n=strlen(msg);
		strcpy(code,"");
		for(i=0;i<n;i++)
			for(j=0;j<30;j++)
				if(msg[i]==(p+j)->letter){
					strcat(code,(p+j)->morse);
					length[n-1-i]=(p+j)->len;
					break;
				}
		sum=0;
		printf("%d: ",ri);
		for(i=0;i<n;i++){			
			for(j=0;j<30;j++){
				if(length[i]==(p+j)->len){
					for(k=0;k<length[i];k++)
						if(*(pc+sum+k)!=(p+j)->morse[k]) break;
					if(k>=length[i]){
						printf("%c",(p+j)->letter);
						break;
					}
				}
			}
			sum+=length[i];
		}
		printf("\n");
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 805901 	2282 	P,MTHBGWB 	Accepted 	ANSI C 	0.008 	2011-05-23 14:48:32 */
/*
id => 1174326
pid => 2282
pname => P,MTHBGWB
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 17:57:03
*/
