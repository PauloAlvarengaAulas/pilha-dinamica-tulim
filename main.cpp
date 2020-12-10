/*  URI Online Judge | 1430  */
#include <iostream> 
using namespace std; 
template <class T> class Pilha { 
private: 
    template <class TT> class Celula { 
    public: 
        Celula<TT> *prox; 
        TT valor; 
 
        Celula(TT v) { 
            this->valor = v; 
            prox = nullptr; 
        } 
        }; 
        int tamanho; 
        Celula<T> *topo; 
public: 
        Pilha() { 
            topo = nullptr; 
            tamanho = 0; 
        } 
        ~Pilha() { 
            Celula<T> *aux; 
            while(topo!=nullptr) { 
            aux=topo; 
            topo = topo->prox; 
            delete aux; 
            } 
        } 
        int getTamanho() { 
            return tamanho; 
        } 
        bool inserir(const T &valor) { 
            if(this->topo == nullptr) { 
                this->topo = new Celula<T>(valor); 
            } else { 
                Celula<T> *aux = new Celula<T>(valor); 
                aux->prox = this->topo; 
                this->topo = aux; 
            } 
            ++tamanho; 
            return true; 
        } 
        bool excluir(void) { 
            if(this->topo==nullptr) { 
                return false; 
            } else { 
                Celula<T> *aux; 
                aux = topo; 
                this->topo = this->topo->prox; 
                delete aux; 
                --tamanho; 
                return true;
            } 
        } 
        void mostrar() { 
            if(this->topo== nullptr) { 
                cout << "<<nada>>"; 
            } else { 
                cout << this->topo->valor; 
            } 
            cout << endl; 
        } 
        char Retorna_Topo()
        {
            if(this->topo== nullptr) { 
                return '-'; 
            } else { 
                return this->topo->valor; 
            } 
        }
}; 


int main() { 
    Pilha<char> Musica;
    Pilha<char> Bloco_Da_Musica;
    char aux[10000];
    int Blocos_Certos = 0;
    do
    {
        cin.getline(aux, 10000);
        for(int i = 0; aux[i]; i++)
        {
          Musica.inserir(aux[i]);
        }
        for(int i = Musica.getTamanho(); i >= 1; i--)
        {
          if(Musica.Retorna_Topo() != '/')
          {
            Bloco_Da_Musica.inserir(Musica.Retorna_Topo());
            Musica.excluir();
          }
          if(Musica.Retorna_Topo() == '/' && Bloco_Da_Musica.getTamanho() != 0)
          {
              Musica.excluir();
              float Tempo_Bloco_Da_Musicaso = 0;
              for(int k = Bloco_Da_Musica.getTamanho(); k > 0; k--)
              {
                switch (Bloco_Da_Musica.Retorna_Topo())
                {
                  case 'W':
                    Tempo_Bloco_Da_Musicaso +=1;
                    break;
                  case 'H':
                    Tempo_Bloco_Da_Musicaso += 0.5;
                    break;
                  case 'Q':
                    Tempo_Bloco_Da_Musicaso += 0.25;
                    break;
                  case 'E':
                    Tempo_Bloco_Da_Musicaso += 0.125;
                    break;
                  case 'S':
                    Tempo_Bloco_Da_Musicaso += 0.0625;
                    break;
                  case 'T':
                    Tempo_Bloco_Da_Musicaso += 0.03125;
                    break;
                  case 'X':
                    Tempo_Bloco_Da_Musicaso += 0.015625;
                    break;
                  default:
                    Tempo_Bloco_Da_Musicaso += 0;
                    break;
                }
                Bloco_Da_Musica.excluir();
              }
              if(Tempo_Bloco_Da_Musicaso == 1)
              {
                Blocos_Certos++;
              }
          }
          if(Musica.Retorna_Topo() == '/' && Bloco_Da_Musica.getTamanho() == 0)
          {
            Musica.excluir();
          }
        }
        cout<<Blocos_Certos<<endl;
    } while (aux[0] != '*');
    

    return 0;
} 