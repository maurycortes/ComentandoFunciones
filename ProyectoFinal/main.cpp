#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string sNombreArchivo; //Nombre que teclea el usuario
    string sNombreArchivoEntrada="", sNombreArchivoSalida=""; //Nombres de los archivos de entrada y salida
    string sArroba="";
    ifstream sArchivoEntrada;//Archivos de entrada y salida
    ofstream sArchivoSalida;

    cout << "Escribe el nombre del archivo de entrada sin extension" << endl;
    getline(cin,sNombreArchivo); //Leer el documento de entrada que teclea el usuario
    sNombreArchivoEntrada = sNombreArchivo + ".cpp"; //Agregar extensiones a los documentos
    sNombreArchivoSalida = sNombreArchivo + ".txt";
    sArchivoEntrada.open(sNombreArchivoEntrada.c_str());//Abrir los documentos
    sArchivoSalida.open(sNombreArchivoSalida.c_str());
    sArchivoSalida << "<!DOCTYPE>" << endl;//Desplegar las primeras etiquetas
    sArchivoSalida << "<html>" << endl;
    sArchivoSalida << "<head>" << endl;
    sArchivoSalida << "<style type=\"text/css\">" << endl;
    sArchivoSalida << "body {background-color:lightblue}" << endl;
    sArchivoSalida << "<title>" << endl;
    sArchivoSalida << sNombreArchivoEntrada << endl;
    sArchivoSalida << "</title>" << endl;
    sArchivoSalida << "</style>" << endl;
    sArchivoSalida << "</head>" << endl;
    sArchivoSalida << "<body>" << endl;
    while(!sArchivoEntrada.eof())//Mientras haya texto para leer
    {
        sArchivoEntrada >> sNombreArchivoEntrada;
        if(sNombreArchivoEntrada == "/**")
        {
        while(sNombreArchivoEntrada != "*/")
            {
            sArchivoEntrada >> sNombreArchivoEntrada;
               sArroba=sNombreArchivoEntrada[0];
                if(sArroba=="@")
                {
                    if(sNombreArchivoEntrada=="@progName")
                    {
                        getline(sArchivoEntrada,sNombreArchivoEntrada);
                        sArchivoSalida << "<h1>" << endl;
                        sArchivoSalida << "<big>" << endl;
                        sArchivoSalida << "<p style=\"color:blue;margin-left:10px\">" << endl;
                        sArchivoSalida << "Programa: " << sNombreArchivoEntrada << "<br>" << endl;
                        sArchivoSalida << "</p>" << endl;
                        sArchivoSalida << "</big>" << endl;
                        sArchivoSalida << "</h1>" << endl;
                    }
                    else if(sNombreArchivoEntrada=="@author")
                    {
                        getline(sArchivoEntrada,sNombreArchivoEntrada);
                        sArchivoSalida << "<strong> <dd> Autor: </strong>" << sNombreArchivoEntrada << "</dd> <br>" << endl;
                    }
                    else if(sNombreArchivoEntrada=="@date")
                    {
                        getline(sArchivoEntrada,sNombreArchivoEntrada);
                        sArchivoSalida << "<strong> <dd> Fecha de elaboraci&oacute;n: </strong>" << sNombreArchivoEntrada << "</dd> <br>" << endl;
                    }
                    else if(sNombreArchivoEntrada=="@funcName")
                    {
                        getline(sArchivoEntrada,sNombreArchivoEntrada);
                        sArchivoSalida << "<h2>" << endl;
                        sArchivoSalida << "<p style=\"margin-left:10px\">" << endl;
                        sArchivoSalida << "<hr><br> Funci&oacute;n: " << sNombreArchivoEntrada << "<br>" << endl;
                        sArchivoSalida << "</p>" << endl;
                        sArchivoSalida << "</h2>" << endl;
                    }
                    else if(sNombreArchivoEntrada=="@desc")
                    {
                        getline(sArchivoEntrada,sNombreArchivoEntrada);
                        sArchivoSalida << "<i> " << endl;
                        sArchivoSalida << "<strong> <dd> Descripci&oacute;n: </strong> " << sNombreArchivoEntrada << "</dd> <br>" << endl;
                        sArchivoSalida << "</i> " << endl;
                    }
                    else if(sNombreArchivoEntrada=="@param")
                    {
                        getline(sArchivoEntrada,sNombreArchivoEntrada);
                        sArchivoSalida << "<strong> <dd> Par&aacute;metro: </strong>" << sNombreArchivoEntrada << "</dd> <br>" << endl;
                    }
                    else if(sNombreArchivoEntrada=="@return")
                    {
                        getline(sArchivoEntrada,sNombreArchivoEntrada);
                        sArchivoSalida << "<strong> <dd> Valor de Retorno: </strong>" << sNombreArchivoEntrada << "</dd> <br>" << endl; //factorial del valor iNum
                    }
               }
            }
        }
    }
    sArchivoSalida << "</body" << endl; //Las etiquetas finales del archivo
    sArchivoSalida << "</html>" << endl;
    sArchivoEntrada.close();//Se cierran los archivos
    sArchivoSalida.close();
    return 0;
}
