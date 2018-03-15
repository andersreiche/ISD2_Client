/* 
 * File:   controller.h
 * Author: Anders
 */


#include <iostream>
#include <signal.h>
#include "TCPClient.h"
#include "controller.h"

using namespace std;

TCPClient tcp;
int target = 25; //default target temperature
float temp = 26; //default temperature reading resulting in "OFF" state

template <typename T> string tostr(const T& t) {
    ostringstream os;
    os << t;
    return os.str();
}

void sig_exit(int s) {
    tcp.exit();
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc == 2 && string(argv[1]).length() == 2) {
        target = toint(string(argv[1]));
    } else {
        print_help();
        exit(0);
    }
    signal(SIGINT, sig_exit);

    tcp.setup("127.0.0.1", 1955);
    while (1) {
        tcp.Send("GETTEMP");
        string rec = tcp.receive();
        if (rec != "") {
            cout << "Temperature is " << rec  << " degC" << endl;
            temp = stof(rec);
            /* Instructs the host to turn on/off the heater */
            tcp.Send(tostr(heater(temp, target)));
        }
        sleep(1);
    }
    return 0;
}