#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#define AMARILLO_T "\x1b[33m"
#define RESET_COLOR    "\x1b[0m"
#define MAGENTA_T  "\x1b[35m"
#define  ROJO_T     "\x1b[31m"
#define  VERDE_T     "\x1B[32m"
#define NUM_OPCIONES 8
struct Alumno {
    char nombre[50];
    int edad;
    char matricula[50];
    float promedio;
    char carrera[50];
};

struct Nodo {
    struct Alumno alumno;
    struct Nodo *sig;
};
struct Nodo* buscarAlumno(struct Nodo *lista, char matricula[20]);
void mostrarMatriculasActuales(char **matriculas, int cantidadMatriculas) ;
void gotoxy(int x, int y);
void insertarAlumnoCuadro(int a, int b);
void agregarAlumno(struct Nodo **lista, struct Alumno nuevoAlumno);
void mostrarAlumno(struct Alumno alumno);
void eliminar(struct Nodo **lista, char matricula[50]);
void modificarAlumno(struct Nodo *lista, char matricula[20]);
void representacionGrafica(struct Nodo *lista, struct Alumno alumno);
void almacenarEnArchivo(struct Nodo *lista);

struct Nodo *leerDesdeArchivo(struct Nodo *principio);
void cuadrito(int a, int b);
void ordenarLista(struct Nodo **lista);
void intercambiarNodos(struct Nodo *a, struct Nodo *b);
void matricula(int a , int b);
	void margen(int c,int f);
