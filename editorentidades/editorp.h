#include <iostream>
#include <math.h>
#include <string>
using namespace std;


class elemento
{
    string nombre;
public:
    elemento()
    {
        nombre = "Vacio";
    }
    elemento(string x)
    {
        nombre = x;
    }
    elemento( elemento &o)
    {
        nombre=o.getnombre();
    }
    void set_elemento(string x)
    {
        nombre =x;
    }
    string getnombre()
    {
        return nombre;
    }

};

class rama_elemental
{

    elemento *lista;
    int **tabla_debilidades;
    int numero;
public:
    rama_elemental(int x)
    {
        numero = x;
        lista = new elemento[x];
        tabla_debilidades = new int *[numero];
        for(int i =0; i<x;i++)
            tabla_debilidades[i]=new int [numero];
        for(int l=0;l<numero;l++)
            for(int m=0; m<numero;m++)
                tabla_debilidades[l][m]= 1;

    }
    void set_element(string x, int y)
    {
        lista[y].set_elemento(x);
    }
    void set_debilidad_fortaleza(string x, string y, string z)
    {
        bool validacion=false;
        for(int i = 0; i<numero; i++)
            if (x==lista[i].getnombre())
                for(int j = 0; j<numero; j++)
                    if (y==lista[j].getnombre())
                        for(int k = 0; k<numero; k++)
                            if (z==lista[k].getnombre())
                                validacion = true;
        if (validacion==true)
            for(int i = 0; i<numero; i++)
                if (x==lista[i].getnombre())
                    for(int j = 0; j<numero; j++)
                        if (y==lista[j].getnombre())
                            for(int k = 0; k<numero; k++)
                                if (z==lista[k].getnombre())
                                {
                                    for(int l=0;l<numero;l++)
                                        for(int m=0; m<numero;m++)
                                        {
                                            if (j==k){
                                                tabla_debilidades[i][j]=3;
                                                tabla_debilidades[j][i]=3;}
                                            else
                                            {
                                                tabla_debilidades[i][j]=2;
                                                tabla_debilidades[i][k]=0;
                                                tabla_debilidades[j][i]=0;
                                                tabla_debilidades[k][i]=2;

                                            }
                                        }
                                }
    }
    void mostrar_tabla()
    {
        for(int l=0;l<numero;l++){
            for(int m=0; m<numero;m++)
                cout << tabla_debilidades[l][m] << " ";
            cout << endl;
            }
    }
    elemento get_elemento(int x)
    {
        return lista[x];
    }
    string get_nombre(int x)
    {
        return lista[x].getnombre();
    }
    ~rama_elemental()
    {
        delete lista;
        delete *tabla_debilidades;
        delete tabla_debilidades;
    }

};

class estadistica
{

    string nombre;
public:
    int valor;
    estadistica()
    {
        valor=0;
        nombre="VACIO";
    }
    estadistica(string x, int y)
    {
        valor = y;
        nombre = x;
    }
    estadistica(estadistica &o)
    {
        valor = o.get_valor();
        nombre = o.getnom();
    }
    int get_valor()
    {
        return valor;
    }
    string getnom()
    {
        return nombre;
    }
    void set_valor(int x)
    {
        valor = x;
    }
    void set_nombre(string x)
    {
        nombre = x;
    }
    void sumar_valor(int x)
    {
        valor +=x;
    }
};

