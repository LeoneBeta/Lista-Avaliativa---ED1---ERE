#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"
#include "ProblemJosephus.h"

/*Algumas partes de código estão comentadas pois foi uma tentativa de fazer com que o drum fosse uma lista
circular, mas por algum motivo o programa estva dando "Segment Fault" não consegui encontrar o erro, então
utilizei o drum como um vetor de 6 posições apenas, mas mantive o codigo para futuras atualizações*/

void removeEnter(char string[]){
	int tamanho = strlen(string) - 1;
	if (string[tamanho] == '\n'){
		string[tamanho] = '\0';
	}else {
		while (getc(stdin) != '\n')
			continue;
	}
}

void sitPlayers(list l, int players){
    system("clear");
    int i;
    TElement e;
    //Jogadores se sentam em volta da mesa
    for(i=1;i<=players;i++){
        e.key = i;
        setbuf(stdin,NULL);
        printf("\nNome do Jogador %d:",i);
        fgets(e.name,20,stdin);
        removeEnter(e.name);
        insertEnd(l,e);
    }
}

//void setDrum(listDrum drum){
//    int i;
//    TElementDrum e;
//    for(i=1;i<=6;i++){
//        e.key = i;
//        e.slot = 0;
//        insertEndDrum(drum,e);
//    }
//}

void game(list l, int players){
    system("clear");
    //listDrum drum;
    int posCartucho = 0,aux,i=0;
    char enter[3];
    int drum[6];

    for(i=0;i<6;i++)
        drum[i] = 0;


    srand(time(NULL));
    //Criando a Lista Drum
    //drum = creatListDrum();
    //Inserindo os espaços no Drum sem munição
    //setDrum(drum);


    posCartucho = (rand()%6)+1;         //Gera um valor aleatório entre 1 e 6, as posições possiveis no Drum do revolver
    drum[posCartucho - 1] = 1;
    
    
    //setCurrentDrum(drum,posCartucho);   //Seta o ponteiro current no lugar em que a munição será inserida
    //drum->current->info.slot = 1;       //Insere o valor '1' na posição do Drum (Munição colocada no lugar)

    //setCurrentDrum(drum,1);             //Seta o ponteiro current na primeira posição do drum
    setCurrent(l,1);                    //Seta o ponteiro current no primeiro jogador

    printf("\nJogador %s colocou uma munição da arma",l->current->info.name);
    i=0;
    do{                                 //Que os jogos comecem
        printf("\nJogador %s",l->current->info.name);
        setbuf(stdin,NULL);
        printf("\nPressione Enter para puxar o gatilho");
        fgets(enter,3,stdin);
        removeEnter(enter);

        if(drum[i] == 1){
            printf("~POW~");
            printf("\nJogador %s cai morto",l->current->info.name);
            aux = l->current->info.key; 
            l->current = l->current->next;      //Seta o ponteiro current no proximo nodo
            removeElement(l,aux);               //Remove o jogador que se suicidou
            l->size--;

            if(l->size == 1)
                break;
                
            //drum->current->info.slot = 0;       //Retira o cartucho gasto da posição

            posCartucho = (rand()%6)+1;         //Gera outro valor aleatório e insere o cartucho nessa
            drum[posCartucho - 1] = 1;
            i=0;
            //setCurrentDrum(drum,posCartucho);   //posição do drum, assim setando novamente o ponteiro
            //drum->current->info.slot = 1;       //current para o primeiro nodo
            //setCurrentDrum(drum,1);
            printf("\nJogador %s colocou uma munição da arma",l->current->info.name);
            
        }else{
            printf("~CLICK~\n");
            l->current = l->current->next;
            i++;
            //drum->current = drum->current->next;
        }

    }while(l->size != 1);

    printf("\n~~~~~ Vencedor ~~~~~");
    printf("\n%s",l->first->info.name);
}