#include "Matrix2.hpp"

// void Matrix :: printMatrix(){
//     cout << "     ";
//     for(int i = 0 ; i < column ; i ++){
//         cout << "  " << array_of_character[i] << "   ";
//     }
//     // Row initiation

//     cout << endl << "    ";
//     printMatrixLine();

//     for(int i = 0 ; i < row ; i++){
//         if(i+1 < 10){
//             cout << " " << 0 << i+1 << " ";
//             cout << "|";
//             for(int j = 0; j < column ; j++){
//                 try{
//                     GameObject temp = getElement(array_of_character[j] + to_string(0) +to_string(i+1));
//                     cout << " " << temp.getCode() << " |";
//                 } catch(exception &e) {
//                     cout << "     |";
//                 }
//             }
//             cout << endl << "    ";
//             printMatrixLine();
//         } else {
//             cout << " " << i+1 << " ";
//             cout << "|";
//             for(int j = 0; j < column ; j++){
//                 try{
//                     GameObject temp = getElement(array_of_character[j] + to_string(i+1));
//                     cout << " " << temp.getCode() << " |";
//                 } catch(exception &e) {
//                     cout << "     |";
//                 }
//             }
//             cout << endl << "    ";
//             printMatrixLine();
//         }
//     }
// }

// void Matrix :: printMatrixLine(){
//     bool first = true;
//     for(int i = 0 ; i < column + 1 ; i++){
//         if(first){
//             cout << "+";
//             first = false;
//         } else {
//             cout << "-----+";
//         }
//     }
//     cout << endl;
// }