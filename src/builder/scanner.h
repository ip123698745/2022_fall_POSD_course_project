#pragma once

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Scanner
{
private:
    string _input;
    size_t pos = 0;
    vector<string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "Vector", "(", ")", ","};

    void skipOtherCharacter() {
        while(!(_input[pos] >= 'A' && _input[pos] <= 'Z') && !(_input[pos] >= 'a' && _input[pos] <= 'z') 
           && !(_input[pos] >= '0' && _input[pos] <= '9') && !(_input[pos] == '(') && !(_input[pos] == ')') 
           && !(_input[pos] == ',') && !(_input[pos] == '-') && !(_input[pos] == '\0')) 
        {
            pos++;
        }
    }

public:
    Scanner(string input = "") : _input(input){}

    string next() {
        string result = "";
        skipOtherCharacter();

        for(auto token : tokenList)
        {
            if(_input.compare(pos,token.length(),token) == 0)
            {
                pos += token.length();
                result = token;
                break;
            }
        }

        if(result == ""){
            throw "Invalid Input";
        }

        return result;
    }

    double nextDouble() {
        string result = "";
        skipOtherCharacter();

        if(_input[pos] == '-'){
            result += _input[pos++];
        }

        if(!((_input[pos] >= '0') && (_input[pos] <= '9'))){
            throw "Invalid Input";
        }

        while((_input[pos] >= '0') && (_input[pos] <= '9')){
            result += _input[pos++];
        }

        if(_input[pos] == '.'){
            result += _input[pos++];
        }

        while((_input[pos] >= '0') && (_input[pos] <= '9')){
            result += _input[pos++];
        }

        return stod(result);
    }

    bool isDone() {
        skipOtherCharacter();
        return pos == _input.length();
    }
};
