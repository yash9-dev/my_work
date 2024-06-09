#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
string get_random_word(vector<string>& words);
void play();
void brain();
void rock_paper();
void quiz();
string q;
string Question_Text = q;


vector<string> words = {"paris", "tokyo" , "delhi" , "sydney", "california" , "texas" , "vegas"};

string hangman_art[7] = {
    " +---+\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|   |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/    |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/ \\  |\n"
    "     |\n"
    "=========="
};

class TicTacToe
{
private:
    char board [9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char current_turn = 'X';
    bool playing = true;
    int state = 0;
    int input;

public:
    void print_board ();
    int play_move (int index, char move);
    int check_win (char move);
    void start ()
    {
        while (playing == true)
    {
        print_board ();
        cout << "Play your move " << current_turn << endl;
        cin >> input;
        if (play_move (input, current_turn) == 0)
        {
            cout << "Box already occupied" << endl;
            continue;
        };
        state = check_win(current_turn);
        if (state == 1)
        {
            print_board();
            cout << current_turn << " wins the game!" << endl;
            break;
        }
        else if (state == 2)
        {
            cout << "Draw!" << endl;
            break;
        };
        current_turn = (current_turn == 'X') ? 'O' : 'X';
    };  
    };
};




  

void TicTacToe :: print_board()
{
    for (int i = 0; i <9; i++)
    {
        if (i == 1 || i == 2 || i == 4 || i == 5 || i == 7 || i == 8)
        {
            cout << " | ";
        }
        cout << board[i];
        if (i == 2 || i == 5)
        {
            cout << endl;
            cout << "---------" << endl;
        }
    }
    cout << endl;
};

int TicTacToe :: play_move(int index, char move)
{
    if (index >= 0 && index < 9)
    {
        if (board[index] == ' ')
        {
            board[index] = move;
            return 1;
        }
    }
    return 0;
};

/*
   0 1 2
   3 4 5
   6 7 8
*/
int TicTacToe ::check_win(char move)
{
    if (
        // Horizontal checks
        (board[0] == move && board[1] == move && board[2] == move) ||
        (board[3] == move && board[4] == move && board[5] == move) ||
        (board[6] == move && board[7] == move && board[8] == move) ||
        // Vertical Checks
        (board[0] == move && board[3] == move && board[6] == move) ||
        (board[1] == move && board[4] == move && board[7] == move) ||
        (board[2] == move && board[5] == move && board[8] == move) ||
        // Diagonal Checks
        (board[0] == move && board[4] == move && board[8] == move) ||
        (board[2] == move && board[4] == move && board[6] == move))
    {
        return 1;
    }
    else
    {
        bool draw = true;
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == ' ')
            {
                draw = false;
                break;
            }
        }
        if (draw == true)
        {
            return 2;
        }
    }
    return 0;
};

char guess; //Answer user inputs for question.
int total; //Total score.


//4 possible answers, correct answer and question score.
class Question {
public:
    void setValues (string, string, string, string, string, char, int); 
    void askQuestion (); 
    void quiz();

private:
    string Question_Text;
    string answer_1;
    string answer_2;
    string answer_3;
    string answer_4;

    char correct_answer;
    int Question_Score;
};

