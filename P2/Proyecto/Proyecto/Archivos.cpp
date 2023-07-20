#include "Archivos.h"

void Archivos::guardarListaRegistro(ListaRegistro* lista) {
    std::ofstream archivo("Registro.txt");

    if (archivo.is_open()) {
        for (int i = 0; i < lista->dimencion(); i++) {
            archivo << lista->getPosicion(i).getEmpleado().getNombre() << ",";
            archivo << lista->getPosicion(i).getEmpleado().getApellido() << ",";
            archivo << lista->getPosicion(i).getEmpleado().getCedula() << ",";
            archivo << lista->getPosicion(i).getEmpleado().getFecha().getDia() << ",";
            archivo << lista->getPosicion(i).getEmpleado().getFecha().getMes() << ",";
            archivo << lista->getPosicion(i).getEmpleado().getFecha().getAnio() << ",";
            archivo << lista->getPosicion(i).getEmpleado().getSalario() << ",";
            archivo << lista->getPosicion(i).getEntrada().getDia() << ",";
            archivo << lista->getPosicion(i).getEntrada().getMes() << ",";
            archivo << lista->getPosicion(i).getEntrada().getAnio() << ",";
            archivo << lista->getPosicion(i).getEntrada().getHora() << ",";
            archivo << lista->getPosicion(i).getEntrada().getMinutos() << ",";
            archivo << lista->getPosicion(i).getEntrada().getSegundos() << ",";
            archivo << lista->getPosicion(i).getSalidaAlmuerzo().getDia() << ",";
            archivo << lista->getPosicion(i).getSalidaAlmuerzo().getMes() << ",";
            archivo << lista->getPosicion(i).getSalidaAlmuerzo().getAnio() << ",";
            archivo << lista->getPosicion(i).getSalidaAlmuerzo().getHora() << ",";
            archivo << lista->getPosicion(i).getSalidaAlmuerzo().getMinutos() << ",";
            archivo << lista->getPosicion(i).getSalidaAlmuerzo().getSegundos() << ",";
            archivo << lista->getPosicion(i).getEntradaAlmuerzo().getDia() << ",";
            archivo << lista->getPosicion(i).getEntradaAlmuerzo().getMes() << ",";
            archivo << lista->getPosicion(i).getEntradaAlmuerzo().getAnio() << ",";
            archivo << lista->getPosicion(i).getEntradaAlmuerzo().getHora() << ",";
            archivo << lista->getPosicion(i).getEntradaAlmuerzo().getMinutos() << ",";
            archivo << lista->getPosicion(i).getEntradaAlmuerzo().getSegundos() << ",";
            archivo << lista->getPosicion(i).getSalida().getDia() << ",";
            archivo << lista->getPosicion(i).getSalida().getMes() << ",";
            archivo << lista->getPosicion(i).getSalida().getAnio() << ",";
            archivo << lista->getPosicion(i).getSalida().getHora() << ",";
            archivo << lista->getPosicion(i).getSalida().getMinutos() << ",";
            archivo << lista->getPosicion(i).getSalida().getSegundos() << endl;
        }
        archivo.close();
        std::cout << "Lista de productos guardada exitosamente en Registro.txt" << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo Registro.txt para escribir" << std::endl;
    }
}

