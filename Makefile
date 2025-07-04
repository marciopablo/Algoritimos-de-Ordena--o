# Nome do executável
EXEC = comparador

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -O2

# Arquivos fonte e headers (usando os nomes atuais)
SRCS = main.cpp algoritmos_ordenação.cpp gerador_vetores.cpp
HDRS = algoritmos_ordenação.h gerador_vetores.h

# Regra padrão
all: $(EXEC)

$(EXEC): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC)

clean:
	rm -f $(EXEC)
