#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cctype>

using namespace std;

void displayWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.size(); ++i) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool isWordGuessed(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.size(); ++i) {
        if (!guessed[i]) {
            return false;
        }
    }
    return true;
}

bool isGameOver(int remainingGuesses, bool wordGuessed) {
    return remainingGuesses <= 0 || wordGuessed;
}

char getUserGuess() {
    char guess;
    cout << "Enter your guess: ";
    cin >> guess;
    return tolower(guess);
}

bool updateGuessed(const string& word, vector<bool>& guessed, char guess) {
    bool correctGuess = false;
    for (size_t i = 0; i < word.size(); ++i) {
        if (word[i] == guess) {
            guessed[i] = true;
            correctGuess = true;
        }
    }
    return correctGuess;
}

void hangmanGame(const string& word) {
    vector<bool> guessed(word.size(), false);
    int remainingGuesses = 10;

    cout << "Guess the word: " << endl;
    displayWord(word, guessed);

    while (!isGameOver(remainingGuesses, isWordGuessed(word, guessed))) {
        char guess = getUserGuess();
        if (!updateGuessed(word, guessed, guess)) {
            cout << "Incorrect guess! Remaining guesses: " << remainingGuesses - 1 << endl;
            --remainingGuesses;
        } else {
            cout << "Correct guess!" << endl;
        }
        cout << "Current status: ";
        displayWord(word, guessed);
    }

    if (isWordGuessed(word, guessed)) {
        cout << "Congratulations! You guessed the word: " << word << endl;
    } else {
        cout << "Game over! The word was: " << word << endl;
    }
}

string getRandomWord(const vector<string>& words) {
    srand(time(NULL));
    int index = rand() % words.size();
    return words[index];
}

int main() {
    string path; cin>>path;
    ifstream inputFile(path);
    vector<string> words;
    string word;

    if (!inputFile.is_open()) {
        cerr << "Failed to open input file!" << endl;
        return 1;
    }

    while (inputFile >> word) {
        if (word.back() == '.') {
            word.pop_back();
            words.push_back(word);
            break;
        }
        words.push_back(word);
    }

    string selectedWord = getRandomWord(words);

    hangmanGame(selectedWord);

    return 0;
}

