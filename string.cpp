#include <string>
#include <stdio.h>

main()
{
  using namespace std;

  string temp;

  temp += 'r';
  temp += 'e';
  temp += 'd';

  if (temp == "red")
    cout << "Matches\n";
  else
    cout << "No match\n";

}