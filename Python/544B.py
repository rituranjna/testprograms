import sys;

def input_array():
    inp = str( raw_input() );
    A = inp.split();
    return list(map(int, A));

if __name__ == '__main__':
	A=input_array();
	n=A[0];
	req=A[1];

	can = (n*n+1)/2;

	if( can < req):
		print("NO");
		sys.exit();
	
	ans = [['S']*n for i in range(n)]

	for i in range(n):
		for j in range(n):
			if( req > 0):
				if( (i+j)%2 == 0):
					ans[i][j]='L';
					req-=1;

	print("YES");
	for i in range(n):
		print( ''.join(ans[i]) );