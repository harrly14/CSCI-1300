#include "Game.h"

int main() {
    srand(time(NULL));

    Game game = Game();
    if (!game.can_open_all_reqd_files()) {
        return 1;
    }

    game.initialize_data_from_files(); 
    game.display_pre_game_info();
    game.setup_game();

    while (!game.someone_has_reached_the_end()) {
        for (int i = 0; i < game.get_num_of_players(); ++i) {
            std::cout << "\n\nPlayer " << i + 1 << " it is your turn." << std::endl;
            game.display_main_menu(i, 1);
            game.spin_and_move(i);
            game.evaluate_tile_conditions(i); 
            game.display_main_menu(i, 2);
        }
    }
    game.find_winner();
    return 0;
}