class stats
{
    int tamano;
public:
    estadistica *S;
    stats()
    {
        tamano=7;
        S= new estadistica[tamano];
        for(int i = 0; i<tamano; i++){
            (S+i)->set_nombre("llenar");
            (S+i)->set_valor(10);
        }
    }
    stats(int x, string l[], int m[])
    {
        tamano = x;
        S= new estadistica[tamano];
        for(int i = 0; i<tamano; i++)
            *(S+i)= estadistica(l[i],m[i]);
    }
    stats( stats &o)
    {
        tamano = o.get_tamano();
        S= new estadistica[tamano];
        for(int i = 0; i<tamano; i++)
            *(S+i)= estadistica(o.get_stats_nombre(i),get_stats_valor(i));
    }
    void set_nombre(string x, int y)
    {
        (S+y)->set_nombre(x);
    }
    void set_valor(int x, int y)
    {
        (S+y)->set_valor(x);
    }
    int get_tamano()
    {
        return tamano;
    }
    int get_stats_valor(int x)
    {
        return (S+x)->get_valor();
    }
    string get_stats_nombre(int x)
    {
        return (S+x)->getnom();
    }
    void mostrar_stats()
    {
        for(int i =0;i<tamano;i++)
            cout << "ESTADISTICA " << i+1 << ":  "<<get_stats_nombre(i)<<" VALOR:  "<<get_stats_valor(i)<<endl;
    }
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
    nivel()
    {
        nive = 1;
        experiencia = 0;
        exp_necesaria = 10;
        exp_total = 0;
        nivel_maximo = 100;
        constante = 2.7818;
    }
    nivel (double x, double y, double z, double j, double w, double i)
    {
        nive = x;
        experiencia = y;
        exp_necesaria = z;
        exp_total = j;
        nivel_maximo = w;
        constante = i;
    }
    nivel ( nivel &o)
    {
        nive = o.getnivel();
        experiencia = o.getexp();
        exp_necesaria = o.getexpn();
        exp_total = o.getexptotal();
        nivel_maximo = o.getnivel_max();
        constante = o.get_constante();
    }
    double getexptotal()
    {
        return exp_total;
    }
    double getnivel()
    {
        return nive;
    }
    double getexp()
    {
        return experiencia;
    }
    double getexpn()
    {
        return exp_necesaria;
    }
    double getnivel_max()
    {
        return nivel_maximo;
    }
    double get_constante()
    {
        return constante;
    }
    void set_exnec()
    {
        exp_necesaria = pow(get_constante(),nive/10)*100;
    }
    void aumentar_exp(double x)
    {
        experiencia += x;
        exp_total += x;
    }
    void subir_nivel(int f)
    {
        experiencia = f;
        if (nive < nivel_maximo)
            nive++;
        set_exnec();
    }
    void sistema_de_validacion()
    {
        if (getexp()>=getexpn()){
            int f = getexp()-getexpn();
            subir_nivel(f);}
    }

};

class estado
{
    string nombre;
    string codigo_efecto;
public:
    estado()
    {
        nombre = "Normal";
        codigo_efecto = "00000";
    }
    estado(estado &o)
    {
        nombre = o.getnombre();
        codigo_efecto = o.get_codigo();
    }
    estado (string x, string y)
    {
        nombre = x;
        codigo_efecto = y;
    }
    void setnombre(string x)
    {
        nombre = x;
    }
    void set_codigo(string x)
    {
        codigo_efecto = x;
    }
    string getnombre()
    {
        return nombre;
    }
    string get_codigo()
    {
        return codigo_efecto;
    }
};

class habilidad
{
    string nombre;
    int potencia;
    elemento elem;

public:
    estado stad;
    habilidad()
    {
        nombre = "INSERTE DATOS";
        potencia = 0;
    }
    habilidad(string x, int y, rama_elemental z, int zx, string r, string k)
    {
        nombre = x;
        potencia = y;
        elem.set_elemento(z.get_nombre(zx));
        stad.setnombre(r);
        stad.set_codigo(k);
    }
    string get_nombre()
    {
        return nombre;
    }
    int get_potencia()
    {
        return potencia;
    }
    string get_elemento()
    {
        return elem.getnombre();
    }
    string get_estado()
    {
        return stad.getnombre();
    }
    estado getestad()
    {
        return stad;
    }
    void set_nombre(string x)
    {
        nombre = x;
    }
    void set_potencia(int x)
    {
        potencia = x;
    }
    void set_elemento(rama_elemental x, int y)
    {
        elem.set_elemento(x.get_nombre(y));
    }
    void set_estado (estado x)
    {
        stad.setnombre(x.getnombre());
        stad.set_codigo(x.get_codigo());
    }
    void mostrar_datos()
    {
        cout << "Nombre: "<<get_nombre()<<endl;
        cout << "Potencia: "<<get_potencia()<<endl;
        cout << "Elemento: "<<get_elemento()<<endl;
        cout << "Estado: "<<get_estado()<<endl;
    }
};

class item
{
protected:
    string name;
    string description;
public:
    item()
    {
        name = "ITEM VACIO";
        description = "SIN DESCRIPCION";
    }
    item(string x, string y)
    {
        name = x;
        description = y;
    }
    string get_nombre()
    {
        return name;
    }
    string get_description()
    {
        return description;
    }
    void set_nombre(string x)
    {
        name = x;
    }
    void set_descripcion(string x)
    {
        description = x;
    }
};

class tipo_de_arma
{
    string tipo;
public:
    tipo_de_arma()
    {
        tipo = "ninguno, esto no es un arma";
    }
    tipo_de_arma(string x)
    {
        tipo = x;
    }
    void set_tipo(string x)
    {
        tipo = x;
    }
    string get_tipo()
    {
        return tipo;
    }
};

