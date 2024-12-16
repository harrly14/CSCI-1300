#include "Game.h"

Game::Game(){
    game_board = Board();
    players_array[0] = Player();
    players_array[1] = Player();
    display_beginner_prompts = true;

}

bool Game::can_open_all_reqd_files(){
    std::ifstream characters_file("characters.txt");
    if (!characters_file.is_open()) {
        std::cout << "Error opening the characters file." << std::endl;
        return false;
    }
    characters_file.close();

    std::ifstream familiars_file("familiars.txt");
    if (!familiars_file.is_open()) {
        std::cout << "Error opening the familiars file." << std::endl;
        return false;
    }
    familiars_file.close();

    std::ifstream random_events("random_events.txt");
    if (!random_events.is_open()) {
        std::cout << "Error opening the random events file." << std::endl;
        return false;
    }
    random_events.close();

    std::ifstream riddles("riddles.txt");
    if (!riddles.is_open()) {
        std::cout << "Error opening the riddles file." << std::endl;
        return false;
    }
    riddles.close();

    return true;
}

void Game::initialize_data_from_files(){
    //first the characters file
    std::ifstream characters_file("characters.txt");
    std::string line; 
    static const int CHAR_NUM_OF_ATTRS = 6;
    std::string char_attrs[CHAR_NUM_OF_ATTRS]; 

    std::getline(characters_file, line); //first line just has format data, so skip it
    for (int i = 0; std::getline(characters_file, line); ++i) {
        int start_of_attr = 0;
        for (int j = 0; j < CHAR_NUM_OF_ATTRS; ++j) { 
            int next_attr = line.find('|', start_of_attr+1) + 1;
            char_attrs[j] = line.substr(start_of_attr, next_attr - start_of_attr - 1);
            start_of_attr = next_attr;
        }
        characters.push_back(Player(char_attrs[0], stoi(char_attrs[1]), stoi(char_attrs[2]), stoi(char_attrs[3]),
                               stoi(char_attrs[4]), stoi(char_attrs[5])));
    }
    characters_file.close();


    //now the familiars file
    std::ifstream familiars_file("familiars.txt");
    line = ""; 

    for (int i = 0; std::getline(familiars_file, line); ++i) {
        std::string familiar_num = line.substr(0, line.find('.'));
        int length_of_name = line.find('|') - line.find('.') - 2;
        std::string familiar_name = line.substr(line.find('.') + 2, length_of_name);
        std::string familiar_power = line.substr(line.find('|') + 1);
        

        familiars.push_back(Familiar(stoi(familiar_num), familiar_name, familiar_power));
    }
    familiars_file.close();

    
    //random events file
    std::ifstream events_file("random_events.txt");
    line = ""; 
    const int NUM_OF_EVENT_ATTRS = 8;
    std::string event_attrs[NUM_OF_EVENT_ATTRS]; 

    std::getline(events_file, line); //first line just has format data, so skip it

    while (std::getline(events_file, line)) {
        int start_of_attr = 0;
        for (int j = 0; j < NUM_OF_EVENT_ATTRS - 1; ++j) { 
            int next_attr = line.find('|', start_of_attr) + 1;
            event_attrs[j] = line.substr(start_of_attr, next_attr - start_of_attr - 1);
            start_of_attr = next_attr;
        }
        event_attrs[NUM_OF_EVENT_ATTRS - 1] = line.substr(start_of_attr);

        std::vector<int> impacting_familiars;
        
        // Check if there are multiple familiars
        if (event_attrs[2].find(',') != std::string::npos) {
            int comma_pos = event_attrs[2].find(',');
            impacting_familiars.push_back(std::stoi(event_attrs[2].substr(0, comma_pos)));
            impacting_familiars.push_back(std::stoi(event_attrs[2].substr(comma_pos + 1)));
        } else if (!event_attrs[2].empty() && event_attrs[2] != "0") {
            // Single familiar
            impacting_familiars.push_back(std::stoi(event_attrs[2]));
        }

        // Create Event with parsed data
        events.push_back(Event(stoi(event_attrs[0]),stoi(event_attrs[1]), 
                              impacting_familiars, stoi(event_attrs[3]), 
                              event_attrs[4], event_attrs[5],event_attrs[6],
                              stoi(event_attrs[7])));
    }
    events_file.close();

    //aaaand finally the riddles file
    std::ifstream riddles_file("riddles.txt");
    line = ""; 
    std::getline(riddles_file, line); // first line is just format data 
    for (int i = 1; std::getline(riddles_file, line); ++i) { 
        std::string question = line.substr(0, line.find('|'));
        std::string answer = line.substr(line.find('|') + 1);
        std::string lower_answer;
        for (char c : answer) {
            lower_answer += tolower(c);
        }
        answer = lower_answer;
        riddles.push_back(Riddle(i, question, answer));
    }
    riddles_file.close();
}

