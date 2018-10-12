#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){

	pid_t result;
	int i = 0;
	const int max = 16;
	
	//mostra o pid do processo inicial
 	printf("Processo inicial: %d\n",(int)getpid()); fflush(stdout);
        struct rlimit rl;
	//mostra o limite do numero de processos maximo do usuario
        getrlimit(RLIMIT_NPROC, &rl);
        printf("%d\n", rl.rlim_cur);
	
	//cria varios processos a partir de max
	for(i = 0; i < max; i++){
		//cria processo
		result = fork();

		//mostra erro caso fork = -1
		if(result==-1){
            		perror("Erro na execucao do fork."); fflush(stdout);
       		}
		//se fork = 0 e novo processo, uma vez que e filho, entao mostra seu pid
		else if(result == 0){
            		printf("Novo processo: %d\n",(int)getpid()); fflush(stdout);
            		wait();
		}
		//se fork > 0 entao criou o filho e 
		//como ja foi impresso o pid do pai entao so continua
		else{
            		continue;
            		wait();
		}

	}

	return 0;
}

