#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;
void success();
void fail(string name, int returnValue);

int main() {
    int exitCode;
    vector<char*> tests;
    vector<int> results;
    //Positive Test Cases
    tests.push_back("setport > test.txt");
    results.push_back(0);
    tests.push_back("setport -h > test.txt");
    results.push_back(0);
    tests.push_back("setport --help > test.txt");
    results.push_back(0);
    tests.push_back("setport -? > test.txt");
    results.push_back(0);
    tests.push_back("setport -! > test.txt");
    results.push_back(0);
    tests.push_back("setport --about > test.txt");
    results.push_back(0);
    tests.push_back("setport -v > test.txt");
    results.push_back(0);
    tests.push_back("setport --version > test.txt");
    results.push_back(0);
    tests.push_back("setport -p 4040 > test.txt");
    results.push_back(0);
    tests.push_back("setport --port 4040 > test.txt");
    results.push_back(0);
    tests.push_back("setport -p -e > test.txt");
    results.push_back(0);
    tests.push_back("setport -p -e PORT > test.txt");
    results.push_back(0);
    
    //Negative Test Cases
    tests.push_back("setport help > test.txt");
    results.push_back(-3);
    tests.push_back("setport -help > test.txt");
    results.push_back(-3);
    tests.push_back("setport --h > test.txt");
    results.push_back(-3);
    tests.push_back("setport -h --help > test.txt");
    results.push_back(2);
    tests.push_back("setport -hs > test.txt");
    results.push_back(-3);
    tests.push_back("setport -p --port 9 > test.txt");
    results.push_back(1);
    tests.push_back("setport -p 77 33 > test.txt");
    results.push_back(1);
    tests.push_back("setport -p -21 > test.txt");
    results.push_back(-2);
    tests.push_back("setport -p 0 > test.txt");
    results.push_back(-2);
    tests.push_back("setport --port > test.txt");
    results.push_back(-1);
    tests.push_back("setport -p 90642 > test.txt");
    results.push_back(-2);
    tests.push_back("setport -x 45321 > test.txt");
    results.push_back(-3);
    tests.push_back("setport -P 714 > test.txt");
    results.push_back(-3);
    tests.push_back("setport -P 714 > test.txt");
    results.push_back(-3);
    
    for (int i = 0; i < tests.size(); i++) {
        exitCode = system(tests[i]) / 256;
        if (exitCode != 0 && exitCode != 1 && exitCode != 2) {
            exitCode -= 256;
        }
    if (exitCode == results[i]) {
        success();
    }
    
    else fail(tests[i], exitCode);
    }
    cout << "\nSwitching to Spanish" << endl << endl;
    setenv("LANGUAGE", "es", 1);
        for (int i = 0; i < tests.size(); i++) {
        exitCode = system(tests[i]) / 256;
        if (exitCode != 0 && exitCode != 1 && exitCode != 2) {
            exitCode -= 256;
        }
    if (exitCode == results[i]) {
        success();
    }
    
    else fail(tests[i], exitCode);
    }
    remove("test.txt");
    return 0;
}

void success() {
    cout << "Success" << endl;
}

void fail(string name, int returnValue) {
    cout << "Failure on " << name << " with value " << returnValue << endl;
}