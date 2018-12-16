#include "Funciones.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>


void Imprime_archivo()
{
    std::ifstream archivo;
    std::__cxx11::string texto;
    //int n=0;

    archivo.open("espiral.mesh",std::ios::in);

    if(archivo.fail())
        std::cout<<"Error, no se pudo abrir el archivo!"<<std::endl;

    archivo.seekg(8); //se omite la primera linea de datos del archivo mesh: "9665 3"
    while(!archivo.eof())    //mientras no sea el final del archivo
    {
        getline(archivo,texto);
        if(texto!="")
        {
            //coordenada=atof(strcpy(cad, texto.c_str()));
            std::cout<<texto<<std::endl;
            //n++;
        }
    }

    archivo.close();
    //std::cout<<"Cantidad de triangulos del archivo node/mesh: "<<n<<std::endl;
}


void Coordenadas_Triangulo()
{
    std::ifstream archivo_m,archivo_n;
    //std::ofstream nuevo;
    std::__cxx11::string texto_m,texto_n;
    double Triangulos[9665][6];

    archivo_m.open("espiral.mesh",std::ios::in);
    archivo_n.open("espiral.node",std::ios::in);
    //nuevo.open("Coordenadas_Triangulo.bin",std::ios::out);

    if(archivo_m.fail() || archivo_n.fail())
        std::cout<<"Error, no se pudo abrir el archivo!"<<std::endl;

    archivo_m.seekg(8); //se omite la primera linea de datos del archivo mesh: "9665 3"
    while(!archivo_m.eof())    //mientras no sea el final del archivo
    {
        for(int i=0;i<9665;i++)
        {
            getline(archivo_m,texto_m,' ');//se guarda en "texto_m" cada numero de vertice del archivo mesh
            while(!archivo_n.eof())
            {
                getline(archivo_n,texto_n);
                int pos = texto_n.find(" ");
                string vertice = texto_n.substr (0,pos);
                if(texto_m==vertice)
                {
                    string c1= texto_n.substr (vertice.size(),pos);
                }

                for(int k=0;k<6;k++)
                {

                }
            }

        }

    }

    archivo_m.close();
    archivo_n.close();
    //nuevo.close();
}


