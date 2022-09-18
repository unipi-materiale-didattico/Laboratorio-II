# Laboratorio-II

## Estensioni

Per mantenere coerente lo stile dei file usare la seguente estensione:

* [EditorConfig](https://marketplace.visualstudio.com/items?itemName=EditorConfig.EditorConfig) per VSCode
* [EditorConfig](https://plugins.jetbrains.com/plugin/7294-editorconfig) Per Clion

## Librerie

* ### stdutils

    ```C
    /**
     * This macro return the size of the given array
     * @param a
     */
    #define sizeOfArr(a) (int)(sizeof(a) / sizeof((a)[0]))

    /**
     * This function print array values
     * @param arr the array to print
     * @param size the length of the array
     */
    void print_array(int* arr, int size);
    ```
