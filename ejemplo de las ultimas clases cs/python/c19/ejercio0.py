# mandar a pedir al usuario un número x
# para mostrar la tabla de multiplicar
import csv
from cs50 import *

x = get_int('ingrese un número')

for i in range(1,13):
    print(f"{i} * {x} = {x * i}")