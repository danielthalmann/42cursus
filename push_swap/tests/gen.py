import random
list = random.sample(range(-10, 200), 100)
text = ""
for i in list:
    text += str(i)
    text += " "
print(text)

