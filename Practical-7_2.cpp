#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main()
{
    ifstream file("data.txt"); 

    if(!file)  
    {
        cerr << "Error: Cannot open the file.." << endl;
        return 1;
    }

    string line;
    int lineCount = 0, charCount = 0, wordCount = 0;
    vector<string> lines;

    while (getline(file, line))  
    {
        lines.push_back(line);
        lineCount++;
        charCount += line.length();

        stringstream ss(line);  
        string word;
        while (ss >> word)
        {
            wordCount++;
        }
    }

    cout << "Lines     : " << lineCount << endl;
    cout << "Characters: " << charCount << endl;
    cout << "Words     : " << wordCount << endl;

    cout << "\nRIDHAM LAKKAD :: 24CE059" << endl;
    cout << endl;

    return 0;
}