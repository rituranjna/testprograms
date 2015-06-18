def cando( aval , req):
	ans=1000000;
	assert( len(aval) == len(req) );
	for i in range( len(aval) ):
		if( req[i] > 0):
			ans=min( ans , aval[i]/req[i]);
	assert( ans != 1000000 );
	return ans;

def getCount(input):
	#print(input);
	ans=[ 0 for i in range(26)];
	for i in range( len(input) ):
		#print( ord(input[i]) - ord('a') );
		ans[ ord(input[i]) - ord('a') ]+=1;
	assert( len(ans) == 26);
	#print(ans);
	return ans;

def getResi(aval , req , cont):
	aval=list(aval);
	req=list(req);
	ans = [ 0 for i in range(26)];
	for i in range( len(aval) ):
		ans[i]=aval[i]-req[i]*cont;
	return ans;

#if __name__ == '__main__':


a=str( raw_input() );
b=str( raw_input() );
c=str( raw_input() );

A=getCount(a);

"""print("A value is ");
print(A);
#print( getCount(a) );
#print("yo");
"""
B=getCount(b);
C=getCount(c);

"""print("Before ");
print(A);
"""
maxB=cando(A,B);

#print(A);

#print(maxB);

bc=0;
cc=0;

for i in range(0,maxB+1):
	tb=i;
	rem = getResi(A,B,tb);
	tc= cando(rem,C);

	if( tb + tc > bc + cc):
		bc=tb;
		cc=tc;
#now print ans
ans=[]
for i in range(bc):
	for j in range( len(b) ):
		ans.append( b[j] );

for i in range(cc):
	for j in range( len(c) ):
		ans.append( c[j]);


A=getResi(A,B,bc);


A=getResi(A,C,cc);



for i in range(len(A)):
	for j in range(A[i]):
		ans.append(chr(97+i));

print( ''.join(ans) );


"""
def solve( A, B):
	A= list(A);
	B= list(B);
	B[1]+=10;
	return A;

x=[i for i in range(5)];
y=[i*2 for i in range(5)];

sx=x;
sy=y;

print(x);
sx[0]+=10;
print(x);
print(y);
print("After solving");
x=solve(x,y);
print(x);
print(y);
"""