#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float funcao_afim(float a, float b, float x){
    float y = a*x + b;
    return y;
}

float funcao_quadratica(float a, float b, float c, float x){
    float y = a*(pow(x, 2)) + b*x + c;
    return y;
}

float funcao_modular(float a, float b, float c, float x){
    float y;
    switch((int)c){
        case 0:
            y = fabs(a*x) + b;
            break;
        case 1:
            y = fabs(a*x + b);
            break;
    }
    return y;
}



float funcao_exponencial(float a, float x){
    float y = pow(a, x);
    return y;
}

void gera_grafico(int func, float a, float b, float c){
    char matriz[21][21]; //armazena o grafico
    int resultados[21]; //armazena os resultados da funcao
    int i, j;
    
    //adquire resultados
    switch(func){
        case 1:
            for(i = 20; i>=0; i--){
                resultados[i] = (int) funcao_afim(a, b, i-10);
            }
            break;
        case 2:
            for(i = 20; i>=0; i--){
                resultados[i] = (int) funcao_quadratica(a, b, c, i-10);
            }
            break;
        case 3:
            for(i = 20; i>=0; i--){
                resultados[i] = (int) funcao_modular(a, b, c, i-10);
            }
            break;
        case 4:
            for(i = 20; i>=0; i--){
                resultados[i] = (int) funcao_exponencial(a, i-10);
            }
            break;
    }
    //armazena dados na matriz
    for(i = 20; i>=0; i--){
        for(j = 0; j<=20; j++){
            if(i == resultados[j]+10){
                matriz[i][j] = 'O';
            }else{
                matriz[i][j] = ' ';
            }
        }
    }
    //desenha o grafico
    for(i = 20; i>=0; i--){
        for(j = 0; j<=20; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
    
    return;
}

int main(){
    int func, operacao;
    float resultado;
    float a = 1, b = 0, c = 0;
    printf("Digite qual tipo de funcao voce deseja aprender: ");
    printf("\n1 para afim");
    printf("\n2 para quadratica");
    printf("\n3 para modular");
    printf("\n4 para exponencial\n\n");
    
    scanf("%d", &func);
    //adquire os dados
    switch(func){
        case 1:
        	
        	printf("\n1 para aprender os conceitos");
        	printf("\n2 encontrar os interceptos da funcao");
        	printf("\n3 para mostrar grafico da funcao\n");

            scanf("%d", &operacao);
        	
        	switch(operacao) {
        		
        		case 1: 
        		    printf("conceitos");
        		    break;
        	
				case 2: 
				    printf("\nDigite a: ");
	                scanf("%f", &a);
	                printf("Digite b: ");
	                scanf("%f", &b);
                    float intercepto_x;
                    intercepto_x = -b/a;
                    float intercepto_y;
                    intercepto_y = b;
	                printf("\nOs interceptos da funcao sao %f no eixo X e %f no eixo Y.", intercepto_x, intercepto_y);
	                break;
				    
				case 3:
				    printf("Digite a: ");
	                scanf("%f", &a);
	                printf("Digite b: ");
	                scanf("%f", &b);
	                gera_grafico(func, a, b, c);
	                break;	
			    }
            break;
        	
        case 2:
        	
        	printf("\n1 para aprender os conceitos");
        	printf("\n2 encontrar raizes da funcao");
        	printf("\n3 para mostrar grafico da funcao\n");

            scanf("%d", &operacao);
        	
        	switch(operacao) {
        		
        		case 1: 
        		printf("conceitos");
        		break;
        	
				case 2: 
				printf("\nDigite a: ");
	            scanf("%f", &a);
	            printf("Digite b: ");
	            scanf("%f", &b);
                printf("Digite c: ");
	            scanf("%f", &c);
                float raiz1, raiz2, delta;
                delta = b*b - 4*a*c;
                if(delta < 0){
                    printf("\nA funcao nao possui raizes reais.");
                } else if (delta == 0){
                    raiz1 = (-b + sqrt(delta))/(2*a);
                    printf("\nA raiz da funcao e %f.", raiz1);
                } else {
                    raiz1 = (-b + sqrt(delta))/(2*a);
                    raiz2 = (-b - sqrt(delta))/(2*a);
                    printf("\nAs raizes da funcao sao %f e %f.", raiz1, raiz2);
                }
	            break;
				
				case 3:
				printf("Digite a: ");
	            scanf("%f", &a);
	            printf("Digite b: ");
	            scanf("%f", &b);
                printf("Digite c: ");
	            scanf("%f", &c);
	            gera_grafico(func, a, b, c);
	            break;	
			}
            break;

        case 3:
        	
        	printf("\n1 para aprender os conceitos");
        	printf("\n2 encontrar as raizes da funcao");
        	printf("\n3 para mostrar grafico da funcao\n");

            scanf("%d", &operacao);
        	
        	switch(operacao) {
        		
        		case 1: 
        		printf("conceitos");
        		break;
        	
				case 2: 
				printf("Digite a: ");
	            scanf("%f", &a);
	            printf("Digite b: ");
	            scanf("%f", &b);
                printf("b se encontra dentro do modulo? 0 = nao, 1 = sim");
	            scanf("%f", &c);
                if (c == 1){
                    float raiz = -b/a;
                    printf("\nA raiz da funcao e %f.", raiz);
                } else {
                    if(b > 0){
                        printf("\nA funcao nao tem raizes reais.");
                    } else if(b < 0){
                        float raiz1, raiz2;
                        raiz1 = b/a;
                        raiz2 = -b/a;
                        printf("\nAs raizes da funcao sao %f e %f.", raiz1, raiz2);
                    } else {
                        printf("\nA raiz da funcao e 0.");
                    }
                }
	            break;
				
				case 3:
				printf("Digite a: ");
	            scanf("%f", &a);
	            printf("Digite b: ");
	            scanf("%f", &b);
                printf("b se encontra dentro do modulo? 0 = nao, 1 = sim");
	            scanf("%f", &c);
	            gera_grafico(func, a, b, c);
	            break;	
			}
            break;

        case 4:
        	printf("\n1 para aprender os conceitos");
        	printf("\n2 trololo");
        	printf("\n3 para mostrar grafico da funcao\n");

            scanf("%d", &operacao);

            switch(operacao){
                case 1:
                    printf("\nconceitos");
                    break;
                case 2:
                    printf("\ntrololo");
                    break;
                case 3:
                    printf("Digite a: ");
                    scanf("%f", &a);
                    gera_grafico(func, a, b, c);
            }
            
            break;
    }


    return 0;
}
