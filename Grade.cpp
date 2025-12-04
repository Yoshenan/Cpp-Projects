#include <iostream>
#include <stdexcept>
using namespace std;

int main() {

    const int test_percent = 20, quiz_percent = 10, assignment_percent = 20, final_exam_percent = 50;

    float out_of_100, total_assignment, total_quiz, total_test, total_exam, sum_total, gpa;
    char grade;

    cout << "WELCOME TO GRADE CALCULATOR" << endl;
    cout << "Assignment Grade: " << assignment_percent << "%" << endl;
    cout << "Test Grade: " << test_percent << "%" << endl;
    cout << "Quiz Grade: " << quiz_percent << "%" << endl;
    cout << "Exam Grade: " << final_exam_percent << "%" << endl;

    cout << "\nWhat is the graded percentage (out of 100%) for Assignments? ";
    cin >> out_of_100;
    total_assignment = (assignment_percent / 100.0) * out_of_100;

    cout << "What is the graded percentage (out of 100%) for Test? ";
    cin >> out_of_100;
    total_test = (test_percent / 100.0) * out_of_100;

    cout << "What is the graded percentage (out of 100%) for Final Exam? ";
    cin >> out_of_100;
    total_exam = (final_exam_percent / 100.0) * out_of_100;

    cout << "What is the graded percentage (out of 100%) for Quiz? ";
    cin >> out_of_100;
    total_quiz = (quiz_percent / 100.0) * out_of_100;

    sum_total = total_assignment + total_exam + total_quiz + total_test;

    try{
     cin>>out_of_100;
     if(cin.fail()){
        throw invalid_argument ("Enter a number");}
        cout<<"You entered:"<<out_of_100<<endl;
     }catch(const invalid_argument& e) {
         cout<<e.what() <<endl;
    }

    if (sum_total >= 90) {
        gpa = 4.00;
        grade = 'A';
    } else if (sum_total >= 80) {
        gpa = 3.90;
        grade = 'A';
    } else if (sum_total >= 70) {
        gpa = 3.80;
        grade = 'A';
    } else if (sum_total >= 60) {
        gpa = 3.70;
        grade = 'B';
    } else {
        cout << "\nPay money" << endl;

    }

    cout << "\n---------------------------------------------" << endl;
    cout << "Total Weighted Score: " << sum_total << "%" << endl;
    cout << "Grade: " << grade << endl;
    cout << "GPA: " << gpa << endl;
    cout << "---------------------------------------------" << endl;

    return 0;
}