void Game::display_pre_game_info() {
    std::cout << "Welcome to the Circle of Life!\n\n" << std::endl;
    
    std::cout << "Would you like to display beginner prompts? (Y/N)" <<std::endl;
    std::string y_or_n;
    std::cin >> y_or_n;
    while (y_or_n != "Y" && y_or_n != "y" && y_or_n != "N" && y_or_n != "n") {
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cin >> y_or_n;
    }
    if (y_or_n == "Y" || y_or_n == "y") {
        display_beginner_prompts = true;
    } else if (y_or_n == "N" || y_or_n == "n") {
        display_beginner_prompts = false;
    }
    std::cout << "\nThe board for every game is randomly generated. Here is the board for this game:" << std::endl;
    game_board.displayBoard();

    if (display_beginner_prompts) {
        std::cout << "In this game you will play as cat wizards racing to get the most sardines before either player reaches the end of the board."
                << " You'll notice that there are two paths, one for magic school and one for the dungeon. At the start of the game, "
                << "you will be prompted to choose one of these paths. Going to magic school for cats means you get a stats boost and a "
                << "magical familiar immediately, but it comes at the cost of tuition, taking away some of your precious sardines. If you "
                << "instead choose to head straight for the dungeon, it means that you gain sardines instead of losing them, but don't gain "
                << "as many stat points. Both paths are made up of 52 tiles. The tiles are as follows: \n\nGreen-- the unpredictable world. "
                << "Landing on a green tile may cause a random event that can impact your sardines either "
                << "negatively or positively. There are more world tiles on the dungeon path, which could mean more bonuses or it could mean more "
                << "negative effects. \nBlue-- the break room. If you land on a break room tile, you can choose to take forgo your next turn in "
                << "exchange for a much needed break (and some extra sardines).\nPink-- the pet shop. If you land on a pet shop tile, you may select "
                << "a familiar to join you on your journey.\nRed-- an ambush. Landing on a red tile will move you backwards and lower your stats."
                << "\nBrown-- traps. Landing on a brown tile will cause you to run back to your previous position and will lower your stamina. "
                << "Tread carefully!" << std::endl;
    }
}

void Game::selectCharacter(int player_index){
    std::cout << "Select a character:" << std::endl;

    //the below logic (making sure only one player can select a character) only works for two players.
    //the process would (slightly) be more complex for more than 2. 
    int unavilable_line;
        for (unsigned int i = 0; i < characters.size(); ++i) {
            if (player_index > 0 && characters[i].getName() == players_array[0].getName()){
                unavilable_line = i + 1;
                std::cout << i+1 << ". [UNAVAILABLE] ";
            } else {
                std::cout << i+1 << ". ";
            }
            std::cout << characters[i].getName() << " | Age: " << characters[i].getAge() << " | Agility: " << characters[i].getAgility()
                      << " | Mana: " << characters[i].getMana() << " | Wisdom: " << characters[i].getWisdom() 
                      << " | Sardines: " << characters[i].getSardines() << std::endl;
        }
    
    std::string character_selection;
    std::cin >> character_selection;
    
    while (character_selection.length() != 1 || !isdigit(character_selection[0]) || stoi(character_selection) == unavilable_line 
           || stoi(character_selection) < 1 || stoi(character_selection) > 5 ) {
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cin >> character_selection;
    }

    players_array[player_index] = characters[stoi(character_selection)-1];

    std::cout << "\n" << "Success! Here are your selected stats Player " << player_index+1 << ":" << std::endl;
    players_array[player_index].printStats();
    std::cout << std::endl;
}

