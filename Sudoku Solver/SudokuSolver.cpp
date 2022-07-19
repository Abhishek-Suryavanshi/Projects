#include <iostream>
#include<cmath>
using namespace std;
bool issafetoput(int board[][9],int i,int j,int n,int no)
{
	//check for the rows and columns
	for(int k=0;k<n;k++)
	{
		if(board[i][k]==no)   //for row
		{
			return false;
		}
		if(board[k][j]==no)   //for columns
		{
			return false;
		}
	}

	//check for box
	int N=sqrt(n);
	int si=(i/N)*N;
	int sj=(j/N)*N;
	for(int k=si;k<si+N;k++)
	{
		for(int l=sj;l<sj+N;l++)
		{
			if(board[k][l]==no)
			{
				return false;
			}
		}
	}
	return true;
}
bool SudokuSolver(int board[][9],int i,int j,int n)
{
	//base case
	if(i==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}
	//recursive case
	if(j==n)
	{
		return SudokuSolver(board,i+1,0,n);
	}
	if(board[i][j]!=0)
	{
		return SudokuSolver(board,i,j+1,n);
	}
	for(int number=1;number<=n;number++)
	{

	 if(issafetoput(board,i,j,n,number)==true)
	 {
		board[i][j]=number;
	    bool kyabaatbani=SudokuSolver(board,i,j+1,n);
	    if(kyabaatbani==true)
	    {
	 	return true;
	    }
	    board[i][j]=0;
      }
    }
   return false;
}

int main() 
{
	int board[][9]={
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};
	SudokuSolver(board,0,0,9);
	return 0;
}