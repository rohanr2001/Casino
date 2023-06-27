/* 
    Casino Game : Number Guessing Program
    This is a Number Guessing Game.Player deposits an initial amount to start playing game.He guess a number between 1 to 
    10 and enters betting amount.If he wins he will get 10 times of money he bets.If he bets on wrong number he will lost 
    his betting amount.Game continues till user wants to play.
*/
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

class Player
{
    int total_amt = 0, betting_amt = 0, random_num, guessed_num;
    char option;

public:
    int rand_num();
    void display();
    void game();
    Player()
    {
        cout << "\n**********$$$$$$$$ CAE$AR$ PALACE - LAS VEGAS $$$$$$$$**********" << endl;
        cout << "\nPlayer name: Rohan R\nPlayer ID: 19030141CSE032" << endl;
        cout << "Enter your initial amount: ";
        cin >> total_amt;
        game();
    }
};

int Player::rand_num()
{
    srand(time(NULL));
    return rand() % 10 + 1;
}

void Player::game()
{
    cout << "\nLet's begin the game!!" << endl;
    do
    {
        cout << "===========================================" << endl;
        cout << "Enter your bet amount(minimum bet: $10): ";
        cin >> betting_amt;
        if (betting_amt < 10)
        {
            cout << "Sorry Minimum bet is 10\nTry later!!" << endl;
            break;
        }

        cout << "Guess a number between 1-10: ";
        cin >> guessed_num;

        random_num = rand_num();

        if (random_num == guessed_num)
        {
            cout << "\nCongratulations!! You have guessed right number." << endl;
            total_amt += betting_amt;
            display();
            cout << "You won: $" << betting_amt << endl;
            betting_amt = 0;
        }
        else
        {
            cout << "\nSorry, You have guessed the wrong number!!" << endl;
            total_amt -= betting_amt;
            display();
            cout << "You Lost: $" << betting_amt << endl;
            betting_amt = 0;
        }
        cout << "\nDo you want to continue[y/n]: ";
        cin >> option;
        if (option == 'y')
        {
            if (total_amt < 10)
            {
                cout << "\nYour total amount is not suffiecient for minimum bet.\nSorry you cannot continue the game." << endl;
                break;
            }
        }
    } while (option != 'n');
}

void Player::display()
{
    cout << "Guessed Number: " << guessed_num << " Random Number: " << random_num << endl;
    cout << "\nYour Wallet: $" << total_amt << endl;
    cout << endl;
}

int main()
{
    Player p1;
}