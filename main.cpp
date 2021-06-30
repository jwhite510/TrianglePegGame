#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<algorithm>
#include<set>
using namespace std;

void printboard(vector<vector<bool>>& board) {

}

class TeeGame {
  public:
    TeeGame (vector<vector<bool>>& board) {


      get_moves(board);




    }
  private:
    vector<pair<int, int>>get_moves(vector<vector<bool>>& board) {

      for ( int i = 0; i < board.size(); i++ ) {
        for ( int j = 0; j < board[i].size(); j++ ) {
          // can move up ?
          if ( i - 2 >= 0 ) {
            // up / right
            if ( j < board[i-2].size() && board[i - 2][j] == 0
                && board[i - 1][j] == 1 ) {

            }
            // up / left
            if ( ((j - 2) >= 0) && (j - 2) < board[i - 2].size()
                && board[i - 2][j - 2] == 0
                && board[i - 1][j - 1] == 1 ) {

            }
          }
          // can move left / right ?

          // can move down ?
          if ( i + 2 < board.size() ) {
            if ( board[i + 2][j + 2] == 0 && board[i + 1][j + 1] ==  1 ) {

            }
            if ( board[i + 2][j] == 0 && board[i + 1][j] == 1 ) {

            }
          }
        }

      }

      return {};
    }
};

int main()
{
  vector<vector<bool>> board {
         {0},
       {1, 1},
     {1, 1, 1},
    {1, 1, 1, 1},
  };
  TeeGame teegame(board);
}
