#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <bitset>

using namespace std;
int main(int argc, char** argv) {
  //string input = string(argv[1]);
  ifstream in(argv[1]);
  vector<string> numbers;
  string line;
  while(getline(in,line)) {
    numbers.push_back(line);
  }

  for(int i = 0; i<numbers.size(); i++) {
    std::istringstream buffer(numbers[i]);
    unsigned long long value;
    buffer >> std::hex >> value;
    bitset<32> b(value);
    string bin = b.to_string();
    string out;
    int counter = 0;
    for(int j = 0; j<bin.length(); j++) {
      out.push_back(bin[j]);
      counter++;
      if(counter%4 == 0) {
        counter = 0;
        out.push_back(' ');
      }
    }
    cout << out << endl;
  }


}
