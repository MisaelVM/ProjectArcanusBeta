#include <iostream>
#include <math.h>
#include <string>
#include "editor.h"
using namespace std;



elemento::elemento()
{
    nombre = "Vacio";
}
elemento::elemento(string x)
{
    nombre = x;
}
elemento::elemento( elemento &o)
{
    nombre=o.getnombre();
}
void elemento::set_elemento(string x)
{
    nombre =x;
}
string elemento::getnombre()
{
    return nombre;
}

rama_elemental::rama_elemental(int x)
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
void rama_elemental::set_element(string x, int y)
{
    lista[y].set_elemento(x);
}
void rama_elemental::set_debilidad_fortaleza(string x, string y, string z)
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
void rama_elemental::mostrar_tabla()
{
    for(int l=0;l<numero;l++){
        for(int m=0; m<numero;m++)
            cout << tabla_debilidades[l][m] << " ";
        cout << endl;
        }
}
elemento rama_elemental::get_elemento(int x)
{
    return lista[x];
}
string rama_elemental::get_nombre(int x)
{
    return lista[x].getnombre();
}
rama_elemental::~rama_elemental()
{
    delete lista;
    delete *tabla_debilidades;
    delete tabla_debilidades;
}

estadistica::estadistica()
{
    valor=0;
    nombre="VACIO";
}
estadistica::estadistica(string x, int y)
{
    valor = y;
    nombre = x;
}
estadistica::estadistica(estadistica &o)
{
    valor = o.get_valor();
    nombre = o.getnom();
}
int estadistica::get_valor()
{
    return valor;
}
string estadistica::getnom()
{
    return nombre;
}
void estadistica::set_valor(int x)
{
    valor = x;
}
void estadistica::set_nombre(string x)
{
    nombre = x;
}
void estadistica::sumar_valor(int x)
{
    valor +=x;
}

stats::stats()
{
    tamano=7;
    S= new estadistica[tamano];
    for(int i = 0; i<tamano; i++){
        (S+i)->set_nombre("llenar");
        (S+i)->set_valor(10);
    }
}
stats::stats(int x, string l[], int m[])
{
    tamano = x;
    S= new estadistica[tamano];
    for(int i = 0; i<tamano; i++)
        *(S+i)= estadistica(l[i],m[i]);
}
stats::stats( stats &o)
{
    tamano = o.get_tamano();
    S= new estadistica[tamano];
    for(int i = 0; i<tamano; i++)
        *(S+i)= estadistica(o.get_stats_nombre(i),get_stats_valor(i));
}
void stats::set_nombre(string x, int y)
{
    (S+y)->set_nombre(x);
}
void stats::set_valor(int x, int y)
{
    (S+y)->set_valor(x);
}
int stats::get_tamano()
{
    return tamano;
}
int stats::get_stats_valor(int x)
{
    return (S+x)->get_valor();
}
string stats::get_stats_nombre(int x)
{
    return (S+x)->getnom();
}
void stats::mostrar_stats()
{
    for(int i =0;i<tamano;i++)
        cout << "ESTADISTICA " << i+1 << ":  "<<get_stats_nombre(i)<<" VALOR:  "<<get_stats_valor(i)<<endl;
}



nivel::nivel()
{
    nive = 1;
    experiencia = 0;
    exp_necesaria = 10;
    exp_total = 0;
    nivel_maximo = 100;
    constante = 2.7818;
}
nivel::nivel (double x, double y, double z, double j, double w, double i)
{
    nive = x;
    experiencia = y;
    exp_necesaria = z;
    exp_total = j;
    nivel_maximo = w;
    constante = i;
}
nivel::nivel ( nivel &o)
{
    nive = o.getnivel();
    experiencia = o.getexp();
    exp_necesaria = o.getexpn();
    exp_total = o.getexptotal();
    nivel_maximo = o.getnivel_max();
    constante = o.get_constante();
}
double nivel::getexptotal()
{
    return exp_total;
}
double nivel::getnivel()
{
    return nive;
}
double nivel::getexp()
{
    return experiencia;
}
double nivel::getexpn()
{
    return exp_necesaria;
}
double nivel::getnivel_max()
{
    return nivel_maximo;
}
double nivel::get_constante()
{
    return constante;
}
void nivel::set_exnec()
{
    exp_necesaria = pow(get_constante(),nive/10)*100;
}
void nivel::aumentar_exp(double x)
{
    experiencia += x;
    exp_total += x;
}
void nivel::subir_nivel(int f)
{
    experiencia = f;
    if (nive < nivel_maximo)
        nive++;
    set_exnec();
}
void nivel::sistema_de_validacion()
{
    if (getexp()>=getexpn()){
        int f = getexp()-getexpn();
        subir_nivel(f);}
}


