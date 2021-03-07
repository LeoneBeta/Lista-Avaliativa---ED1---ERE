#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"
#include "ProblemJosephus.h"

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

void setDrum(listDrum drum){
    int i;
    TElementDrum e;
    for(i=1;i<=6;i++){
        e.key = i;
        e.slot = 0;
        insertEndDrum(drum,e);
    }
}

void game(list l, int players){
    system("clear");
    listDrum drum;
    int posCartucho = 0,aux;
    char enter[3];

    srand(time(NULL));
    //Criando a Lista Drum
    drum = creatListDrum();
    //Inserindo os espaços no Drum sem munição
    setDrum(drum);


    posCartucho = (rand()%6)+1;         //Gera um valor aleatório entre 1 e 6, as posições possiveis no Drum do revolver
    
    
    
    setCurrentDrum(drum,posCartucho);   //Seta o ponteiro current no lugar em que a munição será inserida
    drum->current->info.slot = 1;       //Insere o valor '1' na posição do Drum (Munição colocada no lugar)

    setCurrentDrum(drum,1);             //Seta o ponteiro current na primeira posição do drum
    setCurrent(l,1);                    //Seta o ponteiro current no primeiro jogador

    printf("\nJogador %s colocou uma munição da arma",l->current->info.name);
    
    do{                                 //Que os jogos comecem
        printf("\nJogador %s",l->current->info.name);
        setbuf(stdin,NULL);
        printf("\nPressione Enter para puxar o gatilho");
        fgets(enter,3,stdin);
        removeEnter(enter);

        if(drum->current->info.slot == 1){      //Caso
            printf("~POW~");
            printf("\nJogador %s cai morto",l->current->info.name);
            aux = l->current->info.key; 
            l->current = l->current->next;      //Seta o ponteiro current no proximo nodo
            removeElement(l,aux);               //Remove o jogador que se suicidou
            l->size--;

            drum->current->info.slot = 0;       //Retira o cartucho gasto da posição

            posCartucho = (rand()%6)+1;         //Gera outro valor aleatório e insere o cartucho nessa
            setCurrentDrum(drum,posCartucho);   //posição do drum, assim setando novamente o o ponteiro
            drum->current->info.slot = 1;       //current para o primeiro nodo
            setCurrentDrum(drum,1);
            printf("\nJogador %s colocou uma munição da arma",l->current->info.name);
            
        }else{
            printf("\n~CLICK~");
            l->current = l->current->next;
            drum->current = drum->current->next;
        }

    }while(l->size != 1);

    printf("\n~~~~~ Vencedor ~~~~~");
    printf("\n%s",l->first->info.name);
}