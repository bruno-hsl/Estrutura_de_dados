// #include <stdio.h>

// // struct pessoa {
// // char nome[50];
// // int idade;
// // };

// // void 
// //  crescer(struct  pessoa *pe, int anos, float crescimento){
// //     pe->idade = pe->idade = anos;
   
// //  }
 
// // int main() {
// //     int mostrar = 0;

// //     struct pessoa pe;

  
// //     printf("Nome da pessoa: ");
// //     scanf(" %49s", pe.nome);

// //     printf("Idade: ");
// //     scanf(" %d", &pe.idade);

    
// //     printf("Deseja ver as pessoas cadastradas:\n Se sim digite: 1 \n ");
// //     scanf("%d", &mostrar);
// //     switch (mostrar){
// //     case 1:
// //         printf("Nome: %s\n", pe.nome);
// //         printf("Idade: %d\n", pe.idade);
// //         break;
    
// //     }
    
// //     return 0;
// //     }
    
// #include <stdio.h>
// int main() {

// struct pessoa {
//     char nome[50];
//     int idade;
//    };

// struct pessoa.nome[] = {'ana', 'pedro', 'gulherme', 'daniel', 'lucas'};
// struct pessoa.idade[] = {5, 3, 4, 2, 1};

// int n = sizeof(pessoa.idade) / sizeof(pessoa.idade[0]);

// int i, chave, j;

// for (i = 1; i < n; i++) {
// chave = pessoa.idade[i];
// j = i - 1;
// while (j >= 0 && pessoa[j] > chave) {
// pessoa[j + 1] = pessoa[j];
// j--;
// }
// pessoa[j + 1] = chave;
// }


// for (int i = 0; i < n; i++) {
// printf("%d ", pessoa[i]);
// }

// printf("\n");
// return 0;
// }

#include <stdio.h>
#include <string.h>  

struct pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct pessoa pessoas[] = {
        {"ana", 5},
        {"pedro", 3},
        {"gulherme", 4},
        {"daniel", 2},
        {"lucas", 1}
    };

    int n = sizeof(pessoas) / sizeof(pessoas[0]);

     
    int i, chave, j;
    struct pessoa pessoaChave;

    for (i = 1; i < n; i++) {
        pessoaChave = pessoas[i];
        j = i - 1;

        while (j >= 0 && pessoas[j].idade > pessoaChave.idade) {
            pessoas[j + 1] = pessoas[j];
            j--;
        }

    
        pessoas[j + 1] = pessoaChave;
    }

    for (i = 0; i < n; i++) {
        printf("Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }

    return 0;
}




