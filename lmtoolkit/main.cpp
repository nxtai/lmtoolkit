//
//  main.cpp
//  lmtoolkit
//
//  Created by Jeppe Hallgren on 01/02/15.
//  Copyright (c) 2015 Jeppe Hallgren. All rights reserved.
//

#include <stdio.h>
#include <iostream>


using namespace std;

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        cout << "Wrong number of arguments supplied, expected 1" << endl;
        exit(-1);
    }
    
    char inputFile [50];
    strcpy(inputFile, argv[1]);
    char outputFile [50];
    
    sprintf(outputFile, "%s.char", inputFile);
    
    FILE* fin = fopen(inputFile, "rb");
    if (fin == NULL) {
        cout << "Error reading input file: " << inputFile << endl;
        exit(-1);
    }
    
    FILE* fout = fopen(outputFile, "w+");
    
    int charCount = 0;
    
    while (!feof(fin)) {
        char ch=fgetc(fin);
        
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            fprintf(fout, "%c ", ch);
        } else if (ch == ' ') {
            fprintf(fout, "_ ");
        } else {
            fprintf(fout, "<unk> ");
        }
        
        charCount++;
    }
    
    cout << "Parsed " << charCount << " characters" << endl;
    return 0;
}
