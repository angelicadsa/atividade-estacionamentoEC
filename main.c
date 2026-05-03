#include <stdio.h>
#include <string.h>

int main() {
    // Declaração de variáveis
    char placa[10];
    int tipoVeiculo;
    float horas, valorHora, valorBase, desconto = 0, multa = 0, valorFinal;
    char nomeTipo[15];

    printf("============= SISTEMA DE ESTACIONAMENTO =============\n");

    // Entrada de Dados
    printf("Digite a placa do veiculo: ");
    scanf("%s", placa);

    printf("Selecione o tipo de veiculo:\n");
    printf("1 - Carro (R$ 5.00/h)\n");
    printf("2 - Moto (R$ 3.00/h)\n");
    printf("3 - Caminhonete (R$ 8.00/h)\n");
    printf("Opcao: ");
    scanf("%d", &tipoVeiculo);

    printf("Digite o tempo de permanencia (em horas): ");
    scanf("%f", &horas);

    // Processamento: Definição do valor base via Switch-Case
    switch (tipoVeiculo) {
        case 1:
            valorHora = 5.00;
            strcpy(nomeTipo, "Carro");
            break;
        case 2:
            valorHora = 3.00;
            strcpy(nomeTipo, "Moto");
            break;
        case 3:
            valorHora = 8.00;
            strcpy(nomeTipo, "Caminhonete");
            break;
        default:
            printf("\nOpcao de veiculo invalida! Encerrando...\n");
            return 1; // Encerra o programa com erro
    }

    // Regra: Até 1 hora (valor mínimo)
    if (horas < 1.0) {
        valorBase = valorHora;
    } else {
        valorBase = horas * valorHora;
    }

    // Regra: Acima de 5 horas (Desconto de 10%)
    if (horas > 5.0) {
        desconto = valorBase * 0.10;
    }

    // Regra: Acima de 10 horas (Multa de R$ 20.00)
    if (horas > 10.0) {
        multa = 20.00;
    }

    // Cálculo Final
    valorFinal = valorBase - desconto + multa;

    // Saída de Dados (Recibo)
    printf("\n--------------------------------------------------\n");
    printf("                RECIBO DE PAGAMENTO               \n");
    printf("--------------------------------------------------\n");
    printf("Placa:            %s\n", placa);
    printf("Veiculo:          %s\n", nomeTipo);
    printf("Permanencia:      %.2f horas\n", horas);
    printf("Valor Base:       R$ %.2f\n", valorBase);
    
    if (desconto > 0) {
        printf("Desconto (10%%):  - R$ %.2f\n", desconto);
    }
    
    if (multa > 0) {
        printf("Multa (>10h):     + R$ %.2f\n", multa);
    }

    printf("--------------------------------------------------\n");
    printf("VALOR TOTAL:      R$ %.2f\n", valorFinal);
    printf("--------------------------------------------------\n");

    return 0;
}
