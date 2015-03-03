
import math

def get_gcd(a, b):
	if(b==0):
		return a
	else:
		return get_gcd(b, a%b)


test_cases = int(raw_input())

while test_cases:

	number = raw_input()
	if '.' not in number:
		print 1
	else:
		index = number.find('.')
		first_half = number[0:index]
		second_half = number[index+1:]
		length = len(second_half)
		gcd = get_gcd(int(first_half+second_half), pow(10, length))
		#dividing the power of 10 by gcd gives us the number
		#1.25 can be written as 125/100 = 5/4
		#gcd of 125 and 100 gives us a common greatest divisor 
		#using this we can have the greatest denominator that is possible
		#this is equal to the number of games
		print pow(10, length)/gcd

	test_cases-=1
	