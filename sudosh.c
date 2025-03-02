#include "sudosh.h"

int main(int argc, char **argv){

    // laod config files

    // loop shell
    sudosh();

    // cleanup when loop terminated

    return EXIT_SUCCESS;
}

void sudosh(void){
    char *line;
    char **args;

    int status=1;

    while(status){
        printf("\x1b[32m>\x1b[0m ");
        line = sudosh_read_line();
        save_history(line);
        args = sudosh_split_line(line);
        status = sudosh_execute(args);


        free(line);
        free(args);
    }   
}

char *sudosh_read_line(void){
    int buffer_size = SUDOSH_BUFFER_SIZE;
    int pos = 0;
    char *buffer = malloc(sizeof(char) * buffer_size);
    char c;

    if(!buffer){
        fprintf(stderr, "[ERR] memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    while(1){
        c = getchar();

        if(c==EOF || c=='\n'){
            buffer[pos] = '\0';
            return buffer;
        }

        buffer[pos] = c;
        pos++;


        if(pos>=buffer_size){
            buffer_size+=SUDOSH_BUFFER_SIZE;
            buffer = realloc(buffer, buffer_size);
            
            if(!buffer){
                fprintf(stderr, "[ERR] memory allocation error!\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}


char **sudosh_split_line(char *line){
    int buffer_size = SUDOSH_TOKEN_BUFSIZE;
    int pos = 0;
    char **tokens = malloc(buffer_size * sizeof(char *));
    char *token;

    if(!token){
        fprintf(stderr, "[ERR] memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, SUDOSH_TOKEN_DELIMITER);
    while(token!=NULL){
        tokens[pos] = token;
        pos++;
        if(pos>=buffer_size){
            buffer_size+=SUDOSH_TOKEN_BUFSIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if(!tokens){
                fprintf(stderr, "[ERR] memory allocation error!\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, SUDOSH_TOKEN_DELIMITER);
    }
    tokens[pos] = NULL;
    return tokens;
}



int sudosh_launch(char **args){
    __pid_t pid, wpid;
    int status;

    pid = fork();
    if(pid==0){
        // child process creation
        if(execvp(args[0], args) == -1){
            perror("sudosh");
        }
        exit(EXIT_FAILURE);
    }

    else if (pid < 0) {
        // Error forking
        perror("sudosh");
    }

    else{
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        }while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

char *builtin_str[] = {"cd", "help", "exit"};
int (*builtin_fxn[]) (char **) = {&sudosh_cd, &sudosh_help, &sudosh_exit};

int sudosh_builtin_count(){
    return sizeof(builtin_str) / sizeof(char *);
}



int sudosh_cd(char **args){
    if(args[1] == NULL){
        fprintf(stderr, "sudosh: missing arguement\n");
        return 1;
    }
    if(chdir(args[1])!=0){
        perror("sudosh");
    }
    return 1;
    
}
int sudosh_help(char **args){
    printf("sudosh ~ shell \nlist of built-in programs :\n");
    for(int i=0;i<sudosh_builtin_count();i++){
        printf("%d. %s\n", i, builtin_str[i]);
    }
    printf("Use the man command for information on other programs.\n");
    return 1;
}

int sudosh_exit(char **args){
    return 0;
}


int sudosh_execute(char **args)
{
    if (args[0] == NULL) {
      // An empty command was entered.
      return 1;
    }
    
    for(int i = 0; i < sudosh_builtin_count   (); i++) {
      if (strcmp(args[0], builtin_str[i]) == 0) {
        return (*builtin_fxn[i])(args);
      }
    }

  return sudosh_launch  (args);
}

void save_history(const char *line){
    FILE *fp;
    fp = fopen("sudosh_history.hist","a");
    fprintf(fp, "%s\n", line);
    fclose(fp);
}