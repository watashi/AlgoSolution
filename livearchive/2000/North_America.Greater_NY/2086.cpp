#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int doit(char str[],int &flag){
	char tmp[20];
	int cur;

	cur=atoi(str);
	sprintf(tmp,"%d",cur);
	flag=strcmp(str,tmp);
	return cur;
}
bool pr(string a,string b)
{
	for(int i=0;i<a.length();i++)
		a[i]=tolower(a[i]);
	for(int i=0;i<b.length();i++)
		b[i]=tolower(b[i]);
	return a<b;
}
int main()
{
	char ch,str[20];
	int len,tmp,flag;
	vector<string> vstr;
	vector<string>::iterator stritr;
	vector<int> vint;
	vector<int>::iterator intitr;
	vector<bool> strint;
	vector<bool>::iterator boolitr;

	while(scanf("%s",str)!=EOF){
		if(!strcmp(str,".")) break;
		vstr.clear();
		vint.clear();
		strint.clear();
		while(1){
			len=strlen(str);
			ch=str[len-1];
			str[len-1]='\0';
			tmp=doit(str,flag);
			if(flag==0){strint.push_back(true);vint.push_back(tmp);}
			else{strint.push_back(false);vstr.push_back((string)str);}
			if(ch=='.') break;
			scanf("%s",str);
		}
		sort(vstr.begin(),vstr.end(),pr);
		sort(vint.begin(),vint.end());
		stritr=vstr.begin();
		intitr=vint.begin();
		for(boolitr=strint.begin();boolitr!=strint.end();++boolitr){
			if(boolitr!=strint.begin()) cout<<", ";
			if(*boolitr){
				cout<<*intitr;
				intitr++;
			}
			else{
				cout<<*stritr;
				stritr++;
			}
		}
		cout<<"."<<endl;
	}
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805940 	2086 	Scramble Sort 	Accepted 	C++ 	0.096 	2011-05-23 15:37:44
/*
id => 1174124
pid => 2086
pname => Scramble Sort
status => Accepted
lang => C++
time => 0.079
date => 2012-12-14 17:26:53
*/
