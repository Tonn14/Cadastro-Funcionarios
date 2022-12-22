#include <stdio.h>
#include<stdbool.h>

struct {
    int matricula[3];
    int horaInicial[3],minutoInicial[3],segundoInicial[3];
    int horaFinal[3],minutoFinal[3],segundoFinal[3];
    float Salario[3];
}funcionario;
//vetor para cada dado que será exibido
int main() {
    int i=0;
    int Matriculaf=0;
    int opcao, quantf=0;
    bool girando = true;

    do {
        printf("\n----------Bem-Vindo ao Menu da Empresa-----------\n");
        printf("\n[1]----------Cadastro dos Funcionarios-----------\n");
        printf("\n[2]----------Consulta um funcionario-----------\n");
        printf("\n[3]----------Lista todos os Funcionarios Cadastrados-----------\n");
        printf("\n[4]----------Sair do Programa-----------\n");

        printf("Digite a Opcao desejada:");
        scanf("%d", &opcao);
        switch (opcao) {


            case 1: {
                printf("\n----------Cadastro dos Funcionarios -----------\n\n\n");

                printf("Digite a matricula do funcionario %d:\n", i + 1);
                scanf("%d", &funcionario.matricula[i]);
                do {// Verificação se o horario de entrada e valido
                    printf("Digite o horario de entrada no formato <hora:minuto:segundo>:\n");
                    scanf("%d:%d:%d", &funcionario.horaInicial[i], &funcionario.minutoInicial[i],
                          &funcionario.segundoInicial[i]);
                    if (funcionario.horaInicial[i] > 23 || funcionario.minutoInicial[i] > 59 ||
                        funcionario.segundoInicial[i] > 59) {
                        printf("Horario Invalido!!\n");
                    }
                } while (funcionario.horaInicial[i] > 23 || funcionario.minutoInicial[i] > 59 ||
                         funcionario.segundoInicial[i] > 59);

                do {//verificaçao se o horario de saida e valido
                    printf("Digite o horario de saida no formato <hora:minuto:segundo>:\n");
                    scanf("%d:%d:%d", &funcionario.horaFinal[i], &funcionario.minutoFinal[i],
                          &funcionario.segundoFinal[i]);
                    if (funcionario.horaFinal[i] > 23 || funcionario.minutoFinal[i] > 59 ||
                        funcionario.segundoFinal[i] > 59) {
                        printf("Horario Invalido!!\n");
                    }
                } while (funcionario.horaFinal[i] > 23 || funcionario.minutoFinal[i] > 59 ||
                         funcionario.segundoFinal[i] > 59);

                printf("Digite o salario:\nR$");
                scanf("%f", &funcionario.Salario[i]);
                quantf++;
                break;
            }

            case 2: {
                printf("\n----------Consulta um funcionario -----------\n\n\n");


                printf("Digite a matricula do funcionario desejado:\n");
                scanf("%d", &Matriculaf);
                bool registro = false;
                for (i = 0; i < 3; i++) {
                    if (Matriculaf == funcionario.matricula[i]) {
                        //comparação da matrícula desejada com cada matrícula adicionada em cada posição
                        printf("\nMatricula  do funcionario e: %d\n", Matriculaf);
                        printf("\nHorario de entrada: %d:%d:%d\n", funcionario.horaInicial[i],
                               funcionario.minutoInicial[i],
                               funcionario.segundoInicial[i]);
                        printf("\nHorario de saida: %d:%d:%d\n", funcionario.horaFinal[i], funcionario.minutoFinal[i],
                               funcionario.segundoFinal[i]);
                        printf("\nSalario do funcionario: R$%.2f\n", funcionario.Salario[i]);
                        registro=true;
                        break;


                    }

                }
                if(registro==false){
                    printf("funcionario com essa matricula não foi encontrando");
                    }
                break;
            }

            case 3: {

                printf("\n----------Funcionarios Cadastrados-----------\n\n\n");
                for (i = 0; i < quantf; i++) {
                    printf("Funcionario %d", &i + 1);
                    printf("\nMatricula  do funcionario e: %d\n", funcionario.matricula[i]);
                    printf("\nHorario de entrada: %d:%d:%d\n", funcionario.horaInicial[i], funcionario.minutoInicial[i],
                           funcionario.segundoInicial[i]);
                    printf("\nHorario de saida: %d:%d:%d\n", funcionario.horaFinal[i], funcionario.minutoFinal[i],
                           funcionario.segundoFinal[i]);
                    printf("\nSalario do funcionario: R$%.2f\n", funcionario.Salario[i]);


                }
            }
                break;

            case 4: {
                girando = false;
                default:
                break;
            }
        }
    } while (girando);

        return 0;
}
