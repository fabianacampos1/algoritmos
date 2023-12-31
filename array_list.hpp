#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

class array_list {
private:
    int* data; //Ponteiro.
    unsigned int size_, capacity_;  
    
    void increase_capacity() { //O(n) n=quantidade de elementos.
        int *new_data = new int[this->capacity_ *2]; // Aloca um novo array com o dobro da capacidade atual. 
        for (unsigned int i=0 ; i<this->size() ; ++i){ // Copia os dados do array antigo para o novo array.
            new_data[i] = this->data[i]; }
        delete [] this->data; // Deleta o array antigo.
        this->data = new_data; // Atualiza o ponteiro `data` para apontar para o novo array.
        this->capacity_ = this->capacity_*2; // Atualiza a capacidade máxima do array.
    }

public:
    array_list() {  //construtor
        data = new int[8]; //Aloca um array de tamanho 8.
        this->size_ = 0; //Inicializa o tamanho atual do array para 0.
        this->capacity_ = 8; //Inicializa a capacidade máxima atual do array para 8.
    }
    ~array_list() {   //Deleta o array que armazena os dados do objeto. O(1)
        delete[] data;  
    }

    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return this->size_; //O(1)
    }

    unsigned int capacity() { // Retorna o espaço reservado para armazenar os elementos
        return this->capacity_; //O(1)
    }

    double percent_occupied() { //Retorna um valor entre 0.0 a 1.0 com o percentual da memória usada.
        return (double)size_ / (double)capacity_; //O(1)
    }

    bool insert_at(unsigned int index, int value) {  //O(n) / Insere elemento no indice index/ N é a quantidade de elementos
        if ( index > this->size_ ) // Verifica se o índice é válido.
                return false;
            if ( index == this->size_ ){ // Se o índice for o último elemento do array, insere o elemento no final do array.
                this->push_back(value);
                return true;}
            if ( this->size_ == this->capacity_ ) // Aumenta a capacidade do array se necessário.
                increase_capacity();
            for ( unsigned int i = this->size_; i > index; i-- ) // Desloca os elementos do array para a direita
                this->data[i] = this->data[i-1];
            this->data[index] = value; // Insere o novo elemento no array
            this->size_++;  // Aumenta o tamanho do array e retorna `true`
            return true;
        }

    bool remove_at(unsigned int index) { // O(n) remove elemento no indice index
        if (index >= this->size_)
            return false; // Não removeu
        for (unsigned i = index + 1; i < this->size_; ++i) {
            this->data[i - 1] = this->data[i];
        }
        this->size_--;
        return true; // Removeu
    }

    int get_at(unsigned int index) { //retorna elemento no indice index. O(1).
        if(index >= size_){
            return -1;}
        else return this->data[index];
    }

    void clear() { //remove todos os elementos do vetor deixando ele no estado inicial. O(1).
        this->size_ = 0;
        this->capacity_=8;
        this->data = new int[8];
        delete [] this->data;
        }

    void push_back(int value) { //adiciona um elemento no final do vetor O(1).
        if (this->size_ == this->capacity_) // Verifica se o array precisa ser expandido
            this->increase_capacity();
        this->data[this->size_++]=value; // Insere o novo elemento no array na última posição
        }

    void push_front(int value) {//adiciona um elemento no inicio do vetor O(n)
    if (this->size_ == capacity_) // Verifica se o array precisa ser expandido
        increase_capacity();
    for ( unsigned int i = this->size_; i > 0; i--) // Desloca os elementos para a direita
                this->data[i] = this->data[i-1];
            this->data[0] = value;  // Insere o novo elemento no array na posição 0
            this->size_++;} // Aumenta o tamanho do array

    bool pop_back() { //remove um elemento do final do vetor O(1).
        if ( this->size_ == 0 ) // Verifica se o array está vazio
                return false;
            this->size_--; // Remove o elemento do final do array
            return true;}

    bool pop_front() { //remove um elemento do inicio do vetor O(n)
        if (this->size_==0) // Verifica se o array está vazio
                return false;
            for ( unsigned i=1;i< this->size_; i++) // Desloca os elementos para a esquerda
                this->data[i-1] = this->data[i];
            this->size_--; // Remove o elemento do início do array
            return true;}
    
    int front(){//retorna o elemento do inicio do vetor O(1).
        if (this->size_==0) //Verifica se está vazio
            return -1;
        return data[0];} // Retorna o elemento do início do array

    int back(){//retorna o elemento do final do vetor O(1).
         if (this->size_==0) // Verifica se o array está vazio
            return -1;
        return data[size_-1];} // Retorna o ultimo elemento

    bool remove(int value) {//remove value do vetor caso esteja presente O(n).
        for (unsigned int i = 0; i < this->size(); i++){  // Percorre o array procurando o elemento
            if(this->find(value)){
                for(unsigned int j=i; j <this->size() - 1; j++){ //executa se encontrar o elemento
                    this->data[j] = this->data[j+1];
                }
                this->size_--; // Remove o elemento do array
                return true;
            }
        }
        return false;
        }

    int find(int value) { // O(n)
        for (unsigned int i = 0 ; i<this->size() ; ++i) // Percorre o array procurando o elemento especificado
            if (value == this->data[i])
                return true;
        return -1;} // Retorna -1 para indicar que o elemento não foi encontrado

    int count(int value) {//retorna quantas vezes value ocorre no vetor. O(n)
        int contar=0;
        for( unsigned i =0; i < this->size_; i++)
            if(this-> data[i] == value) contar++;
        return contar;}

    int sum() {//retorna a soma dos elementos do vetor O(n)
         int sum = 0;
    for (unsigned int i = 0; i < size_; i++) {
      sum += data[i];}
    return sum;}
};

#endif // __ARRAY_LIST_IFRN__