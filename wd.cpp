#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cctype>
#include <unistd.h>
#include <cstring>

using namespace std;

int main(int argc, char **argv){


/*
SHOW COMMANDTO ACCES TO THE DIRECTORY WITH A Windows PATH ON WSL
(Windows Subsystem for Linux)
*/

if (argc!=2){
    cout<<"Erreur : saisissez un chemin absolu - exemple : wd C:\\Users\\Paul\\Documents";
}
else{

    //basic path of disk in WSL
    string path = "/mnt/";

    //define delimiter
    string delimiter = "\\";

    string arg2(argv[1]);

    //get lower case letter of the disk 
    path+=tolower(arg2[0]);
    path+='/';

    //add nods to path
    for(int index=2;index<arg2.length();index++){
        if(arg2[index] == '\\'){
            cout<<index<<endl;  
                path += '/';
        } else {
            if(isupper(arg2[index]) && index>2 && !isupper(arg2[index-1])) {
                path += '/';
                path += arg2[index];
            } else {
                path+=arg2[index];
            }
            
        }
        
    }

    //show line to past (because chdir() affect the local process)
    cout<<"cd ";
    cout<<path<<endl;

    return 0;
}
}