ListaRegistro* Archivos::leerListaRegistro() {
    ListaRegistro* lista = new ListaRegistro();
    std::ifstream archivo("Registro.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::string nombre;
            std::string apellido;
            std::string cedula;
            double sueldo;
            int nd, nm, na, ed, em, ea, eh, emi, es, sad, sam, saa, sah, sami, sas, ead, eam, eaa, eah, eami, eas, sd, sm, sa, sh, smi, ss;
            size_t coma_pos = linea.find(",");
            size_t coma_pos2 = linea.find(",", coma_pos + 1);
            size_t coma_pos3 = linea.find(",", coma_pos2 + 1);
            size_t coma_pos4 = linea.find(",", coma_pos3 + 1);
            size_t coma_pos5 = linea.find(",", coma_pos4 + 1);
            size_t coma_pos6 = linea.find(",", coma_pos5 + 1);
            size_t coma_pos7 = linea.find(",", coma_pos6 + 1);
            size_t coma_pos8 = linea.find(",", coma_pos7 + 1);
            size_t coma_pos9 = linea.find(",", coma_pos8 + 1);
            size_t coma_pos10 = linea.find(",", coma_pos9 + 1);
            size_t coma_pos11 = linea.find(",", coma_pos10 + 1);
            size_t coma_pos12 = linea.find(",", coma_pos11 + 1);
            size_t coma_pos13 = linea.find(",", coma_pos12 + 1);
            size_t coma_pos14 = linea.find(",", coma_pos13 + 1);
            size_t coma_pos15 = linea.find(",", coma_pos14 + 1);
            size_t coma_pos16 = linea.find(",", coma_pos15 + 1);
            size_t coma_pos17 = linea.find(",", coma_pos16 + 1);
            size_t coma_pos18 = linea.find(",", coma_pos17 + 1);
            size_t coma_pos19 = linea.find(",", coma_pos18 + 1);
            size_t coma_pos20 = linea.find(",", coma_pos19 + 1);
            size_t coma_pos21 = linea.find(",", coma_pos20 + 1);
            size_t coma_pos22 = linea.find(",", coma_pos21 + 1);
            size_t coma_pos23 = linea.find(",", coma_pos22 + 1);
            size_t coma_pos24 = linea.find(",", coma_pos23 + 1);
            size_t coma_pos25 = linea.find(",", coma_pos24 + 1);
            size_t coma_pos26 = linea.find(",", coma_pos25 + 1);
            size_t coma_pos27 = linea.find(",", coma_pos26 + 1);
            size_t coma_pos28 = linea.find(",", coma_pos27 + 1);
            size_t coma_pos29 = linea.find(",", coma_pos28 + 1);
            size_t coma_pos30 = linea.find(",", coma_pos29 + 1);
            if (coma_pos != std::string::npos) {
                nombre = linea.substr(0, coma_pos);
                apellido = linea.substr(coma_pos + 1, coma_pos2 - coma_pos - 1);
                cedula = linea.substr(coma_pos2 + 1, coma_pos3 - coma_pos2 - 1);
                nd = std::stoi(linea.substr(coma_pos3 + 1, coma_pos4 - coma_pos3 - 1));
                nm = std::stoi(linea.substr(coma_pos4 + 1, coma_pos5 - coma_pos4 - 1));
                na = std::stoi(linea.substr(coma_pos5 + 1, coma_pos6 - coma_pos5 - 1));
                sueldo = std::stod(linea.substr(coma_pos6 + 1, coma_pos7 - coma_pos6 - 1));
                ed = std::stoi(linea.substr(coma_pos7 + 1, coma_pos8 - coma_pos7 - 1));
                em = std::stoi(linea.substr(coma_pos8 + 1, coma_pos9 - coma_pos8 - 1));
                ea = std::stoi(linea.substr(coma_pos9 + 1, coma_pos10 - coma_pos9 - 1));
                eh = std::stoi(linea.substr(coma_pos10 + 1, coma_pos11 - coma_pos10 - 1));
                emi = std::stoi(linea.substr(coma_pos11 + 1, coma_pos12 - coma_pos11 - 1));
                es = std::stoi(linea.substr(coma_pos12 + 1, coma_pos13 - coma_pos12 - 1));
                sad = std::stoi(linea.substr(coma_pos13 + 1, coma_pos14 - coma_pos13 - 1));
                sam = std::stoi(linea.substr(coma_pos14 + 1, coma_pos15 - coma_pos14 - 1));
                saa = std::stoi(linea.substr(coma_pos15 + 1, coma_pos16 - coma_pos15 - 1));
                sah = std::stoi(linea.substr(coma_pos16 + 1, coma_pos17 - coma_pos16 - 1));
                sami = std::stoi(linea.substr(coma_pos17 + 1, coma_pos18 - coma_pos17 - 1));
                sas = std::stoi(linea.substr(coma_pos18 + 1, coma_pos19 - coma_pos18 - 1));
                ead = std::stoi(linea.substr(coma_pos19 + 1, coma_pos20 - coma_pos19 - 1));
                eam = std::stoi(linea.substr(coma_pos20 + 1, coma_pos21 - coma_pos20 - 1));
                eaa = std::stoi(linea.substr(coma_pos21 + 1, coma_pos22 - coma_pos21 - 1));
                eah = std::stoi(linea.substr(coma_pos22 + 1, coma_pos23 - coma_pos22 - 1));
                eami = std::stoi(linea.substr(coma_pos23 + 1, coma_pos24 - coma_pos23 - 1));
                eas = std::stoi(linea.substr(coma_pos24 + 1, coma_pos25 - coma_pos24 - 1));
                sd = std::stoi(linea.substr(coma_pos25 + 1, coma_pos26 - coma_pos25 - 1));
                sm = std::stoi(linea.substr(coma_pos26 + 1, coma_pos27 - coma_pos26 - 1));
                sa = std::stoi(linea.substr(coma_pos27 + 1, coma_pos28 - coma_pos27 - 1));
                sh = std::stoi(linea.substr(coma_pos28 + 1, coma_pos29 - coma_pos28 - 1));
                smi = std::stoi(linea.substr(coma_pos29 + 1, coma_pos30 - coma_pos29 - 1));
                ss = std::stoi(linea.substr(coma_pos30 + 1));
                Fecha nacimiento(nd, nm, na);
                Fecha entrada(ed, em, ea,eh,emi,es);
                Fecha salidaAlmuerzo(sad, sam, saa,sah,sami,sas);
                Fecha entradoAlmuerzo(ead,eam,eaa,eah,eami,eas);
                Fecha salida(sd, sm, sa,sh,smi,ss);
                Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
                Registro registro(empleado, entrada, salidaAlmuerzo, entradoAlmuerzo, salida);
                
                lista->insertar(registro);
            }
        }
        archivo.close();
        std::cout << "Lista de productos leída exitosamente desde Registro.txt" << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo Registro.txt para leer" << std::endl;
    }
    return lista;
}

