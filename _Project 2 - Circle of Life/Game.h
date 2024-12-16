#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"
#include "Riddle.h"
#include <vector>

class Game {
    private:
        Board game_board;
        static const int _num_of_players = 2;
        Player players_array[_num_of_players];
        //data from files: characters, familiars, random events, riddles
        std::vector<Player> characters;
        std::vector<Familiar> familiars;
        std::vector<Event> events;
        std::vector<Riddle> riddles;
        bool display_beginner_prompts;

    public:
        Game();
        bool can_open_all_reqd_files();
        void initialize_data_from_files();
        void display_pre_game_info();
        void selectCharacter(int player_index);
        void setup_game();
        void display_main_menu(int player_index, int main_or_secondary);
        void spin_and_move(int player_index);
        Event selectRandomEvent(int player_index);
        void evaluate_tile_conditions(int player_index);
        void find_winner();
        bool someone_has_reached_the_end();
        int get_num_of_players() {return _num_of_players;}
        Familiar chooseFamiliar(int player_index);
        Player magicSchool(int player_index);
        Player toDungeon(int player_index);


};

#endif