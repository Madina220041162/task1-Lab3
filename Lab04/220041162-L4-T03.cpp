#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string EmpName;
    int ID;
    float BaseSalary;
    int JoiningYear;
    int housingAllowance;

    float calculateTotalSalary(int currentYear) {

        int yearsOfService = currentYear - JoiningYear;

        float updatedBaseSalary = BaseSalary;
        for (int i = 0; i < yearsOfService; i++) {
            updatedBaseSalary += updatedBaseSalary * 0.03;
        }

        float transportAllowance = updatedBaseSalary * 0.10;

    float calculateBonus(string status, int currentYear) {

        int yearsOfService = currentYear - JoiningYear;
        float updatedBaseSalary = BaseSalary;
        for (int i = 0; i < yearsOfService; i++) {
            updatedBaseSalary += updatedBaseSalary * 0.03;
        }

        if (status == "Low") {
            return updatedBaseSalary * 0.05;
        } else if (status == "Moderate") {
            return updatedBaseSalary * 0.10;
        } else if (status == "High") {
            return updatedBaseSalary * 0.15;
        } else {
            return 0;
        }
    }ousingAllowance = updatedBaseSalary * 0.30;
        float miscAllowance = updatedBaseSalary * 0.10;

        return updatedBaseSalary + transportAllowance + housingAllowance + miscAllowance;
    }
    public:

    void FeedInfo(string name, int id, float baseSalary, int joiningYear) {
        EmpName = name;
        ID = id;
        BaseSalary = baseSalary;
        JoiningYear = joiningYear;
    }

    void ShowInfo(int currentYear) {

        string status = getStatus(currentYear);
        float totalSalary = calculateTotalSalary(currentYear);
        float bonus = calculateBonus(status, currentYear);

        cout << "Employee Information:" << endl;
        cout << "Name: " << EmpName << endl;
        cout << "ID: " << ID << endl;
        cout << "Base Salary: $" << BaseSalary << endl;
        cout << "Joining Year: " << JoiningYear << endl;
        cout << "Years of Service: " << currentYear - JoiningYear << endl;
        cout << "Status: " << status << endl;
        cout << "Total Salary: $" << totalSalary << endl;
        cout << "Bonus: $" << bonus << endl;
    }
};

int main() {

    Employee emp;
    emp.FeedInfo("John Doe", 12345, 50000, 2018);

    int currentYear = 2024;
    emp.ShowInfo(currentYear);

    return 0;
}

