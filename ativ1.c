#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_VEICULOS 10

typedef struct {
  char marca[10];
  char modelo[10];
  char placa[9];
  int ano;
  int preenchido;
} Veiculo;

int main() {
  Veiculo veiculos[NUM_VEICULOS];
  int veiculos_alocados = 0;
  int continuar;

  for (int i = 0; i < NUM_VEICULOS; i++) {
    strcpy(veiculos[i].marca, "Nenhuma");
    strcpy(veiculos[i].modelo, "Nenhum");
    strcpy(veiculos[i].placa, "Nenhuma");
    veiculos[i].ano = 0;
    veiculos[i].preenchido = 0;
  }

  do {
    int option;

    printf("\n1 - Listar veiculos cadastrados\n");
    printf("2 - Inserir um novo veiculo\n");
    printf("3 - Listar veiculos por ano de fabricacao\n");
    printf("4 - Listar veiculos acima de um ano de fabricacao.\n");
    printf("5 - Listar veiculos pelo modelo.\n");
    printf("0 - Sair\n\n");

    scanf("%d", &option);

    switch (option) {
    case 0:
      continuar = 0;
      break;
    case 1:
      for (int i = 0; i < NUM_VEICULOS; i++) {
        printf("\nVeiculo: %d Marca: %s\n", i, veiculos[i].marca);
        printf("Veiculo: %d Modelo: %s\n", i, veiculos[i].modelo);
        printf("Veiculo: %d Placa: %s\n", i, veiculos[i].placa);
        printf("Veiculo: %d Ano: %d\n", i, veiculos[i].ano);
        printf("Veiculo: %d Preenchido: %d\n", i, veiculos[i].preenchido);
      }
      break;
    case 2:
      Veiculo veiculo_aux;


      printf("\nDigite a marca do veiculo: ");
      scanf("%s", veiculo_aux.marca);
      printf("Digite o modelo do veiculo: ");
      scanf("%s", veiculo_aux.modelo);
      printf("Digite a placa do veiculo: ");
      scanf("%s", veiculo_aux.placa);
      printf("Digite o ano do veiculo: ");
      scanf("%d", &veiculo_aux.ano);
      veiculo_aux.preenchido = 1;


      short indice = 0;
      for (int i = 0; i < NUM_VEICULOS; i++) {
        int preenchido = veiculos[i].preenchido;
        int anoDoAux = veiculo_aux.ano;
        int anoDoVeiculoI = veiculos[i].ano;

        if (preenchido > 0 && (anoDoAux < anoDoVeiculoI)) {
          indice = i;
          for (int j = NUM_VEICULOS - 1; j >= indice; j--) {
            if (veiculos[j].preenchido) {
              Veiculo veiculo = veiculos[j];
              veiculos[j] = veiculo_aux;
              veiculos[j + 1] = veiculo;
            }
          }
          break;
        }
        if (preenchido > 0 && (anoDoAux >= anoDoVeiculoI)) {
          indice++;
        }
      }
      veiculos[indice] = veiculo_aux;
      veiculos_alocados++;
      break;
    case 3:
      short choice;
      printf("\nDigite o ano de fabricacao do veiculo: ");
      scanf("%d", &choice);
      for (int i = 0; i < NUM_VEICULOS; i++) {
        if (veiculos[i].ano != choice) continue;
        printf("\nVeiculo: %d Marca: %s\n", i, veiculos[i].marca);
        printf("Veiculo: %d Modelo: %s\n", i, veiculos[i].modelo);
        printf("Veiculo: %d Placa: %s\n", i, veiculos[i].placa);
        printf("Veiculo: %d Ano: %d\n", i, veiculos[i].ano);
      }
      break;
    case 4:
      short opt;
      printf("\nDigite o ano de fabricacao do veiculo: ");
      scanf("%d", &opt);
      for (int i = 0; i < NUM_VEICULOS; i++) {
        if (veiculos[i].ano <= opt) continue;
        printf("\nVeiculo: %d Marca: %s\n", i, veiculos[i].marca);
        printf("Veiculo: %d Modelo: %s\n", i, veiculos[i].modelo);
        printf("Veiculo: %d Placa: %s\n", i, veiculos[i].placa);
        printf("Veiculo: %d Ano: %d\n", i, veiculos[i].ano);
      }
      break;
    case 5:
      char model[10];
      printf("\nDigite o modelo do veiculo: ");
      scanf("%s", model);
      for (int i = 0; i < NUM_VEICULOS; i++) {
        if (strcmp(model, veiculos[i].modelo) != 0) continue;
        printf("\nVeiculo: %d Marca: %s\n", i, veiculos[i].marca);
        printf("Veiculo: %d Modelo: %s\n", i, veiculos[i].modelo);
        printf("Veiculo: %d Placa: %s\n", i, veiculos[i].placa);
        printf("Veiculo: %d Ano: %d\n", i, veiculos[i].ano);
      }
      break;
    default:
      printf("Digite uma das opcoes.\n");
      break;
    }
  } while (continuar);
  return 0;
}