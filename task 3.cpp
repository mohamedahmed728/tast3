#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("welcome.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }
    outFile << "Hello Everybody";
    outFile.close();

    ifstream inFile("welcome.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }
    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    string target = "body";
    string replacement = "one";
    size_t pos = content.find(target);
    if (pos != string::npos) {
        content.replace(pos, target.length(), replacement);
    }

    ofstream finalFile("welcome.txt");
    if (!finalFile) {
        cerr << "Error opening file for final write!" << endl;
        return 1;
    }
    finalFile << content;
    finalFile.close();

    cout << "Done! Final content: " << content << endl;
    return 0;
}
