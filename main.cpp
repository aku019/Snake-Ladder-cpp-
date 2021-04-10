#include <bits/stdc++.h>
using namespace std;

#define maxsize 100

class Player{
	string name;
	int pos;
	public:
	// Player(string n)
	// {
	// 	name=n;
	// 	pos=0;
	// }
	
	int getpos()
	{
		return pos;
	}
	
	string getname()
	{
		return name;
	}
	void setname(string n)
	{
		name=n;
	}
	void setpos(int n)
	{
		pos=n;
	}
};

class Game{

	Player player[maxsize];
	unordered_map<int,int> snakes;

	unordered_map<int,int> laders;

 public:
	void setplayers(vector<string> v)
	{
		for(int i=0;i<v.size();i++)
 		{
 			player[i].setname(v[i]);
 		}
	}
	
		void setpositions(vector<string> v)
	{
		for(int i=0;i<v.size();i++)
 		{
 			player[i].setpos(0);
 		}
	}
	
	string getplayer(int i)
	{
		return player[i].getname();
	}
	
	int getposition(int i)
	{
		return player[i].getpos();
	}
	
	
	void setsnakeladers(int s,vector<vector<int>> vs,int l,vector<vector<int>> vl)
	{
		for(int i=0;i<vs.size();i++)
 		{
 			snakes[vs[i][0]]=vs[i][1];
 		}

 		for(int i=0;i<vl.size();i++)
 		{
 			 laders[vl[i][0]]=vl[i][1];
 		}

	}
	
	int turn(int i,int dice)
	{
	 		int newpos=player[i].getpos()+dice;
		//cout<<dice<<" "<<newpos<<endl;
		     if(newpos>100)
				 return 0;
// 		     if(newpos==100)
// 			 {
				
// 				 player[i].setpos(100);
// 			  return 1;
// 			 }
	        while(snakes[newpos]||laders[newpos])
			{
				if(snakes[newpos])
					newpos=snakes[newpos];
				if(laders[newpos])
					newpos=laders[newpos];
			}
		 if(newpos==100)
			 {
				
				 player[i].setpos(100);
			  return 1;
			 }
		player[i].setpos(newpos);
		
		return 0;
				
		
	}
};
int main() {
	Game game;
	int n,s,l;
	
	cin>>n;
	vector<string> s1;
	for(int i=0;i<n;i++)
	{
		string v;
		cin>>v;
		s1.push_back(v);
	}
	cin>>s;
	vector<vector<int>> vs,vl;
	for(int i=0;i<s;i++)
	{
		int a,b;
		cin>>a>>b;
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		vs.push_back(v);
	}
	cin>>l;
	for(int i=0;i<l;i++)
	{
		int a,b;
		cin>>a>>b;
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		vl.push_back(v);
	}
	game.setplayers(s1);
	game.setpositions(s1);
	game.setsnakeladers(s,vs,l,vl);
	
	int over=0;
	string winner;
	int i=0;
	while(over==0)
	{
		
		int dice=rand()%6+1;
		int previous=game.getposition(i);
		over=game.turn(i,dice);
		int current=game.getposition(i);
		cout<<game.getplayer(i)<<" rolled "<<dice<<" went from "<<previous<<" to "<<current<<endl;
		if(over==0)
		{
			i++;
		if(i>=n)
			i=0;
		}
	}
	
	cout<<game.getplayer(i)<<" is the winner.\n";
	
	
	return 0;
}