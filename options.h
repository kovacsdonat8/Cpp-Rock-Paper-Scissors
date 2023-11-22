#ifndef PROG2_NHF_RPSLS_OPTIONS_H
#define PROG2_NHF_RPSLS_OPTIONS_H

#include <iostream>
#include "game.h"

#define MAX_NUM_PLAYERS 20
#define MAX_NUM_RULES 5
#define MAX_NUM_GAMES 5
#define DEFAULT_GAME_LEN 20


class App{
    int gameLength;
    Game *actualGame;
    Player *players[MAX_NUM_PLAYERS];
    Rules *rules[MAX_NUM_RULES];
    Game *games[MAX_NUM_GAMES];
    int numberOfPlayers;
    int numberOfRules;
    int numberOfGames;
public:
    App(){
        actualGame = NULL;
        numberOfPlayers = 0;
        numberOfRules = 0;
        numberOfGames = 0;
        gameLength = DEFAULT_GAME_LEN;
    }

    int GetGameLength() {return gameLength;}

    void AddPlayer(Player* p);

    void AddRule(Rules* r);

    void AddGame(Game* g);

    void CreateGame();

    void MainMenu();

    void PrintOptions(Player&, Player&);

    void PrintRules(Rules &);

    int GetNumberOfPlayers() {return numberOfPlayers;}

    Player *GetPlayer(int i) {return players[i];}

    ~App(){
        int i;
        for (i = 0; i < numberOfPlayers; i++){
            delete players[i];
        }
        for (i = 0; i < numberOfRules; i++){
            delete rules[i];
        }
        for (i = 0; i < numberOfGames; i++){
            delete games[i];
        }

    }
};


#endif //PROG2_NHF_RPSLS_OPTIONS_H
