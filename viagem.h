typedef struct viagem viagem;

void inserirViagem(grafo*);
viagem *buscarViagem(grafo*, enum veiculo, no, no);
void deletarViagem(grafo*, enum veiculo, no, no);