#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type)
{
   int     fd[2];
   pid_t   pid;

   // 1. Validação dos parãmetros
   if (!file || !argv || (type != 'r' && type != 'w'))
       return (-1);

   // 2. Criar tubo e Checar vazamento
   if (pipe(fd) == -1)
       return (-1);

   // 3. Clonar Processos e checar erros
   pid = fork();

   if (pid == -1)
   {
       close(fd[0]);
       close(fd[1]);
       return (-1);
   }

   // 4. Processo FILHO - SEQUESTRADOR E EXECUTOR
   if (pid == 0)
   {
       if (type == 'r')
       {
           if (dup2(fd[1], STDOUT_FILENO) == -1)
           {
               close(fd[0]);
               close(fd[1]);
               exit(1);
           }
       }
       else if (type == 'w')
       {
           if (dup2(fd[0], STDIN_FILENO) == -1)
           {
               close(fd[0]);
               close(fd[1]);
               exit(1);
           }
       }

       // O dup2 deu certo, logo fechamos as pontas originais.
       close(fd[0]);
       close(fd[1]);

	   // Executamos
       execvp(file, argv);

       // Se execvp falhar (comando não existe), sai com erro.
       exit(1);
   }

   // 5. Processo PAI - Mario, o encanador
   if (type == 'r')
   {
       close(fd[1]);
       return (fd[0]);
   }
   else
   {
       close(fd[0]);
       return (fd[1]);
   }
}