void Game::setup_game(){
    if (display_beginner_prompts) {
        std::cout << "\n\nThe stats for each character are age, agility, mana, wisdom and sardines. Agility, mana, and wisdom all"
                << " max out at 1000 and have a minimum score of 100. Sardines have no restrictions and can be negative. As of"
                << " right now, age has no impact on in-game events. As stated above, you may choose magic school or the dungeon as"
                << " your path. See the above for more details." << std::endl;
    }
    for (int i = 0; i < _num_of_players; ++i){
        std::cout << "\nPlayer " << i+1 << " please select your character and select a path.\n" << std::endl;
        selectCharacter(i);

        std::string path_choice;
        std::cout << "Would you like to (1) go to magic school for cats, or (2) go straight to the dungeon to look for sardines?" << std::endl;
        std::cin >> path_choice;
        while (path_choice.length() != 1 || !isdigit(path_choice[0]) || stoi(path_choice) < 1 || stoi(path_choice) > 2) {
            std::cout << "Invalid input. Input a 1 for magic school or a 2 to go straight to the dungeon." << std::endl;
            std::cin >> path_choice;
        }
        if (stoi(path_choice) == 1){
            players_array[i] = magicSchool(i);
            game_board.addPlayer(0, 1);
        } else if (stoi(path_choice) == 2) {
            players_array[i] = toDungeon(i);
            game_board.addPlayer(0, 2);
        }
        std::cout << std::endl;
    }
    std::cout << "Great, now that we have selected characters, we can officially start the game. Player 1 you're up first."
    << " Here's the board again. Good luck!" << std::endl;
    game_board.displayBoard();
}

void Game::display_main_menu(int player_index, int main_or_secondary){
    int selection = 0;
    while(selection != 5) {
        if (main_or_secondary == 1) {
            std::cout << "Which of the following would you like to do?\n"
                    << "1. Check Player Progress: Review sardines and stats.\n"
                    << "2. Review Character: Check your character name and age.\n"
                    << "3. Check Position: Display board to view current position.\n"
                    << "4. Review your Familiar: Check who your current familiar is and what they do.\n"
                    << "5. Move Forward: Spin the virtual spinner to move your character and end your turn." << std::endl;
        } else if (main_or_secondary == 2) {
            std::cout << "\nWould you like to do anything else before ending your turn? (Y/N)\n";
            std::cin.clear();
            std::string y_or_n;
            std::cin >> y_or_n;
            while (y_or_n != "Y" && y_or_n != "y" && y_or_n != "N" && y_or_n != "n") {
                std::cout << "Invalid input. Please try again." << std::endl;
                std::cin >> y_or_n;
            }
            if (y_or_n == "N" || y_or_n == "n") {
                return;
            } 
            std::cout << "1. Check Player Progress: Review sardines and stats.\n"
                        << "2. Review Character: Check your character name and age.\n"
                        << "3. Check Position: Display board to view current position.\n"
                        << "4. Review your Familiar: Check who your current familiar is and what they do.\n"
                        << "5. End your turn." << std::endl;
        }

        std::string str_selection;
        std::cin >> str_selection;

        if (!(isdigit(str_selection[0])) || str_selection.length() > 1){
            std::cout << "Invalid entry. Please try again." << std::endl;
            continue;
        } 
        selection = stoi(str_selection);
        
        if (selection == 1){
            players_array[player_index].printStats();
            //option to move stats to sardines (refactor)
            std::cout << "Would you like to refactor your stats to sardines? Warning: this will reset all of your stats to the minimum value. (Y/N)" << std::endl;
            std::string y_or_n;
            std::cin >> y_or_n;
            while (y_or_n != "Y" && y_or_n != "y" && y_or_n != "N" && y_or_n != "n") {
                std::cout << "Invalid input. Please try again." << std::endl;
                std::cin >> y_or_n;
            }
            if (y_or_n == "Y" || y_or_n == "y") {
                players_array[player_index].refactorStats();
            } 
        } else if (selection == 2) {
            //added functionality: the ability to change your name
            std::cout << "Your name is: " << players_array[player_index].getName() << ", and your age is: " << players_array[player_index].getAge() << std::endl;
            std::cout << "Would you like to change your name? (Y/N)" << std::endl;
            std::string y_or_n;
            std::cin >> y_or_n;
            while (y_or_n != "Y" && y_or_n != "y" && y_or_n != "N" && y_or_n != "n") {
                std::cout << "Invalid input. Please try again." << std::endl;
                std::cin >> y_or_n;
            }
            if (y_or_n == "Y" || y_or_n == "y") {
                std::cout << "What would you like to change your name too?" << std::endl;
                std::string name;
                std::cin >> name;
                while (!players_array[player_index].setName(name)) {
                    std::cout << "Please try again." << std::endl;
                    std::cin >> name;
                }
                std::cout << "Success! Your cool wizard name is now: " << name << std::endl;
            }
        } else if (selection == 3) {
            game_board.displayBoard();
        } else if (selection == 4) {
        Familiar familiar = players_array[player_index].getFamiliar();
        if (familiar._name == "") {
            std::cout << "You do not have a familiar." << std::endl;
        } else {
            std::cout << "Your familiar is: " << familiar._name << ". Their power is: " << familiar._power << std::endl; 
        }
        } else if (selection == 5) {
            //if this is the main menu, the moving function is called right after this function in the driver, so there's no need to call it here
            //if this is the secondary menu, this should end the persons turn
            return;
        } else {
            std::cout << "Invalid input. Please try again." << std::endl;
            display_main_menu(player_index, main_or_secondary);
            return;
        }
        std::cout << std::endl;
    }
}


