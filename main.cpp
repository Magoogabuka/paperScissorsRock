#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;

/*
Rock set as rock;
paper set as paper;
scissors set as scissors;
*/

class Game{
    public:

        void playGame();
        char getChoice();
        int checkWin(string &player1, string &player2, string &playerOneName, string &playerTwoName);

        void waitForKeyPress();
        void clearScreen();
        bool playAgain();
        char menuScreen();
};

char Game::menuScreen()
{
    char choice;
    cout<<"Paper, scissors, rock...\n";
    sleep(1);
    cout<<"Brought to you by....\n\n";
    sleep(2);
    clearScreen();
    cout<<"-----Eva Terminal Games------\n\n";
    sleep(1);
    cout<<
    "   ######################\n"
    "   #                    #\n"
    "   #                    #\n"
    "   # P. to play game    #\n"
    "   # Q. to quit game    #\n"
    "   #                    #\n"
    "   #                    #\n"
    "   ######################\n";
    cout<<"\nEnter choice: ";
    cin>>choice;
    
    clearScreen();
    return choice;

}
    

void Game::playGame()
{
    string player1, player2;
    int keepPlaying;
    string playerOneChoice, playerTwoChoice;

    cout<<"Choose name for player 1: ";
    cin>>player1;
    cout<<"Choose name for player 2: ";
    cin>>player2;
    clearScreen();

    do { 
        cout<<"Player "<<player1<<" turn: ";
        cin>>playerOneChoice;
        clearScreen();
        waitForKeyPress();
        cout<<"Player "<<player2<<" turn: ";
        cin>>playerTwoChoice; 
        clearScreen();
        waitForKeyPress();

        cout<<"scissors.....\n";
        sleep(2);// need to #include unistd.h, unit is in SECONDS; 
        cout<<"paper.....\n";
        sleep(2);
        cout<<"rock.....\n";
        
        
        keepPlaying = checkWin(playerOneChoice, playerTwoChoice, player1, player2);

    } while(keepPlaying == -1);
}


int Game::checkWin(string &player1, string &player2, string &playerOneName, string &playerTwoName)
{
    char checkPlayerOne;

    if(player1 == "rock")
    {
        checkPlayerOne = 'r';
        switch(checkPlayerOne)
        {
            case 'r':
                if(player2 == "scissors")
                {
                cout<<"Player "<<playerOneName<<" used rock and Player "<<playerTwoName<<" used scissors! Player "<<playerOneName<<" wins!"<<endl;
                return 1; 
                }
                else if(player2 == "paper")
                {
                    cout<<"Player "<<playerOneName<<" used rock and Player "<<playerTwoName<<" used paper! Player "<<playerTwoName<<" wins!"<<endl;
                    return 1;
                }
                else if(player2 == "rock")
                {
                    cout<<"Player "<<playerTwoName<<" and Player "<<playerOneName<<" used rock! No-one wins!"<<endl;
                    return -1;
                }
                break;
       }
    } else if(player1 == "scissors") {

        checkPlayerOne = 's';
        switch(checkPlayerOne)
        {
            case 's':
            if(player2 == "scissors")
                {
                cout<<"Player "<<playerOneName<<" and Player "<<playerTwoName<<" used scissors! No-one wins!"<<endl;
                return -1; 
                }
                else if(player2 == "paper")
                {
                    cout<<"Player "<<playerOneName<<" used scissors and Player "<<playerTwoName<<" used paper! Player "<<playerOneName<<" wins!"<<endl;
                    return 1;
                }
                else if(player2 == "rock")
                {
                    cout<<"Player "<<playerOneName<<" used scissors and Player "<<playerTwoName<<" used rock! Player "<<playerTwoName<<" wins!"<<endl;
                    return 1;
                }
                break;
        }
    } else if(player1 == "paper") {
        
        checkPlayerOne = 'p';
        switch(checkPlayerOne)
        {
            case 'p':
            if(player2 == "scissors")
                {
                cout<<"Player "<<playerOneName<<" used paper and Player "<<playerTwoName<<" used scissors! Player "<<playerTwoName<<" wins!"<<endl;
                return 1; 
                }
                else if(player2 == "paper")
                {
                    cout<<"Player "<<playerOneName<<" and Player "<<playerTwoName<<" used paper! No-one wins!"<<endl;
                    return -1;
                }
                else if(player2 == "rock")
                {
                    cout<<"Player "<<playerOneName<<" used paper and Player "<<playerTwoName<<" used rock! Player "<<playerOneName<<" wins!"<<endl;
                    return 1;
                }
                break;
        }
    }

       return -1; 
}
void Game::clearScreen()
{
    system("clear");
}

void Game::waitForKeyPress()
{
    cin.get();
    //system("pause"); <- can only be used for windows.
}

bool Game::playAgain()
{
    char choice;

    cout<<"would you like to play again? (Y/n): ";
    cin>>choice;

    if(choice == 'y' || choice == 'Y')
    {
        return true;
    }
    return false;
}

int main()
{
    Game game;
    char menu;
    menu = game.menuScreen();

    if(menu == 'p' || menu == 'P')
    {
        do
        {
            game.playGame();

        } while (game.playAgain());
    }
    else if(menu == 'Q' || menu == 'q'){

        return 0;
    }
    return 0;
}
