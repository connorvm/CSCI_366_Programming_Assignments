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

//    file->seekg(0, std::ifstream::end); //0 offset, to the end of the file
//    int length = file->tellg();
//    cout << file << " is the input file.\n";
//    return length;

    /*
    std::ifstream f_in(*file);
    char character; int count = 0;
    while (fin >> character) ++count;
    std::cout << count << " characters in Player 1 board\n";*/
    return 0;
}


void Server::initialize(unsigned int board_size,
                        string p1_setup_board,
                        string p2_setup_board){
    /*The method opens player setup boards containing ship positions and checks the size of boards compared to
     * board_size parameter.
     */

    //open setup_boards
    cout << "-----------------\n";

    ifstream p1_in(p1_setup_board);
    char character1; int count1 = 0;
    while (p1_in >> character1) ++count1;
    cout << "count1 is " << count1 << endl;
    cout << (count1/board_size) << " characters in Player 1 board\n";
    cout << endl;

    cout << board_size << " characters in board size\n";
    cout << endl;

    ifstream p2_in(p2_setup_board);
    char character2; int count2 = 0;
    while (p2_in >> character2) ++count2;
    cout << "count2 is " << count2 << endl;
    cout << (count2/board_size) << " characters in Player 2 board\n";
    cout << endl;
    cout << board_size << " characters in board size\n";
    cout << endl;
    cout << p1_setup_board << " read in\n";
    cout << p2_setup_board << " read in\n";
    cout << "-----------------\n";

    //do the player boards match?
    if (count1/board_size == count2/board_size == board_size){
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

    /*Check player number is within bounds*/
    if (player < 1){
        throw ServerException("Player number is low.");
    }
    if (player > 2){
        throw ServerException("Player number is high.");
    }

    /*Check that shot coordinates are within bounds, if so, return 0*/
    if (x > BOARD_SIZE){
        cout << "X coordinates is not within bounds" << endl;
        return 0;
    }
    if (y > BOARD_SIZE){
        cout << "Y coordinates is not within bounds" << endl;
        return 0;
    }

    /*Determine if shot is a miss, if so, return -1*/
    fstream shotFile;
    int ypos;
    int pos;
    char shotValue;
    char value;

    cout << "Player number is " << player << endl;
    if (player == 1){
        shotFile.open("player_1.json");
    } else if (player == 2) {
        shotFile.open("player_2.json");
    }

    if (shotFile.is_open()) {
        cout << "File is open." << endl;
    }

    if (y > 0){
        ypos = y * board_size;
        pos = ypos + x;
    } else if (y == 0){
        pos = x;
    }
    cout << "pos = " << pos << endl;
    shotFile.seekg(pos);
    cout << "The value at coordinates " << x << "," << y << " is " << shotFile.get() << endl;
    shotValue = shotFile.get();
    //shotFile.get(shotValue);
    cout << "shotValue = " << shotValue << endl;

    //If the shot is a miss, return -1
    if (shotValue != 'C' || 'B' || 'R' || 'S'|| 'D'){
        cout << "Miss!\n";
        return -1;
    }

    /*Determine if shot is a hit, if so, return 1*/
    if (shotValue == 'C'){
        cout << "Hit! You hit a Carrier.\n";
        return 1;
    } else if (shotValue == 'B'){
        cout << "Hit! You hit a Battleship.\n";
        return 1;
    } else if (shotValue == 'R'){
        cout << "Hit! You hit a cRuiser.\n";
        return 1;
    } else if (shotValue == 'S'){
        cout << "Hit! You hit a Submarine.\n";
        return 1;
    } else if (shotValue == 'D'){
        cout << "Hit! You hit a Destroyer.\n";
        return 1;
    }
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

    /*
    string fname;

    if (player == 1){
        fname = "player_1.json";
    }
    else if (player == 2){
        fname = "player_2.json";
    }

    // remove any old serialization files
    remove(fname.c_str());

    // create an integer array
    vector< int > array1(2);

    // set some value and print
    array1[1] = 1;
    printf("array1[0] = %d, array1[1] = %d\n", array1[0], array1[1]);

    // serialize the array
    ofstream array_ofp(fname); // create an output file stream
    cereal::JSONOutputArchive write_archive(array_ofp); // initialize an archive on the file
    write_archive(cereal::make_nvp("array", array1)); // serialize the data giving it a name
    write_archive.finishNode(); // wait for the writing process to finish
    array_ofp.close(); // close the file


    // create a two dimensional array for deserialization
    vector< int > array2(2);

    // deserialize the array
    ifstream array_ifp(fname); // create an input file stream
    cereal::JSONInputArchive read_archive(array_ifp); // initialize an archive on the file
    read_archive(array2); // deserialize the array
    array_ifp.close(); // close the file

    // print the result of deserialization
    printf("array2[0] = %d, array2[1] = %d\n", array2[0], array2[1]);
    */
    return NO_SHOT_FILE;
}