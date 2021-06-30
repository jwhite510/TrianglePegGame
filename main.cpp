#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<algorithm>
#include<set>
using namespace std;

typedef vector<pair<pair<int, int>, pair<int, int>>> moveslist;

void printboard(vector<vector<bool>>& board) {

}

class TeeGame {
  public:
    TeeGame (vector<vector<bool>>& board) {

      moveslist m = get_moves(board);
      makemoves(board, m);
      // cout<<"hello"<<endl;


    }
  private:
    moveslist get_moves(vector<vector<bool>>& board) {

      moveslist moves;
      for ( int i = 0; i < board.size(); i++ ) {
        for ( int j = 0; j < board[i].size(); j++ ) {
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
    void makemoves(vector<vector<bool>>& board, moveslist& movesl) {
      for ( auto m : movesl ) {
        // calculate midpoint
        pair<int, int>mid;
        mid.first = (m.first.first + m.second.first) / 2;
        mid.second = (m.first.second + m.second.second) / 2;
        cout<<"move "<<
          m.first.first<<" " <<m.first.second<<" -> "
          <<m.second.first<<" "<<m.second.second
          <<"  midpoint:"<<mid.first<<" "<<mid.second
          <<endl;

      }

    }
};

int main()
{
  vector<vector<bool>> board {
         {1},
       {1, 0},
     {1, 1, 1},
    {1, 0, 1, 1},
  };
  TeeGame teegame(board);
}
