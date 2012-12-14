#include <vector>
#include <string>
#include <utility>
#include <iostream>
using namespace std;
class card{
private:
	char _color;
	bool _isTwo;
public:
	card(string &that)
	{
		_color=that[0];
		_isTwo=(that.length()>1);
	}
	char color()
	{
		return _color;
	}
	bool isTwo()
	{
		return _isTwo;
	}
};
class Colorville{
private:
	int p[4];
	int nPlayer;
	string board;
	vector<card> deck;
public:
	friend istream& operator>>(istream& is,Colorville& that)
	{
		is>>that.nPlayer;
		int n,m;
		is>>n>>m;
		is>>that.board;
		that.deck.clear();
		while(m--){
			string cur;
			is>>cur;
			that.deck.push_back(card(cur));
		}
		for(int i=0;i<that.nPlayer;i++)
			that.p[i]=-1;
		return is;
	}
	friend ostream& operator<<(ostream& os,const Colorville& that)
	{
		Colorville it=that;
		try{
			int iCard=0;
			while(1){
				for(int i=0;i<it.nPlayer;i++){
					if(iCard>=it.deck.size()) throw iCard;
					char color=it.deck[iCard].color();
					while(++it.p[i]<it.board.length()&&it.board[it.p[i]]!=color);
					if(it.deck[iCard].isTwo())
						while(++it.p[i]<it.board.length()&&it.board[it.p[i]]!=color);
					if(it.p[i]>=it.board.length()-1) throw make_pair(i+1,iCard+1);
					iCard++;
				}
			}
		}
		catch(int e)
		{
			os<<"No player won after "<<e<<" cards.";
		}
		catch(pair<int,int> e)
		{
			os<<"Player "<<e.first<<" won after "<<e.second<<" cards.";
		}
		return os;
	}
};
int main()
{
	Colorville colorville;

	while(cin>>colorville) cout<<colorville<<endl;

	return 0;
}
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806253 	2063 	Colorville 	Accepted 	C++ 	0.008 	2011-05-24 10:48:34
/*
id => 1174120
pid => 2063
pname => Colorville
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:25:45
*/
