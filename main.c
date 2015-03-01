/* Supponi di avere in memoria una matrice rettangolare N X M di numeri interi 
 * indicatnti l'altezza di alcune persone. Qual'è la persona più alta: la più
 * bassa tra le più alte di ogni riga, oppure la più alta tra le più basse di
ogni colonna? */

#include <stdio.h>
#include <stdlib.h>

const int N=4;
const int M=5;

int main(int argc, char** argv) {
    int persone[N][M];
    int basso_tra_alti, alto_tra_bassi, alto_riga, basso_colonna;
    int y,x;
    
    printf("Inserisci l'altezza delle persone (in cm) nella matrice: \n");
    printf("Riga|Colonna\n");
    for(y=0; y<N; y++) {
        for(x=0; x<M; x++) {
            printf("%d|%d : ", y,x);
            scanf("%d", &persone[y][x]);
        }
        printf("\n");
    }
    
    for(y=0; y<N; y++) {
        for(x=0; x<M; x++) {
            printf("%d\t", persone[y][x]);
            if (x==0) {
                alto_riga=persone[y][0];
            }
            if (persone[y][x]>alto_riga) {
                alto_riga=persone[y][x];
            }
        }
        
        if (y==0){
                basso_tra_alti=alto_riga;
            }
        if (alto_riga<basso_tra_alti) {
            basso_tra_alti=alto_riga;
        }
        printf("%d\n", alto_riga);
    }
    printf("\n");
    for(x=0; x<M; x++) {
        for(y=0; y<N; y++) {
            if (y==0) {
                basso_colonna=persone[0][x];
            }
            if (persone[y][x]<basso_colonna) {
                basso_colonna=persone[y][x];
            }
        }
        
        if (x==0){
                alto_tra_bassi=basso_colonna;
            }
        if (basso_colonna>alto_tra_bassi) {
            alto_tra_bassi=basso_colonna;
        }
        printf("%d\t", basso_colonna);
    }
    printf("\n");
    printf("Il più basso tra i più alti di ogni riga e': %d\n", basso_tra_alti);
    printf("Il più alto tra i più bassi di ogni colonna e': %d\n", alto_tra_bassi);
    
    if (alto_tra_bassi>basso_tra_alti) {
        printf("Il più alto tra i più bassi di ogni colonna è più alto del più basso tra i più alti di ogni riga.\n");
    }
    else if (alto_tra_bassi<basso_tra_alti) {
        printf("Il più basso tra i più alti di ogni riga è più alto del più alto tra i più bassi di ogni colonna.\n");
    }
    else printf("Il più alto tra i più bassi di ogni colonna ha la stessa altezza del più basso tra i più alti di ogni riga.\n");
    return (EXIT_SUCCESS);
}

