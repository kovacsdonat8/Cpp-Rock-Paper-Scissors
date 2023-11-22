#include "game.h"
#include "options.h"
#include <iostream>

#define MAX_ROUND_NUM 100

//Game
void Game::PrintResults() {
    std::cout << "\n";
    if (winp1 > winp2){
        std::cout << player1->GetPlayerName() << " won!" << std::endl;
    }
    else if (winp1 == winp2){
        std::cout << "Draw!" << std::endl;
    }
    else {
        std::cout << player2->GetPlayerName() << " won!" << std::endl;
    }
    std::cout << "\nRESULTS:" << std::endl;
    std::cout << player1->GetPlayerName() << "'s wins = " << winp1 << std::endl;
    std::cout << player2->GetPlayerName() << "'s wins = " << winp2 << std::endl;
    std::cout << "Draws = " << draw << std::endl;
    std::cout << "Rounds = " << winp1 + winp2 + draw << std::endl;
}

void Game::Simulate() {
    player1->StartGame(this);
    player2->StartGame(this);
    int round = 1;
    winp1 = 0;
    winp2 = 0;
    draw = 0;
    while(!IsGameWon(round, winp1, winp2)){
        if (Interactive()){
            std::cin.get();
        }
        if (TwoPlayermode()) {
            std::cout << "\nROUND " << round << std::endl;
        }
        int shape1 = player1->GetNextShape(*actualRule);
        int shape2 = player2->GetNextShape(*actualRule);
        player1->OpponentsShape(shape2);
        player2->OpponentsShape(shape1);
        if(shape1 == 0 || shape2 == 0){
            break;
        }
        if (TwoPlayermode()) {
            std::cout << player1->GetPlayerName() << "'s shape: " << actualRule->GetShapeName(shape1) << std::endl;
            std::cout << player2->GetPlayerName() << "'s shape: " << actualRule->GetShapeName(shape2) << std::endl;
        }
        if (actualRule->Result(shape1, shape2) == 0) {
            if (TwoPlayermode()) {
                std::cout << "DRAW" << std::endl;
            }
            draw++;
        } else if (actualRule->Result(shape1, shape2) == 1) {
            if (TwoPlayermode()) {
                std::cout << "WINNER: " << player1->GetPlayerName() << std::endl;
            }
            winp1++;
        } else {
            if (TwoPlayermode()) {
                std::cout << "WINNER: " << player2->GetPlayerName() << std::endl;
            }
            winp2++;
        }
        round++;
    }
    player1->AddPoints(winp1 > winp2? 1 : 0);
    player2->AddPoints(winp2 > winp1? 1 : 0);
}

bool Game::IsGameWon(int round, int win1, int win2) {
    if(win1 >= app->GetGameLength()){
        return true;
    }
    else if(win2 >= app->GetGameLength()){
        return true;
    }
    else if(round >= MAX_ROUND_NUM) {
        return true;
    }
    return false;
}

void Game::Play() {
    Simulate();
}

//Tournament
void Tournament::Play() {
    for (int i = 1; i < app->GetNumberOfPlayers() - 1; i++){
        for (int j = i + 1; j < app->GetNumberOfPlayers(); j++){
            player1 = app->GetPlayer(i);
            player2 = app->GetPlayer(j);
            Simulate();
        }
    }
}

void Tournament::PrintResults() {
    std::cout << "\nTOURNAMENT RESULTS:" << std::endl;
    for (int i = 1; i < app->GetNumberOfPlayers(); i++){
        std::cout << app->GetPlayer(i)->GetPlayerName() << "'s wins = " << app->GetPlayer(i)->GetPoints() << std::endl;
    }
}