#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
#define sz(s) ((int)(s.size()))

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
#define maxn 200009

int n;
int in[maxn];

int left_min[maxn];//index of first number( towards left side) that is minimum than curr
int right_min[maxn];//index of first number(towards rigt side) that is minimum than curr

int ans[maxn];

int main()
{

    cin>>n;

    for(int i=1; i<=n; i++)
      cin>>in[i];

    in[0]=in[n+1]=-(1e9+25);

    {
         //calculate right_max
         stack<int> st;
         st.push(n+1);

         for(int i=n;i>=1;i--)
         {
             while( in[st.top()] >= in[i] )//stack in increasing order
                st.pop();

             right_min[i]=st.top();
             st.push(i);
         }

    }

    //cout<<"** right min\n";

    //for(int i=1;i<=n;i++)
     //cout<<right_min[i]<<" ";

    //cout<<"  \n**";


    {
        //calculate left max
        stack<int> st;

        st.push(0);

        for(int i=1;i<=n;i++)
        {
            while( in[st.top()] >= in[i] )
             st.pop();

            left_min[i]=st.top();
            st.push(i);
        }
    }

    //cout<<"** Left min\n";

//    for(int i=1;i<=n;i++)
//     cout<<left_min[i]<<" ";

    //cout<<"  \n**";
     //
    fill(ans,0);

    //cout<<" ** Len is\n";

    for(int i=1;i<=n;i++)
    {
        int len=( i - left_min[i] -1) + ( right_min[i] - i -1) +1;

      //  cout<<len<<" ";

        ans[len]=max( ans[len] , in[i] );
    }

    //cout<<"\n";
    //calculate for len = N
    ans[n]=(1e9)+10;

    for(int i=1;i<=n;i++)
     ans[n]=min( ans[n] , in[i] );

    for(int i=n-1;i>=1;i--)
      ans[i]=max( ans[i] , ans[i+1]);


    for(int i=1;i<=n;i++)
     cout<<ans[i]<<" ";

    return 0;
}
