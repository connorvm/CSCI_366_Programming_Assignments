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

#include <math.h>
#include "BitArray2D.hpp"

BitArray2D::BitArray2D(unsigned int rows, unsigned int columns) {
    /**
    * Sets up the array to store rows * columns bits
    * @param rows - number of rows
    * @param columns - number of columns
    */
    char *array;
    int num_bits;
    int num_chars;
    int mod_check;

    cout << "---------------------------------------\n";
    num_bits = rows * columns;
    cout << "num_bits = " << num_bits << endl;
    num_chars = num_bits/8;
    cout << "num_chars = " << num_chars << endl;
    mod_check = num_bits%8;
    cout << "mod_check = " << mod_check << endl;

    if (num_bits == 0){
        throw BitArray2DException("0 Rows and 0 Columns. No array to make.");
    } else if (mod_check == 0) {
        //num_chars is the number needed
        cout << "mod_check = 0\n";
        cout << "num_chars = " << num_chars << endl;
        *array = array[num_chars];
        cout << "---------------------------------------\n";
    } else if (mod_check > 0){
        num_chars += 1; //need to add one more char
        cout << "mod_check > 0\n";
        cout << "num_chars = " << num_chars << endl;
       *array = array[num_chars];
        cout << "---------------------------------------\n";
    }


}


BitArray2D::~BitArray2D() {

}


bool BitArray2D::get(unsigned int row, unsigned int column){
    /**
    * Get bit at row and column
    * @param row
    * @param column
    * @return bit at row and column as bool
    */
   // check array bounds
   //int bounds = ;

   // get the element
   return get_bit_elem(array, columns, row, column);
}



void BitArray2D::set(unsigned int row, unsigned int column){
   // check array bounds

   // set the element
   set_bit_elem(array, columns, row, column);
}
