#include "options.h"


//App
void App::PrintOptions(Player &p1, Player &p2) {
    int options;
    do {
        std::cout   << "\n1. Game Type: " << actualGame->GetActualRule().GetRuleName()
                    << "\n2. Game Mode: " << actualGame->GetModeName()
                    << "\n3. Game Length: " << gameLength;
        if(actualGame->TwoPlayermode()) {
            std::cout << "\n4. Player 1 Name: " << p1.GetPlayerName()
                      << "\n5. Player 1 Type: " << actualGame->GetPlayer1()->GetStrategyName()
                      << "\n6. Player 2 Name: " << p2.GetPlayerName()
                      << "\n7. Player 2 Type: " << actualGame->GetPlayer2()->GetStrategyName();
        }
        std::cout << "\n0. Main Menu\n";
        std::cin >> options;
        switch (options) {
            case 1:
                int rule;
                std::cout << "Choose the Game Type (";
                for (int i = 0; i < numberOfRules; i++){
                    std::cout << i << " = " << rules[i]->GetRuleName();
                    if (i < numberOfRules - 1){
                        std::cout << ", ";
                    }
                }
                std::cout << "): ";
                std::cin >> rule;
                if (rule < 0 || rule >= numberOfRules){
                    std::cout << "Invalid input!" << std::endl;
                }
                else{
                    actualGame->SetActualRule(rules[rule]);
                }
                break;
            case 2:
                int mode;
                std::cout << "Choose the Game Mode (";
                for (int i = 0; i < numberOfGames; i++){
                    std::cout << i << " = " << games[i]->GetModeName();
                    if (i < numberOfGames - 1){
                        std::cout << ", ";
                    }
                }
                std::cout << "): ";
                std::cin >> mode;
                if (mode < 0 || mode >= numberOfGames){
                    std::cout << "Invalid input!" << std::endl;
                }
                else{
                    actualGame = games[mode];
                }
                break;
            case 3:
                int len;
                std::cout << "Set the Game Length (1 - 50): ";
                std::cin >> len;
                if (len < 1 || len > 50){
                    std::cout << "Invalid input!" << std::endl;
                }
                else {
                    gameLength = len;
                }
                break;
            case 4:
                if (actualGame->TwoPlayermode()) {
                    char n1[MAX_NAME_LEN];
                    std::cout << "Enter the name: ";
                    std::cin >> n1;
                    p1.SetPlayerName(n1);
                }
                break;
            case 5:
                if (actualGame->TwoPlayermode()) {
                    int type1 = 0;
                    std::cout << "Choose the type (";
                    for (int i = 0; i < numberOfPlayers; i++){
                        std::cout << i << " = " << players[i]->GetStrategyName();
                        if (i < numberOfPlayers - 1){
                            std::cout << ", ";
                        }
                    }
                    std::cout << "): ";
                    std::cin >> type1;
                    if (type1 < 0 || type1 >= numberOfPlayers){
                        std::cout << "Invalid input!" << std::endl;
                    }
                    else{
                        actualGame->SetPlayer1(players[type1]);
                    }
                }
                break;
            case 6:
                if (actualGame->TwoPlayermode()) {
                    char n2[MAX_NAME_LEN];
                    std::cout << "Enter the name: ";
                    std::cin >> n2;
                    p2.SetPlayerName(n2);
                }
                break;
            case 7:
                if (actualGame->TwoPlayermode()) {
                    int type2 = 2;
                    std::cout << "Choose the type (";
                    for (int i = 0; i < numberOfPlayers; i++){
                        std::cout << i << " = " << players[i]->GetStrategyName();
                        if (i < numberOfPlayers - 1){
                            std::cout << ", ";
                        }
                    }
                    std::cout << "): ";
                    std::cin >> type2;
                    std::cin.sync();
                    if (type2 < 0 || type2 >= numberOfPlayers){
                        std::cout << "Invalid input!" << std::endl;
                    }
                    else{
                        actualGame->SetPlayer2(players[type2]);
                    }
                }
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    }while(options != 0);
}

void App::PrintRules(Rules &r){
    std::cout << "Rock paper scissors is a hand game played by two people, in which each player simultaneously forms one of "
    << r.NumberofShapes() << " shapes (";
    for (int i = 0; i < r.NumberofShapes(); i++){
        if (i < r.NumberofShapes() - 1){
            std::cout << r.GetShapeName(i) << ", ";
        }
        else{
        std::cout << r.GetShapeName(i);
        }
    }
    std::cout << "). The objective of the game is to choose a shape that defeats the shape chosen by the other player. ";
    if(r.NumberofShapes() == 3){
        std::cout << "Rock crushes scissors, scissors cuts paper and paper covers rock. ";
    }
    else{
        std::cout << "Rock crushes scissors and lizard, scissors cuts paper and decapitates lizard,"
                     " paper covers rock and disproves spock, lizard poisons spock and eats paper "
                     "and spock smashes scissors and vaporizes rock. ";
    }
    std::cout << "The game ends when a player achieves the predetermined number of victories." << std::endl;
}


void App::AddPlayer(Player *p){
    players[numberOfPlayers] = p;
    numberOfPlayers++;
}

void App::AddRule(Rules *r){
    rules[numberOfRules] = r;
    numberOfRules++;
}

void App::AddGame(Game *g){
    games[numberOfGames] = g;
    numberOfGames++;
}

void App::CreateGame(){
    Player *human = new Human;
    Player *clever = new CleverStrat;
    Player *copy = new CopyStrat;
    Player *random = new RandomStrat;
    Player *pred = new PredictiveStrat;

    AddPlayer(human);
    AddPlayer(clever);
    AddPlayer(copy);
    AddPlayer(random);
    AddPlayer(pred);

    Rules *rps = new RPS;
    Rules *rpsls = new RPSLS;

    AddRule(rps);
    AddRule(rpsls);

    Game *sbs = new SBS(this, human, random);
    Game *sim = new Simulation(this, copy, clever);
    Game *tour = new Tournament(this);

    AddGame(sbs);
    AddGame(sim);
    AddGame(tour);

    actualGame = games[0];
    sbs->SetActualRule(rps);
    sim->SetActualRule(rps);
    tour->SetActualRule(rps);
}

void App::MainMenu(){
    int menu;
    do {
        std::cout << "\n1. Play\n" << "2. Options\n" << "3. Rules\n" << "0. Exit\n";
        std::cin >> menu;
        switch(menu){
            case 1:
                actualGame->Play();
                actualGame->PrintResults();
                break;
            case 2:
                PrintOptions(*players[0], *players[3]);
                break;
            case 3:
                PrintRules(actualGame->GetActualRule());
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    } while(menu != 0);
}