class rama_tipos_arma
{
    tipo_de_arma *T;
    int tamano;
public:
    rama_tipos_arma(tipo_de_arma tt[], int x)
    {
        T = new tipo_de_arma[x];
        tamano = x;
        for (int i = 0; i < tamano; i++)
            T[i].set_tipo(tt[i].get_tipo());
    }
    char get_codigo_arma(int x)
    {
        string y = T[x].get_tipo();
        return y[0];
    }
    ~rama_tipos_arma()
    {
        delete T;
    }
};

class weapon:item
{
    int tamano;
    string *stat_mejorado;
    int *aumento;
    elemento element;
    tipo_de_arma tip;
public:
    weapon()
    {
        item();
        tip = tipo_de_arma();
        stat_mejorado = new string[0];
        aumento = new int[0];
        tamano = 0;
        element=elemento();
    }
    weapon (string descr, string x, string y[],int f, int z[], string elem, tipo_de_arma typ)
    {
        set_nombre(x);
        set_descripcion(descr);
        tamano = f;
        stat_mejorado = new string[f];
        for(int i = 0; i < tamano; i++)
            stat_mejorado[i]=y[i];
        aumento = new int[f];
        for(int i = 0; i < tamano; i++)
            aumento[i]=z[i];
        element = elemento(elem);
        tip = tipo_de_arma(typ.get_tipo());
    }
    weapon (weapon &o)
    {
        tamano = o.get_tamano();
        item(o.nombre(),o.description());
        stat_mejorado = new string[tamano];
        for(int i = 0; i < tamano; i++)
            stat_mejorado[i]=o.get_stat_mejorado(i);
        aumento = new int[tamano];
        for(int i = 0; i < tamano; i++)
            aumento[i]=o.get_aumento(i);
        element = o.get_elemento();
    }
    string description()
    {
        return get_description();
    }
    int get_tamano()
    {
        return tamano;
    }
    string nombre()
    {
        return get_nombre();
    }
    string get_stat_mejorado(int x)
    {
        return stat_mejorado[x];
    }
    int get_aumento(int x)
    {
        return aumento[x];
    }
    string get_elemento()
    {
        return element.getnombre();
    }

    void set_stats_mejorador_plus_stat_(string x[], int y[])
    {
        for(int i = 0; i < tamano; i++)
            stat_mejorado[i]=x[i];
        for(int i = 0; i < tamano; i++)
            aumento[i]=y[i];
    }
    void set_elemento(elemento r)
    {
        element.set_elemento(r.getnombre());
    }
    void mostrar_datos()
    {
        cout << "NOMBRE DEL WEAPON:  " <<nombre()<<"\n\n\n"<<"DESCRIPCION:  "<<description()<<endl;
        cout << "STATS Y AUMENTOS Y/O DECREMENTOS:  "<<"\n\n";
        for(int i = 0; i < tamano; i++)
            cout << "STAT MODIFICADO:  "<<get_stat_mejorado(i) << "  MODIFICACION:   "<< get_aumento(i)<<endl;
        cout << "ELEMENTO  "<< get_elemento();
    }
    ~weapon()
    {
        delete stat_mejorado;
        delete aumento;
    }

};


class clase
{
    string nombre;
    int tam;
    habilidad *H;
    int *niveles_para_llegar;
    string beneficio_stats;
    string beneficio_armas;
public:
    clase(int x)
    {
        nombre = "vacio";
        tam = x;
        H=new habilidad[tam];
        niveles_para_llegar=new int[tam];
        beneficio_stats="0000000";
        beneficio_armas="xxxxxxx";
    }
    clase()
    {
        nombre = "vacio";
        tam = 0;
        H=new habilidad[tam];
        niveles_para_llegar=new int[tam];
        beneficio_stats="0000000";
        beneficio_armas="xxxxxxx";
    }
    clase(int x,string y, string z, string e, int niv[], habilidad hab[])
    {
        nombre = y;
        tam = x;
        beneficio_armas = e;
        beneficio_stats = z;
        niveles_para_llegar = new int[tam];
        H = new habilidad[tam];
        for (int i = 0; i < tam; i++){
            H[i]=hab[i];
            niveles_para_llegar[i]=niv[i];}

    }
    clase(clase &o)
    {
        tam = o.get_tam();
        nombre = o.getnom();
        beneficio_armas = o.getbenar();
        beneficio_stats = o.getbenst();
        niveles_para_llegar = new int[tam];
        H = new habilidad[tam];
        for (int i = 0; i < tam; i++){
            H[i]=o.gethab(i);
            niveles_para_llegar[i]=o.getniv(i);
        }
    }
    void nombrar(string x)
    {
        nombre = x;
    }
    void setear_stats(string x)
    {
        beneficio_stats = x;
    }
    void setear_armas(string x)
    {
        beneficio_armas = x;
    }
    void set_habilidades(int o, int niv,habilidad hab, rama_elemental z, int zx)
    {
        H[o].set_nombre(hab.get_nombre());
        H[o].set_potencia(hab.get_potencia());
        H[o].set_elemento(z,zx);
        H[o].set_estado(hab.stad);
        niveles_para_llegar[o]=niv;
    }
    habilidad gethab(int x)
    {
        return H[x];
    }
    int get_tam()
    {
        return tam;
    }
    string getnom()
    {
        return nombre;
    }
    string getbenar()
    {
        return beneficio_armas;
    }
    string getbenst()
    {
        return beneficio_stats;
    }
    int getniv(int x)
    {
        return niveles_para_llegar[x];
    }
    void mostrar_datos()
    {
        cout << "NOMBRE DE LA CLASE: "<<getnom()<< "\n\n\n";
        cout << "CODIGO DE VERIFICACION DE ARMAS: "<< getbenar() << "\n";
        cout << "CODIGO DE VERIFICACION DE STATS: "<< getbenst() << "\n";
        for (int i = 0; i < tam; i++){
            cout << "HABILIDAD: ";
            H[i].mostrar_datos();
            cout<< "NIVEL NECESARIO: "<< getniv(i)<<"\n\n";
        }
    }
    ~clase()
    {
        delete H;
        delete niveles_para_llegar;
    }

};



