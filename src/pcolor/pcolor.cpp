/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
Modified at: 23/10/2023
**/

#include <cstdio>
#include <string>
#include "pcolor.hpp"
using namespace std;

void print_red(char c)
{
    printf("%s%c", RED, c);
    printf("%s", NORMAL);
}

void print_green(char c)
{
    printf("%s%c", GREEN, c);
    printf("%s", NORMAL);
}

void print_blue(char c)
{
    printf("%s%c", BLUE, c);
    printf("%s", NORMAL);
}

void printStringRed(string str)
{
    for(int i = 0 ; i < (int)str.size() ; i++){
        print_red(str[i]);
    }
}

void printStringGreen(string str)
{
    for(int i = 0 ; i < (int)str.size() ; i++){
        print_green(str[i]);
    }
}

int main(){
    printStringGreen("haha\n");
    return 0;
}