#include "IsValidInput.h"

bool IsValidInput(string option,int start,int end) 
{
    string a[] = {"a","b","c","d","e","f","g","h","i","j","k"};

    for (int i = start; i < end; i++) 
    {
        if (a[i] == option) return true;
    }
    cout<< "Invalid Input... \n\n";
    return false;
}