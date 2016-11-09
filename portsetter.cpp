#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

string lang = "en";
char* langValue;
int portNumber = -1;
string version = "1.0.2";
bool usage();
bool about();
string output(int index);
int main(int argc, char* args[]) {
    ///////////////////////////////////////////////////////////////////////////////////
    //BEGINNING OF LANGUAGE SPECIFICATION
    char* langHolder[] = {"LANGUAGE", "LC_ALL", "LC_MESSAGES", "LANG"};
    for (int i = 0; i < 4; i++) {
        langValue = getenv(langHolder[i]);
        //cout << langValue << endl;
        if (langValue != NULL) {
            if (langValue[0] == 'e' && langValue[1] == 'n') {
                lang = "en";
                i = 9;
            }
            else if (langValue[0] == 'e' && langValue[1] == 's') {
                lang = "es";
                i = 9;
            }
        }
        
    }
    
    if (lang[0] == 'e' && lang[1] == 'n') {
        lang = "en";
      //  cout << "en" << endl;
    }
    else if (lang[0] == 'e' && lang[1] == 's') {
        lang = "es";
      //  cout << "es" << endl;
    }
    else { //if (lang != "en" && lang != "es")
        lang = "en";
        cout << "Language not set or "<< getenv("LANGUAGE") << " is not supported, defaulting to " << lang << endl;
    }
    //END OF LANGUAGE SPECIFICATION
    ///////////////////////////////////////////////////////////////////////////////////
    string flag = "";
    if (argc <= 1) {
        if (!usage()){ return -5; }
        return 0;
    }
    else if (argc >= 4 && string(args[2]) != "-e" || argc >= 4 && string(args[2]) != "--environment") {
        cout << output(1) << endl; //"Error: too many arguments"
        if (!usage()){ return -5; }
        return 1;
    }
   flag = string(args[1]);
    if (flag == "-!" || flag == "--about")
    {
        if (!about()) {
            return -6;
            
        }
        return 0;
    }
    if (flag == "-v" || flag == "--version")
    {
        cout << output(2) << version << endl; //"setport version " 
        return 0;
    }
   
      if (flag == "-h" || flag == "--help" || flag == "-?" || argc == 1) {
          if (argc > 2) {
              cout << output(3) << endl; //"too many arguments"
              if (!usage()){ return -5; }
              return 2;
          }
           if (!usage()){ return -5; }
           return 0;
      }
      else if (flag == "--port" || flag == "-p") {
          if (argc < 3) {
              cout << output(4) << endl; //"Error: must provide a port number"
              if (!usage()){ return -5; }
              return -1;
          }
          if (string(args[2]) == "-e" || string(args[2]) == "--environment") {
              char* pPath;
              if (argc < 4) {
                pPath = getenv ("PORT");
              }
              else {
                  pPath = getenv (args[3]);
                 // cout << pPath << endl;
              }
              portNumber = stoi(pPath);
            if (pPath!=NULL && stoi(pPath) != 0) {
                
             if (portNumber < 1 || portNumber > 65000) {
             cout << output(5) << endl; //"Error: Invalid Port Number"
             return -90;
            }
            cout << output(6) << stoi(pPath) << endl; //"Listening on Port: "
            return 0;
            }
            if (stoi(pPath) == 0){
                cout << output(7) << endl; //"Invalid Environment Variable"
                return -7;
            }


          }
         portNumber = stoi(string(args[2]));
         if (portNumber < 1 || portNumber > 65000) {
             cout << output(5) << endl; //"Error: Invalid Port Number"
             return -2;
         }
         else {
        cout << output(6) << portNumber << endl; //"Listening on Port: "
        return 0;
         }
      }
      else {
           cout << output(8) << endl; //"Error: Invalid Parameter"
           if (!usage()){ return -5; }
           return -3;
      }
    //   for(int i = 0; i < argc; ++i) {
    //      // cout << args[i] << endl;
    //   }
    cout << output(9) << endl; //"Error: Unknown"
    if (!usage()){ return -5; }
    return -4;
}

bool usage() {
    ifstream in;
    char line[256];
    in.open("/files/setport/portsetter.usage_" + lang + ".txt");
    if(in.fail()) {
        cout << "can't find USAGE file";
        return false;
    }
    while (!in.eof()) {
    in.getline(line, 256);
    cout << line << endl;
    }
    in.close();
    return true;
}

bool about() {
    ifstream in;
    char line[256];
    in.open("/files/setport/portsetter.about_" + lang + ".txt");
        if(in.fail()) {
        cout << "can't find ABOUT file";
        return false;
    }
    while (!in.eof()) {
    in.getline(line, 256);
    cout << line << endl;
    }
    in.close();
    return true;
}
string output(int index) {
    ifstream in;
    char line[256];
    in.open("/files/setport/portsetter.output_" + lang + ".txt");
        if(in.fail()) {
        return "can't find OUTPUT file";
        
    }
    for (int i = 0; i < index; i++) {
        if (!in.eof()) {
            in.getline(line, 256);
        }
    }
    in.close();
    return line;
}
