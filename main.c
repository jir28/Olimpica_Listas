#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//29-22 s

int main() {
    int n_p = 4,i,temp2,d;//numero corredores
    float temp1;
    char temp3[n_p];
    srand(time(NULL));

    struct atletas{
        char apellido[50];
        int ncorredor;
        float tiempo;
    }corredor[n_p];

    for (i = 0;i < n_p;i++){
        printf("N. %i Ingrese el apellido del corredor: \n",i+1);
        scanf("%s",corredor[i].apellido);
        printf("N. %i Ingrese el numero del corredor: \n",i+1);
        scanf("%d",&corredor[i].ncorredor);
        corredor[i].tiempo = (rand() % 300)/10.f;
    }

    for (i = 0;i < n_p;i++){
      //  printf("N. %i El apellido del corredor es:  %s\n",i+1,corredor[i].apellido);
        printf("N. %i El n. del corredor es:  %d\n",i+1,corredor[i].ncorredor);
        printf("N. %i El tiempo del corredor:  %.2f\n",i+1,corredor[i].tiempo);
    }

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
    for (i = 0;i < 3;i++){
        printf("N. %i El apellido del corredor es:  %s\n",i+1,corredor[i].apellido);
        printf("N. %i El numero del corredor es:  %d\n",i+1,corredor[i].ncorredor);
        printf("N. %i El tiempo del corredor:  %.2f\n",i+1,corredor[i].tiempo);
    }

    return 0;
}
