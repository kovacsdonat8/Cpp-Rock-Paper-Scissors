#include "rules.h"
#include "player.h"
#include "options.h"
#include <iostream>
#include <ctime>

//#define TEST_MODE
#ifdef TEST_MODE
#include <cstring>


#define TEST(condition) \
    if(condition){ \
        std::cout << "OK" << std::endl; \
    } \
    else { \
        std::cout << "ERROR checking " << #condition << " in line " << __LINE__ << std::endl; \
    }

void Test(){
    //Rules test
    RPS rps;
    RPSLS rpsls;
    TEST(rps.NumberofShapes() == 3);
    TEST(rpsls.NumberofShapes() == 5);
    TEST(strcmp(rps.GetShapeName(1), "Rock") == 0);
    TEST(strcmp(rpsls.GetShapeName(5), "Spock") == 0);
    TEST(rps.Result(1, 1) == 0);
    TEST(rps.Result(1, 3) == 1);
    TEST(rpsls.Result(5, 4) == -1);
    TEST(rps.WhoBeats(1) == 2);
    TEST(strcmp(rps.GetRuleName(), "Rock-Paper-Scissors") == 0);
    TEST(strcmp(rpsls.GetRuleName(), "Rock-Paper-Scissors-Lizard-Spock") == 0);

    //App test
    App app;
    TEST(app.GetNumberOfPlayers() == 0);


    //Player test
    //Human human;
    //human.GetNextShape(rps);

    //Random test
    RandomStrat random;
    int rand1 = random.GetNextShape(rps);
    std::cout << rand1 << std::endl;
    int rand2 = random.GetNextShape(rpsls);
    std::cout << rand2 << std::endl;


}
#endif //TEST_MODE


int main(){
#ifdef TEST_MODE
    Test();
#else
    srand(time(NULL));
    App app;
    app.CreateGame();
    app.MainMenu();
#endif //TEST_MODE
}