#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
using namespace std;

// Function to set up the quiz questions and their correct answers
void setupQuestions(string questions[], char answers[], int &size) {
    size = 5; // total number of questions

    // Adding questions with correct answers
    questions[0] = "C++ is a programming language? (y/n)";
    answers[0] = 'y';

    questions[1] = "2 + 2 = 5? (y/n)";
    answers[1] = 'n';

    questions[2] = "Earth is flat? (y/n)";
    answers[2] = 'n';

    questions[3] = "Water boils at 100C? (y/n)";
    answers[3] = 'y';

    questions[4] = "C++ supports OOP? (y/n)";
    answers[4] = 'y';
}

// Function to generate a random number in range [min, max]
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to shuffle the order of questions and answers
void shuffleQuestions(string questions[], char answers[], int size) {
    for(int i = 0; i < size; i++) {
        int j = getRandomNumber(0, size - 1); // pick random index
        swap(questions[i], questions[j]);     // swap questions
        swap(answers[i], answers[j]);         // swap corresponding answers
    }
}

// Function to run the quiz and return the score
int runQuiz(string questions[], char answers[], int size) {
    int score = 0;
    char answer;

    for(int i = 0; i < size; i++) {
        // Display question
        cout << questions[i] << " ";
        cin >> answer;

        // Check if user's answer matches the correct one (case-insensitive)
        if(answer == answers[i] || 
           answer == toupper(answers[i]) || 
           answer == tolower(answers[i])) {
            score++; // increase score if correct
        }
    }
    return score; // return total score
}

int main() {
    srand(time(0)); // seed random number generator

    string questions[50]; // array to hold questions
    char answers[50];     // array to hold correct answers
    int totalQuestions;   // number of questions used

    // Setup quiz questions
    setupQuestions(questions, answers, totalQuestions);

    // Shuffle to randomize question order
    shuffleQuestions(questions, answers, totalQuestions);

    // Run quiz and get score
    int score = runQuiz(questions, answers, totalQuestions);

    // Show result
    cout << "You got " << score << " out of " << totalQuestions << " correct.\n";

    return 0;
}
