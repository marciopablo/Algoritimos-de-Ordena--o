#include "gerador_vetores.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

std::vector<int> gerar_vetor_aleatorio(int n) {
    std::vector<int> v(n);
    std::iota(v.begin(), v.end(), 0); // preenche de 0 a n-1

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::shuffle(v.begin(), v.end(), std::default_random_engine(seed));

    return v;
}

std::vector<int> gerar_vetor_quase_ordenado(int n) {
    std::vector<int> v(n);
    std::iota(v.begin(), v.end(), 0);

    // Embaralha só alguns elementos
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine engine(seed);

    for (int i = 0; i < n / 10; ++i) {
        int idx1 = engine() % n;
        int idx2 = engine() % n;
        std::swap(v[idx1], v[idx2]);
    }

    return v;
}

std::vector<int> gerar_vetor_inversamente_ordenado(int n) {
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = n - i;
    }
    return v;
}
