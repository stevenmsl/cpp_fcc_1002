#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol940;

/*
Input: ["bella","label","roller"]
Output: ["e","l","l"]
*/
tuple<vector<string>, vector<string>>
testFixture1()
{
  auto input = vector<string>{"bella", "label", "roller"};
  auto output = vector<string>{"e", "l", "l"};
  return make_tuple(input, output);
}

/*
Input: ["cool","lock","cook"]
Output: ["c","o"]
*/

tuple<vector<string>, vector<string>>
testFixture2()
{
  auto input = vector<string>{"cool", "lock", "cook"};
  auto output = vector<string>{"c", "o"};
  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  cout << "Expect to see " << Util::toString(get<1>(f))
       << ": " << Util::toString(sol.findCommonChars(get<0>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  Solution sol;
  cout << "Expect to see " << Util::toString(get<1>(f))
       << ": " << Util::toString(sol.findCommonChars(get<0>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}