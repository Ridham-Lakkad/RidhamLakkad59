#include<iostream>
#include<cstring>    
#include<cctype>    
using namespace std;

const int INITIAL_CAPACITY = 10;

void toLowerCase(char* str)
{
    for(int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int main()
{
    char paragraph[1000];

    cout << "Enter a paragraph:\n";
    cin.getline(paragraph, 1000);  

    int capacity = INITIAL_CAPACITY;
    char** words = new char*[capacity];
    int* freq = new int[capacity];
    int wordCount = 0;

    char* token = strtok(paragraph, " ,.!?;:\n");

    while(token != NULL)
    {
        toLowerCase(token);

        bool found = false;
        for(int i = 0; i < wordCount; i++)
        {
            if(strcmp(words[i], token) == 0)
            {
                freq[i]++;
                found = true;
                break;
            }
        }

        if(!found)
        {
            if(wordCount == capacity)
            {
                int newCapacity = capacity * 2;
                char** newWords = new char*[newCapacity];
                int* newFreq = new int[newCapacity];

                for(int i = 0; i < wordCount; i++)
                {
                    newWords[i] = words[i];
                    newFreq[i] = freq[i];
                }

                delete[] words;
                delete[] freq;

                words = newWords;
                freq = newFreq;
                capacity = newCapacity;
            }

            words[wordCount] = new char[strlen(token) + 1];
            strcpy(words[wordCount], token);
            freq[wordCount] = 1;
            wordCount++;
        }

        token = strtok(NULL, " ,.!?;:\n");
    }

    cout << "\nWord Frequencies:\n";
    for(int i = 0; i < wordCount; i++)
    {
        cout << words[i] << " : " << freq[i] << endl;
    }

    for(int i = 0; i < wordCount; i++)
    {
        delete[] words[i];
    }
    delete[] words;
    delete[] freq;

    cout << "\nRIDHAM LAKKAD :: 24CE059" << endl;
    cout << endl;

    return 0;
}
