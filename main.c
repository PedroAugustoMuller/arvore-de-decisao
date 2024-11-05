#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Nodo {
    const char *pergunta;
    const char *pergunta_esquerda;
    struct Nodo *esquerda;
    const char *pergunta_direita;
    struct Nodo *direita;
} Nodo;


Nodo* criar_nodo(const char *pergunta, const char *pergunta_esquerda, const char *pergunta_direita) {
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo->pergunta = pergunta;
    nodo->pergunta_esquerda = pergunta_esquerda;
    nodo->esquerda = NULL;
    nodo->pergunta_direita = pergunta_direita;
    nodo->direita = NULL;
    return nodo;
}


void navegar_arvore(Nodo *nodo) {
    char resposta;
    while (nodo != NULL) {
        printf("%s (d/e): \n", nodo->pergunta);
        printf("%s\n", nodo->pergunta_direita);
        printf("%s\n", nodo->pergunta_esquerda);
        resposta = getchar();

     while (getchar() != '\n');

        if (resposta == 'd' || resposta == 'D') {
            nodo = nodo->direita;
        } else if (resposta == 'e' || resposta == 'E') {
            nodo = nodo->esquerda;
        } else {
            printf("Por favor responda direita (d) ou esquerda (e).\n");
        }
    }
    printf("Final da árvore.\n");
}

void arvore_manual(Nodo* fechado)
{
    Nodo* manual = criar_nodo("Prefere mais construir ou pintar?", "(esquerda) Construir", "(direita) Pintar");
    fechado->direita = manual;

    manual->esquerda = criar_nodo("Gosta de costurar?", "(esquerda) Sim", "(direita) Não");
    manual->esquerda->esquerda = criar_nodo("Resposta - Tapeçaria", "Final", "Final");
    manual->esquerda->direita = criar_nodo("Resposta - Marcenaria", "Final", "Final");

    manual->direita = criar_nodo("Gosta de desenhar?", "(esquerda) Sim", "(direita) Não");
    manual->direita->esquerda = criar_nodo("Resposta - Pintura de tela", "Final", "Final");
    manual->direita->direita = criar_nodo("Resposta - Pintar figuras de ação", "Final", "Final");
}

void arvore_intelectual(Nodo* fechado)
{
    Nodo* intelectual = criar_nodo("Quer aprendizado constante?", "(esquerda) Sim", "(direita) Não");
    fechado->esquerda = intelectual;

    Nodo* sim_aprendizado = criar_nodo("Gosta mais de ler ou resolver problemas?", "(esquerda) Ler", "(direita) Resolver Problemas");
    intelectual->esquerda = sim_aprendizado;

    sim_aprendizado->esquerda = criar_nodo("Resposta - Leitura de livros educacionais", "Final", "Final");

    Nodo* resolver_problemas = criar_nodo("Gosta de jogos de computador?", "(esquerda) Sim", "(direita) Não");
    sim_aprendizado->direita = resolver_problemas;

    resolver_problemas->direita = criar_nodo("Resposta - Escape Room", "Final", "Final");

    Nodo* jogos_computador = criar_nodo("Prefere jogos de estratégia ou quebra cabeça?", "(esquerda) Estratégia", "(direita) Quebra-Cabeça");
    resolver_problemas->esquerda = jogos_computador;

    jogos_computador->esquerda = criar_nodo("Resposta - Age of Empires", "Final", "Final");
    jogos_computador->direita = criar_nodo("Resposta - The Room", "Final", "Final");

    Nodo* nao_aprendizado = criar_nodo("Gosta de jogos de computador?", "(esquerda) Sim", "(direita) Não");
    intelectual->direita = nao_aprendizado;

    nao_aprendizado->direita = criar_nodo("Resposta - Leitura de Ficção", "Final", "Final");

    Nodo* planejar_jogo = criar_nodo("Gosta de planejar enquanto joga?", "(esquerda) Sim", "(direita) Não");
    nao_aprendizado->esquerda = planejar_jogo;

    planejar_jogo->esquerda = criar_nodo("Resposta - Baldur's Gate 3", "Final", "Final");
    planejar_jogo->direita = criar_nodo("Resposta - Call of Duty Black Ops 6", "Final", "Final");
}

void arvore_relaxante(Nodo* arLivre)
{
    Nodo* relaxante = criar_nodo("Gosta de atividades com natureza?", "(esquerda) Sim", "(direita) Não");
    arLivre->esquerda = relaxante;

    Nodo* natureza_sim = criar_nodo("Prefere sozinho ou em grupo?", "(esquerda) Sozinho", "(direita) Grupo");
    relaxante->esquerda = natureza_sim;

    natureza_sim->esquerda = criar_nodo("Resposta - Caminhadas em trilhas solo", "Final", "Final");

    Nodo* explorar = criar_nodo("Gosta de explorar e descobrir novas lugares?", "(esquerda) Sim", "(direita) Não");
    natureza_sim->direita = explorar;

    explorar->esquerda = criar_nodo("Resposta - Observação de Pássaros", "Final", "Final");
    explorar->direita = criar_nodo("Resposta - Jardinagem Comunitária", "Final", "Final");

    relaxante->direita = criar_nodo("Resposta - Yoga", "Final", "Final");
}

