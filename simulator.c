#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {

  int menu, ind = 0, acerto[99] = {}, i, usado = 0;
  double vo[99] = {}, anginc[99] = {}, distalvo[99] = {}, tamalvo[99] = {}, altmax[99] = {}, g = 9.81, pi = 3.14, temptraj[99] = {}, alchori[99] = {}, media = 0, altmaior, porcacerto, quant_n_null, contacerto;

  while(menu != 4){
    
    menu = 0;
			
    while(menu > 4 || menu < 1){
      printf("\n|--------- Simulador de Lancamento de Projeteis ---------|");
      printf(" \n 1. Simular disparo.\n 2. Mostrar estatistica.\n 3. Mostrar resumo de todos os disparos realizados.\n 4. Sair.\n");
      printf("|--------------------------------------------------------|\n ");
      scanf("%i", &menu);
	
      if(menu > 4 || menu < 1){
        printf("\n Opcao invalida, escolha uma opcao valida.\n");
      }
    }
				
    if(menu == 1){
      
      printf("\n|----------------- Simulacao de Disparo -----------------|");
      while(vo[ind] <= 0){
        printf("\n Qual a velocidade inicial? \n ");
        scanf("%lf", &vo[ind]);

        if(vo[ind] <= 0){
          printf("\n A velocidade inicial deve ser positiva e maior que zero.\n");
        }
      }

      while(anginc[ind] <= 0 || anginc[ind] >= 90){
        printf(" Qual o angulo, em graus, da inclinacao do canhao? \n ");
        scanf("%lf", &anginc[ind]);

        if(anginc[ind] <= 0 || anginc[ind] >= 90){
          printf("\n O valor do angulo deve ser maior que zero e menor que 90.\n\n");
        }
      }
      
      anginc[ind] = (anginc[ind] * (pi / 180));

      while(distalvo[ind] <= 0){
        printf(" Qual a distancia do alvo? \n ");
        scanf("%lf", &distalvo[ind]);

        if(distalvo[ind] <= 0){
          printf("\n O valor da distancia deve ser maior que zero.\n\n");
        }
      }

      while(tamalvo[ind] < 20 || tamalvo[ind] > 50){
        printf(" Qual o tamanho do alvo? \n ");
        scanf("%lf", &tamalvo[ind]);

        if(tamalvo[ind] < 20 || tamalvo[ind] > 50){
          printf("\n O valor do tamanho do alvo deve ser maior igual a 20 e e menor igual a 50.\n\n");
        }
      }

      alchori[ind] = (2 * (pow(vo[ind], 2))*((cos(anginc[ind]) * sin(anginc[ind]))/ g));
      printf("\n O alcance horizontal: %.2lf\n", alchori[ind]);
      
      media = media + alchori[ind];

      temptraj[ind] = ((2 * vo[ind]) * sin(anginc[ind])/ g);
      printf(" O tempo do trajeto: %.2lf\n", temptraj[ind]);

      altmax[ind] = ((pow(vo[ind], 2) * sin(anginc[ind]))/(2 * g));
      printf(" A altura maxima: %.2lf\n", altmax[ind]);

      if(alchori[ind] >= distalvo[ind] && alchori[ind] <= (distalvo[ind] + tamalvo[ind])){
        printf(" Atingiu o alvo.\n");
        acerto[ind] = 1;
        
      } else {

        if(alchori[ind] < distalvo[ind]){
          printf(" Errou, o projetil caiu antes do alvo.\n");
          acerto[ind] = 2;

        } else {

          if(alchori[ind] > (distalvo[ind] + tamalvo[ind])){
            printf(" Errou, o projetil caiu depois do alvo.\n");
            acerto[ind] = 2;
          }
        }
      }

      ind++;
      usado = 0;
      
      printf("|--------------------------------------------------------|\n");
    }

    if(menu == 2){
    	
      printf("\n|--------------------- Estatisticas ---------------------|");	

      if(ind == 0){
      printf("\n Simule um disparo antes de usar esta opcao!\n");

      } else {

        if(usado == 0){

          altmaior = 0;
          quant_n_null = 0.0;
          contacerto = 0.0;

          for(i = 0; i < 99; i++){
            if(acerto[i] != 0){
              quant_n_null = quant_n_null + 1.0;
            }

            if(altmax[i] > altmaior){
              altmaior = altmax[i];
            }

            if(acerto[i] == 1){
              contacerto = contacerto + 1.0;
            }
          }

          media = media/quant_n_null;
          porcacerto = ((contacerto/quant_n_null)*100);

          printf("\n A media do alcance horizontal dos disparos: %.2lf\n", media);
          printf(" A maior altura atingida: %.2lf\n", altmaior);
          printf(" A porcentagem de disparos que atingiram o alvo: %.2lf", porcacerto);
          printf("%%\n");

          usado = 1;

        } else {

          printf("\n A media do alcance horizontal dos disparos: %.2lf\n", media);
          printf(" A maior altura atingida: %.2lf\n", altmaior);
          printf(" A porcentagem de disparos que atingiram o alvo: %.2lf", porcacerto);
          printf("%%\n");
        }
      }
      
      printf("|--------------------------------------------------------|\n");
    }

    if(menu == 3){
		
	  printf("\n|----------------------- Disparos -----------------------|");	
      if(ind == 0){
      printf("\n Simule um disparo antes de usar esta opcao!\n");

      } else {

        for(i = 0; i < 99; i++){
          if(acerto[i] != 0){
            printf("\n O disparo %i", i + 1);

            if(acerto[i] == 1){
              printf(" acertou o alvo.\n");

            } else {

              printf(" errou o alvo.\n");
            }
          }
        }
      }
      
      printf("|--------------------------------------------------------|\n");
    }
  }
    
  return 0;
}
