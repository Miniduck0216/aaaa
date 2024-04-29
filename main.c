#include <stdio.h>
#include <string.h>
#define MAX_ESTUDIANTES 10


void mostrarMenu() {

printf("Menú de opciones:\n");

printf("1. INGRESAR ESTUDIANTES\n");

printf("2. INGRESAR NOTAS DE ESTUDIANTES\n");

printf("3. MOSTRAR PROMEDIOS FINALES\n");

printf("4. SALIR\n");

printf("Seleccione una opción: ");
}

int main() {
float notas[MAX_ESTUDIANTES][3];

int opcion;

char estudiantes[MAX_ESTUDIANTES][10];

int numEstudiantes = 0;

char nombre[10];

do {
 mostrarMenu();
 scanf("%d", &opcion);

 switch(opcion) {
 case 1:
 printf("Ingrese el nombre del estudiante (o escriba 'fin' para terminar): \n");
 while (numEstudiantes < MAX_ESTUDIANTES) {
printf("Estudiante %d: ", numEstudiantes + 1);
scanf("%s", nombre);
if (strcmp(nombre, "fin") == 0) {
break;
}
strcpy(estudiantes[numEstudiantes], nombre);
numEstudiantes++;
}
printf("Se ingresaron %d estudiantes.\n", numEstudiantes);
break;
case 2:
printf("Ingrese las notas de los estudiantes:\n");
for (int i = 0; i < numEstudiantes; i++) {
printf("Notas del estudiante %s:\n", estudiantes[i]);
printf("Progreso 1 (35%%): ");
scanf("%f", &notas[i][0]);
printf("Progreso 2 (25%%): ");
scanf("%f", &notas[i][1]);
printf("Progreso 3 (40%%): ");
scanf("%f", &notas[i][2]);
}
printf("Notas ingresadas correctamente.\n");
break;
case 3:
printf("Lista de estudiantes y promedios:\n");
for (int i = 0; i < numEstudiantes; i++) {
float promedio = (notas[i][0] * 0.35) + (notas[i][1] * 0.25) + (notas[i][2] * 0.40);
printf("%d. %s - Promedio: %.2f\n", i + 1, estudiantes[i], promedio);
if (promedio >= 6.0) {
printf("(Aprobado)\n");
} else {
printf("(Reprobado)\n");
}
}
break;
}
} while(opcion != 4);

return 0;
}