#include <thread>
#include <chrono>

void Game::spin_and_move(int player_index){
    game_board.setPastPlayerPosition(game_board.getPlayerPosition(player_index), player_index);

    int spaces_to_move = 0;
    const int max_nums_generated = 40;
    const int min_nums_generated = 30;
    int iterations = rand() % (max_nums_generated + 1 - min_nums_generated) + min_nums_generated; 

    std::cout << "Rolling..." << std::endl;

    for (int i = 0; i < iterations; ++i) {

        spaces_to_move = rand() % 6 + 1; 
        std::cout << "\r" << spaces_to_move << " "; //adding space so the cursor is farther away from the number and its easier to read

        const int initial_sleep = 20;
        const int final_sleep = 200;
        double double_i = 1.0 * i;
        double progress = double_i/iterations;
        int sleep_duration = initial_sleep + progress * (final_sleep-initial_sleep); //for a nice rolling effect

        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_duration)); 
    }

    game_board.movePlayer(player_index, spaces_to_move);
    std::cout << "\nYou have been moved forward " << spaces_to_move << " spaces." << std::endl;
}

Event Game::selectRandomEvent(int player_index) {
    int current_path = game_board.getPlayerBoard(player_index) + 1;
    int familiar_num = players_array[player_index].getFamiliar()._line_num;
    std::vector<Event> valid_events = {};
    
    // Filter valid events
    for (unsigned int i = 0; i < events.size(); ++i) {
        if (events[i].isValidEvent(current_path, familiar_num)) {
            valid_events.push_back(events[i]);
        }
    }
    
    // If no valid events, select the first event i guess?
    if (valid_events.empty()) {
        std::cout << "Something went wrong. :/" << std::endl;
        return events[0];  
    }
    
    // Select a random event from valid events
    int max_num = valid_events.size() + 5; //extra odds for getting into a wizard duel
    int min_num = 1;
    unsigned int event_index = rand() % (max_num + 1 - min_num) + min_num; 

    if (event_index >= valid_events.size()) {
        if (event_index < valid_events.size() + 3) {
            event_index = valid_events.size() - 2; //should go to wizard duel
        } else {
            event_index = valid_events.size() - 1; //should go to the nothing event
        }
    }
    return valid_events[event_index];
}

