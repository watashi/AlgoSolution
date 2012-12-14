#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
using namespace std;
char tmp,cmd[30],text[22][30][80];
int len[30];
int scanfit(int &m)
{
	int i,j,k;
	
	gets(&cmd[1]);
	for(j=0;cmd[j];j++)
		len[j]=0;
	m=j;
	for(i=0;;i++){
		switch(text[i][0][0]=getchar()){
		case '*':case '<':case '=':case '>':tmp=text[i][0][0];return i;
		}
		k=1;
		while((text[i][0][k]=getchar())!='&'&&text[i][0][k]!='\n') k++;
		text[i][0][k]='\0';
		if(k>len[0]) len[0]=k;
		for(j=1;j<m;j++){
			k=0;
			while((text[i][j][k]=getchar())!='&'&&text[i][j][k]!='\n') k++;
			text[i][j][k]='\0';
			if(k>len[j]) len[j]=k;
		}				
	}
}
void output(int i,int j,char s)
{
	int t;
	
	putchar(' ');
	if(s=='<'){
		cout<<text[i][j];
		t=len[j]-strlen(text[i][j]);
		cout<<setw(t+2)<<"|";
	}
	else if(s=='>'){
		cout<<setw(len[j])<<text[i][j];
		cout<<" |";
	}
	else if(s=='='){

		t=len[j]-strlen(text[i][j]);
		t=(t+1)/2;
		cout<<setw(len[j]-t)<<text[i][j]<<setw(t+2)<<"|";
	}
}
void outtable(int m,char a,char b)
{
	int i,j;
	
	putchar(b);
	for(i=0;i<m;i++){
		for(j=-1;j<=len[i];j++)
			putchar('-');
		if(i==m-1) putchar(b);
		else putchar(a);
	}
	putchar('\n');
}
void printfit(int n,int m)
{
	int i,j;

	outtable(m,'-','@');
	putchar('|');
	for(j=0;j<m;j++)
		output(0,j,cmd[j]);
	putchar('\n');
	outtable(m,'+','|');
	for(i=1;i<n;i++){
		putchar('|');
		for(j=0;j<m;j++)
			output(i,j,cmd[j]);
		putchar('\n');
	}
	outtable(m,'-','@');
}
int main()
{
	int n,m;

	cmd[0]=getchar();
	while(cmd[0]!='*'){
		n=scanfit(m);
		printfit(n,m);
		cmd[0]=tmp;
	}
	return 0;
}
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806255 	2066 	Instruens Fabulam 	Accepted 	C++ 	0.008 	2011-05-24 10:50:23
/*
id => 1174121
pid => 2066
pname => Instruens Fabulam
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:26:07
*/
