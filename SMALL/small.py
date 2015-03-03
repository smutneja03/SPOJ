
def gcd(a, b):
	if(b==0):
		return a
	else:
		return gcd(b, a%b)

def lcm(a, b):
	solution = (a*b)/gcd(a, b)
	return solution

test_cases = int(raw_input())

solution = [1, 1]

for i in range(2, 10002):
	solution.append(lcm(solution[i-1], i)) 

while test_cases:

	number = int(raw_input())
	sol = solution[number]
	print sol%1000000007
	test_cases-=1
