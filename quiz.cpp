#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Question {
    string question;
    string options[4];
    char correctAnswer;
};

vector<Question> loadQuestions(const string &filename) {
    vector<Question> questions;
    ifstream file(filename.c_str());

    if (!file) {
        cout << "Error opening file!" << endl;
        return questions;
    }
    
    Question q;
    while (getline(file, q.question)) {
        for (int i = 0; i < 4; i++) {
            getline(file, q.options[i]);
        }
        file >> q.correctAnswer;
        file.ignore(); // Ignore newline
        questions.push_back(q);
    }
    
    file.close();
    return questions;
}

void startQuiz(const vector<Question> &questions) {
    int score = 0;
    for (size_t i = 0; i < questions.size(); i++) {
        cout << "\nQuestion " << (i + 1) << ": " << questions[i].question << endl;
        for (int j = 0; j < 4; j++) {
            cout << char('A' + j) << ") " << questions[i].options[j] << endl;
        }
        
        char answer;
        cout << "Your answer: ";
        cin >> answer;
        answer = toupper(answer);
        
        if (answer == questions[i].correctAnswer) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Wrong! Correct answer was: " << questions[i].correctAnswer << endl;
        }
    }
    
    cout << "\nQuiz Over! Your final score: " << score << " out of " << questions.size() << endl;
}

int main() {
    string filename = "questions.txt";
    vector<Question> questions = loadQuestions(filename);
    if (questions.empty()) {
        cout << "No questions loaded. Check the file." << endl;
        return 1;
    }
    startQuiz(questions);
    return 0;
}
