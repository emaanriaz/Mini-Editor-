#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "editor.h"
#include <string>
#include <unistd.h>
using namespace std;


Editor::Editor() {
  ifstream file ("editor.txt");
  while (getline(file, line)){
    v.push_back(line);
  }
  file.close();
}
    
void Editor:: menu(){
  char answer;
  cout<< "Welcome! This is a mini editor program. Here is what your file looks like: " << endl<< endl;
  sleep(2);
  display();
  sleep(2);
  // displays editing options to user:
  cout <<endl << "You have 4 editing options: "<< endl << "Press 'i' to insert a word/sentence" << endl << "Press 'd' to delete a line" << endl << "Press 's' to search for a sentence" << endl << "Press 'r' to search and replace a sentence" << endl << "Press 'n' to get the number of words in the file "<< endl << endl<< "Choose one:  "; 
  cin >> answer;
  
  do {
  if (answer == 'i'){
    insertLine();
    cout << endl<< "*Select another editing option (i, d, s, r, n) or press 'e' to exit*  "; // pressing any other letters will take user to function. Do while loop continues until user presses 'e' to exit. 
    cin >> answer;
  }
  else if (answer == 'd'){
    deleteLine();
    cout << endl << "*Select another editing option (i, d, s, r, n) or press 'e' to exit*  ";
    cin>> answer;
  }
  else if (answer == 's'){
    search();
    cout << endl << "*Select another editing option (i, d, s, r, n) or press 'e' to exit*  ";
    cin>> answer;
  }
  else if (answer == 'r'){
    searchReplace();
    cout <<endl << "*Select another editing option(i, d, s, r, n) or press 'e' to exit*  ";
    cin>> answer;
  }
  else if (answer == 'n'){
    cout<< endl << "Number of Words:  " << numOfWords()<< endl;
    cout <<endl << "*Select another editing option (i, d, s, r, n) or press 'e' to exit*  ";
    cin>> answer;
  }
  } while (answer != 'e');
  if (answer == 'e'){
    cout<< "*You are now exiting the Editor program*"<< endl;
  }
}  

void Editor::display(){
  for (int i=0; i<v.size(); i++){
    cout << i+1 << ")  " << v[i]<< endl;
  }
}
    
void Editor::insertLine(){
  int position=0;
  cout<<endl<< "Enter a word/sentence to insert:  ";
  cin.get();
  getline(cin, line);
  cout<< "Where would you like to insert this word/sentence? (Enter line number):  ";
  cin >> position;
  v.insert(v.begin()+(position-1), line);
  cout << endl << "*UPDATED FILE* "<< endl;
  sleep(1);
  display();
} 

void Editor::deleteLine(){
  int position;
  cout<< "To delete a line a line, enter the line number:  ";
  cin >> position;
  v.erase(v.begin()+(position-1));
  cout << endl << "*UPDATED FILE* "<< endl;
  sleep(1);
  display();
}

void Editor::search(){ 
  int count = 0;
  cout<< endl<<"Enter the sentence you would like to search for:  ";
  string word;
  cin.get();
  getline(cin, word); 
  int pos;
  pos = (find(v.begin(), v.end(), word) - v.begin());
  
  if (line.find(word)){
    cout << "'" << word << "' was found at line " << pos+1 << endl;
  }
  else cout << word << " was not found!"<< endl;
 
  
}

void Editor::searchReplace(){
  cout << endl<<"Enter the sentence you would like to replace:  ";
  string searchedLine, replacedLine;
  cin.get();
  getline(cin,searchedLine);
  
  if (line.find(searchedLine)){
  cout <<"Enter the sentence you would like to replace it with:  ";
  getline(cin, replacedLine);
  
  replace(v.begin(), v.end(), searchedLine, replacedLine);
  cout << endl << "*UPDATED FILE* "<< endl;
  
  sleep(1);
  display(); 
  }
  
}

int Editor::numOfWords(){
  ifstream file("editor.txt");
  string word;
  int numWords=0;
  while (file >> word) {
    ++numWords;
  }
  return numWords;
  
}