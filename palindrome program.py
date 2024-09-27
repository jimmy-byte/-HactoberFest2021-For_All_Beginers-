# function which return reverse of a string

def isPalindrome(s):
	return s == s[::-1]


# Driver code
s = "malayalam"
ans = isPalindrome(s)  #can take any string

if ans:
	print("Yes")
else:
	print("No")
