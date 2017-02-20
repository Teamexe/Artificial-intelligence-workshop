#include <iostream>
#include <stdio.h>
#include <climits>

using namespace std;

const int n = 3;
int me = 1, bot = -1;
// me - O , bot = X
struct tictac
{
	int board[n][n];
	void printBoard();
	int wincheck(int board[n][n]);
};

void tictac::printBoard()
{
	cout<<"BOARD: \n\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j] == me) cout<<" O ";
			else if(board[i][j] == bot) cout<<" X ";
			else cout<<"   ";
			if(j != n-1) cout<<"|";
		}
		if(i!=n-1) cout<<"\n------------\n";
	}
	cout<<"\n";
}

int tictac::wincheck(int board[n][n])
{
	if(board[0][0]==me && board[0][1]==me && board[0][2]==me) return me;
    else if(board[1][0]==me && board[1][1]==me && board[1][2]==me) return me;
    else if(board[2][0]==me && board[2][1]==me && board[2][2]==me) return me;
    else if(board[0][0]==me && board[1][0]==me && board[2][0]==me) return me;
    else if(board[0][1]==me && board[1][1]==me && board[2][1]==me) return me;
    else if(board[0][2]==me && board[1][2]==me && board[2][2]==me) return me;
    else if(board[0][0]==me && board[1][1]==me && board[2][2]==me) return me;
    else if(board[0][2]==me && board[1][1]==me && board[2][0]==me) return me;
    
    
    else if(board[0][0]==bot && board[0][1]==bot && board[0][2]==bot) return bot;
    else if(board[1][0]==bot && board[1][1]==bot && board[1][2]==bot) return bot;
    else if(board[2][0]==bot && board[2][1]==bot && board[2][2]==bot) return bot;
    else if(board[0][0]==bot && board[1][0]==bot && board[2][0]==bot) return bot;
    else if(board[0][1]==bot && board[1][1]==bot && board[2][1]==bot) return bot;
    else if(board[0][2]==bot && board[1][2]==bot && board[2][2]==bot) return bot;
    else if(board[0][0]==bot && board[1][1]==bot && board[2][2]==bot) return bot;
    else if(board[0][2]==bot && board[1][1]==bot && board[2][0]==bot) return bot;
    
    else return 0;
}
int main()
{
	tictac tt;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			tt.board[i][j] = 0;
		}
	}
	int turn = me;
	int ipos, jpos, countfill = 0;
	pair<int, int> move;
	tt.printBoard();
	while(1)
	{
		if(turn == me)
		{
			cout<<"Player 1 Enter the position to mark: \n";
			cin >> ipos >> jpos;
		}
		else // bot turn
		{
			cout<<"Player 2 Enter the position to mark: \n";
			cin>>ipos >> jpos;
			// perfrom bot moves
		}
		if( (ipos>=0 && ipos<n) && (jpos>=0 && jpos<n))
		{
			if(tt.board[ipos][jpos] == 0)
			{
				tt.board[ipos][jpos] = turn;
				// if win condition comes, then end the game.
				int result = tt.wincheck(tt.board);
				turn*=-1;
				countfill++;
				tt.printBoard();
				if(result!= 0)
				{
					if(result == me) cout<<"Player 1 WON\n";
					else cout<<"Player 2 wins\n";
					break;
				}
				else if(countfill == 9)
				{
					cout<<"GAME DRAWN\n";
					break;
				}	
			}
			else cout<<"position not empty, move again\n";
		}
		else cout<<"Invalid move, move again\n";
	}
	return 0;
}
