#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int n_p = 15,i,temp2,d;//numero corredores
    float temp1;
    char temp3[n_p];//variable temporal para los apellidos
    srand(time(NULL));

    struct atletas{
        char apellido[50];
        int ncorredor;
        float tiempo;
    }corredor[n_p];
    //Registro de datos de los corredores
    for (i = 0;i < n_p;i++){
        printf("N. %i Ingrese el apellido del corredor: \n",i+1);
        scanf("%s",corredor[i].apellido);
        printf("N. %i Ingrese el numero del corredor: \n",i+1);
        scanf("%d",&corredor[i].ncorredor);
        corredor[i].tiempo = (rand() % 300)/10.f;//Generamos el tiempo en un rango de 0-30s con flotantes, primera vuelta
    }
    //Ordenamiento de primeros 10 lugares
    for (int x = 0;x <= (n_p-1);x++){
        for(i = 0,d=1;d <= (n_p-1);i++,d++){
            if (corredor[i].tiempo > corredor[d].tiempo){ //Reordenamiento usando el tiempo
                temp1 = corredor[d].tiempo; // tiempo
                temp2 = corredor[d].ncorredor; //Numero de corredor
                memcpy(temp3,corredor[i].apellido,n_p); //Apellido

                corredor[d].tiempo = corredor[i].tiempo;
                corredor[d].ncorredor = corredor[i].ncorredor;
                memcpy(corredor[i].apellido,corredor[d].apellido,n_p);

                corredor[i].tiempo = temp1;
                corredor[i].ncorredor = temp2;
                memcpy(corredor[d].apellido,temp3,n_p);
            }
        }
    }
    //Imprimir primeros 10 lugares
    printf("Etapa 1 \n Primeros 10 lugares\n");
    for (i = 0;i < 10;i++){
        printf("Posicion %i la ocupa:  %s\n",i+1,corredor[i].apellido);
        printf("El numero del corredor es:  %d\n",corredor[i].ncorredor);
        printf("El tiempo del corredor:  %.2f\n",corredor[i].tiempo);
    }

    //Incrementamos mas tiempo a a los corredores para la sgunda vuelta
    for (i = 0;i < n_p;i++){
        corredor[i].tiempo = corredor[i].tiempo + (rand() % 300)/10.f;
    }
    //Ordenamiento de los 5 lugares de la segunda vuelta
    for (int x = 0;x <= (n_p-1);x++){
        for(i = 0,d=1;d <= (n_p-1);i++,d++){
            if (corredor[i].tiempo > corredor[d].tiempo){
                temp1 = corredor[d].tiempo;
                temp2 = corredor[d].ncorredor;
                memcpy(temp3,corredor[i].apellido,n_p);

                corredor[d].tiempo = corredor[i].tiempo;
                corredor[d].ncorredor = corredor[i].ncorredor;
                memcpy(corredor[i].apellido,corredor[d].apellido,n_p);

                corredor[i].tiempo = temp1;
                corredor[i].ncorredor = temp2;
                memcpy(corredor[d].apellido,temp3,n_p);
            }
        }
    }
    //Imprimir los 5 lugares
    printf("Etapa 2\n 5 lugares\n");
    for (i = 0;i < 5;i++){
        printf("Posicion %i la ocupa:  %s\n",i+1,corredor[i].apellido);
        printf("El numero del corredor es:  %d\n",corredor[i].ncorredor);
        printf("El tiempo del corredor:  %.2f\n",corredor[i].tiempo);
    }
    //Incrementamos de nuevo el tiempo, esta es la segunda vuelta
    for (i = 0;i < n_p;i++){
        corredor[i].tiempo = corredor[i].tiempo + (rand() % 300)/10.f;
    }
    //Ordenamiento de los 3
    //Parte final
    for (int x = 0;x <= (n_p-1);x++){
        for(i = 0,d=1;d <= (n_p-1);i++,d++){
            if (corredor[i].tiempo > corredor[d].tiempo){
                temp1 = corredor[d].tiempo;
                temp2 = corredor[d].ncorredor;
                memcpy(temp3,corredor[i].apellido,n_p);

                corredor[d].tiempo = corredor[i].tiempo;
                corredor[d].ncorredor = corredor[i].ncorredor;
                memcpy(corredor[i].apellido,corredor[d].apellido,n_p);

                corredor[i].tiempo = temp1;
                corredor[i].ncorredor = temp2;
                memcpy(corredor[d].apellido,temp3,n_p);
            }
        }
    }

    printf("A continuacion se muestran los ganadores de la carrera: \n");
    for (i = 0;i < 3;i++){
        printf("El ganador N. %i es:  %s\n",i+1,corredor[i].apellido);
        printf("El numero del corredor es:  %d\n",corredor[i].ncorredor);
        printf("El tiempo del corredor:  %.2f\n",corredor[i].tiempo);
    }
    printf("Felicidades a todos");
    return 0;
}
