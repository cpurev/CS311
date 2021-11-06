//hdtcount.cpp
//Chuluunbat Purev
//2021-9-27
//
//Source for hdtcount.h

#include "hdtcount.h" // hdtcount template

#include <vector>		//std::vector
#include <algorithm>    // std::find

//hdtCount_recurse
//hdtCount work horse function
// x and y are board indexese, after recurse they go starting from x, y thus no repeat solutions
//Pre:
//		x >= 0, y >= 0, must be valid range in board.
//		dim_x == board.size  && dim_y == board[0].size, must be the board dimensions
//		squaresLeft >= 0, must be even number; 
// 		board must have 2 forbidden squares.
//		board must have unavaliable squares as 1 and avaliable ones as 0
//Does not throw
int hdtCount_recurse(std::vector<std::vector<int>> & board, size_t x, size_t y, size_t dim_x, size_t dim_y, int squaresLeft){
	if(squaresLeft == 0)
		return 1; //We have a full solution

	int total = 0;

	for(size_t i = x; i < dim_y; ++i){
		// ternary operator to make sure we dont check positions before x,y for no repeat solutions.
		for(size_t j = (i == x ? y : 0); j < dim_x; ++j){
			if(board[i][j] == 1)
				continue;

			board[i][j] = 1;
			
			//Horizontal
			if(j + 1 < dim_x && board[i][j + 1] == 0){
				board[i][j + 1] = 1;
				total += hdtCount_recurse(board, i, j, dim_x, dim_y, squaresLeft - 2);
				board[i][j + 1] = 0;
			}

			//Vertical
			if( i + 1 < dim_y && board[i + 1][j] == 0){
				board[i + 1][j] = 1;
				total += hdtCount_recurse(board, i, j, dim_x, dim_y, squaresLeft - 2);
				board[i + 1][j] = 0;
			}
			
			board[i][j] = 0;
		}
	}

	return total;
}

//hdtCount
//with given dimensions and forbidden tile positions counts how many Holey Domino Tiling is possible
//Pre:
//		dim_x > 0 && dim_y > 0, must be the board dimensions.
//		0 <= forbid1_x < dim_x, 0 <= forbid2_x < dim_y.
//		0 <= forbid1_y < dim_y, 0 <= forbid2_y < dim_y.
//		[forbid1_x, forbid1_y, forbid2_x, forbid2_y] > 0, must be in range valid of board dimensions.
//Does not throw
int hdtCount(int dim_x, int dim_y,
             int forbid1_x, int forbid1_y,
             int forbid2_x, int forbid2_y){
	std::vector<std::vector<int>> board(size_t(dim_y), std::vector<int>(size_t(dim_x), 0));

	board.at(size_t(forbid1_y)).at(size_t(forbid1_x)) = 1;
	board[size_t(forbid2_y)][size_t(forbid2_x)] = 1;

	return hdtCount_recurse(board, 0, 0, size_t(dim_x), size_t(dim_y), ((dim_x*dim_y)-2));
}