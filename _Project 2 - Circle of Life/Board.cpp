#include "Board.h"
#include <iostream>
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"  /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

void Board::initializeBoard()
{
    // Seed random number generator in your main function once
    for (int i = 0; i < 2; i++)
    {
        initializeTiles(i);  // This ensures each lane has a unique tile distribution
    }
}

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

void Board::initializeTiles(int player_index)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;


    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == 25) {
            //second half odds may be different
            setOdds(player_index, 2);
        }

        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } 
        else if (i == 0) {
            // Set the first tile as Grey for Starting Point
            temp.color = 'Y';
            setOdds(player_index, 1);
        } 
        //doesn't necessarily always get the max number of green tiles
        else if (green_count < _max_green_tiles && (rand() % (total_tiles - i) < _max_green_tiles - green_count)) {
            temp.color = 'G';
            green_count++;
        }
        else
        {
            //added logic: special tiles of the same type cannot repeat twice in a row
            char previous_tile_color = _tiles[player_index][i-1].color;
            do {
                int color_choice = rand() % 100;

                //Blue = B, Pink = P, Brown = N, Red= R, Purple =U
                if ((color_choice>= 0 && color_choice < _ambush_odds)) {
                    temp.color = 'R';
                } else if ((color_choice >= _ambush_odds && color_choice < _trap_odds)){
                    temp.color = 'N';
                } else if ((color_choice >= _trap_odds && color_choice < _pet_store_odds)){
                    temp.color = 'P';
                } else if ((color_choice >= _pet_store_odds && color_choice < _break_room_odds)){
                    temp.color = 'B';
                } else if (color_choice >= _break_room_odds) {
                    temp.color = 'U';
                }
            } 
            while (temp.color == previous_tile_color);
        }


        // Assign the tile to the board for the specified lane
        _tiles[player_index][i] = temp;
    }
}

void Board::setOdds(int player_index, int half) {
    if (half != 1 && half !=2) {
        std::cout << "Invalid half. Cannot set odds." << std::endl;
        return;
    }

    //0 = magic school
    if (player_index == 0) {
        _max_green_tiles = 20;
        _ambush_odds = 20;
        _trap_odds = 20 + _ambush_odds;
        _pet_store_odds = _trap_odds + 15;

        if (half == 1){
            _break_room_odds = _pet_store_odds + 25;
        } else if (half == 2) {
            _break_room_odds = 15;
        }
    } else if (player_index == 1) {
        _max_green_tiles = 30;
        if (half == 1){
            _ambush_odds = 25;
            _trap_odds = _ambush_odds + 25;
            _pet_store_odds = _trap_odds + 20;
            _break_room_odds = _pet_store_odds + 5;

        } else if (half == 2) {
            _ambush_odds = 15;
            _trap_odds = _ambush_odds + 15;
            _pet_store_odds = _trap_odds + 20;
            _break_room_odds = _pet_store_odds + 25;
        }
    }
}

Board::Board()
 {
    //will be used for pre-game loading the board without players on it
     _player_count = 0;
     _player_last_position[0] = 0;
     _player_last_position[1] = 0;
     _player_position[0] = 53;
     _player_position[1] = 53; //initialized this way so that players are off the board to begin with

     // Initialize player position
     //_player_position[0] = 0;

     // Initialize tiles
     initializeBoard();
 }

Board::Board(int player_count)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }

    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
        _player_board[i] = i;

    }

    // Initialize tiles

    initializeBoard();
}

bool Board::isPlayerOnTile(int player_index, int board_num, int pos) {
    if (_player_count == 0) {
        return false;
    }
    if (_player_position[player_index] == pos && _player_board[player_index] == board_num)
    {
        return true;
    }
    return false;
}

void Board::displayTile(int board_num, int pos)
{
    std::string color = "";

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

    // Determine color to display
    if (_tiles[board_num][pos].color == 'R')
    {
        color = RED;
    }
    else if (_tiles[board_num][pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[board_num][pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[board_num][pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[board_num][pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[board_num][pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[board_num][pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[board_num][pos].color == 'Y')
    {
        color = GREY;
    }

    //does not scale for more than 2 players
    if (isPlayerOnTile(0, board_num, pos) && isPlayerOnTile(1, board_num, pos))
    {
            std::cout << color << "|1+2|" << RESET;
    } else if (isPlayerOnTile(0,board_num,pos)) {
            std::cout << color << "|" << 1 << "|" << RESET;
    } else if (isPlayerOnTile(1,board_num,pos)) {
        std::cout << color << "|" << 2 << "|" << RESET;
    } else {
        std::cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(int board_num)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(board_num, i);
    }
    std::cout << std::endl;
}

void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        if (i == 0) {
            std::cout << "Magic school: ";
        } else if (i == 1) {
            std::cout << "     Dungeon: ";
        }
        displayTrack(i);
        if (i == 0) {
            std::cout << std::endl;  // Add an extra line between the two lanes
        }
    }
}

bool Board::movePlayer(int player_index, int spaces_moved)
 {
     // Increment player position
     _player_position[player_index] += spaces_moved;
     if (_player_position[player_index] >= _BOARD_SIZE - 1)
     {
         // Player reached last tile
         _player_position[player_index] = 51;
         return true;
     }
     if (_player_position[player_index] < 0) {
        _player_position[player_index] = 0;
     }
     return false;
 }

 int Board::getPlayerPosition(int player_index) const
 {
     if (player_index >= 0 && player_index <= _player_count)
     {
         return _player_position[player_index];
     }
     return -1;
 }

void Board::addPlayer(int position, int board) {
    ++_player_count;
    _player_position[_player_count - 1] = position;
    _player_board[_player_count - 1] = board - 1;

}

void Board::setPlayerBoard(int player_num, int board_num) {
    if (board_num > 2 || board_num < 1) {
        std::cout << "Unable to set player's board. Make sure it is being set to a 1 or a 2." << std::endl;
        return;
    }
    _player_board[player_num - 1] = board_num - 1;
}

int Board::getPlayerBoard(int player_index) const {
     if (player_index >= 0 && player_index <= _player_count)
     {
         return _player_board[player_index];
     }
     return -1;
 }

void Board::setPastPlayerPosition(int pos, int player_index) {
    _player_last_position[player_index] = pos;
}

int Board::getPastPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_last_position[player_index];
    }
    return -1;
}

