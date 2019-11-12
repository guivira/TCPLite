#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <stdio.h>
using namespace std;

class Window{
private:
    /*Variables privadas*/
    int w_len; ///< Tamaño de la ventana.
    int frame_len; ///< Tamaño de los fragmentos en la ventana.
    char ** ventana; ///< Ventana donde se guardan los fragmentos de archivo.
    int nMin; ///< El número de paquete más pequeño guardado.
    int item_counter; ///< Cantidad de elementos guardados.
    int last_filled; ///< El número de paquete más grande guardado.
    bool * status; ///< Estado (vacío/lleno) de cada una de las posisciones de la ventana.

    /*Métodos privados*/
    /**
     * @brief copy_to_me copia en el punto de la ventana señalada el fragmento ingresado.
     * @param pivote posición de la ventana a ingresar el fragmento.
     * @param source fragmento fuente a ser ingresado.
     */
    void copy_to_me(int pivote, char * source);

public:
    /*Métodos públicos*/

    /**
     * @brief Window constructor que inicializa todos los datos que se usan en la clase.
     * @param w_len longitud de la ventana.
     * @param frame_len tamaño máximo de los fragmentos a guardar.
     */
    Window(int w_len, int frame_len);

    /**
     *  @brief ~Window destructor de la clase, borra las instancias hechas.
     */
    ~Window();

    /**
     * @brief put intenta insertar un fragmento en la ventana, solo si está en el rango.
     * @param num_package especifíca el número de fragmento que desea ingresar.
     * @param source es el fragmento a ser ingresado.
     * @return 1 si logró insertar el fragmento
     */
    int put(int num_package, char * source);

    /**
     * @brief get_recv intenta obtener y sacar de la ventana el fragmento más pequeño existente.
     * @param dest buffer donde se desea enviar el fragmento.
     * @return
     * 1 existe el fragmento y se logró sacar con éxito.
     * 0 no existe el fragmento y no se logró sacar con éxito.
     */
    int get_recv(char * dest);

    /**
     * @brief copy_to_others copia lo que hay en el buffer source, dentro del buffer dest,
     * todo esto con tamaño frame_len.
     * @param dest buffer destino de la copia.
     * @param source buffer fuente de la copia.
     */
    void copy_to_others(char * dest, char * source);

    /**
     * @brief check_status permite imprimir todas las variables esenciales de la ventana.
     */
    void check_status();

    /**
     * @brief print imprime todo el contenido activo en la ventana.
     */
    void print();

    /**
     * @brief get_send obtiene el número de p
     * @param dest
     * @param num_package
     * @return
     */
    int get_send(char * dest, int num_package);

    /**
     * @brief get_nMin obtiene el valor del paquete más pequeño en la ventana y lo retorna.
     * @return paquete más pequeño en la ventana (nMin).
     */
    int get_nMin();

    /**
     * @brief get_W_len obtiene el tamaño de la ventana y lo retorna.
     * @return tamaño de la ventana.
     */
    int get_W_len();

    /**
     * @brief empty verifica si existe algún elemento en la ventana.
     * @return
     * true si la ventana está vacía.
     * false si la ventana no está vacía.
     */
    bool empty();

    /**
     * @brief get_last obtiene el último paquete que se ingresó en la ventana.
     * @return el último paquete ingresado.
     */
    int get_last();

    /**
     * @brief get_frame_len obtiene el tamaño asignado para cada fragmento.
     * @return Tamaño asignado para cada fragmento.
     */
    int get_frame_len();

    /**
     * @brief set_nMin cambia el valor el paquete más pequeño ingresado, y con ello el rango
     * de la ventana.
     * @param num_package el número de paquete, con el cual se desea cambiar nMin.
     */
    void set_nMin(int num_package);
};

#endif // WINDOW_H
