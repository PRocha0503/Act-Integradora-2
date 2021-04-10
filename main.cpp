#include <sstream>
#include <algorithm>
#include <fstream>
#include "lista.h"
using namespace std;

int convertirMes(string m){
    if(m=="Jan"){
        return 1;
    }
    else if(m=="Feb"){
        return 2;
    }
    else if(m=="Mar"){
        return 3;
    }
    else if(m=="Apr"){
        return 4;
    }
    else if(m=="May"){
        return 5;
    }
    else if(m=="Jun"){
        return 6;
    }
    else if(m=="Jul"){
        return 7;
    }
    else if(m=="Aug"){
        return 8;
    }
    else if(m=="Sep"){
        return 9;
    }
    else if(m=="Oct"){
        return 10;
    }
    else if(m=="Nov"){
        return 11;
    }
    else if(m=="Dec"){
        return 12;
    }
    return 100000;
}

formatoHora cambiarHora(string h){
    int hora;
    int minuto; 
    int segundo;
    h.erase(remove(h.begin(), h.end(), ':'), h.end());
    string stringHora,stringMinuto,stringSegundo;
    stringHora = h.substr (0,2);
    stringMinuto = h.substr (2,2);
    stringSegundo = h.substr (4,2);
    stringstream conv(stringHora);
    conv>>hora;
    stringstream conv1(stringMinuto);
    conv1>>minuto;
    stringstream conv2(stringSegundo);
    conv2>>segundo;
    formatoHora horaConFormato;
    horaConFormato.hora = hora;
    horaConFormato.minuto = minuto;
    horaConFormato.segundo = segundo;
    return horaConFormato;
} 

void leerDatos(DoubleLinkedList<entrada> &ve){
    string line;
    string mes;
    int dia;
    string hora;
    string ip;
    string razon;
    string razon1;
    string razon2;
    string razon3;
    string razon4;
    string razon5;
    ifstream bitacora("bitacora.txt");
    if (bitacora.is_open()){
        while (getline(bitacora,line)){
            entrada e;
            istringstream ss(line);
            ss>>mes>>dia>>hora>>ip>>razon>>razon1>>razon2>>razon3>>razon4>>razon5;
            string razonFinal;
            razonFinal = razon +" " + razon1+" " + razon2+" " + razon3+" " + razon4+" " + razon5;
            int mesInt;
            mesInt = convertirMes(mes);
            formatoHora horaCambiada = cambiarHora(hora);
            horaCambiada.mes = mesInt;
            horaCambiada.dia = dia;
            e.fecha = horaCambiada;
            e.ip = ip;
            e.razonFalla = razonFinal;
            ve.addLast(e);
            razon1 = "";// Vuelvo a restablecer todos las palabras por si no se usan en la siguiente linea
            razon2 = "";
            razon3 = "";
            razon4 = "";
            razon5 = "";
        }
    }
    bitacora.close();
}

int main(){
    DoubleLinkedList<entrada> vectorEntradas;
    leerDatos(vectorEntradas);
    int tamaño = vectorEntradas.getItemCount();
    vectorEntradas.quickSort(0,tamaño-1);
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    //INICIO
    cout<<"Ponga mes,dia,hora,minuto,segundo de la fecha de inicio/// SEPARADO POR ESPACIOS"<<endl;
    char fechaInicio[15];
    cin.getline(fechaInicio,sizeof(fechaInicio));
    istringstream ss(fechaInicio);
    ss>>mes>>dia>>hora>>minuto>>segundo;
    entrada inicio;
    inicio.fecha.mes = mes;
    inicio.fecha.dia = dia;
    inicio.fecha.hora = hora;
    inicio.fecha.minuto = minuto;
    inicio.fecha.segundo = segundo;
    int indexInicio  = vectorEntradas.binaria(inicio);

    //FIN
    cout<<"Ponga mes,dia,hora,minuto,segundo de la fecha del fin/// SEPARADO POR ESPACIOS"<<endl;
    char fechaFin[15];
    cin.getline(fechaFin,sizeof(fechaFin));
    istringstream ss2(fechaFin);
    ss2>>mes>>dia>>hora>>minuto>>segundo;
    entrada fin;
    fin.fecha.mes = mes;
    fin.fecha.dia = dia;
    fin.fecha.hora = hora;
    fin.fecha.minuto = minuto;
    fin.fecha.segundo = segundo;
    int indexFin  = vectorEntradas.binaria(fin);
    string salida = "resultado_busqueda.txt";
    vectorEntradas.sacarLista(indexInicio,indexFin,salida);

    cout<<"Tu busqueda se guardo en el archivo Salida.txt"<<endl;
    cout<<"La lista completa ordenada tardara un rato en aparecer"<<endl;
    vectorEntradas.sacarLista(0,tamaño-1,"bitacora_ordenada.txt");
    cout<<"Listo, ya se hizo el archivo de la lista ordenada"<<endl;
    // FECHAS DE PRUEBA
    //Jun 1 00:22:36
    //06 01 00 22 36
    //Jun 1 06:46:16
    //06 01 06 46 16
        

    return 0;
}