void quiz ()
{
   

    cout << "Press enter to start...\n";
    cin.get();

    //Get the user's name.
    string name;
    cout << "What's your name?\n";
    cin >> name;
    cout << "\n";

    //Ask if user wants to start quiz.
    string respond;
    cout << "Are you ready to start the quiz, " << name << "? Yes/No.\n";
    cin >> respond;

    //If user says yes, the quiz begins.
    if (respond == "Yes" || respond == "yes") {
        cout << "\n";
        cout << "Good luck!\n";
        cout << "\n";
        cout << "Press enter to continue.";
        cin.get();
        cin.ignore();
    } else {
     cout << "\n";
        cout << "Goodbye!\n";
     cin.ignore();
        cin.get();
        
    }//Else, quiz ends.

    //Instances of the questions. 
   
    Question q1;
    Question q2;
    Question q3;
    Question q4;
    Question q5;
    Question q6;
    Question q7;
    Question q8;
    Question q9;
    Question q10;
    Question q11;
    Question q12;
    Question q13;
    Question q14;
    Question q15;
 

    //Calling the member function setValues. 
    //Question is set, 4 answer choices, the correct char answer, 4 points per question.
    q1.setValues("1.What is the file extension for a C++ source code file?",
        ".exe",
        ".cpp",
        ".c",
        ".py",
        'b',
        4);

    q2.setValues("2. Which of the following categories does C++ belong to?",
        "Operating System",
        "Compiler",
        "low-level programming language",
        "High-level programming language",
        'd',
        4);

    q3.setValues("3. Which command is correctly written?",
        "cout >>",
        "cin <<",
        "cout <>",
        "cin >>",
        'd',
        4);

    q4.setValues("4. What is this called, <iostream>?",
        "directive",
        "command",
        "file",
        "pre-processor directive",
        'd',
        4);

    q5.setValues("5. What punctuation ends most lines of code?",
        " . ",
        " , ",
        " : ",
        " ; ",
        'd',
        4);

    q6.setValues("6. Which of the following is not a valid data type in C++?",
        "string",
        "float",
        "num",
        "int",
        'c',
        4);

    q7.setValues("7. Which of the following is the boolean operator for logical-and?","&",
        "|",
        "&&",
        "|&",
        'c',
        4);

     q8.setValues("8. What does the '++' operator do in C++?",
        "Decrements a variable by 1",
        "Divide by 2",
        "Increment a variable by 1",
        "Add 2",
        'c',
        4);

      q9.setValues("9.Which of the following loops is used for executing a block of code repeatedly as long as a condition is true?",
        "While",
        "for",
        "If",
        "Switch",
        'a',
        4);
    q10.setValues("10.What does the 'break' statement do in C++?",
        "Terminates the program",
        " Skips the current iteration of a loop",
        " Exits from a function",
        "Prints a message to the console",
        'b',
        4);

      q11.setValues("11. Which of the following correctly declares an array?",
        "int anarray[10];",
        "int anarray",
        "anarray{10};",
        "array anarray[10];",
        'a',
        4);

      q12.setValues("12. What is the index number of the last element of an array with 29 elements?",
        "29",
        "0",
        "28",
        "Programmer-defined",
        'c',
        4);
q13.setValues("13. Which is not a loop structure?",
        "for",
        "do while",
        "while",
        "repeat until",
        'd',
        4);

      q14.setValues("14. When does the code block following while (x < 100) execute?",
        "When x is less than one hundred",
        "When x is greater than one hundred",
        "When x is equal to one hundred",
        "While it wishes",
        'a',
        4);

      q15.setValues("15. Most programmers use a for loop __ .",
        "for every loop they write",
        "when a loop will not repeat",
        "when they do not know the exact number of times a loop will repeat",
        "when they know the exact number of times a loop will repeat",
        'd',
        4); 
    
  q1.askQuestion();
    q2.askQuestion();
    q3.askQuestion();
    q4.askQuestion();
    q5.askQuestion();
    q6.askQuestion();
    q7.askQuestion();
    q8.askQuestion();
    q9.askQuestion();
    q10.askQuestion();
    q11.askQuestion();
    q12.askQuestion();
    q13.askQuestion();
    q14.askQuestion();
    q15.askQuestion();
    
  //Final score displayed when user finishes quiz.
            cout << "Your Total Score is " << total << " out of 100!\n";
            cout << "\n";

            
            if (total > 69) {
                cout << "Congratulations! You passed\n";
                cout << "\n";
                cin.get ();
                cin.ignore();
               
            }
            else
            {
                cout << "You failed... Sorry, better luck next time.\n";
                cout << "\n";
            }
            cin.get();
            cin.ignore();

        }

        //Function called for question guidelines. 
        void Question::setValues(string q, string a1, string a2, string a3, string a4, char ca, int pa)
        {
            Question_Text = q;
            answer_1 = a1;
            answer_2 = a2;
            answer_3 = a3;
            answer_4 = a4;
            correct_answer = ca;
            Question_Score = pa;
        }
        //Format for possible answers displayed when program executes. 
        void Question::askQuestion()
        {
            cout << "\n";
            cout << Question_Text << "\n";
            cout << "a. " << answer_1 << "\n";
            cout << "b. " << answer_2 << "\n";
            cout << "c. " << answer_3 << "\n";
            cout << "d. " << answer_4 << "\n";
            cout << "\n";

            //User enters their answer.
            cout << "What is your answer?" << "\n";
            cin >> guess;
            //If their answer is correct, message is displayed and 4 points are added to their score.
            if (guess == correct_answer) {
                cout << "\n";
                cout << "Correct!" << "\n";
                total = total + Question_Score;
                cout << "\n";
              cout << "Press enter to continue." << "\n";
              cin.get();
                cin.ignore();
            }
            else //If their answer is incorrect, message is displayed, no points added. 
                 //Correct answer displayed. 
            {
                cout << "\n";
                cout << "Sorry, you're wrong..." << "\n";
                cout << "The correct answer is " << correct_answer << "." << "\n";
                cout << "\n";
                cout << "Press enter to continue." << "\n";
                cin.get();
                cin.ignore();
            }
        }


