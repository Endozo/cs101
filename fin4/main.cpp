#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class freqFile{
    private:
        ifstream of;
        string temp, outp, fn;
        int charactor[26] = {0};
        char check;
    public:
        freqFile(string filename) {
            fn = filename;
        }
        void readFile() {
            of.open(fn);
            while (!of.eof()) {
                of.get(check);
                if (check >= 'A' && check <= 'Z')
                    check = check + ('a' - 'A');
                if (check >= 'a' && check <= 'z')
                    charactor[check-'a']++;
            }
            of.close();
        }
        void showFreq() {
            check = 'a';
            for (int i = 0; i < 26; i++) {
                cout << '[' << check << "] = " << charactor[i] << endl;
                check++;
            }
            check = '\0';
        }
};

int main() {
    freqFile myFile("main.cpp");
    myFile.readFile();
    myFile.showFreq();

    return 0;
}
