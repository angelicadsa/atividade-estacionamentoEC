# atividade-estacionamentoEC
# Sistema de Estacionamento Rotativo

**Disciplina:** Laboratório de Programação  
**Estudante:** Angelica da silva alves
**Matrícula:** [20250067604]
**Curso:** Bacharel em Ciencias e Tecnologia  – UFMA   

---

## Descrição do Problema

Programa que calcula o valor a pagar em um estacionamento.  
O usuário informa:  
- Placa do veículo  
- Tipo (1-Carro, 2-Moto, 3-Caminhonete)  
- Tempo de permanência (em horas)  

O sistema aplica:  
- Valor por hora: Carro R$5, Moto R$3, Caminhonete R$8  
- Até 1h → cobra 1 hora (valor mínimo)  
- Acima de 5h → desconto de 10%  
- Acima de 10h → multa de R$20  

---

## Modelagem

### Variáveis

| Nome         | Tipo       | Finalidade |
|--------------|------------|-------------|
| `placa`      | char[10]   | Placa do veículo |
| `tipoVeiculo`| int        | 1, 2 ou 3 |
| `horas`      | float      | Tempo em horas |
| `valorHora`  | float      | Tarifa por hora |
| `valorBase`  | float      | Valor antes de descontos/multa |
| `desconto`   | float      | 10% se horas > 5 |
| `multa`      | float      | R$20 se horas > 10 |
| `valorFinal` | float      | Total a pagar |
| `nomeTipo`   | char[15]   | Nome do tipo para exibir |

### Regras de Negócio

- `valorBase = horas * valorHora` (se horas < 1, usa `valorHora` – mínimo 1h)
- `desconto = valorBase * 0.10` se horas > 5
- `multa = 20.00` se horas > 10
- `valorFinal = valorBase - desconto + multa`

### Fluxograma (resumido)

1. Ler placa, tipo, horas  
2. `switch` para definir `valorHora` e `nomeTipo` (default → erro)  
3. Se `horas < 1` → `valorBase = valorHora`; senão `valorBase = horas * valorHora`  
4. Se `horas > 5` → `desconto = valorBase * 0.10`  
5. Se `horas > 10` → `multa = 20.00`  
6. `valorFinal = valorBase - desconto + multa`  
7. Exibir recibo  

---

## Como Compilar e Executar

### Necessário ter instalado:

1. **GCC** (compilador C) – [Download MinGW (Windows)](http://www.mingw.org/) ou use WSL/Linux.  
2. **Node.js** (opcional, apenas para usar o atalho `npm run start` no Windows).  

### Método 1 – Direto com GCC (qualquer sistema)

Compilar:
```bash
gcc main.c -o estacionamento.exe
