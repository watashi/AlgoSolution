//模拟
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
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2686628 2007-11-27 11:17:36 Accepted 1699 C++ 00:00.00 868K 再做几题改成Fire

// 2012-09-07 00:57:59 | Accepted | 1699 | C++ | 0 | 188 | watashi | Source
