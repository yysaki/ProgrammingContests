/**
 * SRM 559 div2 mid
 * 30•ªl‚¦‚Ä•ª‚©‚ç‚¸AEditorial‚ğ“Ç‚ñ‚Å‰ğ“š
 * –â‘è‚ğ—‰ğ‚µ‚Ä}¦‚·‚é‰ß’ö‚ğçT‚¢‚½
 * http://apps.topcoder.com/wiki/display/tc/SRM+559
 */

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class HyperKnight {

	public: long long countCells(int a, int b, int numRows, int numColumns, int k) {
	  const int A = max(a,b);
	  const int B = min(a,b);

	  long long ans = 0;
	  if(k==2) ans = 4LL*B*B;
	  if(k==3) ans = 8LL*B*(A-B);
	  if(k==4) ans = 2LL*(numRows-2*A)*B + 2LL*(numColumns-2*A)*B+4LL*(A-B)*(A-B);
	  if(k==6) ans = 2LL*(numRows-2*A)*(A-B) + 2LL*(numColumns-2*A)*(A-B);
	  if(k==8) ans = 1LL*(numRows-2*A)*(numColumns-2*A);

		return ans;
	}

};
