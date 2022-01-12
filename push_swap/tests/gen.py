import random
list = random.sample(range(0, 600), 500)
text = ""
s = 0
for i in list:
	if s == 1:
		text += " "

	text += str(i)
	s = 1
print(text)

