#ifndef editor_hpp
#define editor_hpp
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Editor{
private:
    string line, item;
    int position;
    string insertstring;
    
    
public:
    vector <string> v;
    Editor();
    void menu();
    void display();
    void saveFile();
    void insertLine();
    void deleteLine();
    void search();
    void searchReplace();
    int numOfWords();
    
    
    
    
    
    
    
    
    
    
};







#endif


