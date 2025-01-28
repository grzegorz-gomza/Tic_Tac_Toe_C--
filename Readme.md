# Tic-Tac-Toe Game

Welcome to the **Tic-Tac-Toe Game**! This is a simple C++ implementation of the classic Tic-Tac-Toe game where two players can compete against each other on a customizable game board ranging in size from 3x3 to 10x10.

## Features

- **Dynamic Board Size:** Players can select a board size between 3 and 10 at the start of the game .
- **Two-Player Mode:** Play as Player A (X) or Player B (O) and take turns on the board .
- **Winner Detection:** Automatically detects winners by checking rows, columns, and diagonals .
- **Draw Condition:** Detects when the board is full without a winner, resulting in a draw .
- **Input Validation:** Ensures players input valid moves while handling incorrect or occupied inputs gracefully .
- **Interactive Display:** Shows the board state after every move with clear formatting for enhanced readability .

## How to Play

1. Run the program.
2. Enter the size of the board (between 3 and 10) at the prompt.
3. Players take turns choosing a position to play by entering the corresponding position number (e.g., 1-9 for a 3x3 board) .
4. The game ends when one player wins, or all positions are filled resulting in a draw.

## Code Overview

### Functional Highlights
- **Board Initialization:** Creates an empty board of the specified size .
- **Winner Check:** Implements checks for rows, columns, and diagonals to determine a winner .
- **Draw Detection:** Confirms whether all spaces on the board are filled .
- **Player Input Validation:** Ensures valid moves and provides user feedback for invalid inputs .
- **Game Loop:** Continuously updates the board, checks conditions, and alternates turns until the game concludes .

### Key Functions
- `initialize_board(int size)`: Creates an empty game board of the given size .
- `display_board(const std::vector<std::vector<char>>& board)`: Displays the current state of the board in a readable format .
- `check_winner(const std::vector<std::vector<char>>& board, char player)`: Checks if a player has won the game .
- `is_draw(const std::vector<std::vector<char>>& board)`: Determines if the game is a draw .
- `get_valid_move(const std::vector<std::vector<char>>& board)`: Prompts the user for valid moves and verifies them .
- `get_coordinates(int move, int size)`: Converts 1D user input into 2D board coordinates .
- `tictactoe_game()`: Main game loop that orchestrates the gameplay .

### Example Output
```
 X | O | X
---+---+---
 O | X |  
---+---+---
 X | O | O

Player A (X) wins! Congratulations!
```

## How to Compile and Run

### Compilation
1. Ensure you have a C++ compiler installed (e.g., `g++`).
2. Compile the code with the following command:
   ```bash
   g++ -o tictactoe tictactoe.cpp
   ```

### Execution
1. Run the compiled program:
   ```bash
   ./tictactoe
   ```

2. Follow the prompts to setup and play the game.

## Requirements

- **C++ Compiler:** Any C++11 or higher compliant compiler (e.g., `g++`).

## Future Enhancements

- Add support for a single-player mode with AI.
- Improve board visualization.
- Implement a graphical user interface (GUI).

## License

This project is open source and available under the [MIT License](https://opensource.org/licenses/MIT).

## Contribution

Feel free to fork this repository and create pull requests for enhancements or bug fixes. Suggestions are also welcome via issues.

---
**Enjoy the game, and may the best player win!**