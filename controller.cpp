/* 
 * File:   controller.h
 * Author: Anders
 */

#include "controller.h"
#include <signal.h>
#include "TCPClient.h"


void print_help(void) {
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "######################################################################" << endl;
    cout << "                          USAGE INFORMATION" << endl;
    cout << "######################################################################" << endl;
    cout << "Launch the process:        ./isd2_host <temp (2 digits)>" << endl;
    cout << endl;
    cout << "This process will instruct the ISD2_host to turn on or off a heater" << endl;
    cout << "based on the desired temperature." << endl;
    cout << "temp: sets the desired temperature" << endl;
    cout << endl;
    cout << "######################################################################" << endl;
    cout << "######################################################################" << endl;
    cout << endl;
}

int heater(float temperature, int target) {
    if (temperature < target) {
        cout << "Heater ON" << endl;
        return 1;
    } else {
        cout << "Heater OFF" << endl;
        return 0;
    }
}

int toint(std::string s) //The conversion function
{
    return atoi(s.c_str());
}

