/* 
    Un consultorio electrónico es un sistema informático que
    permite gestionar los medicos que trabajan en el centro,
    consultar su proximo paciente, gestionar que ha sido atendido
    o si tiene lista de espera para ser atendido.

    Un medico es una persona que puede trabajar en el consultorio
    y tiene una identidad y una cola de pacientes.

    Un paciente, es una entidad que acude a un consultorio para ser
    atendido por un medico.

    Como argumentos de todas las funciones del consultorio (que lo necesiten) 
    se indicará el id del médico, el cual será transformado implicitamente
    a un objeto médico temporal para realizar las busquedas, comparaciones
    y operaciones pertinentes.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cassert>

using namespace std;

class Paciente
{
    private:
        unsigned id_;
    public:
        Paciente(unsigned);
        unsigned id() const;
};


class Medico: public Paciente
{
    private:
        queue<Paciente> q;
    public:
        Medico(unsigned);
        Paciente consultar() const;
        void atender();
        bool listaEspera() const;
        void asignaPaciente(Paciente);
        bool operator ==(Medico& ) const;
};

class Consultorio
{
    private:
        vector<Medico> v;
    public:
        Consultorio();
        void alta(Medico&);
        void baja(Medico&);
        void listaEspera(Medico&, Paciente);
        Paciente consultar(Medico&) const;
        void atender(Medico&);
        bool listaEspera(Medico&) const;
};

//Crea un paciente a partir de un numero entero
Paciente::Paciente(unsigned id): id_{id} {}
//Devuelve la identidad del paciente
unsigned Paciente::id() const {return id_;}

//Crea un medico a partir de un entero
Medico::Medico(unsigned id): Paciente{id},
q{queue<Paciente>{}} {}

//Si existe, devuelve el proximo paciente del medico
Paciente Medico::consultar() const 
{
    assert(listaEspera());
    return q.front();
}
//Si existe, atiende al proximo paciente del medico
void Medico::atender() {if(listaEspera()) q.pop();}
//Comprueba si el medico tiene algun paciente disponible
bool Medico::listaEspera() const {return q.empty();}
//Añade un paciente a la cola del medico
void Medico::asignaPaciente(Paciente p) {q.push(p);}
//Compara la identidad de dos medicos y devuelve verdadero en caso
// de que ambas sean iguales o falso en el contrario
bool Medico::operator==(Medico& m) const {return id() == m.id();}

//Crea un consultorio vacio
Consultorio::Consultorio(): v{vector<Medico>{}} {}

//da de alta un medico no existente en el consultorio. Si existe
//No hace nada
void Consultorio::alta(Medico& m) 
{
    for(auto medicos : v)
        if(medicos == m)
            return;
    v.push_back(m);
}

//Elimina un medico del consultorio. Sino existe, no hace nada
void Consultorio::baja(Medico& m) 
{    
    for(vector<Medico>::iterator i = v.begin(); i != v.end(); ++i)
        if(*i == m)
        {
            v.erase(i);
            break;
        }
}

/* Añade un paciente a la lista de espera del medico pasado como
argumento. En caso de no existir el medico, no hace nada */
void Consultorio::listaEspera(Medico& m, Paciente p) 
{
    for(auto medicos : v)
        if(medicos == m)
            medicos.asignaPaciente(p);
}

/* Devuelve el proximo paciente del medico pasado como argumento.
En caso de no existir el medico, deuvelve el paciente 0.
En caso de existir el medico, pero no tener pacientes, da error. */
Paciente Consultorio::consultar(Medico& m) const
{
    for(auto medicos : v)
        if(m == medicos)
            return medicos.consultar();
    
    return Paciente{0};
}

//Atiende al proximo paciente del medico indicado como argumento.
//Si el medico no existe o no tiene pacientes, no hace nada.
void Consultorio::atender(Medico& m)
{
    for(auto medicos : v)
        if(medicos == m)
            if(medicos.listaEspera())
                medicos.atender();
            else
                break;
}

//Comprueba si el medico pasado como argumento tiene lista de espera.
//En caso de no existir el medico, devuelve falso.
bool Consultorio::listaEspera(Medico& m) const
{
    for(auto medicos : v)
        if(medicos == m)
            return medicos.listaEspera();

    return false;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
