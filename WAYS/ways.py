def f(n):
	return 2 if n==1 else f(n-1)*(4*n-2)/n
t=int(raw_input())
while t:
	n=int(raw_input())
	print f(n)
	t-=1