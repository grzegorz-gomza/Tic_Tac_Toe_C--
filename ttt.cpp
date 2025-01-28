#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Function to initialize the board
std::vector<std::vector<char>> initialize_board(int size) {
    std::vector<std::vector<char>> board(size, std::vector<char>(size, ' '));
    return board;
}

// Function to display the board
void display_board(const std::vector<std::vector<char>>& board) {
    int size = board.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << board[i][j];
            if (j < size - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < size - 1) {
            for (int j = 0; j < size; ++j) {
                std::cout << "---";
                if (j < size - 1) std::cout << "+";
            }
            std::cout << std::endl;
        }
    }
}

// Function to check for a winner
bool check_winner(const std::vector<std::vector<char>>& board, char player) {
    int size = board.size();

    // Check rows and columns
    for (int i = 0; i < size; ++i) {
        bool row_win = true;
        bool col_win = true;
        for (int j = 0; j < size; ++j) {
            if (board[i][j] != player) row_win = false;
            if (board[j][i] != player) col_win = false;
        }
        if (row_win || col_win) return true;
    }

    // Check diagonals
    bool main_diag_win = true;
    bool anti_diag_win = true;
    for (int i = 0; i < size; ++i) {
        if (board[i][i] != player) main_diag_win = false;
        if (board[i][size - i - 1] != player) anti_diag_win = false;
    }
    return main_diag_win || anti_diag_win;
}

// Check if the board is full (i.e., a draw)
bool is_draw(const std::vector<std::vector<char>>& board) {
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

// Get a valid move from the player
int get_valid_move(const std::vector<std::vector<char>>& board) {
    int move;
    while (true) {
        std::cout << "Enter your move (1-" << board.size() * board.size() << "): ";
        std::cin >> move;

        if (std::cin.fail() || move < 1 || move > board.size() * board.size()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a number within the valid range." << std::endl;
            continue;
        }

        int row = (move - 1) / board.size();
        int col = (move - 1) % board.size();

        if (board[row][col] == ' ') {
            return move;
        } else {
            std::cout << "This position is already taken, try again." << std::endl;
        }
    }
}

// Convert a move to board coordinates
std::pair<int, int> get_coordinates(int move, int size) {
    return std::make_pair((move - 1) / size, (move - 1) % size);
}

void tictactoe_game() {
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    int size;
    while (true) {
        std::cout << "Enter the size of the board (3-10): ";
        std::cin >> size;

        if (size >= 3 && size <= 10) break;

        std::cout << "Invalid input. The size must be between 3 and 10." << std::endl;
    }

    std::vector<std::vector<char>> board = initialize_board(size);

    char player_A = 'X';
    char player_B = 'O';
    int turn = 0;

    while (true) {
        display_board(board);
        std::cout << "Player " << (turn % 2 == 0 ? 'A' : 'B') << " (" << (turn % 2 == 0 ? player_A : player_B) << ")'s turn:" << std::endl;

        int move = get_valid_move(board);
        std::pair<int, int> coordinates = get_coordinates(move, size); // Old-style access to pair
        int row = coordinates.first; // Access the row manually
        int col = coordinates.second; // Access the column manually
        board[row][col] = (turn % 2 == 0 ? player_A : player_B);

        if (check_winner(board, board[row][col])) {
            display_board(board);
            std::cout << "Player " << (turn % 2 == 0 ? 'A' : 'B') << " wins! Congratulations!" << std::endl;
            break;
        }

        if (is_draw(board)) {
            display_board(board);
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        turn++;
    }
}

// Main Function
int main() {
    srand(time(0));
    tictactoe_game();
    return 0;
}