estado::estado()
{
    nombre = "Normal";
    codigo_efecto = "00000";
}
estado::estado(estado &o)
{
    nombre = o.getnombre();
    codigo_efecto = o.get_codigo();
}
estado::estado (string x, string y)
{
    nombre = x;
    codigo_efecto = y;
}
void estado::setnombre(string x)
{
    nombre = x;
}
void estado::set_codigo(string x)
{
    codigo_efecto = x;
}
string estado::getnombre()
{
    return nombre;
}
string estado::get_codigo()
{
    return codigo_efecto;
}

habilidad::habilidad()
{
    nombre = "INSERTE DATOS";
    potencia = 0;
}
habilidad::habilidad(string x, int y, rama_elemental z, int zx, string r, string k)
{
    nombre = x;
    potencia = y;
    elem.set_elemento(z.get_nombre(zx));
    stad.setnombre(r);
    stad.set_codigo(k);
}
string habilidad::get_nombre()
{
    return nombre;
}
int habilidad::get_potencia()
{
    return potencia;
}
string habilidad::get_elemento()
{
    return elem.getnombre();
}
string habilidad::get_estado()
{
    return stad.getnombre();
}
estado habilidad::getestad()
{
    return stad;
}
void habilidad::set_nombre(string x)
{
    nombre = x;
}
void habilidad::set_potencia(int x)
{
    potencia = x;
}
void habilidad::set_elemento(rama_elemental x, int y)
{
    elem.set_elemento(x.get_nombre(y));
}
void habilidad::set_estado (estado x)
{
    stad.setnombre(x.getnombre());
    stad.set_codigo(x.get_codigo());
}
void habilidad::mostrar_datos()
{
    cout << "Nombre: "<<get_nombre()<<endl;
    cout << "Potencia: "<<get_potencia()<<endl;
    cout << "Elemento: "<<get_elemento()<<endl;
    cout << "Estado: "<<get_estado()<<endl;
}

item::item()
{
    name = "ITEM VACIO";
    description = "SIN DESCRIPCION";
}
item::item(string x, string y)
{
    name = x;
    description = y;
}
string item::get_nombre()
{
    return name;
}
string item::get_description()
{
    return description;
}
void item::set_nombre(string x)
{
    name = x;
}
void item::set_descripcion(string x)
{
    description = x;
}

tipo_de_arma::tipo_de_arma()
{
    tipo = "ninguno, esto no es un arma";
}
tipo_de_arma::tipo_de_arma(string x)
{
    tipo = x;
}
void tipo_de_arma::set_tipo(string x)
{
    tipo = x;
}
string tipo_de_arma::get_tipo()
{
    return tipo;
}


rama_tipos_arma::rama_tipos_arma(tipo_de_arma tt[], int x)
{
    T = new tipo_de_arma[x];
    tamano = x;
    for (int i = 0; i < tamano; i++)
        T[i].set_tipo(tt[i].get_tipo());
}
char rama_tipos_arma::get_codigo_arma(int x)
{
    string y = T[x].get_tipo();
    return y[0];
}
rama_tipos_arma::~rama_tipos_arma()
{
    delete T;
}

weapon::weapon()
{
    item();
    tip = tipo_de_arma();
    stat_mejorado = new string[0];
    aumento = new int[0];
    tamano = 0;
    element=elemento();
}
weapon::weapon (string descr, string x, string y[],int f, int z[], string elem, tipo_de_arma typ)
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
weapon::weapon (weapon &o)
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
string weapon::description()
{
    return get_description();
}
int weapon::get_tamano()
{
    return tamano;
}
string weapon::nombre()
{
    return get_nombre();
}
string weapon::get_stat_mejorado(int x)
{
    return stat_mejorado[x];
}
int weapon::get_aumento(int x)
{
    return aumento[x];
}
string weapon::get_elemento()
{
    return element.getnombre();
}

