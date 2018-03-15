/* 
 * File:   controller.h
 * Author: Anders
 *
 * Created on 15. marts 2018, 09:11
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>
#include <syslog.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>
#include <iostream>
#include <string>
#include <sstream>
#include <pthread.h>
#include <stdlib.h>
#include <fstream>

void print_help(void);
int toint(std::string s);
int heater(float temperature, int target);




#endif /* CONTROLLER_H */