int main()
{
    cout<<"============================================"<<endl;
    TicTacToe game;
    int opt;
    cout<<"Welcome to GameZone"<<endl;
    cout<<"Select the game you would like to play"<<endl;
    cout<<"1. Hangman"<<endl;
    cout<<"2. Quiz Game"<<endl;
    cout<<"3. Brain Trainer"<<endl;
    cout<<"4. Tic Tac Toe"<<endl;
    cout<<"5. Rock Paper Scissors"<<endl;
    cout<<"6. Exit"<<endl;
    cin>>opt;
   
    switch(opt){
        
    case 1:
    srand(time(0));
    cout << "Welcome to Hangman!\n";
    cout << "Guess the cities!\n";
    play();
    main();
    break;
    case 2:
    quiz();
    main();
    break;
    case 3:
    brain();
    main();
    break;
    case 4:
    game.start();
    main();
    break;
    case 5:
    rock_paper();
    main();
    break;
    case 6:
    exit(0);
    break;
    default:
    cout<<"Enter a Valid Option."<<endl;
    
    
}

    
}

void play()
{
    string secret_word = get_random_word(words);
   string guess_word = secret_word;
    for (int i = 0; i < secret_word.length(); ++i)
    {
        guess_word[i] = '_';
    }
    int try_no = 0;
    char guess;

    while (true)
    {
       cout << hangman_art[try_no] << "\n";
        cout << guess_word << "\n";
        cout << "Enter your guess:\n";
        cin >> guess;

        if (secret_word.find(guess) != string::npos)
            {   
                for (int i = 0; i < guess_word.length(); ++i)
                {
                    if (secret_word[i] == guess)
                    {
                        guess_word[i] = guess;
                    }
                }
            if (secret_word == guess_word)
            {
               cout << hangman_art[try_no] << "\n";
                cout << guess_word << "\n";
              cout << "You win! The word was " << secret_word << "\n";
                break;
            }
        } else {
            ++try_no;
        }
        if (try_no >= 6)
        {
           cout << hangman_art[try_no] << "\n";
        cout << guess_word << "\n";
           cout << "You lost! The word was " << secret_word << "\n";
            break;
        }
    }
}

string get_random_word(vector<string>& words)
{
    return words[rand() % words.size()];
}

int easy()
{

const int MIN_VALUE = 1;
const int MAX_VALUE = 10;

const int MIN_VALUE1 = 1;
const int MAX_VALUE1 = 5;

int num1;
int num2;
int score = 0;

string right = "right";
string wrong = "wrong";

unsigned seed = time(0);


srand(seed);
for (int i = 0; i<= 20; i++)
{
num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
num2 = (rand() % (MAX_VALUE1 - MIN_VALUE1 + 1)) + MIN_VALUE1;

char op; int expected;
switch(rand() % 4) {
    case 0:  op = '+'; expected = num1 + num2; break;
    case 1:  op = '-'; expected = num1 - num2; break;
    case 2:  op = '/'; expected = num1 / num2; break;
    default: op = '*'; expected = num1 * num2; break;
    
}

cout<<"DISCLAIMER do not enter alphabets !!!"<<endl;
cout << "How much is " << num1 << op << num2 << "?" << endl;

int answer;

cin >> answer;

cout << "Your answer is " << answer <<endl;

if (answer == expected){
    cout<<"Hurray your answer is Right !!!!"<<endl;
    score++;
    
}else {
    cout<<"Your answer is Wrong !!!!"<<endl;
};
cout<<"The correct answer is "<<expected<<endl;
cout<<"Now your score is: "<<score<<endl;
cout<<"_____________"<<endl;
cout<<"........................................"<<endl;
}
return 0; 
}
int medium()
{
const int MIN_VALUE = 1;
const int MAX_VALUE = 100;

const int MIN_VALUE1 = 1;
const int MAX_VALUE1 = 50;


int num1;
int num2;
int score = 0;
//char op;
string right = "right";
string wrong = "wrong";

unsigned seed = time(0);


srand(seed);

for(int i = 0; i<= 20;i++) 
{
num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
num2 = (rand() % (MAX_VALUE1 - MIN_VALUE1 + 1)) + MIN_VALUE1;

char op; int expected;
switch(rand() % 4) {
    case 0:  op = '+'; expected = num1 + num2; break;
    case 1:  op = '-'; expected = num1 - num2; break;
    case 2:  op = '/'; expected = num1 / num2; break;
    default: op = '*'; expected = num1 * num2; break;
    
}

cout << "How much is " << num1 << op << num2 << "?" << endl;

int answer;

cin >> answer;

cout << "Your answer is " << answer <<endl;

if (answer == expected){
    cout<<"Hurray your answer is Right !!!!"<<endl;
    score++;
    
}else {
    cout<<"Your answer is Wrong !!!!"<<endl;
};
cout<<"The correct answer is "<<expected<<endl;
cout<<"Now your score is :" <<score<< endl;
}

return 0; 
}

