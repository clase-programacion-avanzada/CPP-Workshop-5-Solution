#include "libs/List.h"


#include <iostream>

using namespace std;

void printMenu();
List<int> generateRandomList();
List<int*> generatePointerList(List<int>& list);
List<int*> sortPointerList(List<int*>& list);
void printList(List<int>& list);
void printPointerList(List<int*>& list);

int main() {
    
    
    List<int> list;
    List<int*> listPointer;
    int option = 0;
    List<int*> sortedList;
    do {

        printMenu();
        cout << "Ingrese una opción: ";
        cin >> option;
        
        switch (option) {
            case 1:
                list = generateRandomList();
                break;
            case 2:
                listPointer = generatePointerList(list);
                break;
            case 3:
                sortedList = sortPointerList(listPointer);

                break;
            case 4:
                printList(list);
                break;
            case 5:
                printPointerList(sortedList);
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
                break;
        } 

    } while (option != 0);
    cout << "Limpiando memoria..." << endl;
    cout << "eliminando listas..." << endl;
    cout << "lista de numeros aleatorios..." << endl;
    cout << "size inicial: " << list.size 
    << " capacity inicial: " << list.capacity
    << " elementos: " << (int *) list.elements << endl;
    
    list.clear();
    
    cout << "size final: " << list.size
    << " capacity final: " << list.capacity
    << " elementos: " << (int *) list.elements << endl;
    listPointer.clear();
    cout << "lista de apuntadores..." << endl;
    cout << "size inicial: " << listPointer.size
    << " capacity inicial: " << listPointer.capacity
    << " elementos: " << (int *) listPointer.elements << endl;

    sortedList.clear();
    cout << "lista de apuntadores ordenada..." << endl;
    cout << "size inicial: " << sortedList.size
    << " capacity inicial: " << sortedList.capacity
    << " elementos: " << (int *) sortedList.elements << endl;
    cout << "Memoria liberada" << endl;


    return 0;
}

List<int> generateRandomList() {
    cout << "Ingrese el tamaño de la lista: ";
    int size;
    cin >> size;
    
    int min = 0;
    int max = 10;

    List<int> list;

    for (int i = 0; i < size; i++) {
        list.add(rand() % (max - min + 1) + min);
    }

    return list;
}

List<int*> generatePointerList(List<int>& list) {
    List<int*> pointerList;

    for (int i = 0; i < list.size; i++) {
        int* pointer = list.getAddressOf(i);
        pointerList.add(pointer);
    }

    return pointerList;
}

List<int*> sortPointerList(List<int*>& list) {
    List<int*> sortedList = list.copy();

    for (int i = 0; i < sortedList.size; i++) {
        for (int j = 0; j < sortedList.size - 1; j++) {
            if (*sortedList.get(j) > *sortedList.get(j + 1)) {
                int* temp = sortedList.get(j);
                int* temp2 = sortedList.get(j + 1);
                sortedList.set(j, temp2);
                sortedList.set(j + 1, temp);
            }
        }
    }

    return sortedList;
}

void printList(List<int>& list) {
    for (int i = 0; i < list.size; i++) {
        cout << list.get(i) << " ";
    }
    cout << endl;
}

void printPointerList(List<int*>& list) {
    for (int i = 0; i < list.size; i++) {
        cout << *list.get(i) << " ";
    }
    cout << endl;
}


void printMenu() {
    cout << "1. Generar lista con número aleatorios" << endl;
    cout << "2. Generar lista de apuntadores a la primera lista" << endl;
    cout << "3. Ordenar lista de apuntadores" << endl;
    cout << "4. Imprimir lista original" << endl;
    cout << "5. Imprimir lista de apuntadores" << endl;
    cout << "0. Salir" << endl;
}
