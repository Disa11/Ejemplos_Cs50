#casteo de variable

try:
    x = int(input("X: "))
except ValueError:
    print("X solo puede ser un numero")
    exit()

try:
    y = int(input("y: "))
except ValueError:
    print("Y solo puede ser un numero")
    exit()

print(f"\tLa suma es: {x + y} ")