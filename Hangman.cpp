#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;
string chooseWord();
char readAGuess();
void renderGame(string guessedWord, int badGuessCount, string yourGuessedword);
void update(string &guessedWord, char guess, string secretWord);
bool contains(string secretWord, char guess);
void yourguessedword(string &yourGuessedword, char guess);
int Numberchecked(string yourGuessedword, char guess);
char checkedGuess(string yourGuessedword, char guess);

const string Word_List[] = {"dog", "cat", "play","comeback","guess","hello","cammera",
"smartphone","telephone","love","chess","window","github","study","monkey","world","hangman",
"media","listen","monday","tuesday","wednesday","thursday","friday"
"brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
"cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
"chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
"cow", "cup", "curtain", "cushion",
"dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
"face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
"foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
"hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
"hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
"leaf", "leg", "library", "line", "lip", "lock",
"map", "match", "monkey", "moon", "mouth", "muscle",
"nail", "neck", "needle", "nerve", "net", "nose", "nut",
"office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
"pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
"rail", "rat", "receipt", "ring", "rod", "roof", "root"};
const int Word_Count = sizeof(Word_List)/sizeof(string);

const string FIXGURE[] ={" _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |             O     |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |             O     |\n"
                            "|   |             |     |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |             O     |\n"
                            "|   |            /|     |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |             O     |\n"
                            "|   |            /|\\    |\n"
                            "|   |                   |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |             O     |\n"
                            "|   |            /|\\    |\n"
                            "|   |            /      |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n",
                            " _______________________\n"
                            "|                       |\n"
                            "|   ---------------     |\n"
                            "|   |             |     |\n"
                            "|   |             O     |\n"
                            "|   |            /|\\    |\n"
                            "|   |            / \\    |\n"
                            "|   |                   |\n"
                            "| -----                 |\n"
                            "|                       |\n"
                            "|_______________________|\n"};

int main()
{
    srand(time(0));
    string yourAnswer;
    while(yourAnswer != "no")
        {
            int Count = 1;
            string yourGuessedWord = "";
            const int Max_Bad_Guess = 7;
            string secretWord,guessedWord = "";
            secretWord = chooseWord();
            char guess;
     for(int i = 0; i < secretWord.size(); i++)
     {
         guessedWord = guessedWord + "-";
     }
     int badGuessCount = 0;
     do{
             renderGame(guessedWord,badGuessCount,yourGuessedWord);
             guess = readAGuess();
             if(Count == 1){
              yourguessedword(yourGuessedWord, guess);
             }
             if(Count > 1){
                 guess = checkedGuess(yourGuessedWord,guess);
                 yourguessedword(yourGuessedWord, guess);
             }
        if(contains(secretWord,guess) == true)
        {
          update(guessedWord,guess,secretWord);
        }
        else{
            badGuessCount ++;
        }
        if(secretWord == guessedWord)
     {
         renderGame(guessedWord,badGuessCount,yourGuessedWord);
         cout<<endl<<"You win! Congratulation."<<endl;
         cout<<"The secret word is: "<<secretWord<<endl;
         cout<<endl;
         cout<<"Do you want to continue playing? (yes or no) "<<endl;
         cout<<"your Answer: ";
         cin>>yourAnswer;
         if(yourAnswer == "yes")
         {
             cout<<endl<<"please continue!"<<endl;
             badGuessCount = 0;
             cout<<endl;
             break;
         }
         else
         {
             cout<<"Thank you! Next person"<<endl;
         }
     }
      if(badGuessCount == Max_Bad_Guess && secretWord != guessedWord)
     {
         renderGame(guessedWord,badGuessCount,yourGuessedWord);
         cout<<endl<<"You lose! The corect word is: "<<secretWord<<endl;
         cout<<endl;
         cout<<"Do you want to continue playing? (yes or no) "<<endl;
         cout<<"your Answer: ";
         cin>>yourAnswer;
         if(yourAnswer == "yes")
         {
             cout<< endl << "please continue!"<<endl;
             badGuessCount = 0;
             cout<<endl;
             break;
         }
         else
         {
             cout<<endl<<endl<<"Thank you! Next person"<<endl;
         }
     }
     Count++;
     }
     while(badGuessCount < Max_Bad_Guess && secretWord != guessedWord);
     }
}

bool contains(string secretWord, char guess)
{
    for(int i = 0; i < secretWord.size(); i++)
    {
        if(secretWord[i] == guess)
        {
            return true;
        }
    }
    return false;
}
void update(string &guessedWord, char guess, string secretWord)
{
    for(int i = 0; i < secretWord.size(); i++)
    {
        if(secretWord[i] == guess)
        {
            guessedWord[i] = guess;
        }
    }
}

void yourguessedword(string &yourGuessedWord,char guess)
{
yourGuessedWord.insert(yourGuessedWord.end(), guess);

}

char readAGuess(){
    cout<<"your guess: ";
    char guess;
    cin>>guess;
    cout<<endl<<endl;
    return guess;
}

int Numberchecked(string yourGuessedWord, char guess)
{
    int Count = 0;
    for(int i =0; i < yourGuessedWord.size(); i++)
    {
        if(yourGuessedWord[i] == guess)
        {
            Count++;
        }
    }
    return Count;
}

char checkedGuess(string yourGuessedWord, char guess)
{
    int Count = Numberchecked(yourGuessedWord,guess);
    if(Count == 0)
    {
        return guess;
    }
    else{
            int Counts = Count;
            char guessAgain;
    do{
       if(Counts != 0)
      {
        cout<<"Please guess again! The word you selected has been duplicated"<<endl;
        cout<<"your guess: ";
        cin>>guessAgain;
        Counts = Numberchecked(yourGuessedWord, guessAgain);
       }
    }
     while(Counts != 0);
     guess = guessAgain;
     return guess;
          }
}

string chooseWord()
{
    int randomIndex = rand() % Word_Count;
    return Word_List[randomIndex];
}

void renderGame(string guessedWord, int badGuessCount,string yourGuessedWord)
{
    for(int i = 0; i < 32; i++)
    {
        cout << endl;
    }
    cout<<FIXGURE[badGuessCount]<<endl<<endl;
    cout<<"your guessed: "<<guessedWord<<endl;
    cout<<"your guessedWord: "<<yourGuessedWord<<endl;
    cout<<"Number of guess wrong: "<<badGuessCount<<endl;
}
