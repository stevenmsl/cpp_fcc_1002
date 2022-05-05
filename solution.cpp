#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace sol940;
using namespace std;

/*takeaways
  - for each char ('a' to 'z'), find its
    minimum common number among words
  - Input: ["bella","label","roller"]
    - for 'b' count('b')= min(1,0,0) = 0
    - for 'e' count('e')= min(1,1,1) = 1
    - for 'l' count('l') = min(2,2,2) = 2
    - so the answer is ['e','l','l']

*/

vector<string> Solution::findCommonChars(vector<string> &A)
{
  auto common = vector<int>(26, INT_MAX);

  for (auto w : A)
  {
    auto count = vector<int>(26);
    for (auto c : w)
      count[c - 'a']++;
    for (auto i = 0; i < 26; i++)
      /* record the min common number for each char */
      common[i] = min(common[i], count[i]);
  }

  auto result = vector<string>();

  for (auto c = 'a'; c <= 'z'; c++)
    /* see how many times we need to put this char */
    for (auto i = 0; i < common[c - 'a']; i++)
      result.push_back(string(1, c));

  return result;
}