#include <set>
#include <map>
#include <cctype>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int SS = 1, MM = 60 * SS, HH = 60 * MM, DD = 24 * HH, TEN = 10; 
const int DIFF = 6 * HH;

inline int CharToInt(const char ch)
{
	return ch - '0';
}

inline int TimeToInt(const char* const Time)
{
	return  CharToInt(Time[0]) * TEN * DD + CharToInt(Time[1]) * DD +
		CharToInt(Time[3]) * TEN * HH + CharToInt(Time[4]) * HH +
		CharToInt(Time[6]) * TEN * MM + CharToInt(Time[7]) * MM +
		CharToInt(Time[9]) * TEN * SS + CharToInt(Time[10]) * SS;
}

inline void ToLower(string& str)
{
	for (size_t i = 0; i < str.length(); i++)
		if(isupper(str[i]))
			str[i] = tolower(str[i]);
}

struct Address
{
	const string topDomain;
	const string Domain;
	map<string, pair<int, pair<int, int> > >* const Records;
	Address(const string& atopDomain, const string& aDomain) : topDomain(atopDomain), Domain(aDomain),
		Records(new map<string, pair<int, pair<int ,int> > >)
	{
	}
	~Address()
	{
		delete Records;
	}
	bool operator<(const Address& rhs) const
	{
		if(topDomain == rhs.topDomain)
			return Domain < rhs.Domain;
		else
			return topDomain < rhs.topDomain;
	}
	void insert(const string& cur, const int atime) const
	{
		map<string, pair<int, pair<int, int> > >::iterator it = Records->find(cur);

		if(it == Records->end())
			(*Records)[cur] = make_pair(atime, make_pair(1, 0));
		else if(atime < it->second.first + DIFF)
			++it->second.second.second;
		else {
			++it->second.second.first;
			it->second.first = atime;
		}
	}
	void show() const
	{
		printf("Second level domain = %s\n", Domain.c_str());
		for (map<string, pair<int, pair<int, int> > >::const_iterator it = Records->begin(); it != Records->end(); ++it)
			printf("%-65s%4d%4d\n", it->first.c_str(), it->second.second.first, it->second.second.second);
	}
};

char buf[88];

int main(void)
{
	string::size_type pre, pos;
	int atime;
	string cur, topDomain, Domain;
	Address *add;
	set<Address> st;
	set<Address>::iterator it;

	while(gets(buf)) {
		if(buf[0] == '3' && buf[1] == '2')
			break;

		atime = TimeToInt(buf);
		cur = string(buf + 12);
		ToLower(cur);
		pre = cur.rfind('.');
		topDomain = cur.substr(pre + 1);
		pos = cur.rfind('.', pre - 1);
		if(pos == string::npos)
			pos = cur.rfind('@', pre - 1);
		else
			pos = max(pos, cur.rfind('@', pre - 1)); // WA // @@
		Domain = cur.substr(pos + 1, pre - pos - 1);
		add = new Address(topDomain, Domain);
		//printf("%s %s %s\n", topDomain.c_str(), Domain.c_str(), cur.c_str());
		it = st.find(*add);
		if(it == st.end()) {
			st.insert(*add);
			it = st.find(*add);
		}
		else {
			delete add;
			add = NULL;
		}
		it->insert(cur, atime);
	}

	//printf("why?");
	topDomain = "";
	for (it = st.begin(); it != st.end(); ++it) {
		if(it->topDomain != topDomain) {
			topDomain = it->topDomain;
			if(it != st.begin())
				puts("\n");
			printf("TOP-LEVEL DOMAIN = %s\n", topDomain.c_str());
		}
		else if(it != st.begin())
			puts("");
		it->show();
	}

	return 0;
}
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806258 	2016 	Charity Begins at Home-page 	Accepted 	C++ 	0.076 	2011-05-24 10:57:59
/*
id => 1174098
pid => 2016
pname => Charity Begins at Home-page
status => Accepted
lang => C++
time => 0.058
date => 2012-12-14 17:21:57
*/
