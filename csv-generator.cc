#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
using namespace std;

std::vector<vector<string>> read_from_file(string filename)
{
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    fstream file(filename, ios::in);

    if(file.is_open()) {
        while(getline(file, line)) {
            row.clear();
            stringstream str(line);
            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";
    return content;
}

int main()
{
    vector<vector<string>> fn = read_from_file("csvs/firstnames.csv");
    vector<vector<string>> ln = read_from_file("csvs/lastnames.csv");

    int size_of_fn = fn.size();
    int size_of_ln = ln.size();

    ofstream myfile;
    myfile.open("output.csv");

    srand(time(NULL));
    for (int i=0; i<10000000; i++) {
        int fi = rand() % (size_of_fn - 1);
        int li = rand() % (size_of_ln - 1);

        string tmp =
            fn[fi][0] + ";" + ln[li][0] + "\n";

        myfile << tmp;
    }
    myfile.close();

    return 0;
}

