#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_RESERVAS 100

typedef struct {
    char nome[100];
    char cpf[15];
    int dia; // 1 - Quinta, 2 - Sexta, 3 - Sábado, 4 - Domingo
    int numPessoas;
} Reserva;

Reserva reservas[MAX_RESERVAS];
int totalReservas = 0;

void fazerReserva() {
    if (totalReservas >= MAX_RESERVAS) {
        printf("Limite de reservas atingido.\n");
        return;
    }

    Reserva novaReserva;
    
    printf("Digite o nome do responsável: ");
    fflush(stdin);
    fgets(novaReserva.nome, sizeof(novaReserva.nome), stdin);

    printf("Digite o CPF: ");
    fflush(stdin);
    fgets(novaReserva.cpf, sizeof(novaReserva.cpf), stdin);
    
    printf("Digite o dia da reserva (1 - Quinta, 2 - Sexta, 3 - Sábado, 4 - Domingo): ");
    scanf("%d", &novaReserva.dia);
    
    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &novaReserva.numPessoas);
    
    reservas[totalReservas] = novaReserva;
    totalReservas++;
    
    printf("Reserva realizada com sucesso!\n");
}

void listarReservas() {
    if (totalReservas == 0) {
        printf("Nenhuma reserva cadastrada.\n");
        return;
    }
    
    for (int i = 0; i < totalReservas; i++) {
        printf("===============================\n");
        printf("Nome: %s", reservas[i].nome);
        printf("CPF: %s", reservas[i].cpf);
        printf("Dia: %d\n", reservas[i].dia);
        printf("Número de Pessoas: %d\n", reservas[i].numPessoas);
    }
}

void totalPessoasPorDia() {
    int dia;
    int totalPessoas = 0;

    printf("Digite o dia da reserva (1 - Quinta, 2 - Sexta, 3 - Sábado, 4 - Domingo): ");
    scanf("%d", &dia);

    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].dia == dia) {
            totalPessoas += reservas[i].numPessoas;
        }
    }

    printf("Total de pessoas reservadas para o dia %d: %d\n", dia, totalPessoas);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Fazer Reserva\n");
        printf("2 - Listar Reservas\n");
        printf("3 - Total de Pessoas Por Dia\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                fazerReserva();
                break;
            case 2:
                listarReservas();
                break;
            case 3:
                totalPessoasPorDia();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
        
        system("pause"); // Pausa para o usuário visualizar a saída
        system("cls");   // Limpa a tela

    } while(opcao != 4);

    return 0;
}