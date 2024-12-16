#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"
#include "Event.h"

class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    int _player_position[_MAX_PLAYERS]; //initialized this way so that players are off the board to begin with
    int _player_last_position[_MAX_PLAYERS];
    int _player_board[_MAX_PLAYERS];
    int _max_green_tiles, _ambush_odds, _trap_odds, _pet_store_odds, _break_room_odds;
    void displayTile(int board_num, int pos);
    void initializeTiles(int player_index);
    bool isPlayerOnTile(int player_index, int board_num, int pos);
    void setOdds(int player_index, int half);
public:
    Board();
    Board(int player_count);
    void displayTrack(int board_num);
    void initializeBoard();
    void displayBoard();
    bool movePlayer(int player_index, int spaces_moved);
    int getPlayerPosition(int player_index) const;
    void addPlayer(int position, int board);
    void setPlayerBoard(int player_num, int board_num);
    int getPlayerBoard(int player_index) const;
    int getNumPlayers() const {return _player_count;}
    Tile getTile(int pos, int board_num) const {return _tiles[board_num][pos];}
    void setPastPlayerPosition(int pos, int player_index);
    int getPastPlayerPosition(int player_index) const;
};

#endif