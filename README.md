
# Taller 5 - Apuntadores y memoria dinámica

En este taller es obligatorio el uso de estructuras y funciones. Debe usar headers para evitar que el código se vea muy extenso, y ***no puede usar `cin` o `cout` en ninguna parte del código que no sea el archivo `main.cpp`.***



## Ordenamiento con apuntadores (2.5)

**En este punto, cualquier función que realice debe recibir los parámetros por referencia**

Se le ha pedido que haga un programa que permita realizar lo siguiente, debe accederse a cada una de las funcionalidades a través de un menú. A continuación va a encontrar el detalle de cada funcionalidad:

1. Crear una lista de números aleatorios entre 1 y 200 cuyo tamaño sea indicado por el usuario. (0.5)
2. Crear una lista de apuntadores a enteros (int*) donde cada posición apunta a la dirección correspondiente a la de la lista original. Para obtener la dirección de un elemento es necesario usar el método [getAddressOf](https://github.com/clase-programacion-avanzada/CPP-Workshop-5/blob/main/libs/List.h#L40C8-L40C20)(0.5)
3. Crear una función que ordene la lista de apuntadores de acuerdo a los valores de la lista original.(0.5)
4. Hacer una función que imprima la lista original.(0.5)
5. Hacer una función que imprima el contenido de la lista de apuntadores.(0.5)

Si la funcionalidad 4 imprime la lista original y la 5 tiene los valores ordenados, el taller es correcto.  

**DEBE USAR LA ESTRUCTURA LIST**
  
## Memoria Dinámica en la Estructura List (3.0)

Actualmente el array `elements` [usado en la estructura List]([/libs/List.h#10](https://github.com/clase-programacion-avanzada/CPP-Workshop-5/blob/main/libs/List.h#L10)) es de tamaño fijo 100. Esto quita flexibilidad en caso de requerir una lista de más de 100 elementos y, al mismo tiempo, es un desperdicio en memoria ya que si se necesita guardar menos de esa cantidad de elementos dentro de la lista, se tendrán espacios de memoria sin usar. Por este motivo, la estructura List debe ser modificada.

La idea es la siguiente: 

1. [Cuando se cree una nueva lista](https://github.com/clase-programacion-avanzada/CPP-Workshop-5/blob/main/libs/List.h#L13) vacía, se debe crear un nuevo arreglo de tamaño `5`, este será el tamaño mínimo del arreglo `elements`. </br>
   Por otro lado, el tamaño inicial (`size`) debe ser `0` y se introducirá una nueva variable (es decir, un nuevo atributo) a la estructura List, llamada `capacity`, donde se guardará el tamaño total que tiene en ese momento el arreglo `elements`, que será `5`. </br> 
   En este punto debe agregar las variables, cambiar la definición de `elements` para que no sea un arreglo de tamaño fijo sino un apuntador de tipo `T`. También es necesario que el constructor se cambie para que cumpla con el comportamiento descrito en los párrafos anteriores.(0.5)</br></br>
2. Luego de realizar este cambio, será necesario cambiar la definición del [método `add`](https://github.com/clase-programacion-avanzada/CPP-Workshop-5/blob/main/libs/List.h#L17). </br>
   Este método debe validar si el tamaño (`size`) es igual a la capacidad (`capacity`), si es así, debe crear un nuevo array que tenga el doble del tamaño de la capacidad actual (`capacity * 2`).</br>
   Luego, debe copiar la información del atributo `elements` en este nuevo array. </br>

   Finalmente, se debe borrar el arreglo actual (`elements`), asignar  la dirección del nuevo array a este atributo y actualizar `capacity` para que tenga reflejado el nuevo valor (`capacity * 2`).(1.0)</br> </br>
3. El [método `remove`](https://github.com/clase-programacion-avanzada/CPP-Workshop-5/blob/main/libs/List.h#L22) también debe cambiar.</br>
   Este método debe verificar retornar `false` si el índice suministrado no está dentro del rango de los datos (es decir, no puede ser menor que 0 ni mayor que `size`) o si el valor de `elements` es `nullptr`.</br> 
   Si lo anterior no se cumple, debe mover los elementos del array `elements` a la izquierda (esto ya lo está haciendo el código) y reducir el tamaño en uno.</br>
   Finalmente, si el nuevo tamaño del array es menor que la mitad de la capacidad (`capacity / 2`) y la mitad de la capacidad es mayor que 5, se debe:
   1. crear un arreglo con la mitad del tamaño.
   2. Llenar el nuevo arreglo con la información de `elements`.
   3. Liberar la memoria de `elements`.
   4. Asignar a `elements` la dirección del array con la mitad de la capacidad. 
   5. Actualizar el valor de `capacity` a la mitad.(1.0)</br></br>
4. El [método `clear`](https://github.com/clase-programacion-avanzada/CPP-Workshop-5/blob/main/libs/List.h#L55) debe cambiar, pues no debería inicializar solo el valor del tamaño a 0. Debería, en cambio:
   1. Liberar la memoria (es decir eliminar) `elements`.
   2. Asignar el valor de `nullptr` a `elements`.
   3. Asignar el valor de 0 a `size` y a `capacity`.(0.5)

Para finalizar, **cada función dentro de list donde se reciba como parámetro un elemento de tipo T** debe hacerlo por referencia, esto es para evitar hacer una copia de los objetos cuando son estructuras complejas o muy grandes. 

Si necesita ver de forma más visual los algoritmos, puede encontrarlos en la parte izquierds del siguiente [miro board](https://miro.com/app/board/uXjVMYC93wc=/?share_link_id=770076763125).