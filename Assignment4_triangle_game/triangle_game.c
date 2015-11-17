#include <stdio.h>
#include "triangle_routines.h"
#define NMOVES 36 /* The number of possible moves */
#define NBOARD 15 /* The number of pegs */

int npegs(int board[]);
int valid_move(int board[], int move[]);
void make_move(int board[], int move[]);
void unmake_move(int board[], int move[]);
int solve(int board[]);
int moves[NMOVES][3] =
{
  {0, 1, 3}, {3, 1, 0}, {0, 2, 5}, {5, 2, 0},
  {1, 3, 6}, {6, 3, 1}, {1, 4, 8}, {8, 4, 1},
  {2, 4, 7}, {7, 4, 2}, {2, 5, 9}, {9, 5, 2},
  {3, 6, 10}, {10, 6, 3}, {3, 7, 12}, {12, 7, 3},
  {4, 7, 11}, {11, 7, 4}, {4, 8, 13}, {13, 8, 4},
  {5, 8, 12}, {12, 8, 5}, {5, 9, 14}, {14, 9, 5}, /* diagonal moves */
  {3, 4, 5}, {5, 4, 3}, {6, 7, 8}, {8, 7, 6},
  {7, 8, 9}, {9, 8, 7}, {10, 11, 12}, {12, 11, 10},
  {11, 12, 13}, {13, 12, 11}, {12, 13, 14}, {14, 13, 12}
};

/* Return the number of pegs on the board */
int npegs(int board[])
{
  int i;
  int count = 0; /* "count" keeps track of 1's in board[] */
  for(i = 0; i < NBOARD; i++)
  {
    if (board[i] == 1)
    {
      count++;
    }
  }
  return count;
}

/* Return 1 if the move is valid on this board, otherwise return 0 */
int valid_move(int board[], int move[])
{
  int valid = 0; /* becomes 1 if move is valid */
  /* Conditions for the pegs for the move */
  if (board[move[0]] == 1 && board[move[1]] == 1 && board[move[2]] == 0)
  {
    valid = 1;
  }
  return valid;
}

/* Make the move and apply it to the board */
void make_move(int board[], int move[])
{
  board[move[0]] = 0;
  board[move[1]] = 0;
  board[move[2]] = 1;
}

/* Unmake the move and apply it to the board */
void unmake_move(int board[], int move[])
{
  board[move[0]] = 1;
  board[move[1]] = 1;
  board[move[2]] = 0;
}

/* Solve the game starting from this board.  Return 1 if the game can
 * be solved; otherwise return 0.  Do not permanently alter the board passed
 * in. Once a solution is found, print the boards making up the solution in
 * reverse order.  */
int solve(int board[])
{
  int j;
  if (npegs(board) == 1)
  {
    triangle_print(board);
    return 1;
  }
  for (j = 0; j < NMOVES; j++)
  {
    if (valid_move(board, moves[j]))
    {
      make_move(board, moves[j]);
      if (solve(board))
      {
        unmake_move(board, moves[j]);
        triangle_print(board);
        return 1;
      }
      unmake_move(board, moves[j]);
    }
  }
  return 0;
}

int main(void)
{
  int board[NBOARD];
  triangle_input(board);
  /* triangle_print(board); */
  solve(board);
  return 0;
}
