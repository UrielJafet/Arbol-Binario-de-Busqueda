# 🌳 Árbol Binario de Búsqueda en C++

## 📖 Descripción
Este proyecto implementa un **Árbol Binario de Búsqueda (ABB)** en C++ que permite:  
- Insertar nodos de manera ordenada.  
- Recorrer el árbol con **inOrder**.  
- Eliminar nodos mediante dos estrategias:
  - `eliminarIzq(x)`: reemplaza el nodo con el **mayor valor del subárbol izquierdo**.  
  - `eliminarDer(x)`: reemplaza el nodo con el **menor valor del subárbol derecho**.  
- Buscar nodos mayores o menores.  
- Obtener la raíz y podar el árbol para liberar memoria.  

El proyecto combina **punteros, recursión y gestión dinámica de memoria**, mostrando buenas prácticas en C++ para estructuras de datos.  

---

## ⚙️ Características
- Inserción recursiva de nodos manteniendo la propiedad del ABB.  
- Eliminación de nodos con uno, dos hijos o hoja.  
- Recorridos inOrder para impresión ordenada de nodos.  
- Métodos auxiliares para buscar el mayor o menor nodo.  
- Destructor que libera todos los nodos evitando fugas de memoria.  

