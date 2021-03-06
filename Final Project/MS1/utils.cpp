
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }

   int getInt(const char* prompt){
       bool badEntry;
       char nextChar;
       int value;
       if (prompt) cout << prompt;
       do {
           badEntry = false;
           cin >> value;
           if (cin.fail()) {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(3000, '\n');
                badEntry = true;
           }
           else {
               nextChar = cin.get();
               if (nextChar != '\n') {
                   cout << "Enter only an integer, try again: ";
                   cin.ignore(3000, '\n');
                   badEntry = true;
               }
           }
       } while (badEntry);
       return value;
   }

   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
       int val;
       val = getInt(prompt);
       while (val < min || val > max) {
           if (errorMessage != nullptr) {
               cout << errorMessage;
           }
           if (showRangeAtError) {
                cout << "[" << min << " <= value <= " << max << "]: ";
           }
           val = getInt();
       }
       return val;
   }

   char* getcstr(const char* prompt) {
       char* a = 0;
       if (prompt != nullptr) {
           string str;
           cout << prompt;
           getline(cin, str, '\n');
           char* cstr = new char[str.length() + 1];
           strcpy(cstr, str.c_str());
           a = cstr;
       }
       return a;
   }
}
