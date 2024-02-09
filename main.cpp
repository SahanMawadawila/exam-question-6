#include <iostream>
#include <map>
#include <string>
#include<random>
#include<ctime>
#include<sstream>
#include<vector>
using namespace std;

vector< string> split(const string& str, char delimiter) {
    vector<string> tokens; stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;

}

int main() {
  srand(time(0));
  map<string,int> wordsMap;
  string word="";
  int previous_character=0;
  for(int i=0;i<1024;i++){
    int random1=rand()%4;
    while(previous_character==random1){
      random1=rand()%4;
    }
    if(random1==0){
      previous_character=0;
      word+=" ";
    }
    else{
      previous_character=10;
      word+=char(rand()%26+97);
    }
    }
  
  //push all wprds into a vector
  vector<string> words = split(word, ' ');
  
  for(string x:words){
    wordsMap[x]++;
  }

  int counter=97;
  for(auto x:wordsMap){
    if(int(x.first[0])==counter){
      continue;
    }
    else if(int(x.first[0])==counter+1){
      counter++;
    }
    else{
      wordsMap.insert({to_string((counter+1)),0});
      counter++;
    }
    
  }
  for(auto x:wordsMap){
    cout<<x.first<<":"<<x.second<<endl;
  }

  return 0;
}
