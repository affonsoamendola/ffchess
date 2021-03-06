#include <stdlib.h>
#include <string.h>

#include "chess.h"
#include "display.h"

int board_start_x = 0;
int board_start_y = 0;

int viewport_x = 40;
int viewport_y = 40;

int board_size_x = 8;
int board_size_y = 8;

int square_size = 20;
int get_square_size(){return square_size;}

PIECE* board_pieces;

void init_board()
{
	board_pieces = malloc(board_size_x * board_size_y * sizeof(PIECE));
	memset(board_pieces, 0, board_size_x * board_size_y * sizeof(PIECE));

	set_board_piece(0, 0, TOWER, BLACK);
	set_board_piece(1, 0, KNIGHT, BLACK);
	set_board_piece(2, 0, BISHOP, BLACK);
	set_board_piece(3, 0, QUEEN, BLACK);
	set_board_piece(4, 0, KING, BLACK);
	set_board_piece(5, 0, BISHOP, BLACK);
	set_board_piece(6, 0, KNIGHT, BLACK);
	set_board_piece(7, 0, TOWER, BLACK);
	set_board_piece(0, 1, PAWN, BLACK);
	set_board_piece(1, 1, PAWN, BLACK);
	set_board_piece(2, 1, PAWN, BLACK);
	set_board_piece(3, 1, PAWN, BLACK);
	set_board_piece(4, 1, PAWN, BLACK);
	set_board_piece(5, 1, PAWN, BLACK);
	set_board_piece(6, 1, PAWN, BLACK);
	set_board_piece(7, 1, PAWN, BLACK);

	set_board_piece(0, 7, TOWER, WHITE);
	set_board_piece(1, 7, KNIGHT, WHITE);
	set_board_piece(2, 7, BISHOP, WHITE);
	set_board_piece(3, 7, QUEEN, WHITE);
	set_board_piece(4, 7, KING, WHITE);
	set_board_piece(5, 7, BISHOP, WHITE);
	set_board_piece(6, 7, KNIGHT, WHITE);
	set_board_piece(7, 7, TOWER, WHITE);
	set_board_piece(0, 6, PAWN, WHITE);
	set_board_piece(1, 6, PAWN, WHITE);
	set_board_piece(2, 6, PAWN, WHITE);
	set_board_piece(3, 6, PAWN, WHITE);
	set_board_piece(4, 6, PAWN, WHITE);
	set_board_piece(5, 6, PAWN, WHITE);
	set_board_piece(6, 6, PAWN, WHITE);
	set_board_piece(7, 6, PAWN, WHITE);
}

Point2 get_board_size()
{
	return point2(board_size_x, board_size_y);
}

Point2 get_background_start()
{
	Point2 start;

	start.x = get_current_res().x/2 - viewport_x - get_texture_w(0)/2;
	start.y = get_current_res().y/2 - viewport_y - get_texture_h(0)/2;

	return start;
}

Point2 get_board_start()
{
	Point2 start;

	start.x = get_current_res().x/2 - viewport_x - (square_size*board_size_x)/2;
	start.y = get_current_res().y/2 - viewport_y - (square_size*board_size_y)/2;

	return start;
}

void free_board()
{
	free(board_pieces);
}