void weapon::set_stats_mejorador_plus_stat_(string x[], int y[])
{
    for(int i = 0; i < tamano; i++)
        stat_mejorado[i]=x[i];
    for(int i = 0; i < tamano; i++)
        aumento[i]=y[i];
}
void weapon::set_elemento(elemento r)
{
    element.set_elemento(r.getnombre());
}
void weapon::mostrar_datos()
{
    cout << "NOMBRE DEL WEAPON:  " <<nombre()<<"\n\n\n"<<"DESCRIPCION:  "<<description()<<endl;
    cout << "STATS Y AUMENTOS Y/O DECREMENTOS:  "<<"\n\n";
    for(int i = 0; i < tamano; i++)
        cout << "STAT MODIFICADO:  "<<get_stat_mejorado(i) << "  MODIFICACION:   "<< get_aumento(i)<<endl;
    cout << "ELEMENTO  "<< get_elemento();
}
weapon::~weapon()
{
    delete stat_mejorado;
    delete aumento;
}




clase::clase(int x)
{
    nombre = "vacio";
    tam = x;
    H=new habilidad[tam];
    niveles_para_llegar=new int[tam];
    beneficio_stats="0000000";
    beneficio_armas="xxxxxxx";
}
clase::clase()
{
    nombre = "vacio";
    tam = 0;
    H=new habilidad[tam];
    niveles_para_llegar=new int[tam];
    beneficio_stats="0000000";
    beneficio_armas="xxxxxxx";
}
clase::clase(int x,string y, string z, string e, int niv[], habilidad hab[])
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
clase::clase(clase &o)
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
void clase::nombrar(string x)
{
    nombre = x;
}
void clase::setear_stats(string x)
{
    beneficio_stats = x;
}
void clase::setear_armas(string x)
{
    beneficio_armas = x;
}
void clase::set_habilidades(int o, int niv,habilidad hab, rama_elemental z, int zx)
{
    H[o].set_nombre(hab.get_nombre());
    H[o].set_potencia(hab.get_potencia());
    H[o].set_elemento(z,zx);
    H[o].set_estado(hab.stad);
    niveles_para_llegar[o]=niv;
}
habilidad clase::gethab(int x)
{
    return H[x];
}
int clase::get_tam()
{
    return tam;
}
string clase::getnom()
{
    return nombre;
}
string clase::getbenar()
{
    return beneficio_armas;
}
string clase::getbenst()
{
    return beneficio_stats;
}
int clase::getniv(int x)
{
    return niveles_para_llegar[x];
}
void clase::mostrar_datos()
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
clase::~clase()
{
    delete H;
    delete niveles_para_llegar;
}
entidad::entidad()
{

}

entidad::entidad(string x, clase c, stats s, nivel n, weapon w[],int num_w)
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
void entidad::mostrar_datos()
{
    cout << "NOMBRE : "<< nombre << endl;
    _clase.mostrar_datos();
    _stats.mostrar_stats();
    cout << "nivel: "<<_nivel.getnivel();
    for(int i = 0; i< num_weapon; i++)
        _weapon[i].mostrar_datos();
}
void entidad::set_stats()
{
    for(int i = 0; i < _stats.get_tamano(); i++)
        _stats.S[i].valor = _nivel.getnivel()*(_clase.getbenst()[i]-'0')+const_stats[i];
}
void entidad::subir_nivel_exp(int x)
{
    _nivel.aumentar_exp(x);
    _nivel.sistema_de_validacion();
    set_stats();
}
void entidad::cambiar_clase(clase &o, rama_elemental x, int xf, habilidad hs[] )
{
    _clase.setear_armas(o.getbenar());
    _clase.setear_stats(o.getbenst());
    for(int i = 0; i < _clase.get_tam(); i++)
        _clase.set_habilidades(i,o.getniv(i),hs[i],x,xf);
}
void entidad::equipar(weapon wea, int x)
{
    if(_stats.get_stats_nombre(x)==_weapon->get_stat_mejorado(x)){
        _weapon[x] = wea;
        _stats.set_valor(x, _stats.get_stats_valor(x)+_weapon->get_aumento(x));}
}
void entidad::desequipar(int x)
{
    _weapon[x] = weapon();
}
entidad::~entidad()
{
    delete _weapon;
    delete const_stats;
}


personaje::personaje(string x, clase c, stats s, nivel n, weapon w[],int num_w)
{
    entidad(x, c, s, n, w,num_w);
}
void personaje::mostrar_datos()
{
    entidad::mostrar_datos();
}
void personaje::set_stats()
{
    entidad::set_stats();
}
void personaje::subir_nivel_exp(int x)
{
    entidad::subir_nivel_exp(x);
}
void personaje::cambiar_clase(clase &o, rama_elemental z,int xf, habilidad hs[])
{
    entidad::cambiar_clase(o,z,xf,hs);
}
void personaje::equipar(weapon wea, int x)
{
    entidad::equipar(wea,x);
}
void personaje::desequipar(int x)
{
    entidad::desequipar(x);
}

