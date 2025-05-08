#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    map<string, vector<string>> directory;

    string command; 

    while (cin >> command) {
        if (command == "mkdir") {
      
            string folderName;
            cin >> folderName;
            directory[folderName];
        } 
        else if (command == "add") {
            string folderName, fileName;
            cin >> folderName >> fileName;
            directory[folderName].push_back(fileName); 
        } 
        else if (command == "ls") {
            vector<string> folderNames;

            for (auto &entry : directory) {
                folderNames.push_back(entry.first);
            }

            sort(folderNames.begin(), folderNames.end());

            for (auto &folder : folderNames) {
                cout << folder << ": ";

                sort(directory[folder].begin(), directory[folder].end());

                for (auto &file : directory[folder]) {
                    cout << file << " ";
                }
                cout << endl;
            }
        } 
        else {
            break;
        }
    }
    cout << "Ridham Lakkad : 24CE059" << endl;

    return 0;
}