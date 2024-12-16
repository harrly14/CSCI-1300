# Compiling & running
Compile by running: 
g++ Board.cpp Player.cpp Game.cpp Event.cpp Game_Driver.cpp -o game_file -Werror -Wall -Werror

Then just run: .\game_file.exe

Alternatively, you should be able to just run the game_file.exe file without compiling first, as it is already comppiled. 

# Playing the game
1. At the start, you can select if you want to display beginner prompts. Doing so will display the rules at the start of the game. Choosing not to, will launch you straight into the game
2. Both players will then select their character and path as well as familiar if they get one, using the numbers of each option
3. Game play will start. Each turn you can select your option 1-5 from the main menu. After moving, the conditions of the tile you land on will be evaluated. 
4. You will then be prompted if you want to continue your turn. Entering Y displays the menu again and entering N will end your turn
5. This continues until someone reaches the end of the board, at witch point, it will display the players's stats and crown the winner

# External requirements
Outside of the files in the folder, I used the chrono and thread library. I am assuming that whatever device you are running the game file on has C++ installed, so I have not explicitly included the library files in this folder.