ListaRegistro* Archivos::leerListaRegistro(int anio, int mes, int dia) {
    ListaRegistro* lista = new ListaRegistro();
    std::ifstream archivo("Registro.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::string nombre;
            std::string apellido;
            std::string cedula;
            double sueldo;
            int nd, nm, na, ed, em, ea, eh, emi, es, sad, sam, saa, sah, sami, sas, ead, eam, eaa, eah, eami, eas, sd, sm, sa, sh, smi, ss;
            size_t coma_pos = linea.find(",");
            size_t coma_pos2 = linea.find(",", coma_pos + 1);
            size_t coma_pos3 = linea.find(",", coma_pos2 + 1);
            size_t coma_pos4 = linea.find(",", coma_pos3 + 1);
            size_t coma_pos5 = linea.find(",", coma_pos4 + 1);
            size_t coma_pos6 = linea.find(",", coma_pos5 + 1);
            size_t coma_pos7 = linea.find(",", coma_pos6 + 1);
            size_t coma_pos8 = linea.find(",", coma_pos7 + 1);
            size_t coma_pos9 = linea.find(",", coma_pos8 + 1);
            size_t coma_pos10 = linea.find(",", coma_pos9 + 1);
            size_t coma_pos11 = linea.find(",", coma_pos10 + 1);
            size_t coma_pos12 = linea.find(",", coma_pos11 + 1);
            size_t coma_pos13 = linea.find(",", coma_pos12 + 1);
            size_t coma_pos14 = linea.find(",", coma_pos13 + 1);
            size_t coma_pos15 = linea.find(",", coma_pos14 + 1);
            size_t coma_pos16 = linea.find(",", coma_pos15 + 1);
            size_t coma_pos17 = linea.find(",", coma_pos16 + 1);
            size_t coma_pos18 = linea.find(",", coma_pos17 + 1);
            size_t coma_pos19 = linea.find(",", coma_pos18 + 1);
            size_t coma_pos20 = linea.find(",", coma_pos19 + 1);
            size_t coma_pos21 = linea.find(",", coma_pos20 + 1);
            size_t coma_pos22 = linea.find(",", coma_pos21 + 1);
            size_t coma_pos23 = linea.find(",", coma_pos22 + 1);
            size_t coma_pos24 = linea.find(",", coma_pos23 + 1);
            size_t coma_pos25 = linea.find(",", coma_pos24 + 1);
            size_t coma_pos26 = linea.find(",", coma_pos25 + 1);
            size_t coma_pos27 = linea.find(",", coma_pos26 + 1);
            size_t coma_pos28 = linea.find(",", coma_pos27 + 1);
            size_t coma_pos29 = linea.find(",", coma_pos28 + 1);
            size_t coma_pos30 = linea.find(",", coma_pos29 + 1);
            if (coma_pos != std::string::npos) {
                nombre = linea.substr(0, coma_pos);
                apellido = linea.substr(coma_pos + 1, coma_pos2 - coma_pos - 1);
                cedula = linea.substr(coma_pos2 + 1, coma_pos3 - coma_pos2 - 1);
                nd = std::stoi(linea.substr(coma_pos3 + 1, coma_pos4 - coma_pos3 - 1));
                nm = std::stoi(linea.substr(coma_pos4 + 1, coma_pos5 - coma_pos4 - 1));
                na = std::stoi(linea.substr(coma_pos5 + 1, coma_pos6 - coma_pos5 - 1));
                sueldo = std::stod(linea.substr(coma_pos6 + 1, coma_pos7 - coma_pos6 - 1));
                ed = std::stoi(linea.substr(coma_pos7 + 1, coma_pos8 - coma_pos7 - 1));
                em = std::stoi(linea.substr(coma_pos8 + 1, coma_pos9 - coma_pos8 - 1));
                ea = std::stoi(linea.substr(coma_pos9 + 1, coma_pos10 - coma_pos9 - 1));
                eh = std::stoi(linea.substr(coma_pos10 + 1, coma_pos11 - coma_pos10 - 1));
                emi = std::stoi(linea.substr(coma_pos11 + 1, coma_pos12 - coma_pos11 - 1));
                es = std::stoi(linea.substr(coma_pos12 + 1, coma_pos13 - coma_pos12 - 1));
                sad = std::stoi(linea.substr(coma_pos13 + 1, coma_pos14 - coma_pos13 - 1));
                sam = std::stoi(linea.substr(coma_pos14 + 1, coma_pos15 - coma_pos14 - 1));
                saa = std::stoi(linea.substr(coma_pos15 + 1, coma_pos16 - coma_pos15 - 1));
                sah = std::stoi(linea.substr(coma_pos16 + 1, coma_pos17 - coma_pos16 - 1));
                sami = std::stoi(linea.substr(coma_pos17 + 1, coma_pos18 - coma_pos17 - 1));
                sas = std::stoi(linea.substr(coma_pos18 + 1, coma_pos19 - coma_pos18 - 1));
                ead = std::stoi(linea.substr(coma_pos19 + 1, coma_pos20 - coma_pos19 - 1));
                eam = std::stoi(linea.substr(coma_pos20 + 1, coma_pos21 - coma_pos20 - 1));
                eaa = std::stoi(linea.substr(coma_pos21 + 1, coma_pos22 - coma_pos21 - 1));
                eah = std::stoi(linea.substr(coma_pos22 + 1, coma_pos23 - coma_pos22 - 1));
                eami = std::stoi(linea.substr(coma_pos23 + 1, coma_pos24 - coma_pos23 - 1));
                eas = std::stoi(linea.substr(coma_pos24 + 1, coma_pos25 - coma_pos24 - 1));
                sd = std::stoi(linea.substr(coma_pos25 + 1, coma_pos26 - coma_pos25 - 1));
                sm = std::stoi(linea.substr(coma_pos26 + 1, coma_pos27 - coma_pos26 - 1));
                sa = std::stoi(linea.substr(coma_pos27 + 1, coma_pos28 - coma_pos27 - 1));
                sh = std::stoi(linea.substr(coma_pos28 + 1, coma_pos29 - coma_pos28 - 1));
                smi = std::stoi(linea.substr(coma_pos29 + 1, coma_pos30 - coma_pos29 - 1));
                ss = std::stoi(linea.substr(coma_pos30 + 1));
                Fecha nacimiento(nd, nm, na);
                Fecha entrada(ed, em, ea, eh, emi, es);
                Fecha salidaAlmuerzo(sad, sam, saa, sah, sami, sas);
                Fecha entradoAlmuerzo(ead, eam, eaa, eah, eami, eas);
                Fecha salida(sd, sm, sa, sh, smi, ss);
                Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
                Registro registro(empleado, entrada, salidaAlmuerzo, entradoAlmuerzo, salida);
                if (anio == ea && mes == em && dia == ed) {
                    lista->insertar(registro);
                }
            }
        }
        archivo.close();
        std::cout << "Lista de productos leída exitosamente desde Registro.txt" << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo Registro.txt para leer" << std::endl;
    }
    return lista;
}

