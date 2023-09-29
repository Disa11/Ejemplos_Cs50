
list = []

for i in range(5):
    word = input("Ingrese algo: ")
    list.append(word)

list.sort(reverse=True)

for Item in list:
    print(Item)

for n in range(len(list)):
    print(list[n])