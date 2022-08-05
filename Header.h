#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include<fstream>
#include<Windows.h>
using namespace std;

void func1();//Function Prototype

void printboard();//Function Prototype for printing the Board

int game_progress();//Function Prototype for checking progress of the game

int diceRoll();//Function Prototype for rolling dice to play game


//Declaring some Global Variables
int dice_P1; //Checks the dice value of Player 1
int dice_P2; //Checks the dice value for Player 2
int dice_P3;//Checks the dice value for Player 3
int dice_P4;//Checks the dice value for Player 4
char Roll; //User press any key to roll the dice

int progress; //checks the progress of the game
//Initializing initial postion of all players to 0.
int player1 = 0;
int player2 = 0;
int player3 = 0;
int player4 = 0;

int boardValues[100]; //declaring an Array for board values shown on the board


void func1()
{
    string PlayerName1, PlayerName2, PlayerName3, PlayerName4;//Strings used to input names of the players

    string P1_alert = ""; //to alert player 1 for incoming snake bites and ladder climbs
    string P2_alert = ""; //to alert player 2 for incoming snake bites and ladder climbs
    string P3_alert = "";//to alert player 3 for incoming snake bites and ladder climbs
    string P4_alert = "";//to alert player 4 for incoming snake bites and ladder climbs
    int a;
    cout << "****************************" << endl;
    cout << "   SNAKES AND LADDER GAME" << endl;
    cout << "****************************" << endl;
    cout << "Press 1 to PLAY GAME\nPress 2 to see CREDITS of Game\nPress 3 to see Instructions/Rules of Game\nPress 4 to see RECORDS of Players\nPress 5 to EXIT." << endl;
    cin >> a;
    system("cls");

    //PLAY GAME Option//
    if (a == 1)
    {
        ofstream openfile("Snake and Ladder Game.txt", ios::app);
        cout << "Welcome to Main Menu. Enter Names of Players to Continue. " << endl;
        //Player names//
        cout << "Enter the name of Player 1 = ";
        cin >> PlayerName1; cout << endl;//Input names of Players from User
        cout << "Enter the name of Player 2 = ";
        cin >> PlayerName2; cout << endl;
        cout << "Enter the name of Player 3 = ";
        cin >> PlayerName3; cout << endl;
        cout << "Enter the name of Player 4 = ";
        cin >> PlayerName4; cout << endl;

        int t1 = 1, t2 = 2, t3 = 3, t4 = 4; char toss;//Variable Declaration
        srand(time(NULL));
        //Play Toss to Assign turns to the Players
        cout << "Toss the Coin to Assign turns to Players. Press 't' for toss. " << endl;
        cin >> toss;//Press t to Toss
        cout << endl;
        t1 = (rand() % 4) + 1;
        t2 = (rand() % 4) + 1;
        t3 = (rand() % 4) + 1;
        t4 = (rand() % 4) + 1;
        cout << PlayerName1 << " got " << t1 << " turn" << endl;
        //while loop for Assigning turns to Players. This logic will generate random numbers b/w 1 & 4. Generate 4 random nos and store them into 4 different variables. Then cout the first random no in t1, then check whether t2 is equal to t1.If t2 is equal to t1 then generate another random number. Repeat generating random number until it generates different random number then fist one. Do the same for t3 & t4.
        while (t2 == t1)
        {
            if (t2 == t1)
            {
                t2 = (rand() % 4) + 1;
            }
        }
        cout << PlayerName2 << " got " << t2 << " turn" << endl;
        while (t3 == t1 || t3 == t2)
        {
            if (t3 == t1)
            {
                t3 = (rand() % 4) + 1;
            }
            else if (t3 == t2)
            {
                t3 = (rand() % 4) + 1;
            }
        }
        cout << PlayerName3 << " got " << t3 << " turn" << endl;
        while (t4 == t1 || t4 == t2 || t4 == t3)
        {
            if (t4 == t1)
            {
                t4 = (rand() % 4) + 1;
            }
            else if (t4 == t2)
            {
                t4 = (rand() % 4) + 1;
            }
            else if (t4 == t3)
            {
                t4 = (rand() % 4) + 1;
            }
        }
        cout << PlayerName4 << " got " << t4 << " turn" << endl;
        cout << endl;
        Sleep(3000);//Holds/pauses the console window for 2 seconds.
        system("cls");//Clear the console window
       // cout << "SNAKES\tLADDERS\n98-8\t80-99\n92-53\t52-88\n62-57\t33-85\n56-15\t9-31\n51-11\t4-14\n" << endl;

        //This condition is for the Player who has Won the toss. The Player winning the toss will have first turn, then second player turn and so on.
        if (t1 == 1)
        {
            dice_P1 = diceRoll();
        }
        else if (t2 == 1)
        {
            dice_P2 = diceRoll();
        }
        else if (t3 == 1)
        {
            dice_P3 = diceRoll();
        }
        else if (t4 == 1)
        {
            dice_P4 = diceRoll();
        }

        //this for loop gives values to indexes of board starting from zero. Without this loop all board values are initialized to zero
        for (int i = 1; i <= 100; i++)
        {
            boardValues[i] = i;
        }

        bool flag_dice1 = false; bool flag_dice2 = false; bool flag_dice3 = false; bool flag_dice4 = false;
        //***Condition of rolling 6*** Player will not come on board util he scores six on the board. For this purpose, I used a flag controlled while-loop. When six comes on the dice then flag will turn on and players will come on the board to play. 
        while (!flag_dice1)
        {
            dice_P1 = diceRoll();
            if (dice_P1 == 6)
            {
                player1 = boardValues[0];
                flag_dice1 = true;
            }
            else
                flag_dice1 = false;
        }

        while (!flag_dice2)
        {
            dice_P2 = diceRoll();
            if (dice_P2 == 6)
            {
                player2 = boardValues[0];
                flag_dice2 = true;
            }
            else
                flag_dice2 = false;
        }

        while (!flag_dice3)
        {
            dice_P3 = diceRoll();
            if (dice_P3 == 6)
            {
                player3 = boardValues[0];
                flag_dice3 = true;
            }
            else
                flag_dice3 = false;
        }

        while (!flag_dice4)
        {
            dice_P4 = diceRoll();
            if (dice_P4 == 6)
            {
                player4 = boardValues[0];
                flag_dice4 = true;
            }
            else
                flag_dice4 = false;
        }

        //whole game working is done in a do-while loop//
        do
        {
            cout << "Press R to Roll the dice: ";
            cin >> Roll;
            cout << endl;

            dice_P1 = diceRoll();
            //Condition for player who scores 6. If a player scores six then he is awarded with another turn to roll the dice.
            if (dice_P1 == 6)
            {
                dice_P1 = dice_P1 + diceRoll();
            }

            //Condition for Players whose score exceeds the 100 limit. In that case they will remain at their previous position e.g If a player is at position 98 he rolls the dice and 5 comes on dice then in this case he will stay at 98.
            if ((dice_P1 + player1) > 100)
            {
                player1 = player1;//Player will stay on its previous position if score exceeds 100.
            }
            else
            {
                boardValues[player1] = player1;//Overwrites the current position and assign new position to player    
                player1 = player1 + dice_P1;//Player 1 moves to a New position
            }

            //Conditions for Player 2
            dice_P2 = diceRoll();
            //Condition for player who scores 6. If a player scores six then he is awarded with another turn to roll the dice.
            if (dice_P2 == 6)
            {
                dice_P2 = dice_P2 + diceRoll();
            }

            if ((dice_P2 + player2) > 100)
            {
                player2 = player2;//Player wil stay on its previous position if score exceeds 100.
            }
            else
            {
                boardValues[player2] = player2;//Overwrites the current position and assign new position to player
                player2 = player2 + dice_P2;//Player 2 moves to a New position
            }

            //Conditions for Player 3
            dice_P3 = diceRoll();
            //Condition for player who scores 6. If a player scores six then he is awarded with another turn to roll the dice.
            if (dice_P3 == 6)
            {
                dice_P3 = dice_P3 + diceRoll();
            }

            if ((dice_P3 + player3) > 100)
            {
                player3 = player3;//Player wil stay on its previous position if score exceeds 100.
            }
            else
            {
                boardValues[player3] = player3;//Overwrites the current position and assign new position to player
                player3 = player3 + dice_P3;//Player 3 moves to a New position
            }

            //Conditions for Player 4
            dice_P4 = diceRoll();
            //Condition for player who scores 6. If a player scores six then he is awarded with another turn to roll the dice.
            if (dice_P4 == 6)
            {
                dice_P4 = dice_P4 + diceRoll();
            }

            if ((dice_P4 + player4) > 100)
            {
                player4 = player4;//Player wil stay on its previous position if score exceeds 100.
            }
            else
            {
                boardValues[player4] = player4;//Overwrites the current position and assign new position to player
                player4 = player4 + dice_P4;//Player 4 moves to a New position
            }


            //switch structure for Ladder Climb & Snake Bites for Player 1
            switch (player1)
            {
                //First 5 cases for Snake bites
            case 97:
                player1 = 8;
                P1_alert = "OOPS... You ran into a SNAKE!";
                //changes background console color for few seconds.
                system("Color 0C");//0 for black background & C for light Red
                break;

            case 92:
                player1 = 53;
                P1_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 62:
                player1 = 57;
                P1_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 56:
                player1 = 15;
                P1_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 51:
                player1 = 11;
                P1_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

                //Last 5 cases for Ladder climb
            case 80:
                player1 = 99;
                P1_alert = "HURRAH! You climbed a ladder!!!";
                //0 for background color & A for light Green color
                system("Color 0A");
                break;

            case 52:
                player1 = 88;
                P1_alert = "HURRAH! You climbed a ladder!!!";
                system("Color 0A");
                break;

            case 33:
                player1 = 85;
                P1_alert = "HURRAH! You climbed a ladder!!!";
                system("Color 0A");
                break;

            case 9:
                player1 = 31;
                P1_alert = "HURRAH! You climbed a ladder!!!";
                system("Color 0A");
                break;

            case 4:
                player1 = 14;
                P1_alert = "HURRAH! You climbed a ladder!!!";
                system("Color 0A");
                break;

            default:
                P1_alert = "";
            }

            //Snakes and Ladder for PLayer 2
            switch (player2)
            {
                //First 5 cases for Snake bites
            case 97:
                player2 = 8;
                P2_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 92:
                player2 = 53;
                P2_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 62:
                player2 = 57;
                P2_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 56:
                player2 = 15;
                P2_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 51:
                player2 = 11;
                P2_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

                //Last 5 cases for Ladder climb
            case 80:
                player2 = 99;
                P2_alert = "HURRAH! You climbed a ladder!!!";
                system("Color 0A");
                break;

            case 52:
                player2 = 88;
                P2_alert = "HURRAH! You climbed a ladder!!!";
                system("Color 0A");
                break;

            case 33:
                player2 = 85;
                P2_alert = "HURRAH! You climbed a ladder!!!";
                system("Color 0A");
                break;

            case 9:
                player2 = 31;
                P2_alert = "HURRAH! You climbed a ladder!!!";
                system("Color 0A");
                break;

            case 4:
                player2 = 14;
                P2_alert = "HURRAH! You climbed a ladder!!!";
                system("Color 0A");
                break;

            default:
                P2_alert = "";

            }

            //Snakes and Ladder for PLayer 3
            switch (player3)
            {
                //First 5 cases for Snake bites
            case 97:
                player3 = 8;
                P3_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 92:
                player3 = 53;
                P3_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 62:
                player3 = 57;
                P3_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 56:
                player3 = 15;
                P3_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 51:
                player3 = 11;
                P3_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

                //Last 5 cases for Ladder climb
            case 80:
                player3 = 99;
                P3_alert = "HURRAH! You climbed a ladder!!!";
                system("Color 0A");
                break;

            case 52:
                player3 = 88;
                P3_alert = "HURRAH! you climbed a ladder!!!";
                system("Color 0A");
                break;

            case 33:
                player3 = 85;
                P3_alert = "HURRAH! you climbed a ladder!!!";
                system("Color 0A");
                break;

            case 9:
                player3 = 31;
                P3_alert = "HURRAH! you climbed a ladder!!!";
                system("Color 0A");
                break;

            case 4:
                player3 = 14;
                P3_alert = "HURRAH! you climbed a ladder!!!";
                system("Color 0A");
                break;

            default:
                P3_alert = "";

            }

            //Snakes and Ladder for PLayer 4
            switch (player4)
            {
                //First 5 cases for Snake bites
            case 97:
                player4 = 8;
                P4_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 92:
                player4 = 53;
                P4_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 62:
                player4 = 57;
                P4_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 56:
                player4 = 15;
                P4_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

            case 51:
                player4 = 11;
                P4_alert = "OOPS... You ran into a SNAKE!";
                system("Color 0C");
                break;

                //Last 5 cases for Ladder climb
            case 80:
                player4 = 99;
                P4_alert = "HURRAH! You climbed a ladder!!!";
                system("Color 0A");
                break;

            case 52:
                player4 = 88;
                P4_alert = "HURRAH! you climbed a ladder!!!";
                system("Color 0A");
                break;

            case 33:
                player4 = 85;
                P4_alert = "HURRAH! you climbed a ladder!!!";
                system("Color 0A");
                break;

            case 9:
                player4 = 31;
                P4_alert = "HURRAH! you climbed a ladder!!!";
                system("Color 0A");
                break;

            case 4:
                player4 = 14;
                P4_alert = "HURRAH! You climbed a ladder!!!";
                system("Color 0A");
                break;

            default:
                P4_alert = "";
            }

            //Condition for Players having position at same Point Index. In that case all players come to Initial position except the latest one.
            if (boardValues[player1] == boardValues[player2] || boardValues[player1] == boardValues[player3] || boardValues[player1] == boardValues[player4])
            {
                //if player 1 turn is earlier than player 2 then player 1 will come to initial position.Otherwise player 2 will come to 0.
                if (t1 < t2)
                {
                    player1 = 0;
                }
                else
                {
                    player2 = 0;
                }
                //if player 1 turn is earlier than player 3 then player 1 will come to initial position.Otherwise player 3 will come to 0.
                if (t1 < t3)
                {
                    player1 = 0;
                }
                else
                {
                    player3 = 0;
                }
                //if player 1 turn is earlier than player 4 then player 1 will come to initial position.Otherwise player 4 will come to 0.
                if (t1 < t4)
                {
                    player1 = 0;
                }
                else
                {
                    player4 = 0;
                }
            }

            //Condition for Players having position at same Point Index. In that case all players come to Initial position except the latest one.
            if (boardValues[player2] == boardValues[player1] || boardValues[player2] == boardValues[player3] || boardValues[player2] == boardValues[player4])
            {
                //if player 2 turn is earlier than player 1 then player 2 will come to initial position.Otherwise player 1 will come to 0.
                if (t2 < t1)
                {
                    player2 = 0;
                }
                else
                {
                    player1 = 0;
                }
                //if player 2 turn is earlier than player 3 then player 2 will come to initial position.Otherwise player 3 will come to 0.
                if (t2 < t3)
                {
                    player2 = 0;
                }
                else
                {
                    player3 = 0;
                }
                //if player 2 turn is earlier than player 4 then player 2 will come to initial position.Otherwise player 4 will come to 0.
                if (t2 < t4)
                {
                    player2 = 0;
                }
                else
                {
                    player4 = 0;
                }
            }

            //Condition for Players having position at same Point Index. In that case all players come to Initial position except the latest one.
            if (boardValues[player3] == boardValues[player1] || boardValues[player3] == boardValues[player2] || boardValues[player3] == boardValues[player4])
            {
                //if player 3 turn is earlier than player 1 then player 3 will come to initial position.Otherwise player 1 will come to 0.
                if (t3 < t1)
                {
                    player3 = 0;
                }
                else
                {
                    player1 = 0;
                }
                //if player 3 turn is earlier than player 2 then player 3 will come to initial position.Otherwise player 2 will come to 0.
                if (t3 < t2)
                {
                    player3 = 0;
                }
                else
                {
                    player2 = 0;
                }
                //if player 3 turn is earlier than player 4 then player 3 will come to initial position.Otherwise player 4 will come to 0.
                if (t3 < t4)
                {
                    player3 = 0;
                }
                else
                {
                    player4 = 0;
                }
            }

            //Condition for Players having position at same Point Index. In that case all players come to Initial position except the latest one.
            if (boardValues[player4] == boardValues[player1] || boardValues[player4] == boardValues[player2] || boardValues[player4] == boardValues[player3])
            {
                //if player 4 turn is earlier than player 1 then player 4 will come to initial position.Otherwise player 1 will come to 0.
                if (t4 < t1)
                {
                    player4 = 0;
                }
                else
                {
                    player1 = 0;
                }
                //if player 4 turn is earlier than player 2 then player 4 will come to initial position.Otherwise player 2 will come to 0.
                if (t4 < t2)
                {
                    player4 = 0;
                }
                else
                {
                    player2 = 0;
                }
                //if player 4 turn is earlier than player 4 then player 4 will come to initial position.Otherwise player 3 will come to 0.
                if (t4 < t3)
                {
                    player4 = 0;
                }
                else
                {
                    player3 = 0;
                }
            }

            boardValues[player1] = 111; //Player 1 position is represented by 111
            boardValues[player2] = 222; //Player 2 position is represented by 222
            boardValues[player3] = 333;//Player 3 position is represented by 333
            boardValues[player4] = 444;//Player 4 position is represented by 444

            int count = 0;
            if (count == 0)
            {
                printboard();//Function Call
                cout << "SNAKES\tLADDERS\n98-8\t80-99\n92-53\t52-88\n62-57\t33-85\n56-15\t9-31\n51-11\t4-14\n" << endl;

                cout << "*************************************************************" << endl;
                cout << "Player 1 scored " << dice_P1 << " points...\t" << " Player 1 New Position is: " << player1 << "\t" << P1_alert << endl; cout << endl;
                cout << "Player 2 scored " << dice_P2 << " points...\t" << " Player 2 New Position is: " << player2 << "\t" << P2_alert << endl; cout << endl;
                cout << "Player 3 scored " << dice_P3 << " points...\t" << " Player 3 New Position is: " << player3 << "\t" << P3_alert << endl; cout << endl;
                cout << "Player 4 scored " << dice_P4 << " points...\t" << " Player 4 New Position is: " << player4 << "\t" << P4_alert << endl;  cout << endl;
                cout << "*************************************************************" << endl;
                Sleep(3000);
                system("color 07");
                system("cls");
            }

            progress = game_progress();

        } while (progress == 0);

        if (boardValues[100] == 111)
        {
            cout << "Player 1 Won the Game.!!!" << endl;
            openfile << "Player 1 Wins!!!" << endl;
        }
        else if (boardValues[100] == 222)
        {
            cout << "Player 2 Won the Game.!!!" << endl;
            openfile << "Player 2 Wins!!!" << endl;
        }
        else if (boardValues[100] == 333)
        {
            cout << "Player 3 Won the Game.!!!" << endl;
            openfile << "Player 3 Wins!!!" << endl;
        }
        else if (boardValues[100] == 444)
        {
            cout << "Player 4 Won the Game.!!!" << endl;
            openfile << "Player 4 Wins!!!" << endl;
        }
        openfile.close();
        cin.get();
    }

    //Credits of Game
    else if (a == 2)
    {
        cout << endl;
        cout << "***GAME CREDITS***" << endl;
        cout << "- This Game is Created by ABDUL HASEEB, Student of FAST NUCES CFD Campus.\n- This game contains Copyrighted Content. Any misuse of content can lead to Criminal Action.\n- If you want to use Game Content then first mention the Creater of this game.\n\n~CONTACT INFO~\nEMAIL: abdulhaseeb12567@gmail.com\nPhone: 0309-8757049\nIG:  @haseebb.ch\n THANK YOU! " << endl;
    }

    //Rules of Game to Follow
    else if (a == 3)
    {
        cout << endl;
        cout << "***RULES/INSTRUCTIONS***\n ~Follow the Rules mentioned below to play the Game." << endl;
        cout << "1. Input must be randomly generated from 1 to 6.\n2. Any player can start playing by getting six on dice.\n3. If there’s six on dice the player gets another turn to roll dice.\n4. If two or more players are at the same point index then all goes back"
            << "  to the initial state except the latest one.\n5. The first winner can give six moves forward to any other player as a gift.\n6. As soon as snakes bite a player screen color becomes red for few seconds and comes back to original color afterward."
            << "\n7. As soon as any player takes the ladder screen becomes green and comes back to the original color after few seconds." << endl;
    }

    //Records of Players
    else if (a == 4)
    {
        ifstream openfile("Snake and Ladder Game.txt");
        char ch = 0;
        while (!openfile.eof())
        {
            cout << ch;
            openfile.get(ch);
        }
        openfile.close();
    }

    //EXIT the game
    else if (a == 5)
    {
        cout << "You EXITED the Game.\n GOOD BYE!!!" << endl;
    }
}

