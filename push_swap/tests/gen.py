import random
list = random.sample(range(-10, 600), 500)
text = ""
for i in list:
    text += str(i)
    text += " "
print(text)