void Game::evaluate_tile_conditions(int player_index){
    Player player = players_array[player_index];
    int current_position = game_board.getPlayerPosition(player_index);
    int current_board = game_board.getPlayerBoard(player_index);
    char tile_color = game_board.getTile(current_position, current_board).color;

    if (tile_color == 'O'){
        //end
        //the someone_has_reached_the_end function should handle prompting for the winning sequence. just return.
        //change to func bool for reaching end? some other type of return?
        return;
    } else if (tile_color == 'G'){
        //random event
        int fam_num = player.getFamiliar()._line_num;
        Event event = Event();
        event = selectRandomEvent(player_index);
        std::cout << "**" << event._title << "**" << std::endl;

        // Apply event effects
        int new_sardines = event.applyEvent(players_array[player_index].getSardines(), fam_num);
        player.setSardines(new_sardines);
    } else if (tile_color == 'P'){
        //pet store
        player.adjustStats(300);

        std::cout << "You have reached the pet store. +300 to all stats and you can select a familiar. Each familiar costs 100 sardines." << std::endl;
        Familiar player_familiar = player.getFamiliar();
        Familiar new_familiar = chooseFamiliar(player_index);
        if (player_familiar._line_num != new_familiar._line_num) { //only charge them if they actually select a familiar
            player.setSardines(player.getSardines()  - 100); 
        }
    } else if (tile_color == 'R'){
        //ambush
        std::cout << "Ambush! Move back 10 spaces and lose 100 points from all stats" << std::endl;
        game_board.movePlayer(player_index, -10);
        player.adjustStats(-100);
    } else if (tile_color == 'N'){
        //trap
        std::cout << "You reached a trap! Go back to your last position and lose 300 mana." << std::endl;
        int tiles_to_move_backwards = game_board.getPastPlayerPosition(player_index) - game_board.getPlayerPosition(player_index);
        game_board.movePlayer(player_index, tiles_to_move_backwards);
        player.setMana(player.getMana() - 300);
    } else if (tile_color == 'U'){
        //riddle
        int riddle_num = rand() % riddles.size();
        Riddle riddle = riddles[riddle_num];
        std::cout << "**Challenge**\nYou have come across a mysterious figure offerring a boon if you correctly answer their riddle. Their riddle is:" << std::endl;
        std::cout << riddle._question << std::endl;
        std::cout << "What do you answer?" << std::endl;
        std::string inputted_answer;
        std::cin >> inputted_answer;
        if (inputted_answer == riddle._answer) {
            std::cout << "Correct! +300 wisdom." << std::endl;
            player.setWisdom(player.getWisdom() + 300);
        } else {
            std::cout << "Incorrect. You gain nothing, but luckily you lose nothing as well." << std::endl;
        }
    } else if (tile_color == 'B'){
        //break room
        player.adjustStats(200);
        player.setSardines(player.getSardines() + 50); 

        //extra turn
        std::cout << "You have rached the break room. +200 to all stats and +50 to sardines. You also get an extra turn!" << std::endl;

        //going right into another roll gives the player no time to read. pause a bit before rolling again
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        spin_and_move(player_index);
        evaluate_tile_conditions(player_index); 

    }
    players_array[player_index] = player;
}

void Game::find_winner(){
    for (int i = 0; i < _num_of_players; ++i) {
        players_array[i].refactorStats();
        players_array[i].printStats();
        std::cout << std::endl;
    }
    
    int highest_sardines = 0;
    int winner_index;
    for (int i = 0; i < _num_of_players; ++i) {
        if (players_array[i].getSardines() > highest_sardines) {
            highest_sardines = players_array[i].getSardines();
            winner_index = i;
        }
        else if (players_array[i].getSardines() == highest_sardines) {
            std::cout << "There is a tie! You both lose!" << std::endl;
            return;
        }
    }

    if (highest_sardines == 0) {
        std::cout << "How did you both manage to get less than 0 sardines? You both lose." << std::endl;
    } else {
        std::cout << "Player " << winner_index + 1 << " has won!" << std::endl;
    }
}

bool Game::someone_has_reached_the_end() {
    for (int i = 0; i < game_board.getNumPlayers(); ++i) {
        if (game_board.getPlayerPosition(i) >= 51) {
            return true;
        }
    }    
    return false;
}

