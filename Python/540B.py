def input_array():
    inp = str( raw_input() );
    A = inp.split();
    return list(map(int, A));

if __name__ == '__main__':
	tp = input_array();
	n = tp[0];
	k = tp[1];
	mx = tp[2];
	sm = tp[3];
	med = tp[4];

	#print(tp);

	prev= input_array();
	ans = [];# will containExtra  added elements

	done = 0;
	for i in range( len(prev)):
		if( prev[i] >= med):
			done+=1;

	#print(done);

	# itna to append karna padega to make med a medium
	for i in range( done , (n+1)/2 ,+1):
		ans.append(med);
		prev.append(med);

	while( len(prev) < n):
		ans.append(1);
		prev.append(1);

	prev = sorted(prev);

	#print(prev);

	#verify sum , sum must be less or equal sm 
	cs =0
	for i in range(n):
		cs+=prev[i];

	#print(cs);

	#verify mediin , (n/2) item ( 0 based index) must be 
	if( (cs>sm) or (prev[n/2]<med)):
		print("-1");
	else:
		for i in range( len(ans)):
			print( ans[i]),
		#print(ans);

	#print(sm);
	#print( prev[n/2]);