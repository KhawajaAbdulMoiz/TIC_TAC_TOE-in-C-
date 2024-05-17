#include <iostream>
#include <string>
using namespace std;

char grid[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
string player1_name, player2_name; 
string player_name; 

// Display instructions
void instruction() {
    cout << "\n======> TIC TAC TOE <======\n\n";
    cout << "Instructions for Playing Tic Tac Toe Game:\n\n";
    cout << "This will be our Tic Tac Toe Game Board:\n\n";
    cout << " 1 | 2 | 3 \n";
    cout << "---|---|---\n";
    cout << " 4 | 5 | 6 \n";
    cout << "---|---|---\n";
    cout << " 7 | 8 | 9 \n\n";
    cout << "Instructions:\n";
    cout << "1. Insert the spot number (1-9) to put your sign\n";
    cout << "2. You must fill all 9 spots to get the result\n";
    cout << "3. Player 1 will go first\n\n";
}

// Display the board
void board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Take player names as input
void input_names() {
    cout << "Enter Player 1's name: ";
    cin >> player1_name;
    cout << "Enter Player 2's name: ";
    cin >> player2_name;
    player_name = player1_name; 
}

// Take slot input
bool input() {
    int position;
    cout << player_name << ", please enter a number between 1 to 9: ";
    cin >> position;
    if (position < 1 || position > 9) {
        cout << "Invalid input. Please enter a number between 1 to 9." << endl;
        return false;
    }
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    if (grid[row][col] == 'X' || grid[row][col] == 'O') {
        cout << "Spot blocked. Please choose another spot." << endl;
        return false;
    }
    grid[row][col] = (player_name == player1_name) ? 'X' : 'O'; // Set the player's sign
    return true;
}

// Change the current player
void change_player() {
    player_name = (player_name == player1_name) ? player2_name : player1_name;
}

// Check winning conditions
char win() {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) return grid[i][0];
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) return grid[0][i];
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) return grid[0][0];
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) return grid[0][2];
    return '/';
}

// Check for a draw condition
bool full_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] != 'X' && grid[i][j] != 'O') return false;
        }
    }
    return true;
}

int main() {
    instruction();
    input_names(); 
    system("cls");
    board();
    while (true) {
        if (!input()) continue; 
        board();
        char result = win(); 
        if (result=='X' || result=='O') {
            cout << "Congrats " << ((result == 'X') ? player1_name : player2_name) << ", You WON!!" << endl;
            break;
        } else if (full_board()) {
            cout << "It's a tie...!" << endl;
            break;
        }
        change_player();
    }
}
