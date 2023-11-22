#ifndef PROG2_NHF_RPSLS_GAME_H
#define PROG2_NHF_RPSLS_GAME_H

#include "player.h"
#include "rules.h"
class App;

class Game{
protected:
    App *app;
    Player *player1;
    Player *player2;
    Rules *actualRule;
    int winp1;
    int winp2;
    int draw;
public:
    Game(App *a){
        app = a;
        player1 = NULL;
        player2 = NULL;
        actualRule = NULL;
        winp1 = 0;
        winp2 = 0;
        draw = 0;
    }
    virtual void Play();

    virtual void PrintResults();

    void Simulate();

    virtual bool Interactive() {return false;}

    virtual bool TwoPlayermode() {return true;}

    Rules &GetActualRule() {return *actualRule;}

    void SetActualRule(Rules *r) {actualRule = r;}

    void SetPlayer1(Player *p1) {player1 = p1;}

    Player *GetPlayer1() {return player1;}

    void SetPlayer2(Player *p2) {player2 = p2;}

    Player *GetPlayer2() {return player2;}

    virtual const char* GetModeName() = 0;

    bool IsGameWon(int round, int win1, int win2);

    virtual ~Game() {}
};

// Step-by-Step
class SBS : public Game{
public:
    SBS(App *a, Player *p1, Player *p2) : Game(a){
        player1 = p1;
        player2 = p2;
    }

    virtual bool Interactive() {return true;}

    virtual const char* GetModeName() {return "Step-by-Step";}
};

//Simulation
class Simulation : public Game{
public:
    Simulation(App *a, Player *p1, Player *p2) : Game(a){
        player1 = p1;
        player2 = p2;
    }

    virtual const char* GetModeName() {return "Simulation";}
};

//Tournament
class Tournament : public Game{
public:
    Tournament(App *a) : Game(a) {}

    virtual void Play();

    virtual bool TwoPlayermode() {return false;}

    virtual const char* GetModeName() {return "Tournament";}

    virtual void PrintResults();
};

#endif //PROG2_NHF_RPSLS_GAME_H
