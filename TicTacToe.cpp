#include <iostream>
using namespace std;

int main() 
{
    int menuChoice = 0; 
    
    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Play Tic-Tac-Toe\n";
        cout << "2. Rules\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> menuChoice)) 
        {
            cin.clear();             
            cin.ignore(10000, '\n'); 
            menuChoice = 0;          
        }
        
        if (menuChoice == 1) 
        {
            char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
            int choice = 0;
            char player = 'X';
            int moves = 0;
            bool win = false;
            
            while (win == false && moves < 9) 
            {
                cout << "\n===== TIC TAC TOE GAME =====\n";
                cout << "Player 1 = X\nPlayer 2 = O\n\n";
                
                for (int i = 0; i < 3; i++) 
                {
                    cout << " ";
                    for (int j = 0; j < 3; j++) 
                    {
                        cout << board[i][j];
                        if (j < 2) cout << " | ";
                    }
                    cout << "\n";
                    if (i < 2) cout << "---|---|---\n";
                }
                cout << "\n";
                
                cout << "Player " << player << ", enter box number: ";
                
                if (!(cin >> choice)) 
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    choice = 0; 
                }
                
                int row = (choice - 1) / 3;
                int col = (choice - 1) % 3;
                
                if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') 
                {
                    board[row][col] = player;
                    moves++;
                    
                    for (int i = 0; i < 3; i++) 
                    {
                        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) win = true; 
                        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) win = true; 
                    }
                    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) win = true;     
                    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) win = true;     
                    
                    if (win == false) 
                    {
                        if (player == 'X') player = 'O';
                        else player = 'X';
                    }
                } 
                else 
                {
                    cout << "Invalid move! Box already filled, wrong number, or bad input.\n";
                }
            }
            
            cout << "\nFinal Board:\n";
            for (int i = 0; i < 3; i++) 
            {
                cout << " ";
                for (int j = 0; j < 3; j++) 
                {
                    cout << board[i][j];
                    if (j < 2) cout << " | ";
                }
                cout << "\n";
                if (i < 2) cout << "---|---|---\n";
            }
            cout << "\n";
            
            if (win == true) 
                cout << "Player " << player << " wins the game!\n";
            else 
                cout << "Game is a draw!\n";
                
        } 
        else if (menuChoice == 2) 
        {
            cout << "\n--- GAME RULES ---\n";
            cout << "1. The grid is 3x3.\n";
            cout << "2. Player 1 uses 'X' and Player 2 uses 'O'.\n";
            cout << "3. The first to align 3 marks horizontally, vertically, or diagonally wins.\n";
            cout << "4. You cannot overwrite an already filled box.\n";
            cout << "5. If all 9 boxes are filled and no one wins, it is a draw.\n";
        } 
        else if (menuChoice != 3) 
        {
            cout << "Invalid menu choice. Please select 1, 2, or 3.\n";
        }
        
    } while (menuChoice != 3);
    
    cout << "Exiting game...\n";
    return 0;
}