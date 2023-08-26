/*
@Author: mrxhar
@Date:   2023-08-25 10:40:14
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::string;
const int NUM = 26;
const string wordlist[NUM] = {"apiary", "beetle", "cereal", "danger", "ensign", "florrid", "garage", "health", "insult", "jackall", "keeper", "loaner ", " manager ", " nonce ", " onset ", " plaid ", " quilt ", " remote ", " stolid ", " train ", " useful ", " valid ", " whence ", " xenon ", " yearning ", " zippy "};

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::tolower;
    std::srand(std::time(0));

    char play;
    cout << "Will you play a word game? <y/n>";
    cin >> play;
    play = tolower(play);
    while (play == 'y')
    {
        string target = wordlist[std::rand() % NUM];
        int length = target.size();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length << " letters, and you guess\n"
             << "one letter at a time. You get " << guesses << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;
        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos) // 都能在 badchars 和 attempt 中找到，已经猜测过的字符
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }
            int loc = target.find(letter);
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter; // 添加在已
            }
            else{
                cout << "good guess!\n";
                attempt[loc] = letter;
                loc = target.find(letter, loc + 1); // 是否还有这字符
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            cout << "Your ward: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.size() > 0)
                {
                    cout << "Bad choice: " << badchars << endl;
                }
                cout << guesses << "bad guess left\n";
            }

           
            
        }
        if (guesses > 0)
        {
            cout << "That's right!\n";
        }
        else
        {
            cout << "Sorry, the word is " << target << ".\n"
                 << "Will your play another? <y/n>";
            cin >> play;
            play = tolower(play);
        }
    }

    return 0;
}
