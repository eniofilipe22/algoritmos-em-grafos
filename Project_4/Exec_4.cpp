#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <chrono>
#include <time.h>
#include <queue>

using namespace std;

int MATRIZ_CUSTOS[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 2, 1, 2, 3, 2, 3},
    {2, 1, 0, 3, 2, 1, 4, 3, 2},
    {1, 2, 3, 0, 1, 2, 1, 2, 3},
    {2, 1, 2, 1, 0, 1, 2, 1, 2},
    {3, 2, 1, 2, 1, 0, 3, 2, 1},
    {2, 3, 4, 1, 2, 3, 0, 1, 2},
    {3, 2, 3, 2, 1, 2, 3, 0, 1},
    {4, 3, 2, 3, 2, 1, 2, 1, 0},
};

int ESQ = 0;
int CIMA = 1;
int DIR = 2;
int BAIXO = 3;

int MATRIZ_POSSIBILIDADES_JOGADAS[9][4] = {
    {-1, -1, 1, 3},
    {0, -1, 2, 4},
    {1, -1, -1, 5},
    {-1, 0, 4, 6},
    {3, 1, 5, 7},
    {4, 2, -1, 8},
    {-1, 3, 7, -1},
    {6, 4, 8, -1},
    {7, 5, -1, -1},
};

struct JOGADA
{
    vector<int> jogada;
    int custo_posicoes;
    int custo_jogada;
    int custo_total;
    int pai;
    int tipo_jogada;
};

vector<JOGADA> jogadas_existentes;

vector<long int> jogadas_existentes_hash;

struct ComparadorDeMelhorJogada
{
    bool operator()(const int &s1, const int &s2)
    {
        return jogadas_existentes[s1].custo_total > jogadas_existentes[s2].custo_total;
    }
};

priority_queue<int, vector<int>, ComparadorDeMelhorJogada>
    fila_de_prioridade;

int BuscaPosicaoDoZero(JOGADA jogada);

long int CalculaHashJogada(JOGADA jogada);

int CalculaCustoPosicoes(JOGADA jogada);

bool GeraJogada(JOGADA jogada_atual, int index);

bool CalculaEInserePossivelJogada(JOGADA possivel_jogada);

bool ExisteHash(long int hash);

void ResolveJogo(JOGADA ponto_inicial);

void PrintJogadas();

int main()
{
    cout
        << "oooooi" << endl;

    JOGADA initial;
    // 3 + 3 + 0 + 2 + 1 + 1 + 1 + 1 + 0
    initial.jogada = {5, 6, 2, 7, 1, 8, 3, 4, 0};
    // initial.jogada = {1, 2, 0, 3, 4, 5, 6, 7, 8};
    ResolveJogo(initial);

    initial.jogada = {5, 3, 2, 8, 7, 1, 4, 0, 6};
    ResolveJogo(initial);

    initial.jogada = {1, 0, 7, 5, 2, 4, 3, 8, 6};
    ResolveJogo(initial);
    // initial.custo_posicoes = CalculaCustoPosicoes(initial);

    // long int hashInitial = CalculaHashJogada(initial);

    // cout << "Custo inicial = " << initial.custo_posicoes << endl;
    // cout << "HASH inicial = " << hashInitial << endl;

    return 0;
};

long int CalculaHashJogada(JOGADA jogada)
{
    long int total = 0;
    for (int cont = 0; cont < 9; cont++)
    {
        total = total + (pow(10, cont) * jogada.jogada[cont]);
    }

    return total;
};

int CalculaCustoPosicoes(JOGADA jogada)
{

    int total = 0;
    for (int cont = 0; cont < 9; cont++)
    {
        total = total + MATRIZ_CUSTOS[jogada.jogada[cont]][cont];
    }
    return total;
}