void printboard()//prints the board on console
{
    cout << "___________________________________________________________________________" << endl << endl;
    cout << "|" << boardValues[100] << "|" << "\t" << "|" << boardValues[99] << "|" << "\t" << "|" << boardValues[98] << "|" << "\t" << "|" << boardValues[97] << "|" << "\t" << "|" << boardValues[96] << "|" << "\t" << "|" << boardValues[95] << "|" << "\t" << "|" << boardValues[94] << "|" << "\t" << "|" << boardValues[93] << "|" << "\t" << "|" << boardValues[92] << "|" << "\t" << "|" << boardValues[91] << "|" << endl << endl;

    cout << "|" << boardValues[81] << "|" << "\t" << "|" << boardValues[82] << "|" << "\t" << "|" << boardValues[83] << "|" << "\t" << "|" << boardValues[84] << "|" << "\t" << "|" << boardValues[85] << "|" << "\t" << "|" << boardValues[86] << "|" << "\t" << "|" << boardValues[87] << "|" << "\t" << "|" << boardValues[88] << "|" << "\t" << "|" << boardValues[89] << "|" << "\t" << "|" << boardValues[90] << "|" << endl << endl;

    cout << "|" << boardValues[80] << "|" << "\t" << "|" << boardValues[79] << "|" << "\t" << "|" << boardValues[78] << "|" << "\t" << "|" << boardValues[77] << "|" << "\t" << "|" << boardValues[76] << "|" << "\t" << "|" << boardValues[75] << "|" << "\t" << "|" << boardValues[74] << "|" << "\t" << "|" << boardValues[73] << "|" << "\t" << "|" << boardValues[72] << "|" << "\t" << "|" << boardValues[71] << "|" << endl << endl;

    cout << "|" << boardValues[61] << "|" << "\t" << "|" << boardValues[62] << "|" << "\t" << "|" << boardValues[63] << "|" << "\t" << "|" << boardValues[64] << "|" << "\t" << "|" << boardValues[65] << "|" << "\t" << "|" << boardValues[66] << "|" << "\t" << "|" << boardValues[67] << "|" << "\t" << "|" << boardValues[68] << "|" << "\t" << "|" << boardValues[69] << "|" << "\t" << "|" << boardValues[70] << "|" << endl << endl;

    cout << "|" << boardValues[60] << "|" << "\t" << "|" << boardValues[59] << "|" << "\t" << "|" << boardValues[58] << "|" << "\t" << "|" << boardValues[57] << "|" << "\t" << "|" << boardValues[56] << "|" << "\t" << "|" << boardValues[55] << "|" << "\t" << "|" << boardValues[54] << "|" << "\t" << "|" << boardValues[53] << "|" << "\t" << "|" << boardValues[52] << "|" << "\t" << "|" << boardValues[51] << "|" << endl << endl;

    cout << "|" << boardValues[41] << "|" << "\t" << "|" << boardValues[42] << "|" << "\t" << "|" << boardValues[43] << "|" << "\t" << "|" << boardValues[44] << "|" << "\t" << "|" << boardValues[45] << "|" << "\t" << "|" << boardValues[46] << "|" << "\t" << "|" << boardValues[47] << "|" << "\t" << "|" << boardValues[48] << "|" << "\t" << "|" << boardValues[49] << "|" << "\t" << "|" << boardValues[50] << "|" << endl << endl;

    cout << "|" << boardValues[40] << "|" << "\t" << "|" << boardValues[39] << "|" << "\t" << "|" << boardValues[38] << "|" << "\t" << "|" << boardValues[37] << "|" << "\t" << "|" << boardValues[36] << "|" << "\t" << "|" << boardValues[35] << "|" << "\t" << "|" << boardValues[34] << "|" << "\t" << "|" << boardValues[33] << "|" << "\t" << "|" << boardValues[32] << "|" << "\t" << "|" << boardValues[31] << "|" << endl << endl;

    cout << "|" << boardValues[21] << "|" << "\t" << "|" << boardValues[22] << "|" << "\t" << "|" << boardValues[23] << "|" << "\t" << "|" << boardValues[24] << "|" << "\t" << "|" << boardValues[25] << "|" << "\t" << "|" << boardValues[26] << "|" << "\t" << "|" << boardValues[27] << "|" << "\t" << "|" << boardValues[28] << "|" << "\t" << "|" << boardValues[29] << "|" << "\t" << "|" << boardValues[30] << "|" << endl << endl;

    cout << "|" << boardValues[20] << "|" << "\t" << "|" << boardValues[19] << "|" << "\t" << "|" << boardValues[18] << "|" << "\t" << "|" << boardValues[17] << "|" << "\t" << "|" << boardValues[16] << "|" << "\t" << "|" << boardValues[15] << "|" << "\t" << "|" << boardValues[14] << "|" << "\t" << "|" << boardValues[13] << "|" << "\t" << "|" << boardValues[12] << "|" << "\t" << "|" << boardValues[11] << "|" << endl << endl;

    cout << "|" << boardValues[1] << "|" << "\t" << "|" << boardValues[2] << "|" << "\t" << "|" << boardValues[3] << "|" << "\t" << "|" << boardValues[4] << "|" << "\t" << "|" << boardValues[5] << "|" << "\t" << "|" << boardValues[6] << "|" << "\t" << "|" << boardValues[7] << "|" << "\t" << "|" << boardValues[8] << "|" << "\t" << "|" << boardValues[9] << "|" << "\t" << "|" << boardValues[10] << "|" << endl << endl;
    cout << "___________________________________________________________________________" << endl << endl;
}

int diceRoll()//define the dice rolling mechanism
{
    return (rand() % 6) + 1;//Rolls dice b/w 1 & 6.
}

int game_progress()//Checks the Game Progress Conditions
{
    if (boardValues[100] == 111 || boardValues[100] == 222 || boardValues[100] == 333 || boardValues[100] == 444)
    {
        return 1;//Game will end here!! Player with greater score will Win
    }
    else
    {
        return 0;//Game is being carried out 
    }
}
