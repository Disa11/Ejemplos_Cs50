from cs50 import get_int

scores = []

def main():
    for i in range(3): #[ 0, 1, 2 ]
        score = get_int("Ingrese un numero: ")
        scores.append(score)

    prom = sum(scores) / len(scores)
    print(f"El promedio es {prom}")

if __name__ == "__main__":
    main()