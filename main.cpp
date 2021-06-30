#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<algorithm>
#include<set>
#include<fstream>
using namespace std;

typedef vector<pair<pair<int, int>, pair<int, int>>> moveslist;

void printboard(vector<vector<bool>>& board) {
  ofstream ofile;
  ofile.open("debug.txt", ios_base::app);
  ofile<<endl;
  int sp = 4;
  for ( int i = 0; i < board.size(); i++ ) {
    ofile<<string(sp--, ' ');
    for ( int j = 0; j < board[i].size(); j++ ) {
      ofile<<board[i][j]<<" ";
    }
    ofile<<endl;
  }
  ofile.close();
}

class TeeGame {
  public:
    TeeGame () { }
    // calculate the number of ways to win
    int calculate (vector<vector<bool>>& board, int remaining) {
      if ( remaining == 1 ) {
        // printboard(board);
        return 1;
      }
      int ways = 0;
      moveslist movesl = get_moves(board);
      for ( auto move : movesl ) {
        pair<int, int> start = move.first;
        pair<int, int> next = move.second;
        pair<int, int> mid = { (start.first + next.first) / 2, (start.second + next.second) / 2 };
        board[start.first][start.second] = 0;
        board[next.first][next.second] = 1;
        board[mid.first][mid.second] = 0;
        ways += calculate(board, remaining - 1);
        board[start.first][start.second] = 1;
        board[next.first][next.second] = 0;
        board[mid.first][mid.second] = 1;
      }
      return ways;
    }
  private:
    moveslist get_moves(vector<vector<bool>>& board) {

      moveslist moves;
      for ( int i = 0; i < board.size(); i++ ) {
        for ( int j = 0; j < board[i].size(); j++ ) {
          if ( board[i][j] != 1 ) { continue; }
          // can move up ?
          if ( i - 2 >= 0 ) {
            // up / right
            if ( j < board[i-2].size()
                && board[i - 2][j] == 0
                && board[i - 1][j] == 1 ) {
              moves.push_back( { {i, j} , {i - 2, j} });
            }
            // up / left
            if ( ((j - 2) >= 0) && (j - 2) < board[i - 2].size()
                && board[i - 2][j - 2] == 0
                && board[i - 1][j - 1] == 1 ) {
              moves.push_back( { {i, j}, {i - 2, j - 2} } );
            }
          }
          // can move left?
          if ( (j - 2) >= 0 && board[i][j - 2] == 0
              && board[i][j - 1] == 1 ) {
            moves.push_back( { {i, j}, {i, j - 2} } );
          }
          // can move right?
          if ( (j + 2) < board[i].size()
              && board[i][j + 2] == 0
              && board[i][j + 1] == 1 ) {
            moves.push_back( { {i, j}, {i, j + 2} } );
          }
          // can move down ?
          if ( i + 2 < board.size() ) {
            // down / right
            if ( board[i + 2][j + 2] == 0
                && board[i + 1][j + 1] ==  1 ) {
              moves.push_back( { {i, j}, {i + 2, j + 2} } );

            }
            // down / left
            if ( board[i + 2][j] == 0
                && board[i + 1][j] == 1 ) {
              moves.push_back( { {i , j}, {i + 2, j} } );
            }
          }
        }
      }
      return moves;
    }
};

int main()
{
  vector<vector<bool>> board {
         {0},
       {1, 1},
     {1, 1, 1},
    {1, 1, 1, 1},
   {1, 1, 1, 1, 1},
  };
  TeeGame teegame;
  // 2 + 3 + 4 = 9
  int ans = teegame.calculate(board, 14);
  cout<<"ans: "<<ans<<endl;
}
