#include<algorithm>
#include<iostream>
#include <sstream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;

#define df(i,a,b) for(typeof(b) i=a;i>=b;i--)
#define f(i,a,b) for(typeof(b) i=a;i<=b;i++)
#define fill(x,a) memset(x,a,sizeof(x))
#define Clear(x) memset(x,0,sizeof(x))
#define inf 2147000000
#define pb push_back
#define mp make_pair
#define Y second
#define X first

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<string> VS;
typedef pair<int,int> ii;
typedef vector<int> VI;



template <class T>
inline void read(T &i)
{
bool minus=false;
char c;
for(c=getchar();(c<'0'||c>'9')&&(c!='-');c=getchar());
if(c=='-')
{minus=true;
c='0';}
for(i=0;c>='0'&&c<='9';c=getchar())
i=(i<<3)+(i<<1) + (c-48);
if(minus)
i=(~i)+1;
}


int gcd(int a,int b)
{
   if(a==b)
     return b;

   if(b<a)
     return gcd(a%b,b);

   return gcd( a, b%a);
}


vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}

/*Solution code starts here */


class HyperKnight {
public:

long countCells(int a, int b, int row, int col, int k)
{
     
int dx[]={-a,-a,a,a,-b,-b,b,b};
int dy[]={-b,b,-b,b,-a,a,a,-a};  

long long ans=0;

long long  dp[260];

memset(dp,0,sizeof(dp) );



for(int mask = 255 ; mask >=0 ; mask-- )
{
        
        int left=0,right=col,down=0,up=row;
        
        int on=0;
        
        for(int i=0;i<8;i++)
          if( mask & (1<<i) )
           {
               if( dx[i] < 0 )    
                left=max(left , -dx[i] );
               else 
               right=min( right , col-dx[i] );
               
               if( dy[i] < 0 )
                 down=max( down , -dy[i] );
               else
                 up = min( up ,  row-dy[i] );
                
                on++;
           }      
                
                
                
              long long h=abs(right-left),w=abs(up-down);
                
              if( left < right && up > down )    
              dp[mask]=h*w;
              
              for(int m=mask+1;m<=255;m++)
               if( (mask & m)==mask )
                  dp[mask]-=dp[m];
                  
               if(on==k)
                ans+=dp[mask];
}
return ans;             
                   

}
	
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, bool hasAnswer, long long p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	HyperKnight *obj;
	long long answer;
	obj = new HyperKnight();
	clock_t startTime = clock();
	answer = obj->countCells(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	int p3;
	int p4;
	long long p5;
	
	{
	// ----- test 0 -----
	p0 = 2;
	p1 = 1;
	p2 = 8;
	p3 = 8;
	p4 = 4;
	p5 = 20ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 2;
	p2 = 8;
	p3 = 8;
	p4 = 2;
	p5 = 16ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 3;
	p2 = 7;
	p3 = 11;
	p4 = 0;
	p5 = 0ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 3;
	p1 = 2;
	p2 = 10;
	p3 = 20;
	p4 = 8;
	p5 = 56ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 1;
	p1 = 4;
	p2 = 100;
	p3 = 10;
	p4 = 6;
	p5 = 564ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 2;
	p1 = 3;
	p2 = 1000000000;
	p3 = 1000000000;
	p4 = 8;
	p5 = 999999988000000036ll;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
