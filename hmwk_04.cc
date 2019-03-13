// Bhatta, Yubaraj
// yxb4124
// 2019-03-06
// C74767CF6

#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

void processToken(string token)
{

  regex FPP ("^[0-9]+[)][(][0-9]+$");
  regex STR ("^[|][A-Z0-9]*[+]$");
  regex INT ("^[#][0-9r-wR-W]+$");

  if (regex_match(token, FPP))
  {
    cout << ">" << token << "< matches FP." << endl;
  }
  else if (regex_match(token, STR))
  {
    cout << ">" << token << "< matches STR." << endl;
  }
  else if (regex_match(token, INT))
  {
    cout << ">" << token << "< matches INT." << endl;
  }
  else
  {
    cout << ">" << token << "< does not match." << endl;
  }
}
  int main(int argc, char *argv[])
  {
  
    if (argc > 1)
    {
      cout << "processing tokens from " << argv[1] << " ...\n";

      ifstream inputFile;
      string token;

      inputFile.open(argv[1]);

      if (inputFile.is_open())
      {
        while (inputFile >> token)
        {
          processToken(token);
        }
        inputFile.close();
      }
      else
      {
        cout << "unable to open " << argv[1] << "?\n";
      }
    }
    else
    {
      cout << "No input file specified.\n";
    }
  }
