# Evaluacion-de-Polinomios

Durante milenia, los polinomios se han desarrollado a ser parte de la vida cotidiana dentro de las culturas con mayor impacto global. Ya sea que esta implementación fuese para el beneficio de las masas por medio de la construcción de canales, estructuras metropolitanas o incluso para la creación de un sistema de calendario. Todos estos aspectos en los cuales se les encuentra cabida a los polinomios son justamente los usos que se les dieron a los polinomios en la china antigua. Gracias a que el país oriental necesitaba de un gran nivel de protección por sus incontables kilómetros cuadrados, los cálculos de polinomios necesarios para sus construcciones llegaban a ser tan grandes que—por medio de un sentimiento casi darwinista—por necesidad a realizar cálculos tan grandes, fue donde primero se vio el desarrollo de este tipo de herramientas computacionales lo suficientemente eficientes con los recursos con los que contaban. Sin embargo, este tipo de algoritmos antiguos solo cobraron reconocimiento hasta años después bajo el nombre del matemático inglés, William George Horner, quien originalmente lo habría atribuido al matemático italiano, Joseph-Louis Lagrange. El método de Horner consiste en pocas palabras, aumentar la eficiencia con la que se evalúan funciones polinómicas. Por naturaleza, e incluso si un intenta imaginar tal evaluación extensa de polinomios—tanto como para nosotros como para una computadora—este proceso llegar a ser exhausto y altamente propenso a error. Debido a esto, el método de Horner el cual está expresado en forma de un algoritmo el cual, al aprovechar la propiedad distributiva del álgebra, se organiza de tal manera que evita calcular potencias de **x** una y otra vez. Paso por paso, lo que hace es extraer los coeficientes de un polinomio para después ordenar estos en orden descendente tal que el primero en la lista (o i=[0] en un programa) sea el valor del polinomio con el menor grado, o sea, el valor c que corresponde a un coeficiente en un polinomio. Al hacer esto, lo que hace es multiplicar de forma iterativa las descomposiciones distributivas del polinomio en multiplicaciones y sumas secuenciales en x, minimizando drásticamente así, tanto el tiempo, cono el margen de error que hay al realizar una evaluación de polinomios extensa. 

##Requisitos del Sistema

Los requisitos del sistema son los siguientes: 

C++ Executable en la versión C++ 20 estándar. Las librerías necesarias para su ejecución están ya descritas en el archivo principal del programa y las cuales son accesibles y aptas para correr tanto en MacOS, Linux o Windows. Específicamente, el código fue creado y corrido en el sistema macOS Sequoia 15.3.2.

##Instrucciones de compilación y ejecución
Abajo, se adjuntan los pasos a seguir para ejecutar el código exitosamente desde una terminal de preferencia:
1.
   ```sh
   git clone https://github.com/jovannareyesc/Evaluacion-de-Polinomios
   ```
2. 
   ```sh
   cd Evaluacion-de-Polinomios
   ```
3. 
   ```sh
   g++ main.cpp -o main -std=c++20
   ```
4. 
   ```sh
   ./main
   ```

##Resultados experimentales y gráfica comparativa


![graficacomparativa](graficacomparativa.png)

##Análisis de resultados

##Conclusiones
Como ya comentado, 
