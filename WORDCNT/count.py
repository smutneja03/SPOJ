
test_cases = int(raw_input())

while test_cases:

	string = raw_input()
	length_words = []
	words = string.split()
	n = len(words)
	i = 0
	max_count=0;	
	while i < n:
		curr_length = len(words[i])
		i+=1
		curr_count = 1
		while(i<n and curr_length==len(words[i])):
			curr_count +=1
			i+=1
		if(curr_count>max_count):
			max_count = curr_count	
	print max_count
	test_cases-=1