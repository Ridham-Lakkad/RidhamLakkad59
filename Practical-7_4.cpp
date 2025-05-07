#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Student
{
    string name;
    int marks;
    char grade;
};

void directProcessing(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    cout << "\n=== Student Report (Direct Processing) ===\n";
    cout << left << setw(20) << "Name"
         << setw(20) << "Marks"
         << setw(20) << "Grade" << endl;
    cout << string(60, '-') << endl;

    string name;
    int marks;
    char grade;

    while (file >> ws && getline(file, name, ' '))
    {
        string line;
        getline(file, line);
        stringstream ss(line);
        ss >> marks >> grade;
        cout << left << setw(20) << name
             << setw(20) << marks
             << setw(20) << grade << endl;
    }

    file.close();
}

void storeAndProcess(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    vector<Student> students;
    string name;
    int marks;
    char grade;

    while (file >> ws && getline(file, name, ' '))
    {
        string line;
        getline(file, line);
        stringstream ss(line);
        ss >> marks >> grade;
        students.push_back({name, marks, grade});
    }

    file.close();

    for (size_t i = 0; i < students.size(); ++i)
    {
        for (size_t j = i + 1; j < students.size(); ++j)
        {
            if (students[j].marks > students[i].marks)
            {
                swap(students[i], students[j]);
            }
        }
    }

    cout << "\n=== Student Report (Stored & Sorted by Marks) ===\n";
    cout << left << setw(20) << "Name"
         << setw(20) << "Marks"
         << setw(20) << "Grade" << endl;
    cout << string(60, '-') << endl;

    for (const auto& s : students)
    {
        cout << left << setw(20) << s.name
             << setw(20) << s.marks
             << setw(20) << s.grade << endl;
    }
}

int main()
{
    string filename = "students.txt";

    directProcessing(filename);
    storeAndProcess(filename);

    cout<<endl;
    cout<<"\nRIDHAM LAKKAD :: 24CE059"<<endl;

    return 0;
}