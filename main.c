

#include "Queue.h"


int main(){
    char *choice;
    printf("Witaj w symulacji kolejki wybierz jedną z dostepnych opcji:\n");
    do{
    printf("1.Uruchom symulacje za pomocą pliku.\n2.Ustaw parametry symulacji recznie.\n3.Koniec.\n");
    scanf("%s",choice);
    if(!strcmp(choice,"1")){
        char *fname = malloc(20*sizeof(char));
        printf("Podaj nazwe pliku: ");
        scanf("%s",fname); 
        fileSimulation(fname);
        free(fname);
        return 0;
    }
    else if(!strcmp(choice,"2")){
        manualSimulation();
        return 0;
    }
    else if(!strcmp(choice,"3")){
        remove("queueStats");
        return 0;
    }
    else{
        printf("Podano nieoczekiwana wartosc!\n Wybierz jedna z dostepnych opcji.\n");
    }
    } while(choice);

   
}