#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class StudentScore {
private:
    string studentName;
    string indexNumber;
    double score1;
    double score2;
    double score3;
    double totalScore;
    double averageScore;
    string remark;

public:
    // Function to collect student details
    void setStudentDetails() {
        cout << "\nEnter student name: ";
        cin.ignore();
        getline(cin, studentName);
        cout << "Enter index number: ";
        cin >> indexNumber;

        // Input and validate Score 1
        do {
            cout << "Enter practical score 1 (0-100): ";
            cin >> score1;
        } while (!validateScores(score1));

        // Input and validate Score 2
        do {
            cout << "Enter practical score 2 (0-100): ";
            cin >> score2;
        } while (!validateScores(score2));

        // Input and validate Score 3
        do {
            cout << "Enter practical score 3 (0-100): ";
            cin >> score3;
        } while (!validateScores(score3));

        calculateTotalAndAverage();
        assignRemark();
    }

    // Input validation utility
    bool validateScores(double score) {
        if (score < 0 || score > 100) {
            cout << "Invalid score! Score must be between 0 and 100. Try again.\n";
            return false;
        }
        return true;
    }

    // Calculations
    void calculateTotalAndAverage() {
        totalScore = score1 + score2 + score3;
        averageScore = totalScore / 3.0;
    }

    // Performance remark decision structure
    void assignRemark() {
        if (averageScore >= 80) remark = "Excellent";
        else if (averageScore >= 70) remark = "Very Good";
        else if (averageScore >= 60) remark = "Good";
        else if (averageScore >= 50) remark = "Pass";
        else remark = "Needs Improvement";
    }

    // Getter for class average calculations
    double getAverageScore(){
        return averageScore;
    }

    // Display layout
    void displayStudentReport() {
        cout << "Student Name: " << studentName << "\n";
        cout << "Index Number: " << indexNumber << "\n";
        cout << "Total Score: " << totalScore << "\n";
        cout << "Average Score: " << fixed << setprecision(2) << averageScore << "\n";
        cout << "Remark: " << remark << "\n";
        cout << "-------------------------------------\n";
    }

    // Output formatting for file writing
    void saveStudentReport(ofstream &outFile){
        outFile << "Student Name: " << studentName << "\n";
        outFile << "Index Number: " << indexNumber << "\n";
        outFile << "Total Score: " << totalScore << "\n";
        outFile << "Average Score: " << fixed << setprecision(2) << averageScore << "\n";
        outFile << "Remark: " << remark << "\n";
        outFile << "-------------------------------------\n";
    }
};

int main() {
    cout << "==================================================\n";
    cout << "    STUDENT PRACTICAL SCORE MANAGEMENT SYSTEM     \n";
    cout << "==================================================\n";

    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;

    // Recommendation implementation using vectors
    vector<StudentScore> students(numStudents);
    double totalClassScore = 0.0;

    // Collect data via a loop
    for (int i = 0; i < numStudents; i++) {
        cout << "\nRecording details for Student " << (i + 1) << ":";
        students[i].setStudentDetails();
        totalClassScore += students[i].getAverageScore();
    }

    double classAverage = totalClassScore / numStudents;

    // Terminal summary printout
    cout << "\n==================================================\n";
    cout << "              PRACTICAL SCORE REPORT              \n";
    cout << "==================================================\n";
    for (int i = 0; i < numStudents; i++) {
        students[i].displayStudentReport();
    }
    cout << "Class Average: " << fixed << setprecision(2) << classAverage << "\n";
    cout << "==================================================\n";

    // Write contents directly into text file
    ofstream outFile("practical_scores.txt");
    if (outFile.is_open()) {
        outFile << "==================================================\n";
        outFile << "              PRACTICAL SCORE REPORT              \n";
        outFile << "==================================================\n";
        for (int i = 0; i < numStudents; i++) {
            students[i].saveStudentReport(outFile);
        }
        outFile << "Class Average: " << fixed << setprecision(2) << classAverage << "\n";
        outFile << "==================================================\n";
        outFile.close();
        cout << "Report successfully saved to 'practical_scores.txt'\n";
    } else {
        cout << "Error: Unable to save report to file.\n";
    }

    cout << "\nThank you for using the system. Goodbye!\n";
    return 0;
}