int main() {
    char tecla;
    int opcion = 0,i,cantidadMatriculas = 0;
    struct Nodo *lista = NULL;
	struct Alumno nuevoAlumno;
	char matriculaBuscar[20],**matriculas = NULL;  
    char nombres[NUM_OPCIONES][17] = {
        "Ingresar datos",
        "Eliminar alumno",
        "Buscar alumno",
        "Modificar datos",
        "Ordenar lista",
        "Almacenar",
        "Leer",
        "Salir"
    };
    do {
        system("cls");
        margen(1, 1);
        gotoxy(40, 3);
        printf("C O N T R O L  D E  A L U M N O S ");
        for ( i = 0; i < 9; i++) {
            gotoxy(19, 8 + i);
            if (i == opcion) {
                printf("> %s", nombres[i]);
            } else {
                printf("  %s", nombres[i]);
            }
        }
        tecla = getch();

        switch (tecla) {
        case 72: 
            if (opcion > 0) {
                opcion--;
            }
            break;

        case 80: 
            if (opcion < 7) {
                opcion++;
            }
            break;
        case 13: 
            switch (opcion) {
                case 0:
                    system("pause");
                    system("cls");
                    insertarAlumnoCuadro(15,6);
                    gotoxy(50,7); printf("Ingreso de Alumnos");
                    struct Alumno nuevoAlumno;
                    gotoxy(48,10); scanf("%s", nuevoAlumno.matricula);
                    gotoxy(48,12);fflush(stdin);gets( nuevoAlumno.nombre);
                    gotoxy(48,14); scanf("%d", &nuevoAlumno.edad);
                    gotoxy(48,16); scanf("%f", &nuevoAlumno.promedio);
                    gotoxy(48,18);scanf("%s", nuevoAlumno.carrera);
                    gotoxy(40,24);agregarAlumno(&lista, nuevoAlumno);
                     char **nuevasMatriculas = realloc(matriculas, (cantidadMatriculas + 1) * sizeof(char *));
            if (nuevasMatriculas != NULL) {
                matriculas = nuevasMatriculas;
                matriculas[cantidadMatriculas] = strdup(nuevoAlumno.matricula);
                cantidadMatriculas++;
            }
                    printf("Alumno agregado.\n");
                      mostrarMatriculasActuales(matriculas, cantidadMatriculas);
                    gotoxy(60,24);system("pause");
                    break;

                case 1:
                       {
                    system("pause");
                    system("cls");
                    gotoxy(45,1);printf("Eliminar Alumno");
                    matricula(26, 3);
                    gotoxy(8,4); printf("Matr%ccula ",161);
                     gotoxy(28,4); scanf("%s", matriculaBuscar);
                        gotoxy(50,10);printf("Buscando.");sleep(1); gotoxy(50,10);printf("          ");
                    	gotoxy(50,10);printf("Buscando..");sleep(1);gotoxy(50,10);printf("          ");
                    	gotoxy(50,10);printf("Buscando...");sleep(2);gotoxy(50,10);printf("           ");
                    struct Nodo *alumnoEncontrado = buscarAlumno(lista, matriculaBuscar);
                    if (alumnoEncontrado != NULL) {
                    	insertarAlumnoCuadro(15,6);
                    	gotoxy(45,8);printf("Datos del alumno ");
                        mostrarAlumno(alumnoEncontrado->alumno);
                          mostrarMatriculasActuales(matriculas, cantidadMatriculas);
                        gotoxy(8,26);printf("Desea eliminar este alumno? (1: Si / 0: No): ");
                        int respuesta,i;
                        scanf("%d", &respuesta);
                        if (respuesta==1) {
                            eliminar(&lista, matriculaBuscar);
                            mostrarMatriculasActuales(matriculas, cantidadMatriculas);
                        }  
                    } else {	
                       gotoxy(42,10);printf(ROJO_T "Alumno no encontrado.\n"RESET_COLOR);
                    }
                }
                    gotoxy(60,24);system("pause");
                    system("cls");
                        break;
                case 2:
                     {
                    system("pause");
                    system("cls"); matricula(26, 3);
                   gotoxy(8,4); printf("Matr%ccula ",161);
                   gotoxy(28,4);  scanf("%s", matriculaBuscar);
                   gotoxy(50,10);printf("Buscando.");sleep(1); gotoxy(50,10);printf("          ");
                   gotoxy(50,10);printf("Buscando..");sleep(1);gotoxy(50,10);printf("          ");
                   gotoxy(50,10);printf("Buscando...");sleep(2);gotoxy(50,10);printf("           ");
                    struct Nodo *alumnoEncontrado = buscarAlumno(lista, matriculaBuscar);
                    if (alumnoEncontrado != NULL) {
                    	insertarAlumnoCuadro(15,6);gotoxy(45,8);printf("Datos del alumno ");
                        mostrarAlumno(alumnoEncontrado->alumno);
                    } else {
                    	
                      gotoxy(42,10);printf(ROJO_T "Alumno no encontrado.\n"RESET_COLOR);
                    }
                    gotoxy(60,24);system("pause");
                    system("cls");
                        break;
              case 3:
    {
        system("pause");
        system("cls");
        matricula(26, 3);
        gotoxy(8, 4); printf("Matr%ccula ", 161);
        gotoxy(28, 4); scanf("%s", matriculaBuscar);
        gotoxy(50, 10); printf("Buscando.");
        sleep(1);
        gotoxy(50, 10); printf("          ");
        gotoxy(50, 10); printf("Buscando..");
        sleep(1);
        gotoxy(50, 10); printf("          ");
        gotoxy(50, 10); printf("Buscando...");
        sleep(2);
        gotoxy(50, 10); printf("           ");
        struct Nodo *alumnoEncontrado = buscarAlumno(lista, matriculaBuscar);
        if (alumnoEncontrado != NULL) {
            insertarAlumnoCuadro(15, 6);
            gotoxy(45, 8); printf("Datos del alumno ");
     
            gotoxy(48, 10); scanf("%s", alumnoEncontrado->alumno.matricula);
            gotoxy(48, 12); scanf("%s", alumnoEncontrado->alumno.nombre);
            gotoxy(48, 14); scanf("%d", &alumnoEncontrado->alumno.edad);
            gotoxy(48, 16); scanf("%f", &alumnoEncontrado->alumno.promedio);
            gotoxy(48, 18); scanf("%s", alumnoEncontrado->alumno.carrera);
            gotoxy(40, 20); printf("Datos modificados con %cxito.\n", 130);
        }
        else {
            gotoxy(42, 10); printf(ROJO_T "Alumno no encontrado.\n" RESET_COLOR);
        }
        gotoxy(60, 24); system("pause");
        system("cls");
        break;
    }
                case 4:
                
                    system("cls");
                    gotoxy(40,1);
                    printf(AMARILLO_T"L i s t a   O r d e n a d a"RESET_COLOR);
                    ordenarListaPorNombre(&lista);
                    imprimirLista(lista);
                      gotoxy(60, 24); system("pause");
                      system("cls");
                    break;
                case 5:
                    almacenarEnArchivo(lista); 
                    break;

                case 6:
                     lista=leerDesdeArchivo(lista);
                    break;
                case 7:
                    printf("\nSaliendo.\n");
                    exit(0);
            }
            break;
}
        default:
            for ( i = 0; i < 8; i++) {
                if (tolower(tecla) == tolower(nombres[i][0])) {
                    opcion = i;
                    break;
                }
            }
            break;
}
    } while (1);

    return 0;
}

