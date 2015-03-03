"""
Cn is the number of permutations of 
{1, ..., n} that avoid the pattern 123 (or any of the other patterns of length 3);
that is, the number of permutations with no three-term 
increasing subsequence. For n = 3, these permutations
are 132, 213, 231, 312 and 321. For n = 4,
they are 1432, 2143, 2413, 2431, 3142, 3214, 3241, 3412, 3421, 4132, 4213, 4231, 4312 and 4321.
"""
number = int(raw_input())

catalan_numbers = []
catalan_numbers.append(1)
#first catalan number is 1
for i in range(1, 1002):
	prev = catalan_numbers[-1]
	current = prev*(4*i - 2)/(i+1)
	catalan_numbers.append(current)
#precompute the required catalan numbers
while number:
	print catalan_numbers[number]%1000000
	number = int(raw_input())

"""
Its more of a mathematical question than a coding question. The number of ways in which we can arrange n numbers such that 
there is no increasing subsequence of length 3 is the n'th Catalan number. Refer to wikipedia.
After that it is pretty easy. Howecer the following iterative formula that i have used here to implement in python will give WA in C, 
because of overflow. In implementing in C, use the addition formula to generate the n'th catalan number from the previous n-1.
"""