//    Battleship game assignment for MSU CSCI 366
//    Copyright (C) 2020    Mike P. Wittie
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.


#include "common.hpp"
#include "Server.hpp"

#include "fstream"
#include "iostream"
using namespace std;


/**
 * Calculate the length of a file (helper function)
 *
 * @param file - the file whose length we want to query
 * @return length of the file in bytes
 */
int get_file_length(ifstream *file){

    cout << file << " is the input file.\n";

    /*
    std::ifstream f_in(*file);
    char character; int count = 0;
    while (fin >> character) ++count;
    std::cout << count << " characters in Player 1 board\n";*/
}


void Server::initialize(unsigned int board_size,
                        string p1_setup_board,
                        string p2_setup_board){
    /*The method opens player setup boards containing ship positions and checks the size of boards compared to
     * board_size parameter.
     */

    //int board1 = get_file_length(p1_setup_board;

    //open setup_boards
    std::ifstream p1_in("player_1.setup_board.txt");
    char character1; int count1 = 0;
    while (p1_in >> character1) ++count1;
    std::cout << count1/board_size << " characters in Player 1 board\n";

    std::ifstream p2_in("player_2.setup_board.txt");
    char character2; int count2 = 0;
    while (p2_in >> character2) ++count2;
    std::cout << count2/board_size << " characters in Player 2 board\n";

    std::cout << board_size << " characters in board size\n";

    std::cout << p1_setup_board << " read in\n";
    std::cout << p2_setup_board << " read in\n";

    //do the player boards match?
    if (count1 == count2/board_size == board_size){
        //Throw exception??
        throw ServerException("Passed!");
    }
    if (count1/board_size != count2/board_size || count1/board_size != board_size){
        //Throw another exception
        throw ServerException("Failed, board sizes not correct.");
    }
    if (p1_setup_board != "player_1.setup_board.txt" || p2_setup_board != "player_2.setup_board.txt"){
        throw ServerException("File names are not valid. Please try again.");
    }

}


int Server::evaluate_shot(unsigned int player, unsigned int x, unsigned int y) {
    /*Checks the coordinates of a shot against setup board of player
     *
     * Check that player number within bounds, checks that shot coordinates within bounds, determines if the shot
     * results in a HIT, or a MISS.
     * @param player - player number
     * @param x - coordinate
     * @param y - coordinate
     * @return returns shot result as either HIT, MISS, or OUT_OF_BOUNDS
     */

    //Check player number is within bounds
    if (player < 1){
        throw ServerException("Player number is low.");
    }
    if (player > 2){
        throw ServerException("Player number is high.");
    }

    //Check that shot coordinates are within bounds, if so, return 0
    if (x > BOARD_SIZE){
        cout << "X coordinates is not within bounds" << endl;
        return 0;
    }
    if (y > BOARD_SIZE){
        cout << "Y coordinates is not within bounds" << endl;
        return 0;
    }

    //Determine if shot is a miss, if so, return -1
    //if ()

    //Determine if shot is a hit, if so, return 1

}


int Server::process_shot(unsigned int player) {

    /**
    * Processes a shot issued by player
    *
    * Gets the shot from player, extracts coordinates, passes the information of evaluate_shot, and writes the result
    * into player_#.result.json.
    * @param player - player number
    * @return returns SHOT_PROCESSED, or NO_SHOT_FILE if nothing to process
    */


   return NO_SHOT_FILE;
}