class entidad
{
protected:
    string nombre;
    int num_clase;
    clase _clase;
    stats _stats;
    nivel _nivel;
    int num_weapon;
    weapon *_weapon;
    int *const_stats;
public:
    entidad();
    entidad(string x, clase c, stats s, nivel n, weapon w[],int num_w)
    {
        const_stats = new int[s.get_tamano()];
        nombre = x;
        num_clase = c.get_tam();
        _clase=clase(c);
        _stats=stats(s);
        for(int i = 0 ; i < _stats.get_tamano();i++)
            const_stats[i]=_stats.get_stats_valor(i);
        _nivel=nivel(n);
        num_weapon = num_w;
        _weapon = new weapon[num_weapon];
        for (int i =0 ; i < num_weapon; i++)
            _weapon[i]=weapon(w[i]);
    }
    virtual void mostrar_datos()
    {
        cout << "NOMBRE : "<< nombre << endl;
        _clase.mostrar_datos();
        _stats.mostrar_stats();
        cout << "nivel: "<<_nivel.getnivel();
        for(int i = 0; i< num_weapon; i++)
            _weapon[i].mostrar_datos();
    }
    virtual void set_stats()
    {
        for(int i = 0; i < _stats.get_tamano(); i++)
            _stats.S[i].valor = _nivel.getnivel()*(_clase.getbenst()[i]-'0')+const_stats[i];
    }
    virtual void subir_nivel_exp(int x)
    {
        _nivel.aumentar_exp(x);
        _nivel.sistema_de_validacion();
        set_stats();
    }
    virtual void cambiar_clase(clase &o, rama_elemental x, int xf, habilidad hs[] )
    {
        _clase.setear_armas(o.getbenar());
        _clase.setear_stats(o.getbenst());
        for(int i = 0; i < _clase.get_tam(); i++)
            _clase.set_habilidades(i,o.getniv(i),hs[i],x,xf);
    }
    virtual void equipar(weapon wea, int x)
    {
        if(_stats.get_stats_nombre(x)==_weapon->get_stat_mejorado(x)){
            _weapon[x] = wea;
            _stats.set_valor(x, _stats.get_stats_valor(x)+_weapon->get_aumento(x));}
    }
    virtual void desequipar(int x)
    {
        _weapon[x] = weapon();
    }
    virtual ~entidad()
    {
        delete _weapon;
        delete const_stats;
    }

};

class personaje:entidad
{
public:
    personaje(string x, clase c, stats s, nivel n, weapon w[],int num_w)
    {
        entidad(x, c, s, n, w,num_w);
    }
    void mostrar_datos()
    {
        entidad::mostrar_datos();
    }
    void set_stats()
    {
        entidad::set_stats();
    }
    void subir_nivel_exp(int x)
    {
        entidad::subir_nivel_exp(x);
    }
    void cambiar_clase(clase &o, rama_elemental z,int xf, habilidad hs[])
    {
        entidad::cambiar_clase(o,z,xf,hs);
    }
    void equipar(weapon wea, int x)
    {
        entidad::equipar(wea,x);
    }
    void desequipar(int x)
    {
        entidad::desequipar(x);
    }

};
