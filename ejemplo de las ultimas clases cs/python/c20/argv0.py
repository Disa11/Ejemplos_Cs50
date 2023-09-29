from sys import argv

if len(argv) >= 2:
    for  i in argv[1:]:
        print(f"{i}")

else:
    print("hello, world")