void margen(int c,int f)
{
	int i,a=20;
		gotoxy(c,f);
	printf(AMARILLO_T"%c",218);
	//cuadro pqueño
		gotoxy(a+18,f+1);
	printf("%c",218);
		gotoxy(a+18,f+2);
	printf("%c",179);
		gotoxy(a+57,f+2);
	printf("%c",179);
		for(i=0;i<38;i++)
	{
		//-
	gotoxy((a+18)+(i*1)+1,2);
	printf("%c",196);
					//-
	gotoxy((a+18)+(i*1)+1,4);
		printf("%c",196);
	}
	
gotoxy((a+18)+(i*1)+1,2);
printf("%c",191);
gotoxy((a+18)+(i*1)+1,4);
printf("%c",217);
gotoxy(a+18,f+3);
printf("%c",192);
	//cuadro grande 
	for(i=0;i<117;i++)
	{
		//-
	gotoxy(c+(i*1)+1,f);
	printf("%c",196);

			
					//-
	gotoxy(c+(i*1)+1,28);
		printf("%c",196);
	}
	
	gotoxy(c+(i*1)+1,f);
	printf("%c",191);
		
		for(i=0;i<26;i++)
	{
		//l
	gotoxy(c,f+(i*1)+1);
	printf("%c",179);
	gotoxy(119,f+(i*1)+1);
	printf("%c",179);
	
	}
    gotoxy(c,f+(i*1)+1);
	printf("%c",192);
	gotoxy(119,f+(i*1)+1);
	printf("%c"RESET_COLOR,217);
	
}

//windows
 void gotoxy(int x,int y)
 {  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }


