#include <iostream>
#include <string>

using namespace std;

string key(int dial){
  string word[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  return word[dial];
}

int keypad(int num, string output[]){
  if(num == 0){
    output[0] = "";
    return 1;
}
  int digit = num % 10;
  string word = key(digit);
  int smallInput = num / 10;
  string smallOutput[1000];
  int smallOutputSize = keypad(smallInput, smallOutput);
  
  int count=0;
  for(int i=0; i < word.size(); i++){
    for(int j=0; j< smallOutputSize; j++){
      output[count++] =  smallOutput[j] + word[i];
    }
  }
  return count;
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