Familiar Game::chooseFamiliar(int player_index) {
    Player player = players_array[player_index];
    std::cout << "Type the number of the familar you would like to select or type 6 to exit without selecting a familiar." << std::endl;

    std::string familiar_selection;
    int selection_as_an_int;
    Familiar familiar = player.getFamiliar();
    int current_familiar_line = familiar._line_num;

    for (unsigned i = 0; i < familiars.size(); ++i){
        std::string name = familiars[i]._name;
        name[0] = toupper(name[0]);
        std::string power = familiars[i]._power;

        if (i+1 == (unsigned)current_familiar_line) { //+1 because i starts at 0 and familiar line starts at 1
            std::cout << i+1 << ". [Current] ";
        } else {
            std::cout << i+1 << ". ";
        }
        std::cout << name << " -- The power of: " << power << std::endl;
    }

    std::cin >> familiar_selection;

    //error handling: length, if its an int, if its in range
    while (true) {
        if (familiar_selection.length() == 1 && isdigit(familiar_selection[0])) {
            selection_as_an_int = stoi(familiar_selection);
            if (selection_as_an_int >= 1 && selection_as_an_int <= 6) {
                // Check if the selected familiar is not the current familiar
                if (selection_as_an_int != current_familiar_line) {
                    break; // Valid input, exit the loop
                } else {
                    std::cout << "You cannot select the familiar you already have. If you would not like to select a familiar, press 6." << std::endl;
                    std::cin >> familiar_selection;
                }
            } else {
                std::cout << "You must input a single positive integer from 1-6. Please try again." << std::endl;
                std::cin >> familiar_selection;
            }
        } else {
            std::cout << "You must input a single positive integer from 1-6. Please try again." << std::endl;
            std::cin >> familiar_selection;
        }
    }

    if (selection_as_an_int == 6) {
        std::string y_or_n = "x";
        while (y_or_n != "y" && y_or_n != "y" && y_or_n != "N" && y_or_n != "n"){
            std::cout << "You have chosen to not select a familiar. Are you sure about this decision? (Y/N)" << std::endl;
            std::cin >> y_or_n; 

            if (y_or_n == "Y" || y_or_n == "y"){
                std::cout << "Success!" << std::endl;
                return familiar;
            } else if (y_or_n == "N" || y_or_n == "n"){
                std::cout << "Reselect which familiar you would like:" << std::endl;
                return chooseFamiliar(player_index);
            } else {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
    } else {
        std::cout << "Success! You have chosen " << familiars[selection_as_an_int - 1]._name << " to be your familiar." << std::endl;
        return familiars[selection_as_an_int - 1];
    }
    return familiar;
}

Player Game::magicSchool(int player_index){
    const int agility_adjustment = 500;
    const int mana_adjustment = 500;
    const int wisdom_adjustment = 1000;
    const int sardine_adjustment = -500;
    std::cout << "+"<<agility_adjustment<< " agility\n+" << mana_adjustment << " mana\n+" << wisdom_adjustment <<" wisdom\n" << sardine_adjustment << " sardines" << std::endl;
    
    Player player = players_array[player_index];
    player.setTrack(1);

    if (!player.setAgility(player.getAgility() + agility_adjustment)) {
        player.setAgility(1000);
    }
    if (!player.setMana(player.getMana() + mana_adjustment)) {
        player.setMana(1000);
    }
    if (!player.setWisdom(player.getWisdom() + wisdom_adjustment)) {
        player.setWisdom(1000);
    }
    player.setSardines(player.getSardines() + sardine_adjustment);

    std::cout << "Congratulations, you may select a familar!" << std::endl;
    player.setfamiliar(chooseFamiliar(player_index));
    return player;
}

Player Game::toDungeon(int player_index){
    const int agility_adjustment = 200;
    const int mana_adjustment = 200;
    const int wisdom_adjustment = 200;
    const int sardine_adjustment = 500;
    std::cout << "+"<<agility_adjustment<< " agility\n+" << mana_adjustment << " mana\n+" << wisdom_adjustment <<" wisdom\n+" << sardine_adjustment << " sardines" << std::endl;
    
    Player player = players_array[player_index];
    player.setTrack(2);

    if (!player.setAgility(player.getAgility() + agility_adjustment)) {
        player.setAgility(1000);
    }
    if (!player.setMana(player.getMana() + mana_adjustment)) {
        player.setMana(1000);
    }
    if (!player.setWisdom(player.getWisdom() + wisdom_adjustment)) {
        player.setWisdom(1000);
    }
    player.setSardines(player.getSardines() + sardine_adjustment);
    return player;
}
