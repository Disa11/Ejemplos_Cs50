#include <stdio.h>

int main(){
  FILE *archivito;
  char buffer[100] = "Hola Mundo";
  float numero = 3.1416;

  archivito = fopen("text.txt", "a+");
  if(archivito == NULL)
  {
    printf("No se pudo abrir el archivo... \n");
    return -1;
 }

  fputc('H', archivito);
  fputc('o', archivito);
  fputc('l', archivito);
  fputc('i', archivito);
  fputc('\n', archivito);
  fputs(buffer, archivito);
  fprintf (archivito,"\nEsto es un numero con formato %3.3f \n %3.3f", numero,numero);

  fclose(archivito);

  return 0;
}