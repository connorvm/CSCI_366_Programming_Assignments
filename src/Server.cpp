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


/**
 * Calculate the length of a file (helper function)
 *
 * @param file - the file whose length we want to query
 * @return length of the file in bytes
 */
int get_file_length(ifstream *file){
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

    this->p1_setup_board = scan_setup_board(p1_setup_board);
    this->p2_setup_board = scan_setup_board(p2_setup_board);
}


Server::~Server() {
}


BitArray2D *Server::scan_setup_board(string setup_board_name){
    /**
     * Sets up a BitArray2D pointer with bits filled in based on a setup_board_name
     * @param setup_board_name - the name of the setup board file
     * @return an internally allocated pointer to a BitArray2D object
     */

    BitArray2D *p1_setup_board = new BitArray2D(board_size, board_size);
    BitArray2D *p2_setup_board = new BitArray2D(board_size, board_size);
    ifstream p_in(setup_board_name);
    int value = 0;

    if (setup_board_name == "player_1.setup_board.txt"){
//        for (int i = 0; i < board_size*board_size; ++i) {
//            p_in.seekg(i, ios::beg);
//            value = p_in.get();
//            if (value == 67 || 66 || 82 || 83 || 68) {
//                if (i < 10) {
//                    p1_setup_board->set(0, i);
//                }
//                else if (i >= 10 && i < 20) {
//                    p1_setup_board->set(1, i);
//                }
//                else if (i >= 20 && i < 30) {
//                    p1_setup_board->set(2, i);
//                }
//                else if (i >= 30 && i < 40) {
//                    p1_setup_board->set(3, i);
//                }
//                else if (i >= 40 && i < 50) {
//                    p1_setup_board->set(4, i);
//                }
//                else if (i >= 50 && i < 60) {
//                    p1_setup_board->set(5, i);
//                }
//                else if (i >= 60 && i < 70) {
//                    p1_setup_board->set(6, i);
//                }
//                else if (i >= 70 && i < 80) {
//                    p1_setup_board->set(7, i);
//                }
//                else if (i >= 80 && i < 90) {
//                    p1_setup_board->set(8, i);
//                }
//                else if (i >= 90 && i < 100) {
//                    p1_setup_board->set(9, i);
//                }
//            }
//        }
        return p1_setup_board;
    } else if (setup_board_name == "player_2.setup_board.txt"){
//        for (int i = 0; i < board_size*board_size; ++i) {
//            p_in.seekg(i, ios::beg);
//            value = p_in.get();
//            if (value == 67 || 66 || 82 || 83 || 68) {
//                if (i < 10) {
//                    p2_setup_board->set(0, i);
//                }
//                else if (i >= 10 && i < 20) {
//                    p2_setup_board->set(1, i);
//                }
//                else if (i >= 20 && i < 30) {
//                    p2_setup_board->set(2, i);
//                }
//                else if (i >= 30 && i < 40) {
//                    p2_setup_board->set(3, i);
//                }
//                else if (i >= 40 && i < 50) {
//                    p2_setup_board->set(4, i);
//                }
//                else if (i >= 50 && i < 60) {
//                    p2_setup_board->set(5, i);
//                }
//                else if (i >= 60 && i < 70) {
//                    p2_setup_board->set(6, i);
//                }
//                else if (i >= 70 && i < 80) {
//                    p2_setup_board->set(7, i);
//                }
//                else if (i >= 80 && i < 90) {
//                    p2_setup_board->set(8, i);
//                }
//                else if (i >= 90 && i < 100) {
//                    p2_setup_board->set(9, i);
//                }
//            }
//        }
        return p2_setup_board;
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
    if (player < 1) {
        throw ServerException("Player number is low.");
    }
    if (player > 2) {
        throw ServerException("Player number is high.");
    }

    /*Check that shot coordinates are within bounds, if so, return 0*/
    //cout << "BOARD_SIZE = " << BOARD_SIZE << endl;
    //cout << "board_size = " << board_size << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    if (x >= BOARD_SIZE) {
        cout << "X coordinates is not within bounds" << endl;
        return 0;
    }
    if (y >= BOARD_SIZE) {
        cout << "Y coordinates is not within bounds" << endl;
        return 0;
    }

    string board_name;
    int shotValue;
    ifstream p_in(board_name);

    if (player == 1){
        board_name = "player_1.setup_board.txt";
    } else if (player == 2) {
        board_name = "player_2.setup_board.txt";;
    }

    int offset = x + y * (board_size + 1);
    p_in.seekg(offset, ios::beg);
    shotValue = p_in.get();

    /*Determine if shot is a miss, if so, return -1*/
    if (shotValue == 95) {
        /* ASCII -> Decimal:
         * C -> 67
         * B -> 66
         * R -> 82
         * S -> 83
         * D -> 68
         * _ -> 95 (water)
         */
        cout << "Miss\n";
        cout << "-----------------\n";
        return MISS;
    }

    switch (shotValue) {
        case 67: //C
            cout << "Hit! You hit a Carrier.\n";
            cout << "-----------------\n";
            return HIT;
        case 66: //B
            cout << "Hit! You hit a Battleship.\n";
            cout << "-----------------\n";
            return HIT;
        case 82: //R
            cout << "Hit! You hit a cRuiser.\n";
            cout << "-----------------\n";
            return HIT;
        case 83: //S
            cout << "Hit! You hit a Submarine.\n";
            cout << "-----------------\n";
            return HIT;
        case 68: //D
            cout << "Hit! You hit a Destroyer.\n";
            cout << "-----------------\n";
            return HIT;
        default:
            cout << "Miss.\n";
            cout << "-----------------\n";
            return MISS;
    }

    //------------------------------------------------------------------------------------------------------------------//
    //------------------------------------------------------------------------------------------------------------------//

    //------------------------------------------------------------------------------------------------------------------//

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
    int result;

    /*Check player number is within bounds*/
    if (player < 1){
        throw ServerException("Player number is low.");
    }
    if (player > 2){
        throw ServerException("Player number is high.");
    }

    string fname1;
    string fname2;
    if (player == 1){
        fname1 = "player_1.shot.json";
        fname2 = "player_1.result.json";
    }
    else if (player == 2){
        fname1 = "player_2.shot.json";
        fname2 = "player_2.result.json";
    }
    cout << "fname1 = " << fname1 << ", fname2 = " << fname2 << endl;


    // create a two values for deserialization
    int x;
    int y;

    //The if-statement below is to catch Max_In_Bounds test case exception
//    if (x < board_size || y < board_size) {
//        // deserialize the array
//        ifstream array_ifp1(fname1); // create an input file stream
//        cereal::JSONInputArchive read_archive(array_ifp1); // initialize an archive on the file
//        read_archive(x + 1, y + 1); // deserialize the array
//        array_ifp1.close(); // close the file
//        // print the result of deserialization
//        cout << "x = " << x << ", y = " << y << endl;
//        if (x == board_size && y == board_size){
//            result = OUT_OF_BOUNDS;
//        }
//    } else if (x >= board_size) {
//        // deserialize the array
//        ifstream array_ifp2(fname1); // create an input file stream
//        cereal::JSONInputArchive read_archive(array_ifp2); // initialize an archive on the file
//        read_archive(x, y); // deserialize the array
//        array_ifp2.close(); // close the file
//        // print the result of deserialization
//        cout << "x = " << x << ", y = " << y << endl;
//        if (x == board_size && y == board_size){
//            result = OUT_OF_BOUNDS;
//        }
//    }

    // deserialize the array
    ifstream array_ifp2(fname1); // create an input file stream
    cereal::JSONInputArchive read_archive(array_ifp2); // initialize an archive on the file
    read_archive(x, y); // deserialize the array
    array_ifp2.close(); // close the file
    // print the result of deserialization
    cout << "x = " << x << ", y = " << y << endl;

    //Evaluate the shot at the coordinates from player_#.shot.json
    cout << "Checking result.\n" << "x = " << x << " and y = " << y << endl;
    result = evaluate_shot(player, x, y);
    cout << "result = " << result << endl;

    /*Write result into player_#.result.json **/
    // remove any old serialization files
    remove(fname2.c_str());

    // serialize the array
    ofstream array_ofp(fname2); // create an output file stream
    cereal::JSONOutputArchive write_archive(array_ofp); // initialize an archive on the file
    write_archive(cereal::make_nvp("result", result)); // serialize the data giving it a name

    remove(fname1.c_str());
    return SHOT_FILE_PROCESSED;

    return NO_SHOT_FILE;
}