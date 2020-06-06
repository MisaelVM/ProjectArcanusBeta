#include <iostream>
#include <math.h>
#include <string>


class elemento
{
    std::string nombre;
public:
    elemento();
    elemento(std::string );
    elemento( elemento& );
    void set_elemento(std::string);
    std::string getnombre();
};


class rama_elemental
{

    elemento *lista;
    int **tabla_debilidades;
    int numero;
public:
    rama_elemental(int);
    void set_element(std::string , int);
    void set_debilidad_fortaleza(std::string , std::string , std::string );
    void mostrar_tabla();
    elemento get_elemento(int);
    std::string get_nombre(int);
    ~rama_elemental();
};

class estadistica
{

    std::string nombre;
public:
    int valor;
    estadistica();
    estadistica(std::string, int);
    estadistica(estadistica&);
    int get_valor();
    std::string getnom();
    void set_valor(int);
    void set_nombre(std::string);
    void sumar_valor(int);
};

class stats
{

    int tamano;
public:
    estadistica *S;
    stats();
    stats(int , std::string[], int[]);
    stats( stats&);
    void set_nombre(std::string x, int y);
    void set_valor(int x, int y);
    int get_tamano();
    int get_stats_valor(int);
    std::string get_stats_nombre(int);
    void mostrar_stats();
};

class nivel
{
    double nive;
    double experiencia;
    double exp_necesaria;
    double exp_total;
    double nivel_maximo;
    double constante;
public:
    nivel();
    nivel (double , double , double , double , double , double );
    nivel ( nivel& );
    double getexptotal();
    double getnivel();
    double getexp();
    double getexpn();
    double getnivel_max();
    double get_constante();
    void set_exnec();
    void aumentar_exp(double );
    void subir_nivel(int );
    void sistema_de_validacion();
};

class estado
{
    std::string nombre;
    std::string codigo_efecto;
public:
    estado();
    estado(estado& );
    estado (std::string, std::string);
    void setnombre(std::string);
    void set_codigo(std::string);
    std::string getnombre();
    std::string get_codigo();
};

class habilidad
{
    std::string nombre;
    int potencia;
    elemento elem;

public:
    estado stad;
    habilidad();
    habilidad(std::string, int, rama_elemental, int, std::string, std::string);
    std::string get_nombre();
    int get_potencia();
    estado getestad();
    std::string get_elemento();
    std::string get_estado();
    void set_nombre(std::string );
    void set_potencia(int );
    void set_elemento(rama_elemental, int);
    void set_estado (estado);
    void mostrar_datos();
};

class item
{
protected:
    std::string name;
    std::string description;
public:
    item();
    item(std::string, std::string);
    std::string get_nombre();
    std::string get_description();
    void set_nombre(std::string);
    void set_descripcion(std::string);
};
class tipo_de_arma
{
    std::string tipo;
public:
    tipo_de_arma();
    tipo_de_arma(std::string);
    void set_tipo(std::string);
    std::string get_tipo();
};
class rama_tipos_arma
{
    tipo_de_arma *T;
    int tamano;
public:
    rama_tipos_arma(tipo_de_arma[], int);
    char get_codigo_arma(int);
    ~rama_tipos_arma();
};

class weapon:item
{
    int tamano;
    std::string *stat_mejorado;
    int *aumento;
    elemento element;
    tipo_de_arma tip;
public:
    weapon();
    weapon (std::string, std::string, std::string[],int, int[], std::string, tipo_de_arma);
    weapon (weapon&);
    std::string description();
    int get_tamano();
    std::string nombre();
    std::string get_stat_mejorado(int);
    int get_aumento(int);
    std::string get_elemento();
    void set_stats_mejorador_plus_stat_(std::string[], int[]);
    void set_elemento(elemento);
    void mostrar_datos();
    ~weapon();
};

class clase
{
    std::string nombre;
    int tam;
    habilidad *H;
    int *niveles_para_llegar;
    std::string beneficio_stats;
    std::string beneficio_armas;
public:
    clase();
    clase(int );
    clase(clase &);
    clase(int,std::string, std::string, std::string, int[], habilidad[]);
    void nombrar(std::string );
    void setear_stats(std::string);
    void setear_armas(std::string );
    void set_habilidades(int, int ,habilidad , rama_elemental, int );
    habilidad gethab(int);
    int get_tam();
    std::string getnom();
    std::string getbenar();
    std::string getbenst();
    int getniv(int);
    void mostrar_datos();
    ~clase();
};
class entidad
{
protected:
    std::string nombre;
    int num_clase;
    clase _clase;
    stats _stats;
    nivel _nivel;
    int num_weapon;
    weapon *_weapon;
    int *const_stats;
public:
    entidad();
    entidad(std::string , clase , stats , nivel , weapon[],int);
    virtual void mostrar_datos();
    virtual void set_stats();
    virtual void subir_nivel_exp(int);
    virtual void cambiar_clase(clase &, rama_elemental, int, habilidad [] );
    virtual void equipar(weapon, int);
    virtual void desequipar(int);
    virtual ~entidad();
};
class personaje:entidad
{
public:
    personaje(std::string , clase , stats , nivel , weapon [],int);
    void mostrar_datos();
    void set_stats();
    void subir_nivel_exp(int x);
    void cambiar_clase(clase &, rama_elemental,int, habilidad[]);
    void equipar(weapon, int);
    void desequipar(int);
};
