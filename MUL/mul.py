
test_cases = int(raw_input())
while(test_cases):
	line = raw_input().split()
	first = int(line[0])
	second = int(line[1])
	print first*second
	test_cases-=1