#include <stdio.h>
#include <string.h>
int isvalid(const char const str[])
{
	int i;

	for(i = 0; i < 5; i++)
		if(!(str[i] >= 'A' && str[i] <= 'Z')) return 0;
	return str[5] == '\0';
}
int main()
{
	char *p, word[16], pre[16], tmp[16], str[256];
	int i, guess;
	gets(str);
	while(gets(word) && strcmp(word, "LINGO")){
		pre[0] = word[0];
		for(i = 1; i < 5; i++)
			pre[i] = '.';
		pre[5] = '\0';
		printf("\n%s\n", pre);
		for(guess = 1; guess <= 6; guess++){
			gets(str);
			if(!strcmp(str, "")){
				for(i = 0; i < 5; i++)
					pre[i] = word[i] - 'A' + 'a';
				printf("%s\n", pre);
				break;
			}
			if(!isvalid(str)) printf("%s\n", pre);
			else{
				for(i = 0; i < 5; i++){
					if(str[i] == word[i]) {tmp[i] = '.'; pre[i] = word[i];}
					else {tmp[i] = word[i]; pre[i] = '.';}
				}
				tmp[5] = '\0';
				pre[5] = '\0';
				for(i = 0; i < 5; i++){
					if(pre[i] == '.' && (p = strchr(tmp, str[i])) != NULL){
						*p = '.';
						pre[i] = str[i] - 'A' + 'a';
					}
				}
				if(!strcmp(pre, word)){
					printf("%s\n", pre);
					break;
				}
				else if(guess == 6){
					for(i = 0; i < 5; i++)
						pre[i] = word[i] - 'A' + 'a';
					printf("%s\n", pre);
					break;
				}
				else
					printf("%s\n", pre);
			}
		}
		while(strcmp(str, ""))
			gets(str);
	}

	return 0;
}
/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 805967 	2558 	Lingo 	Accepted 	ANSI C 	0.008 	2011-05-23 16:12:12 */
/*
id => 1174335
pid => 2558
pname => Lingo
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 17:58:53
*/
