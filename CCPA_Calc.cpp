#include <iostream>
using namespace std;
#include <iomanip>

float cum_gpa(float gpas[], int credits[], int num_sem) {
    float weighted_sum = 0.00;
    int total_credits = 0;
    for (int i = 0; i < num_sem; i++) {
        weighted_sum += *(gpas + i) * *(credits + i); //Weights semester GPA against the number of credits in the semester
        total_credits += *(credits + i); //Sums credits over all semesters
    }
    return (float) weighted_sum/total_credits;
}

int sem_data(float gpas[], int credits[], int sem_id) {
    cout << "What was your GPA for semester " << sem_id << "?" << endl;
    cin >> *(gpas + sem_id - 1);
    cout << endl;

    while(1) {
    if (cin.fail()) {
      cin.clear();
      cout << "Please enter a number." << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin >> *(gpas + sem_id - 1);
      cout << endl;
    }
    if (!cin.fail()) {
      break;
    }
  }

    cout << "How many credits did you take during semester " << sem_id << "?" << endl;
    cin >> *(credits + sem_id - 1);
    cout << endl;

    while(1) {
    if (cin.fail()) {
      cin.clear();
      cout << "Please enter a number." << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin >> *(credits + sem_id - 1);
      cout << endl;
    }
    if (!cin.fail()) {
      break;
    }
  }

    cout << endl;

    return 0;
}

int main() {
  cout << "------------------------------Cumulative GPA Calculator------------------------------" << endl; //Prompt for num_sem
  cout << "How many semesters have you taken?" << endl;
  int num_sem;
  cin >> num_sem; //Total number of semesters
  cout << endl;

  while(1) {
    if (cin.fail()) {
      cin.clear();
      cout << "Please enter a number." << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin >> num_sem;
      cout << endl;
    }
    if (!cin.fail()) {
      break;
    }
  }

  float gpas[num_sem]; //GPA per semester
  int credits[num_sem]; //Credits per semester

  for (int i = 0; i < num_sem; i++) {
    sem_data(gpas, credits, i + 1); //Collect data on the given semester
  }
  float cgpa = cum_gpa(gpas, credits, num_sem);
  cout << fixed;
  cout << setprecision(2);
  cout << "Your cumulative GPA is: " << cgpa << endl << endl;
  cout << "------------------------------Cumulative GPA Calculator------------------------------" << endl;

  return 0;
}