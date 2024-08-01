#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to convert a string to lowercase
string toLowerCase(const string& str) {
    string result;
    for (char ch : str) {
        result += tolower(ch);
    }
    return result;
}

// Function to check if a word exists in an array of words
bool wordExists(const string words[], int count, const string& word) {
    for (int i = 0; i < count; ++i) {
        if (words[i] == word) {
            return true;
        }
    }
    return false;
}

// Function to get the index of a word in an array of words
int getWordIndex(const string words[], int count, const string& word) {
    for (int i = 0; i < count; ++i) {
        if (words[i] == word) {
            return i;
        }
    }
    return -1;
}

int main() {
    const int MAX_WORDS = 1000;  // Maximum number of unique words
    const int MAX_WORD_LENGTH = 50;  // Maximum length of a word

    string words[MAX_WORDS];  // Array to store unique words
    int frequencies[MAX_WORDS] = {0};  // Array to store frequencies
    int wordCount = 0;

    string paragraph;
    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    string currentWord;
    for (char ch : paragraph) {
        if (isalpha(ch)) {
            currentWord += tolower(ch);
        } else if (!currentWord.empty()) {
            if (!wordExists(words, wordCount, currentWord)) {
                words[wordCount] = currentWord;
                frequencies[wordCount] = 1;
                ++wordCount;
            } else {
                int index = getWordIndex(words, wordCount, currentWord);
                ++frequencies[index];
            }
            currentWord.clear();
        }
    }

    // Check the last word if the paragraph does not end with a non-alphabetic character
    if (!currentWord.empty()) {
        if (!wordExists(words, wordCount, currentWord)) {
            words[wordCount] = currentWord;
            frequencies[wordCount] = 1;
            ++wordCount;
        } else {
            int index = getWordIndex(words, wordCount, currentWord);
            ++frequencies[index];
        }
    }

    // Print out the word frequencies
    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < wordCount; ++i) {
        cout << words[i] << ": " << frequencies[i] << endl;
    }

    return 0;
}
