from hp import personajes

for personaje, casa in personajes.items():
    if "Gryffindor" in casa:
        # casa="UNI"
        print(f"El personaje es: {personaje} y esta en la casa de {casa}")