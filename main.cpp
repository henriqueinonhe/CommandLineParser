#include <iostream>
#include "commandlineparser.h"
#include <QString>

//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"


#ifndef CATCH_CONFIG_MAIN
using namespace std;

int main(int argc, char *argv[])
{
    QString command;
    for(int i = 1; i < argc; i++)
    {
        command += argv[i];
        command += " ";
    }
    CommandLineParser parser(command);
    cout << "Main Command: " << parser.getMainCommand().toStdString() << endl
         << "Options:" << endl;
    for(auto comm : parser.getOptions())
    {
        cout << "           " << comm.toStdString() << endl;
    }
    cout << endl;
    cout << "Positional Arguments:" << endl;
    for(auto comm : parser.getPositionalArgs())
    {
        cout << "           " << comm.toStdString() << endl;
    }
    cout << endl;
    return 0;
}
#endif
