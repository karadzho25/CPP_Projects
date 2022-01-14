#include <iostream>
#include <ctime>

void PrintIntro(int Level){

    std::cout << "Puny human do you wish to proceed to door number " << Level << " ?" << "\n";
    // std::cout << std::endl;
    std::cout << "If so you must first solve my riddle!" << std::endl;

}

bool PlayGame(int Level){

    PrintIntro(Level);

    int CodeA = rand()%Level + Level;
    int CodeB = rand()%Level + Level;
    int CodeC = rand()%Level + Level;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProd = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers to be guessed!" << std::endl;

    std::cout << "+ The numbers add up to: " << CodeSum << std::endl;
    std::cout << "+ The numbers multiply to give: " << CodeProd << std::endl;


    int PlayerGuessA;
    int PlayerGuessB;
    int PlayerGuessC;

    std::cin >> PlayerGuessA;
    std::cin >> PlayerGuessB;
    std::cin >> PlayerGuessC;

    int GuessSum = PlayerGuessC + PlayerGuessA + PlayerGuessB;
    int GuessProd = PlayerGuessB * PlayerGuessA * PlayerGuessC;

    //std::cout << "You entered: " << PlayerGuessA << " " << PlayerGuessB << " " << PlayerGuessC << std::endl;

    if (GuessSum == CodeSum && GuessProd == CodeProd){
        std::cout << "You may pass to the next door!" << std::endl;
        return true;
    } else {
        std::cout << "You guessed wrong but you have another chance!" << std::endl << std::endl; 
        return false;
    }

    return true;
}

int main() {    
   
    srand(time(NULL));
    
    int LevelDifficulty = 1;
    const int MaxLevelDifficulty = 5;

    while(LevelDifficulty <= MaxLevelDifficulty){
       bool bLevelComplete = PlayGame(LevelDifficulty);
       std::cin.clear();
       std::cin.ignore();

       if (bLevelComplete){
           //increase difficulty
           ++LevelDifficulty;
       }
       
   }
    
    std::cout << "Congratulations you've exited the labirinth!" << std::endl; 

    return 0;   

}