int BuscaPosicaoDoZero(JOGADA jogada)
{
    int posicao_zero = 0;

    for (int i = 0; i < 9; i++)
    {
        if (jogada.jogada[i] == 0)
        {
            posicao_zero = i;
            break;
        }
    }

    return posicao_zero;
}

bool ExisteHash(long int hash)
{
    for (long int hash_item : jogadas_existentes_hash)
    {
        if (hash_item == hash)
        {
            return true;
        }
    }

    return false;
}

bool CalculaEInserePossivelJogada(JOGADA possivel_jogada)
{
    bool finalizou = false;

    long int hash_jogada = CalculaHashJogada(possivel_jogada);
    if (!ExisteHash(hash_jogada))
    {
        possivel_jogada.custo_posicoes = CalculaCustoPosicoes(possivel_jogada);
        possivel_jogada.custo_total = possivel_jogada.custo_posicoes + possivel_jogada.custo_jogada;
        jogadas_existentes.push_back(possivel_jogada);
        int posicao_jogada = jogadas_existentes.size() - 1;
        fila_de_prioridade.push(posicao_jogada);
        if (possivel_jogada.custo_posicoes == 0)
        {
            finalizou = true;
        }
    }
    return finalizou;
}

bool GeraJogada(JOGADA jogada_atual, int index)
{

    bool finalizou = false;

    int posicao_do_zero = BuscaPosicaoDoZero(jogada_atual);

    if (MATRIZ_POSSIBILIDADES_JOGADAS[posicao_do_zero][ESQ] > -1)
    {
        int posicao_pra_trocar = MATRIZ_POSSIBILIDADES_JOGADAS[posicao_do_zero][ESQ];
        JOGADA nova_jogada;
        nova_jogada.jogada = jogada_atual.jogada;
        nova_jogada.jogada[posicao_do_zero] = nova_jogada.jogada[posicao_pra_trocar];
        nova_jogada.jogada[posicao_pra_trocar] = 0;
        nova_jogada.pai = index;
        nova_jogada.custo_jogada = jogada_atual.custo_jogada + 1;
        nova_jogada.tipo_jogada = ESQ;

        finalizou = CalculaEInserePossivelJogada(nova_jogada);
        if (finalizou)
        {
            return true;
        }
    }
    if (MATRIZ_POSSIBILIDADES_JOGADAS[posicao_do_zero][CIMA] > -1)
    {
        int posicao_pra_trocar = MATRIZ_POSSIBILIDADES_JOGADAS[posicao_do_zero][CIMA];
        JOGADA nova_jogada;
        nova_jogada.jogada = jogada_atual.jogada;
        nova_jogada.jogada[posicao_do_zero] = nova_jogada.jogada[posicao_pra_trocar];
        nova_jogada.jogada[posicao_pra_trocar] = 0;
        nova_jogada.pai = index;
        nova_jogada.custo_jogada = jogada_atual.custo_jogada + 1;
        nova_jogada.tipo_jogada = CIMA;

        finalizou = CalculaEInserePossivelJogada(nova_jogada);
        if (finalizou)
        {
            return true;
        }
    }
    if (MATRIZ_POSSIBILIDADES_JOGADAS[posicao_do_zero][DIR] > -1)
    {
        int posicao_pra_trocar = MATRIZ_POSSIBILIDADES_JOGADAS[posicao_do_zero][DIR];
        JOGADA nova_jogada;
        nova_jogada.jogada = jogada_atual.jogada;
        nova_jogada.jogada[posicao_do_zero] = nova_jogada.jogada[posicao_pra_trocar];
        nova_jogada.jogada[posicao_pra_trocar] = 0;
        nova_jogada.pai = index;
        nova_jogada.custo_jogada = jogada_atual.custo_jogada + 1;
        nova_jogada.tipo_jogada = DIR;

        finalizou = CalculaEInserePossivelJogada(nova_jogada);
        if (finalizou)
        {
            return true;
        }
    }
    if (MATRIZ_POSSIBILIDADES_JOGADAS[posicao_do_zero][BAIXO] > -1)
    {
        int posicao_pra_trocar = MATRIZ_POSSIBILIDADES_JOGADAS[posicao_do_zero][BAIXO];
        JOGADA nova_jogada;
        nova_jogada.jogada = jogada_atual.jogada;
        nova_jogada.jogada[posicao_do_zero] = nova_jogada.jogada[posicao_pra_trocar];
        nova_jogada.jogada[posicao_pra_trocar] = 0;
        nova_jogada.pai = index;
        nova_jogada.custo_jogada = jogada_atual.custo_jogada + 1;
        nova_jogada.tipo_jogada = BAIXO;

        finalizou = CalculaEInserePossivelJogada(nova_jogada);
        if (finalizou)
        {
            return true;
        }
    }

    return finalizou;
}

