#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>


struct ResultadoOrdenacao {
    long int trocas;
    long int comparacoes;
    long double tempo_ms;
};


ResultadoOrdenacao bubble_sort(std::vector<int>& lista);
ResultadoOrdenacao selection_sort(std::vector<int>& lista);
ResultadoOrdenacao insertion_sort(std::vector<int>& lista);
ResultadoOrdenacao quick_sort(std::vector<int>& lista);
ResultadoOrdenacao merge_sort(std::vector<int>& lista);

#endif