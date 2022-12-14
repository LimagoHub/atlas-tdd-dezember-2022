//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once
#include "game.h"
#include "players/player.h"
#include "../IO/writer.h"
template<class BOARD, class MOVE>
class abstract_game :public game{

public:
    abstract_game(writer &writer) : writer_(writer) {}

    void addPlayer(player<BOARD,MOVE> *player){
        players.push_back(player);
    }

    void play() override {
        while ( !is_gameover())  execute_rounds();
    }

private:
    std::vector<player<BOARD,MOVE>  *> players;
    BOARD board;
    MOVE move;
    writer & writer_;
    player<BOARD,MOVE> *current_player;


    void setCurrentPlayer(player<BOARD,MOVE> *currentPlayer) {
        current_player = currentPlayer;
    }


    void execute_rounds() { // operation, command

        for(auto player: players)  prepare_and_execute_single_move(player);

    }

    void prepare_and_execute_single_move(player<BOARD,MOVE> *player) { // Integration, command
        setCurrentPlayer(player);
        execute_single_move();
    }
    void execute_single_move() { // Integration, command

        if(is_gameover()) return;
        prepare();
        execute_move();
        terminate_move();

    }

    void execute_move()  { // command, operation
        do {
            move = getCurrentPlayer()->do_turn(board);
        }
        while(players_move_is_invalid());
    }

    bool players_move_is_invalid() { // query
        if(is_move_valid()) return false;
        write("Ungueltiger Zug");
        return true;
    }

    void terminate_move() {
        update_board();
        write_game_over_message_if_game_is_over();
    }

    void write_game_over_message_if_game_is_over() { // Query
        if(is_gameover()) write( "Player " + getCurrentPlayer()->getName() + " hat verloren.");

    }
protected:

    void write(std::string message) {
        writer_.write(message);
    }

    player<BOARD,MOVE> *getCurrentPlayer() const {
        return current_player;
    }

    virtual void prepare() {
        // Ok
    }




    const std::vector<player<BOARD, MOVE> *> &getPlayers() const {
        return players;
    }


    BOARD getBoard() const {
        return board;
    }

    void setBoard(BOARD board) {
        abstract_game::board = board;
    }

    MOVE getMove() const {
        return move;
    }

    void setMove(MOVE move) {
        abstract_game::move = move;
    }


    virtual bool is_move_valid() const = 0;

    virtual void update_board() = 0;

    virtual bool is_gameover() const = 0;


};




