#guardar la lista del super de una persona 
#debe almacenar el nombre y precio del producto.
#1. crear una lista 
super = []

while(True):
    producto = input("Ingrese nombre del producto: ")
    precio = int(input("Ingrese el precio del producto: "))
    compra = {
        producto: precio
    }
    super.append(compra)
    detener = input("Desea finalizar: S/N")
    if detener == "N":
        break
#recorrer la lista
for i in super: 
    for j in i:
        print(f"El precio de {j} es de {i[j]}")