struct Nodo* buscarAlumno(struct Nodo *lista, char matricula[20]) {
    while (lista != NULL) {
        if (strcmp(lista->alumno.matricula, matricula) == 0) {
            return lista;
        }
        lista = lista->sig;
    }
    return NULL;
}
void matricula(int a , int b)
{
	int i;
		gotoxy(a,b);printf("%c",218);
		gotoxy(a,b+2);printf("%c",192);
	for(i=0;i<60;i++)
	{
		gotoxy(a+(i*1)+1,b);printf("%c",196);
		gotoxy(a+(i*1)+1,b+2);printf("%c",196);
	}
		gotoxy(a+(i*1)+1,b);printf("%c",191);
		gotoxy(a+(i*1)+1,b+2);printf("%c",217);
	for(i=0;i<1;i++)
	{
		gotoxy(a,b+(i*1)+1);printf("%c",179);
		gotoxy(a+61,b+(i*1)+1);printf("%c",179);
	}
}
void insertarAlumnoCuadro(int a,int b)
{
	int i;
  	gotoxy(a,b);
	printf("%c",218);
	 gotoxy(18,10); printf("Matricula");
	 gotoxy(18,12);printf("Nombre");
	 gotoxy(18,14);printf("Edad");
	 gotoxy(18,16);  printf("Promedio");
	 gotoxy(18,18);printf("Carrera");
	 	
	 for(i=0;i<10;i++)
	{
	gotoxy(a+30,b+3+(i*1)+1);	
	printf("%c",179);		
	}
	for(i=0;i<86;i++)
	{
	gotoxy(a+(i*1)+1,b);	
	printf("%c",196);		
	}
	gotoxy(a+(i*1)+1,b);
	printf("%c",191);
	
	for(i=0;i<86;i++)
	{
	gotoxy(a+(i*1)+1,b+3);	
	printf("%c",196);
	gotoxy(a+(i*1)+1,b+5);	
	printf("%c",196);
	gotoxy(a+(i*1)+1,b+9);	
	printf("%c",196);
	gotoxy(a+(i*1)+1,b+7);	
	printf("%c",196);
	gotoxy(a+(i*1)+1,b+11);	
	printf("%c",196);	
	gotoxy(a+(i*1)+1,b+13);	
	printf("%c",196);		
	}
		for(i=0;i<12;i++)
	{
	gotoxy(a,b+(i*1)+1);	
	printf("%c",179);		
	}
	gotoxy(a,b+(i*1)+1);
	printf("%c",192);
		for(i=0;i<12;i++)
	{
	gotoxy(102,b+(i*1)+1);	
	printf("%c",179);		
	}
		gotoxy(102,b+(i*1)+1);	
	printf("%c",217);
	
}
//FUNCIONES DE ALUMNO	
void agregarAlumno(struct Nodo **lista, struct Alumno nuevoAlumno) {
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevoNodo->alumno = nuevoAlumno;
    nuevoNodo->sig = *lista;
    *lista = nuevoNodo;
}
void mostrarAlumno(struct Alumno alumno) {

    gotoxy(48,10);printf("%s", alumno.matricula);
    gotoxy(48,12);printf("%s", alumno.nombre);
    gotoxy(48,14);printf("%d", alumno.edad);
    gotoxy(48,16);printf("%.2f", alumno.promedio);
   	gotoxy(48,18);printf("%s", alumno.carrera);
}


void eliminar(struct Nodo **lista, char matricula[50])
{
	struct Nodo *actual=*lista;
	struct Nodo *anterior= NULL;
	while(actual!=NULL&&strcmp(actual->alumno.matricula,matricula)!=0)
	{	anterior=actual;
		actual=actual->sig;	
	}
	  if (actual != NULL) {
        if (anterior == NULL) {
            *lista = actual->sig;
        } else {
            anterior->sig = actual->sig;
        }
        free(actual);
        gotoxy(20,20);
        printf(VERDE_T " Alumno eliminado.\n " RESET_COLOR);
    } else {
        printf(ROJO_T " Alumno no encontrado.\n " RESET_COLOR);
    }	
}

void modificarAlumno(struct Nodo *lista, char matricula[20]) {
    struct Nodo *alumnoEncontrado = buscarAlumno(lista, matricula);

    if (alumnoEncontrado != NULL) {
        gotoxy(48,10);scanf("%s", alumnoEncontrado->alumno.matricula);
        gotoxy(48,12); scanf("%s", alumnoEncontrado->alumno.nombre);
        gotoxy(48,14);scanf("%d", &alumnoEncontrado->alumno.edad);
        gotoxy(48,16);scanf("%f", &alumnoEncontrado->alumno.promedio);
        gotoxy(48,18);scanf("%s", alumnoEncontrado->alumno.carrera);
        gotoxy(40,20);printf("Datos modificados con %cxito.\n",130);
    } 
}