int hard()
{
const int MIN_VALUE = 50;
const int MAX_VALUE = 150;

const int MIN_VALUE1 = 50;
const int MAX_VALUE1 = 100;


int num1;
int num2;
int score= 0;

string right = "right";
string wrong = "wrong";

unsigned seed = time(0);

srand(seed);

for (int i = 0; i<= 20; i++) 
{
num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
num2 = (rand() % (MAX_VALUE1 - MIN_VALUE1 + 1)) + MIN_VALUE1;

char op; int expected;
switch(rand() % 4) {
    case 0:  op = '+'; expected = num1 + num2; break;
    case 1:  op = '-'; expected = num1 - num2; break;
    case 2:  op = '/'; expected = num1 / num2; break;
    default: op = '*'; expected = num1 * num2; break;
    
}

cout << "How much is " << num1 << op << num2 << "?" << endl;

int answer;

cin >> answer;

cout << "Your answer is " << answer <<endl;

if (answer == expected) {
    cout<<"Hurray your answer is Right !!!!"<<endl;
    score++;
    
} else {
    cout<<"Your answer is Wrong !!!!"<<endl;
};
cout<<"The correct answer is "<<expected<<endl;
cout<<"Now your score is:"<<score << endl;
}
return 0; 
}



void brain()
{
  
cout << "******" << endl << endl;
cout << "Welcome to the awesome math tutor! \n";
cout << "Get ready to add, subtract, and multiply!" << endl << endl;
cout << "******" << endl << endl;

cout<<"Enter your Level: "<<endl; 
cout<<"Enter 1 for easy level."<<endl;
cout<<"Enter 2 for medium level."<<endl;
cout<<"Enter 3 for hard level."<<endl;


int choice;
cout<<"Enter your Choice: "<<endl;
cin>>choice;
switch(choice) {
    case 1: easy ();
    break;
    case 2: medium ();
    break;
    case 3: hard ();
    break;
   
}
};

const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

 
char getComputerOption (){
    srand (time (0));
    // Random number
    int num = rand () % 3 + 1;
 
    if(num==1) return 'r';
    if(num==2) return 'p';
    if(num==3) return 's';
    return 0;
    
};
 
 char getUserOption () {
    char c;
    //cout << "Rock, Paper and Scissors Game!" << endl;
    cout << "Choose one of the following options" << endl;
    cout << "-----------------------------------"  << endl;
    cout << "(r) for rock " << endl << "(p) for paper" << endl << "(s) for scissors " << endl;
    cin >> c;
    
    while (c !='r' && c !='p' && c !='s')
    {
        cout << "Please enter one of the following options only. " << endl;
        cout << "(r) for rock " << endl << "(p) for paper" << endl << "(s) for scissors " << endl;
        cin >> c;
    }
 
    return c;
}
 
void showSelectedOption (char option) {
    if (option == 'r') cout << "Rock" << endl;
    if (option == 'p') cout << "Paper" << endl;
    if (option == 's') cout << "Scissors" << endl;
}
 
void chooseWinner (char uChoice, char cChoice) {
    if (uChoice == ROCK && cChoice == PAPER) {
        cout << "Computer Wins! Paper wraps Rock."<< endl;
    }
    else if (uChoice == PAPER && cChoice == SCISSORS) {
        cout << "Computer Wins! Scissors cut Paper."<< endl;
        
    }
    else if (uChoice == SCISSORS && cChoice == ROCK) {
        cout << "Computer Wins! Rock smashes Scissors."<< endl;
        
    }
    else if (uChoice == ROCK && cChoice == SCISSORS) {
        cout << "You Win! Paper wraps Rock."<< endl;
        
    }
    else if (uChoice == PAPER && cChoice == ROCK) {
        cout << "You Win! Paper wraps Rock."<< endl;
        
    }
    else if (uChoice == SCISSORS && cChoice == PAPER) {
        cout << "You Win! Scissors cut Paper."<< endl;
    }
    else {
        cout << "Tie. Play again win the Game." << endl;
    }
}
 
void rock_paper () {
    //User's choice
    char uChoice; 
    //Computer's choice
    char cChoice;
    cout << "Rock, Paper and Scissors Game!" << endl;
    for (int i = 0; i< 3; i++) {
    uChoice = getUserOption ();
    cout << "Your choice is: "<< endl;
    showSelectedOption(uChoice);
    
    cout << "Computer's choice is: "<< endl;
    cChoice = getComputerOption ();
    showSelectedOption(cChoice);
    
    chooseWinner (uChoice, cChoice);
    cout<<endl;
    }
    
}
