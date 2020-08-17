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

#include <sys/stat.h>
#include "common.hpp"
#include "Client.hpp"
#include "Server.hpp"

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

    string fname;
    if (player == 1){
        fname = "player_1.action_board.json";
    }
    else if (player == 2){
        fname = "player_2.action_board.json";
    }
    cout << "fname = " << fname << endl;

    //create a two dimensional vector
    vector<vector<int>>board(board_size, vector<int>(board_size, 0));

    // serialize the array
    ofstream array_ofp(fname); // create an output file stream
    cereal::JSONOutputArchive write_archive(array_ofp); // initialize an archive on the file
    write_archive(cereal::make_nvp("board", board)); // serialize the data giving it a name
}


void Client::fire(unsigned int x, unsigned int y) {
    /**
     * Fires a shot on the coordinate target and creates a player_#.shot.json file
     * @param x - coordinate
     * @param y - coordinate
     */

    string fname1;
    cout << "player = " << player << endl;
    if (player == 1){
        fname1 = "player_1.shot.json";
    }
    else if (player == 2){
        fname1 = "player_2.shot.json";
    }
    fname1 = "player_1.shot.json";
    cout << "fname1 = " << fname1 << endl;

    /*Write a shot into player_#.shot.json **/
    // remove any old serialization files
    remove(fname1.c_str());

    // serialize the array
    ofstream array_ofp(fname1); // create an output file stream
    cereal::JSONOutputArchive write_archive(array_ofp); // initialize an archive on the file
    write_archive(cereal::make_nvp("x", x), cereal::make_nvp("y", y)); // serialize the data giving it a name
}


bool Client::result_available() {
    /**
    * Checks if a result file is available for
    * @return true if result is available, false otherwise
    */

    string p1_result = "player_1.result.json";
    string p2_result = "player_2.result.json";

    struct stat buffer;
    return (stat (p1_result.c_str(), &buffer) == 0 ||
            stat (p2_result.c_str(), &buffer) == 0);

}


int Client::get_result() {
    /**
     * Gets the result from the player_#.result.json
     * @return the result as either HIT, MISS, or OUT_OF_BOUNDS
     */
    string fname1;
    if ("player_1.result.json"){
        fname1 = "player_1.result.json";
    }
    else if ("player_2.result.json"){
        fname1 = "player_2.result.json";
    }
    cout << "fname1 = " << fname1 << endl;

    int result; //either HIT, MISS, or OUT_OF_BOUNDS

    // deserialize the array
    ifstream array_ifp(fname1); // create an input file stream
    cereal::JSONInputArchive read_archive(array_ifp); // initialize an archive on the file
    read_archive(result); // deserialize the array
    array_ifp.close(); // close the file
    cout << "result = " << result << endl;

    if (result == HIT){
        remove(fname1.c_str());
        return HIT;
    } else if (result == MISS){
        remove(fname1.c_str());
        return MISS;
    } else if (result == OUT_OF_BOUNDS){
        remove(fname1.c_str());
        return OUT_OF_BOUNDS;
    } else
        throw ServerException("Bad Result");
}



void Client::update_action_board(int result, unsigned int x, unsigned int y) {
    /**
     * Updates the internal representation of player_#.action_board.json on the result of a shot.
     * @param result - the result returned from the server
     * @param x - coordinate
     * @param y - coordinate
     */

    string shotFile = "player_1.action_board.json";
    string actionFile = "player_1.action_board.json";

    //create a vector containing n vectors of size m
    vector<vector<int>>board(10, vector<int>(10, 0));

    // deserialize the array
    ifstream array_ifp(shotFile); // create an input file stream
    cereal::JSONInputArchive read_archive(array_ifp); // initialize an archive on the file
    read_archive(board); // deserialize the array
    array_ifp.close(); // close the file

    board[x][y] = result;

    // serialize the array
    ofstream array_ofp(actionFile); // create an output file stream
    cereal::JSONOutputArchive write_archive(array_ofp); // initialize an archive on the file
    write_archive(cereal::make_nvp("board", board)); // serialize the data giving it a name

}


string Client::render_action_board(){
    /**
    * Formats a string representing player_#.action_board.json as ASCII
    * @return ASCII representation of the action board
    */
}