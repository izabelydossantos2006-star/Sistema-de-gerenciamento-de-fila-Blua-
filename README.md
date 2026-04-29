🏥 Sistema de Gerenciamento de Fila - Blua

📌 Descrição

Sistema de gerenciamento de fila de atendimento médico por teleconsulta, feito em C com estruturas de dados construídas com listas encadeadas.

📋 Funcionalidades

-Enfileirar pacientes (FIFO)

-Priorizar atendimentos de emergência (FIFO)

-Simular atendimento sequencial por médico

-Registrar histórico das consultas (pilha - LIFO)

-Desfazer último atendimento com pilha de ações



🗂️ Estruturas de Dados Utilizadas
Todas as estruturas foram construídas com listas encadeadas, sem uso de arrays ou bibliotecas externas.

Fila (FIFO) → organização dos pacientes, usada na fila regular e na fila de emergência 

-Enqueue() → Insere no final (Tail)

-Dequeue() → Remove do inicio (Head)

-Peek_fila() → Consulta o próximo sem remover 

-Fila_vazia() → Verifica se a fila está vazia 


Pilha (LIFO) → Usada no histórico de consultas e na pilha de ações (desfazer)

Listas encadeadas → implementação das estruturas

-Push() → Insere no topo

-Pop() → Remove do topo

-Peek_pilha() → Consulta o topo sem remover

-Pilha_vazia → Verifica se a pilha está vazia


🧪 Cenários demonstrados

Cenário 1 — Chegada em massa de pacientes regulares
Vários pacientes são adicionados à fila regular. O médico chama todos em ordem FIFO via dequeue(). Demonstra que o primeiro a chegar é o primeiro a ser atendido.

Cenário 2 — Emergência interrompe a fila regular
Pacientes regulares já estão na fila quando uma emergência chega. O sistema verifica fila_vazia(&emergencia) antes de decidir qual fila processar, garantindo prioridade absoluta às emergências.

Cenário 3 — Auditoria com pilha + cancelamento administrativo
Consultas são finalizadas e empilhadas no histórico (LIFO). Um cancelamento administrativo executa pop() na pilha de ações e reverte o último atendimento, reinserindo o paciente na fila. Demonstra uso de pilha para desfazer operações.


❓ Como Executar

Acesse um compilador C (ex: OnlineGDB)

Copie o código do arquivo main.c

Execute o programa

Utilize o menu interativo


📋 Menu do Sistema

1 → Novo paciente

2 → Emergência

3 → Atender paciente

4 → Ver histórico

5 → Desfazer atendimento

0 → Sair


📂 Estrutura do Projeto

main.c

README.md


👨‍💻 Autor

Projeto desenvolvido para fins acadêmicos.


