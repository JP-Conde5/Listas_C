//João Pedro Conde Gomes Alves e Bruna Stephany Valentim do Nascimento - 2º Info
//G1
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

const int COD_GOL = 0;
const int COD_ATQ = 1;
const int COD_DEF = 2;
const int COD_MEIO = 3;

class Pessoa{
    protected:
        int idade;
    public:
        Pessoa(){
            idade = 0;
        }

        Pessoa(int idade){
            this->idade = idade;
        }

        int getIdade() const{
            return idade;
        }

        void setIdade(int idade){
            this->idade = idade;
        }
};

class Jogador : public Pessoa{
    protected:
        int posicao, forca;
    public:
        Jogador(){
            posicao = 0;
            forca = 0;
        }

        Jogador(int idade, int forca, int posicao) : Pessoa(idade){
            this->forca = forca;
            this->posicao = posicao;
        }

        int getPosicao() const{
            return posicao;
        }

        int getForca() const{
            return forca;
        }

        void setPosicao(int posicao){
            this->posicao = posicao;
        }

        void setForca(int posicao){
            this->forca = forca;
        }

        string nome_posicao(){
            if(posicao == COD_ATQ){
                return "Ataque";
            }else if(posicao == COD_DEF){
                return "Defesa";
            }else if(posicao == COD_MEIO){
                return "Meio de campo";
            }else if(posicao == COD_GOL){
                return "Goleiro";
            }else{
                return "Posição inválida";
            }
        }

};

class Time{
    private:
        string nome;
        int divisao, forca_atq, forca_def, forca_meio;
        Jogador *j = new Jogador[11];
    public:
        Time(string nome, int divisao, int numatq, int numdef, int nummeio){
            int idade, forca_base, forca;
            forca_atq = 0;
            forca_def = 0;
            forca_meio = 0;
            this->nome = nome;
            this->divisao = divisao;
            for(int i = 0; i < 11; i++){
                idade = 18 + rand()%23;
                forca_base = (100-(3*abs(idade-21)));
                forca = (5 - divisao)*forca_base;
                if(numatq > 0){
                    Jogador *a = new Jogador(idade, forca, 1);
                    j[i] = *a;
                    forca_atq += forca;
                    numatq--;
                }else if(numdef > 0){
                    Jogador *a = new Jogador(idade, forca, 2);
                    j[i] = *a;
                    forca_def += forca;
                    numdef--;
                }else if(nummeio > 0){
                    Jogador *a = new Jogador(idade, forca, 3);
                    j[i] = *a;
                    forca_meio += forca;
                    nummeio--;
                }else{
                    Jogador *a = new Jogador(idade, forca, 0);
                    j[i] = *a;
                }
            }
        }

        string getNome() const{
            return nome;
        }

        int getDivisao() const{
            return divisao;
        }

        int getForca_atq() const{
            return forca_atq;
        }

        int getForca_def() const{
            return forca_def;
        }

        int getForca_meio() const{
            return forca_meio;
        }

        Jogador getJ(int i){
            return j[i];
        }

        void setNome(string nome){
            this->nome = nome;
        }

        void setDivisao(int divisao){
            this->divisao = divisao;
        }
};

int main()
{
    srand(time(NULL));
    string nome;
    char esc;
    int divisao;
    int numatq, numdef, nummeio;
    bool flag;
    do{
        system("clear");
        flag = false;
        cout << "- Times de Futebol -" << endl << endl;
        cout << "Nome do time: ";
        cin  >> nome;
        do{
            cout << "Divisão do time: ";
            cin >> divisao;
            if((divisao > 0) && (divisao < 5)){
                flag = true;
            }else{
                cout << "Só existem as divisões 1, 2, 3 ou 4" << endl << endl;
            }
        }while(!flag);
        flag = false;
        do{
            cout << "Número de jogadores no ataque: ";
            cin >> numatq;
            cout << "Número de jogadores na defesa: ";
            cin >> numdef;
            cout << "Número de jogadores no meio do campo: ";
            cin >> nummeio;
            if(numdef + numatq + nummeio == 10){
                flag = true;
            }
            else{
                cout << "O total de jogadores deve ser 10!" << endl << endl;
            }
        }while(!flag);
        Time t(nome, divisao, numatq, numdef, nummeio);
        cout << endl << "Time criado" << endl;
        cout << "  - Nome do time: " << t.getNome() << endl;
        cout << "  - Divisão do time: " << t.getDivisao() << "ª" << endl;
        cout << "  - Força dos jogadores: " << endl;
        for(int i = 0; i < 11; i++){
            cout << "     *" << i + 1 << "º Jogador: " << t.getJ(i).getForca() << endl;
        }
        cout << "  - Força de ataque: " << t.getForca_atq() << endl;
        cout << "  - Força de defesa: " << t.getForca_def() << endl;
        cout << "  - Força de meio: " << t.getForca_meio() << endl;
        cout << endl << "Deseja criar outro time?[S/N] ";
        cin >> esc;
    }while(esc == 's' || esc == 'S');
    cout << endl << "Programa Finalizando...";

    return 0;
}