void almacenarEnArchivo(struct Nodo *lista) {
    FILE *archivo;
    archivo = fopen("archivo_alumnos.txt", "w");
    if (archivo == NULL) {
        printf("Error .\n");
        return;
    }

    while (lista != NULL) {
		fprintf(archivo, "%s %s %d %.2f %s\n", lista->alumno.matricula, lista->alumno.nombre, lista->alumno.edad, lista->alumno.promedio, lista->alumno.carrera);
        lista = lista->sig;
    }

    fclose(archivo);
    printf(VERDE_T"Datos almacenados.\n"RESET_COLOR);
    getch();
}




void cuadrito(int a, int b)
{
	int i;
		gotoxy(a+20,b+1);
	printf(MAGENTA_T"|->");
	for(i=0;i<10;i++)
	{
		gotoxy(a+(i*2)+1,b);
		printf("%c",196);
		gotoxy(a+(i*2)+1,b+2);
		printf("%c",196);
	}
	gotoxy(a,b+1);
	printf("|");
   gotoxy(a+15,b+1);
	printf("|"RESET_COLOR);
}



void cua(int a, int b)
{
	int i;
		gotoxy(a+36,b+1);
	printf(AMARILLO_T"|");
	for(i=0;i<18;i++)
	{
		gotoxy(a+(i*2)+1,b);
		printf("%c",196);
		gotoxy(a+(i*2)+1,b+2);
		printf("%c",196);
	}
	gotoxy(a,b+1);
	printf("|"RESET_COLOR);

}


void mostrarMatriculasActuales(char **matriculas, int cantidadMatriculas) {
 
    int i;
    for ( i = 0; i <cantidadMatriculas; i++) {
    	 cuadrito(1+(i*24)+1,21);
    	gotoxy(5+(i*24)+1,22);
        printf("%s ", matriculas[i]);
    }
    printf("\n");
}

void ordenarListaPorNombre(struct Nodo **lista) {
    if (*lista == NULL || (*lista)->sig == NULL) {
    
        return; 
         
    }

    struct Nodo *i, *actual;
    for (i = *lista; i != NULL; i = i->sig) {
        for (actual = i->sig; actual != NULL; actual = actual->sig) {
            if (strcmp(i->alumno.nombre, actual->alumno.nombre) > 0) {
                intercambiarNodos(i, actual);
            }
        }
    }
   
}

void intercambiarNodos(struct Nodo *a, struct Nodo *b) {
    struct Alumno aux = a->alumno;
    a->alumno = b->alumno;
    b->alumno = aux;
}
void imprimirLista(struct Nodo *lista) {
	int i;
    while (lista != NULL) {
       gotoxy(10,4+(i*2)+1);
        printf("%d.-%s",i,lista->alumno.nombre);
        lista = lista->sig;
        i++;
        printf("\n");
    }

    printf("\n");
   
}

struct Nodo *leerDesdeArchivo(struct Nodo *principio) {
    FILE *archivo;
    char matricula[50], nombre[50], carrera[50];
    int edad;
    float promedio;

    archivo = fopen("archivo_alumnos.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return principio;
    }

    while (fscanf(archivo, "%s %s %d %f %s\n", matricula, nombre, &edad, &promedio, carrera) == 6) {
        struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
        if (nuevo == NULL) {
            printf("Error de asignación de memoria.\n");
            fclose(archivo);
            return principio;
        }

        strcpy(nuevo->alumno.matricula, matricula);
        strcpy(nuevo->alumno.nombre, nombre);
        nuevo->alumno.edad = edad;
        nuevo->alumno.promedio = promedio;
        strcpy(nuevo->alumno.carrera, carrera);
        nuevo->sig = principio;
        principio = nuevo;
    }

    fclose(archivo);

    printf(VERDE_T "Datos leídos correctamente.\n" RESET_COLOR);
    return principio;
}

// Llamada desde el main:
// lista = leerDesdeArchivo(lista);

