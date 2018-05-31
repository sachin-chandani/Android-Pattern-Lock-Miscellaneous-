/* Sachin Chandani 
   IIIT Hyderabad  */

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define INF INT_MAX
#define pr_nl cout<<'\n' 
#define nl '\n' 
#define pb push_back
#define SET(a,b) memset(a,b,sizeof(a))
#define fast_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007

/*************************************************************************************************************************************************
  n = number for n x n pattern board
  board[][] = security board array with each cell having a number code
  list[] vector = adj. list of the graph

 
*************************************************************************************************************************************************/

int n;
typedef struct data{
	int val,mark;
}data;
data board[1001][1001];
vector<int> List[1001];
int mark[1000005]={0};




int main()
{
	cout<<"Enter n = number of row(s)/column(s) in the security lock : "<<nl;
	cout<<"Constraint n <=  "<<nl;
	cin>>n;
	cout<<"Your pattern lock looks like this :"<<nl;
	pr_nl;
	int cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			board[i][j].val=cnt++;
			cout<<"|"<<board[i][j].val<<"|"<<"	";
		}
		pr_nl;
		pr_nl;	
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x=i,y=j;
			for(int k=0;k<=n;k++)
				for(int m=0;m<=n;m++)
					board[k][m].mark=0;
			cout<<"for-->"<<i<<" "<<j<<nl;
			for(int k=1;k<=n;k++)
			{
				for(int m=1;m<=n;m++){
					cout<<board[i][j].mark<<" ";
				}
				pr_nl;
				pr_nl;

			}

			x=i,y=j;
			while(x<=n && y<=n){
				board[x][y].mark=1;
				x++;
				y++;

			}	
			x=i,y=j;
			while(x>=1 && y>=1){
				board[x][y].mark=1;
				x--,y--;
			}
			x=i,y=j;
			while(x>=1 && y<=n){
				board[x][y].mark=1;
				x--,y++;
			}
			x=i,y=j;
			while(x<=n && y>=1){
				board[x][y].mark=1;
				x++,y--;
			}
			x=i,y=j;
			for(int k=1;k<=n;k++)
				board[x][k].mark=1;
			for(int k=1;k<=n;k++)
				board[k][y].mark=1;


			board[i][j].mark=1;
			if(i-1>=1) board[i-1][j].mark=0;
			if(i+1<=n) board[i+1][j].mark=0;
			if(j-1>=1) board[i][j-1].mark=0;
			if(j+1<=n) board[i][j+1].mark=0;
			if(i+1<=n && j+1<=n) board[i+1][j+1].mark=0;
			if(i-1>=1 && j-1>=1) board[i-1][j-1].mark=0;
			if(i-1>=1 && j+1<=n) board[i-1][j+1].mark=0;
			if(i+1<=n && j-1>=1) board[i+1][j-1].mark=0;

			for(int k=1;k<=n;k++)
			{
				for(int m=1;m<=n;m++)
					if(board[k][m].mark==0)
					List[board[i][j].val].pb(board[k][m].val);
			}


			for(int k=1;k<=n;k++)
			{
				for(int m=1;m<=n;m++){
					cout<<board[k][m].mark<<" ";
				}
				pr_nl;
				pr_nl;

			}






		}
	}


	for(int i=1;i<=n*n;i++){
		cout<<i<<"---> ";
		for(int j=0;j<List[i].size();j++){
			cout<<List[i][j]<<",";
		}
		pr_nl;
	}


	return 0;
}
