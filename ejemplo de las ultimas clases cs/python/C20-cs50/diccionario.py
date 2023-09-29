grupoH = {
    "Allan": 80,
    "Itzel": 100,
    "Knauth": 20,
    "Enrique": [20 ,30 ,40]
}
print(grupoH["Allan"])
#agregamos clave y valor al diccionario
grupoH["Juan"] = 85 
#modificar 
grupoH["Enrique"] = 10
#borramos clave y valor de el diccionario
grupoH.pop("Knauth")
#recorremos diccionario 
for estudiantes in grupoH:
    print(f"La nota de {estudiantes} fue de {grupoH[estudiantes]}")
#almacenar en una lista las claves del diccionario 
lista_llave = grupoH.keys()
#almacenar en una lista los valores del diccionario
lista_valores = grupoH.values()
print(lista_llave)
print(lista_valores)