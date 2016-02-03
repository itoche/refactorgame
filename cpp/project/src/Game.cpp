#include "Game.h"

Game::Game(const std::string& s):board(s) {
}

Game::Game(const std::string& s, int position, char player):board(s) {
	board[position] = player;
}

int Game::move(char player) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == '-') {
            Game game = play(i, player);
            if (game.winner() == player)
                return i;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (board[i] == '-')
            return i;
    }
    return -1;
}

Game Game::play(int i, char player) {
	return Game(board, i, player);
}

char Game::winner() {
    if (board[0] != '-'
            && board[0] == board[1]
            && board[1] == board[2])
        return board[0];
    if (board[3] != '-'
            && board[3] == board[4]
            && board[4] == board[5])
        return board[3];
    if (board[6] != '-'
            && board[6] == board[7]
            && board[7] == board[8])
        return board[6];
    return '-';

}
