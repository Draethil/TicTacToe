#include <iostream>
#include <list>
using namespace std;

void showPlayground() {
    std:cout << "This is your Playground. Type (0-8) to set your mark." << endl;
    // Shows Board and Number-Index
    std::cout << "-------------" << endl;
    std::cout << "| 0 | 1 | 2 |" << endl << "| 3 | 4 | 5 |" << endl << "| 6 | 7 | 8 |" << endl;
    std::cout << "-------------" << endl;
}

void updatePlayground(string b[]){ // b[] == Active Board

    std::cout << "-------------" << endl;
    for (int i = 0; i < 9; i++) {
        std::cout << "| " << b[i] << " ";
        if ((i + 1) % 3 == 0) { // Formatting the Board
            std::cout << "|"<< endl;
        }
    }
    std::cout << "-------------" << endl;
}

bool firstMove(){
    srand(time(0));
    return rand() % 2;
}

int playerMove(string b[]){
    int playerInput;
    bool validInput = false;

    std::cout << "Players choose your field (0-8): ";
    std::cin >> playerInput;

    while(!validInput){

        if(playerInput >= 0 && playerInput <= 8){ // Valid Number

            if(b[playerInput] == " ") { // Board Space already taken by Player or Computer
                validInput = true;
            }
            else {
                std::cout << "You Input was incorrect. Try again!" << endl;
                std::cout << "Players choose your field (0-8): ";
                std::cin >> playerInput;
            }
        }
        else {
            std::cout << "You Input was incorrect. Try again!" << endl;
            std::cout << "Players choose your field (0-8): ";
            std::cin >> playerInput;
        }
    }
    return playerInput;
}

bool checkWin(string mark, string b[]){

    // Checking Rows
    if(b[0] == mark && b[1] == mark && b[2] == mark) {return true;}
    if(b[3] == mark && b[4] == mark && b[5] == mark) {return true;}
    if(b[6] == mark && b[7] == mark && b[8] == mark) {return true;}

    // Checking Columns
    if(b[0] == mark && b[3] == mark && b[6] == mark) {return true;}
    if(b[1] == mark && b[4] == mark && b[7] == mark) {return true;}
    if(b[2] == mark && b[5] == mark && b[8] == mark) {return true;}

    // Checking Diagonales
    if(b[0] == mark && b[4] == mark && b[8] == mark) {return true;}
    if(b[6] == mark && b[4] == mark && b[2] == mark) {return true;}

    return false; // If no one won
}

void startGame(){
    showPlayground(); // Showing the players, how the board looks like
    string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "}; // Active Board

    bool playerTurn = firstMove(); // If true, player goes first
    bool winner = false; // Is there a winner?
    int turn = 0; // 9 turns are possible -> 10th it's a draw!

    // Start of the Game
    std::cout << "Player 'X' and Computer 'O'" << endl;
    updatePlayground(board);

    while(!winner) {
    
        if(playerTurn) {
            int playerMark = playerMove(board);
            board[playerMark] = "X";
            updatePlayground(board);

            if(checkWin("X", board)) { // Send Message if Player won!
                std::cout << "Player won! Congrats!" << endl;
                winner = true; // End While Loop | End Game
            }
            else { // Computer's Turn now
                playerTurn = false;
            }
            turn++;
        } 
        else { // Computer's Turn
            int computerGuess;
            srand(time(0));
            bool computerGuessValid = false;

            while(!computerGuessValid) { // Random numbers will be generated until it's a vaild guess
                
                computerGuess = rand() % 9;
                if(board[computerGuess] == " "){
                    computerGuessValid = true;
                }
            }
            board[computerGuess] = "O"; // The Computer sets his mark
            std::cout << "Computer chooses Field " << computerGuess << endl;

            updatePlayground(board);

            if(checkWin("O", board)) { // Send Message if Computer won!
                std::cout << "Computer won! Congrats!" << endl;
                winner = true; // End While Loop | End Game
            }
            else { // Player's Turn now
                playerTurn = true;
            }
            turn++;
        }

        // Check if Draw
        if(turn == 9) {
            std::cout << "It's a Draw! Good luck next time!" << endl;
            winner = true; // There is no winner, but it ends while-loop
        }
    }

}

int main(){
    startGame();
    return 0;
}