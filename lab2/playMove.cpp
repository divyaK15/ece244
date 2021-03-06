//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"
using namespace std; 

int code (GameState& game_state);
bool emptySpace (GameState& game_state);

void playMove(GameState& game_state) {
    bool playerTurn = game_state.get_turn();
    int row = game_state.get_selectedRow();
    int col = game_state.get_selectedColumn();
    int gameOver = game_state.get_gameOver();
    int code = game_state.get_winCode();
    bool valid = game_state.get_moveValid();
    int count=0;
    
        if(game_state.get_gameBoard(row,col)==Empty){
        game_state.set_moveValid(true);
    }
    else{ 
        game_state.set_moveValid(false);
    }
        
    if((game_state.get_turn() == true) && (game_state.get_moveValid()==true)){
        game_state.set_gameBoard(row,col,X);
        game_state.set_turn(false);
        
        //playerTurn = false; 
    }
    else if((game_state.get_turn() == false)&& (game_state.get_moveValid()== true)){
        game_state.set_gameBoard(row,col,O);
        game_state.set_turn(true);
        //playerTurn = true;
        }
    
    //right to left
    if((game_state.get_gameBoard(0,2)== game_state.get_gameBoard(1,1))&&(game_state.get_gameBoard(1,1)== game_state.get_gameBoard(2,0))&&(game_state.get_gameBoard(1,1)!=0)){
        game_state.set_winCode(8);
        game_state.set_gameOver(true);
    }
    //left to right
    else if((game_state.get_gameBoard(0,0)== game_state.get_gameBoard(1,1))&&(game_state.get_gameBoard(1,1)== game_state.get_gameBoard(2,2))&&(game_state.get_gameBoard(1,1)!=0)){
        game_state.set_winCode(7);
        game_state.set_gameOver(true);
    }
    //col 3
    else if((game_state.get_gameBoard(0,2)== game_state.get_gameBoard(1,2))&&(game_state.get_gameBoard(1,2)== game_state.get_gameBoard(2,2))&&(game_state.get_gameBoard(0,2)!=0)){
        game_state.set_winCode(6);
        game_state.set_gameOver(true);
    }
    //col 2
    else if((game_state.get_gameBoard(0,1)== game_state.get_gameBoard(1,1))&&(game_state.get_gameBoard(1,1)== game_state.get_gameBoard(2,1))&&(game_state.get_gameBoard(0,1)!=0)){
        game_state.set_winCode(5);
        game_state.set_gameOver(true);
    }
    //col 1
    else if((game_state.get_gameBoard(0,0)== game_state.get_gameBoard(1,0))&&(game_state.get_gameBoard(1,0)== game_state.get_gameBoard(2,0))&&(game_state.get_gameBoard(0,0)!=0)){
        game_state.set_winCode(4);
        game_state.set_gameOver(true);
    }
    //row 3
    else if((game_state.get_gameBoard(2,0)== game_state.get_gameBoard(2,1))&&(game_state.get_gameBoard(2,1)== game_state.get_gameBoard(2,2))&&(game_state.get_gameBoard(2,0)!=0)){
        game_state.set_winCode(3);
        game_state.set_gameOver(true);
    }
    //row 2
    else if((game_state.get_gameBoard(1,0)== game_state.get_gameBoard(1,1))&&(game_state.get_gameBoard(1,1)== game_state.get_gameBoard(1,2))&&(game_state.get_gameBoard(1,0)!=0)){
        game_state.set_winCode(2);
        game_state.set_gameOver(true);
    }
    //row 1
    else if((game_state.get_gameBoard(0,0)== game_state.get_gameBoard(0,1))&&(game_state.get_gameBoard(0,1)== game_state.get_gameBoard(0,2))&&(game_state.get_gameBoard(0,0)!=0)){
        game_state.set_winCode(1);
        game_state.set_gameOver(true);
    }
    else{
        game_state.set_winCode(0);//game is a draw or not over 
        game_state.set_gameOver(false);
    }
    
    
   
    
    
    
    
   /*//row 1
    if((game_state.get_gameBoard(0,0)== game_state.get_gameBoard(0,1))&&(game_state.get_gameBoard(0,1)== game_state.get_gameBoard(0,2))&&(game_state.get_gameBoard(0,0)!=0)){
        game_state.set_winCode(1);
        game_state.set_gameOver(true);
    }
    //row 2
    else if((game_state.get_gameBoard(1,0)== game_state.get_gameBoard(1,1))&&(game_state.get_gameBoard(1,1)== game_state.get_gameBoard(1,2))&&(game_state.get_gameBoard(1,0)!=0)){
        game_state.set_winCode(2);
        game_state.set_gameOver(true);
    }
    //row 3
    else if((game_state.get_gameBoard(2,0)== game_state.get_gameBoard(2,1))&&(game_state.get_gameBoard(2,1)== game_state.get_gameBoard(2,2))&&(game_state.get_gameBoard(2,0)!=0)){
        game_state.set_winCode(3);
        game_state.set_gameOver(true);
    }
    //col 1
    else if((game_state.get_gameBoard(0,0)== game_state.get_gameBoard(1,0))&&(game_state.get_gameBoard(1,0)== game_state.get_gameBoard(2,0))&&(game_state.get_gameBoard(0,0)!=0)){
        game_state.set_winCode(4);
        game_state.set_gameOver(true);
    }
    //col 2
    else if((game_state.get_gameBoard(0,1)== game_state.get_gameBoard(1,1))&&(game_state.get_gameBoard(1,1)== game_state.get_gameBoard(2,1))&&(game_state.get_gameBoard(0,1)!=0)){
        game_state.set_winCode(5);
        game_state.set_gameOver(true);
    }
    //col 3
    else if((game_state.get_gameBoard(0,2)== game_state.get_gameBoard(1,2))&&(game_state.get_gameBoard(1,2)== game_state.get_gameBoard(2,2))&&(game_state.get_gameBoard(0,2)!=0)){
        game_state.set_winCode(6);
        game_state.set_gameOver(true);
    }
    //left to right
    else if((game_state.get_gameBoard(0,0)== game_state.get_gameBoard(1,1))&&(game_state.get_gameBoard(1,1)== game_state.get_gameBoard(2,2))&&(game_state.get_gameBoard(1,1)!=0)){
        game_state.set_winCode(7);
        game_state.set_gameOver(true);
    }
    //right to left
    else if((game_state.get_gameBoard(0,2)== game_state.get_gameBoard(1,1))&&(game_state.get_gameBoard(1,1)== game_state.get_gameBoard(2,0))&&(game_state.get_gameBoard(1,1)!=0)){
        game_state.set_winCode(8);
        game_state.set_gameOver(true);
    }
    else{
        game_state.set_winCode(0);//game is a draw or not over 
        game_state.set_gameOver(false);
    }*/
    
    for(int i = 0; i<= boardSize-1; i++){
        for (int j = 0; j <= boardSize-1; j++){
            if(game_state.get_gameBoard(i,j)== Empty){
                count++;
            }
        }
    }
    if(count==0){
        game_state.set_gameOver(true);
    }
        
     
    
}

