
try:
    x = int(input("X: "))
except ValueError:
    print("X tiene que ser un numero")
    exit()
try:
    y = int(input("y: "))
except Exception as e:
    print("Y tiene que ser un numero")
    print(e)
    exit()

print(f"L a suma es: {x + y}")
#print("La suma es: {}").format(x + y)