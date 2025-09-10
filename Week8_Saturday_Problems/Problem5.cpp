#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Structure to represent an Employee with a name and salary
// A struct is like a "mini-class" that groups related data together.
struct Employee {
    string name;
    double salary;
};

// Function to read the number of employees
int readNumberOfEmployees() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    return n;
}

// Function to input employee details (name + salary)
// and store them in a vector (dynamic array).
void readEmployees(vector<Employee> &employees, int n) {
    for (int i = 0; i < n; i++) {
        Employee emp;
        cout << "Enter name of employee #" << (i + 1) << ": ";
        cin >> emp.name;
        cout << "Enter salary of " << emp.name << ": ";
        cin >> emp.salary;
        employees.push_back(emp); // Add employee to the list
    }
}

// Function to display the list of employees with their salaries
void printEmployees(const vector<Employee> &employees) {
    cout << "\nEmployee List:\n";
    cout << fixed << setprecision(2); // Always show 2 decimals
    for (int i = 0; i < employees.size(); i++) {
        cout << "Name: " << employees[i].name 
             << ", Salary: " << employees[i].salary << " JOD" << endl;
    }
}

// Function to calculate the average salary
double calculateAverage(const vector<Employee> &employees) {
    double total = 0;
    for (int i = 0; i < employees.size(); i++) {
        total += employees[i].salary; // Sum all salaries
    }
    return total / employees.size();  // Divide by number of employees
}

// Function to count how many employees have salary above the average
int countAboveAverage(const vector<Employee> &employees, double average) {
    int count = 0;
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].salary > average) {
            count++;
        }
    }
    return count;
}

// Function to print the average salary and employees above it
void printAboveAverageInfo(const vector<Employee> &employees, double average) {
    cout << "\nAverage salary: " 
         << fixed << setprecision(2) << average << " JOD" << endl;

    int count = countAboveAverage(employees, average);
    cout << "Number of employees earning above average: " << count << endl;

    if (count > 0) {
        cout << "Employees earning above average:\n";
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i].salary > average) {
                cout << employees[i].name 
                     << " with salary " << employees[i].salary << " JOD" << endl;
            }
        }
    }
}

int main() {
    // Step 1: Ask how many employees there are
    int n = readNumberOfEmployees();

    // Step 2: Read employees' info
    vector<Employee> employees;
    readEmployees(employees, n);

    // Step 3: Print all employees
    printEmployees(employees);

    // Step 4: Find the average salary
    double average = calculateAverage(employees);

    // Step 5: Show who earns more than average
    printAboveAverageInfo(employees, average);

    return 0;
}
