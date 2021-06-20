#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cctype>
#include <unistd.h>
#include <filesystem>

using namespace std;

int main(int argc, char *argv[]){


/*
SHOW COMMANDTO ACCES TO THE DIRECTORY WITH A Windows PATH ON WSL
(Windows Subsystem for Linux)
*/

if (argc!=2){
    cout<<"Erreur : saisissez le répertoire actuel (.)";
}
else{

    // //basic path of disk in WSL
    string path = "\\\\wsl.localhost\\Debian";

    // //define delimiter
    string delimiter = "\\";
    string arg2(argv[1]);

    if (arg2 == ".") {
        char tmp[256];
        getcwd(tmp, 256);
        string currentPath(tmp);
        replace( currentPath.begin(), currentPath.end(), '/', '\\' );
        path+=currentPath;
        
         //show line to past (because chdir() affect the local process)
         cout<<path<<endl;

    } else {

    cout<<"Erreur : ne gére pas les répertoires distants";
        
    }




    } 


    return 0;

}