void Archivos::guardarListaEmpleados(ListaEmpleados* lista) {
    std::ofstream archivo("Empleado.txt");

    if (archivo.is_open()) {
        for (int i = 0; i < lista->dimencion(); i++) {
            archivo << lista->getPosicion(i).getNombre() << ",";
            archivo << lista->getPosicion(i).getApellido() << ",";
            archivo << lista->getPosicion(i).getCedula() << ",";
            archivo << lista->getPosicion(i).getFecha().getDia() << ",";
            archivo << lista->getPosicion(i).getFecha().getMes() << ",";
            archivo << lista->getPosicion(i).getFecha().getAnio() << ",";
            archivo << lista->getPosicion(i).getSalario() << endl;
        }
        archivo.close();
        std::cout << "Lista de productos guardada exitosamente en Empleado.txt" << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo Empleado.txt para escribir" << std::endl;
    }
}

ListaEmpleados* Archivos::leerListaEmpleados() {
    ListaEmpleados* lista = new ListaEmpleados();
    std::ifstream archivo("Empleado.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::string nombre;
            std::string apellido;
            std::string cedula;
            double sueldo;
            int nd, nm, na;
            size_t coma_pos = linea.find(",");
            size_t coma_pos2 = linea.find(",", coma_pos + 1);
            size_t coma_pos3 = linea.find(",", coma_pos2 + 1);
            size_t coma_pos4 = linea.find(",", coma_pos3 + 1);
            size_t coma_pos5 = linea.find(",", coma_pos4 + 1);
            size_t coma_pos6 = linea.find(",", coma_pos5 + 1);
            if (coma_pos != std::string::npos) {
                nombre = linea.substr(0, coma_pos);
                apellido = linea.substr(coma_pos + 1, coma_pos2 - coma_pos - 1);
                cedula = linea.substr(coma_pos2 + 1, coma_pos3 - coma_pos2 - 1);
                nd = std::stoi(linea.substr(coma_pos3 + 1, coma_pos4 - coma_pos3 - 1));
                nm = std::stoi(linea.substr(coma_pos4 + 1, coma_pos5 - coma_pos4 - 1));
                na = std::stoi(linea.substr(coma_pos5 + 1, coma_pos6 - coma_pos5 - 1));
                sueldo = std::stod(linea.substr(coma_pos6 + 1));
                Fecha nacimiento(nd, nm, na);
                Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);

                lista->insertar(empleado);
            }
        }
        archivo.close();
        std::cout << "Lista de productos leída exitosamente desde Empleado.txt" << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo Empleado.txt para leer" << std::endl;
    }
    return lista;
}