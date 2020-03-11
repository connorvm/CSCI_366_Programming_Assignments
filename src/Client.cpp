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
#include "Client.hpp"

Client::~Client() {
}


void Client::initialize(unsigned int player, unsigned int board_size){
    /**
     * Performs the initialization functions that normally would be in a constructor, but needs to be a separate
     * function for googletest so clients may be initialized in the SetUp() function.
     * Creates player_#.action_board.json.
     * @param player - the id of the player
     * @param board_size - the square size of the action board
     */

    
}


void Client::fire(unsigned int x, unsigned int y) {
    /**
     * Fires a shot on the coordinate target and creates a player_#.shot.json file
     * @param x - coordinate
     * @param y - coordinate
     */
}


bool Client::result_available() {
    /**
    * Checks if a result file is available for
    * @return true if result is available, false otherwise
    */
    return false;
}


int Client::get_result() {
    /**
     * Gets the result from the player_#.result.json
     * @return the result as either HIT, MISS, or OUT_OF_BOUNDS
     */
}



void Client::update_action_board(int result, unsigned int x, unsigned int y) {
    /**
     * Updates the internal representation of player_#.action_board.json on the result of a shot.
     * @param result - the result returned from the server
     * @param x - coordinate
     * @param y - coordinate
     */
}


string Client::render_action_board(){
    /**
    * Formats a string representing player_#.action_board.json as ASCII
    * @return ASCII representation of the action board
    */
}