void PrintJogadas()
{
    vector<JOGADA> jogadas_em_ordem;

    JOGADA jogada_aux;
    int posicao_aux = jogadas_existentes.size() - 1;
    cout << "posicao : " << posicao_aux << endl;
    do
    {
        jogada_aux = jogadas_existentes[posicao_aux];
        jogadas_em_ordem.insert(jogadas_em_ordem.begin(), jogada_aux);
        posicao_aux = jogada_aux.pai;
    } while (jogada_aux.pai > -1);

    for (JOGADA jogada_para_imprimir : jogadas_em_ordem)
    {
        cout << "---------";
        if (jogada_para_imprimir.tipo_jogada == -1)
        {
            cout << "(INICIO)";
        }
        if (jogada_para_imprimir.tipo_jogada == ESQ)
        {
            cout << "(ESQUERDA <-)";
        }
        if (jogada_para_imprimir.tipo_jogada == CIMA)
        {
            cout << "(CIMA /\\)";
        }
        if (jogada_para_imprimir.tipo_jogada == DIR)
        {
            cout << "(DIREITA ->)";
        }
        if (jogada_para_imprimir.tipo_jogada == BAIXO)
        {
            cout << "(BAIXO \\/)";
        }
        cout << "---------" << endl;
        cout << jogada_para_imprimir.jogada[0] << "\t" << jogada_para_imprimir.jogada[1] << "\t" << jogada_para_imprimir.jogada[2] << endl;
        cout << jogada_para_imprimir.jogada[3] << "\t" << jogada_para_imprimir.jogada[4] << "\t" << jogada_para_imprimir.jogada[5] << endl;
        cout << jogada_para_imprimir.jogada[6] << "\t" << jogada_para_imprimir.jogada[7] << "\t" << jogada_para_imprimir.jogada[8] << endl;
        cout << endl
             << endl;
    }

    cout << "Quantidade de jogadas: " << jogadas_em_ordem.size() << endl;
}

void ResolveJogo(JOGADA ponto_inicial)
{

    int numero_estados_avaliados = 1;

    jogadas_existentes.clear();
    jogadas_existentes_hash.clear();
    fila_de_prioridade = priority_queue<int, vector<int>, ComparadorDeMelhorJogada>();

    ponto_inicial.custo_jogada = 0;
    ponto_inicial.pai = -1;
    ponto_inicial.tipo_jogada = -1;

    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    CalculaEInserePossivelJogada(ponto_inicial);

    while (!fila_de_prioridade.empty())
    {
        int posicao_da_jogada_no_vetor = fila_de_prioridade.top();
        fila_de_prioridade.pop();
        numero_estados_avaliados++;
        bool finalizou = GeraJogada(jogadas_existentes[posicao_da_jogada_no_vetor], posicao_da_jogada_no_vetor);
        if (finalizou)
        {
            break;
        }
    }
    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    cout << "Finalizou" << endl;
    cout << "Numero de estados avaliados: " << numero_estados_avaliados << endl;
    cout << "Tempo de execucao: " << elapsed_seconds.count() << "s" << endl;
    PrintJogadas();
}