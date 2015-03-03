
test_cases = int(raw_input())

while test_cases:
	extra = raw_input()#getting the empty line from the user
	expression = raw_input()
	len_expression = len(expression)
	tmp = 0
	numbers = []
	operators = []

	while tmp <len_expression:
		if(expression[tmp].isdigit()):
			#current character is a digit
			n = expression[tmp]
			tmp+=1
			while(expression[tmp].isdigit()):
				n = n + expression[tmp]
				tmp+=1
			numbers.append(int(n))

		elif(expression[tmp]==' '):
			tmp+=1
		else:
			operators.append(expression[tmp])
			tmp+=1 
	
	index = 0
	ch = operators[index]
	#this operation needs to be performed
	first = numbers[index]
	second = numbers[index+1]
	if(ch=='*'):	
		solution = first * second
	elif(ch=='/'):
		solution = first/second
	elif(ch=='+'):
		solution = first + second
	elif(ch=='-'):
		solution = first - second
	#done with the first set oof operation
	#now we moved to second operand
	index = 1
	length = len(operators) - 2
	#one for the length and one for the equals operator 
	while index <=length:
		n = numbers[index+1]
		ch = operators[index]
		if(ch=='*'):	
			solution = solution * n
		elif(ch=='/'):
			solution = solution/n
		elif(ch=='+'):
			solution = solution + n
		elif(ch=='-'):
			solution = solution - n
		
		index+=1

	print solution

	test_cases-=1