void arvore_adrenalina(Nodo* arLivre)
{
    Nodo* adrenalina = criar_nodo("Prefere esportes ou aventura?", "(esquerda) Esportes", "(direita) Aventura");
    arLivre->direita = adrenalina;

    Nodo* esportes = criar_nodo("Velocidade ou resistência?", "(esquerda) Velocidade", "(direita) Resistência");
    adrenalina->esquerda = esportes;

    esportes->esquerda = criar_nodo("Resposta - Ciclismo de Montanha", "Final", "Final");
    esportes->direita = criar_nodo("Resposta - Caminhadas de Longa Distância", "Final", "Final");

    Nodo* aventura = criar_nodo("Prefere atividades em montanhas ou campos?", "(esquerda) Montanhas", "(direita) Campos");
    adrenalina->direita = aventura;

    aventura->esquerda = criar_nodo("Resposta - Escalada", "Final", "Final");

    Nodo* tipo_campo = criar_nodo("Prefere atividades em grupo ou solo?", "(esquerda) Grupo", "(direita) Solo");
    aventura->direita = tipo_campo;

    tipo_campo->esquerda = criar_nodo("Resposta - Airsoft", "Final", "Final");
    tipo_campo->direita = criar_nodo("Resposta - Offroad", "Final", "Final");
}

Nodo* criar_arvore(){

    Nodo *raiz = criar_nodo("Prefere algo ao ar livre ou ambientes fechados?", "(esquerda) Ao ar livre", "(direita) Ambientes Fechados");

    // Ambientes Fechados
    Nodo *fechado = criar_nodo("Prefere um Hobby manual ou intelectual?", "(esquerda) Intelectual", "(direita) Manual");
    raiz->direita = fechado;

    // Manual
    arvore_manual(fechado);

    // Intelectual
    arvore_intelectual(fechado);

    // Ao ar livre
    Nodo *arLivre = criar_nodo("Prefere algo relaxante ou cheio de adrenalina?", "(esquerda) Relaxante", "(direita) Cheio de Adrenalina");
    raiz->esquerda = arLivre;

    // Relaxante
    arvore_relaxante(arLivre);

    // Cheio de Adrenalina
    arvore_adrenalina(arLivre);

    return raiz;
}

void testCase1(){
    Nodo *root = criar_arvore();
    printf("Pergunta: %s\n",root->pergunta);
    printf("Resposta: %s\n",root->pergunta_esquerda);
    Nodo *next = root->esquerda;
    printf("Pergunta: %s\n",next->pergunta);
    printf("Resposta: %s\n",next->pergunta_esquerda);
    next = next->esquerda;
    printf("Pergunta: %s\n",next->pergunta);
    printf("Resposta: %s\n",next->pergunta_esquerda);
    next = next->esquerda;
    printf("Pergunta: %s\n",next->pergunta);
    printf("Resposta: %s\n",next->pergunta_direita);
    next = next->direita;
    printf("Pergunta: %s\n",next->pergunta);
    printf("Resposta: %s\n",next->pergunta_esquerda);
    next = next->esquerda;
    printf("%s\n",next->pergunta);
}

void testeCase2(){
     Nodo *root = criar_arvore();
    printf("Pergunta: %s\n",root->pergunta);
    printf("Resposta: %s\n",root->pergunta_direita);
    Nodo *next = root->direita;
    printf("Pergunta: %s\n",next->pergunta);
    printf("Resposta: %s\n",next->pergunta_esquerda);
    next = next->esquerda;
    printf("Pergunta: %s\n",next->pergunta);
    printf("Resposta: %s\n",next->pergunta_esquerda);
    next = next->esquerda;
    printf("Pergunta: %s\n",next->pergunta);
    printf("Resposta: %s\n",next->pergunta_direita);
    next = next->direita;
    printf("Pergunta: %s\n",next->pergunta);
    printf("Resposta: %s\n",next->pergunta_esquerda);
    next = next->esquerda;
    printf("Pergunta: %s\n",next->pergunta);
    printf("%s\n",next->pergunta_direita);
    next = next->direita;
    printf("%s\n",next->pergunta);;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    navegar_arvore(criar_arvore());
    puts("#################### TESTE CASE 1 ####################");
    testCase1();
    puts("#################### TESTE CASE 1 ####################");
    puts("#################### TESTE CASE 2 ####################");
    testeCase2();
    puts("#################### TESTE CASE 2 ####################");

}



//arlivre -> relaxante ->contato com natureza -> grupo -> descobrir novos lugares -> Observação de Passáros
