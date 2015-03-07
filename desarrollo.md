## Descripción del problema

Un problema de clasificación consiste en asignar una clase a cada una de las
instancias de un conjunto, en función del valor del resto de sus atributos (==características).
Equivalentemente, se predice el atributo clase en una instancia dada, donde clase 
puede tomar sólo un número finito de valores, con la restricción de que una instancia
no puede pertenecer a dos clases simultáneamente.  (Por ejemplo, clasificar
flores por especie según las medidas de sus pétalos)

Se parte de un conjunto de instancias ya clasificadas, llamadas conjunto de entrenamiento,
con las que se generará un clasificador (una función capaz de predecir la clase para
una instancia dada).

Para cada una de las instancias del conjunto de datos test(de las que se desconoce
su clase y son conocidos el resto de atributos) se predecirá la clase, usando para
ello el clasificador generado. (En el ejemplo, tenemos un conjunto de flores de las 
que conocemos la especie ya clasificadas).

## Relevancia del problema.

Diariamente se recopilan enormes cantidades de datos e información útil desde
redes sociales, ventas, organizaciones.
Toda esta información sólo es útil si se extraen patrones y conocimiento de
estas grandes bases de datos. Ese conocimiento puede usarse para predecir y
para tomar decisiones basadas en la información.

 * Beneficios económicos:
     Optimización de decisiones logísticas y empresariales (tratamientos en
     hospitales, ventas de la empresa). Automatización de procesos humanos
     (detección y clasificación de especies o de dígitos). 
     
     Todos los datos recolectados por una organización pueden ser útiles para mejorar 
     las decisiones futuras de la organización. Para usar los enormes volúmenes 
     de datos que se recolectan, es necesario encontrar patrones en ellos. Un
     ejemplo de uso de clasificación de datos lo constituyen los anuncios
     publicitarios de *Google Ads*: se recolecta información sobre las búsquedas 
     en la web de un usuario y se le muestra un determinado tipo de anuncios 
     en función de la clasificación de sus preferencias a través de la información
     recolectada. Por tanto detrás de la clasificación de datos hay un beneficio
     económico potencialmente explotable.

     Puede suponer un importante ahorro en recursos para una empresa, esto es, se estudia qué
     datos de los almacenados por una empresa resultan más relevantes para su utilidad, y se reducen
     los recursos destinados a los menos relevantes.

 * Beneficios para los usuarios:
     Aprovechan el conocimiento de las grandes bases de datos en servicios
     (recomendaciones personalizadas, inteligencia).
     
     Ejemplo de recomendaciones personalizadas son por ejemplo las que efectúa *Youtube*
     cuando nos sugiere vídeos que podrían ser de nuestro agrado.
     
     Resulta relevante para las empresas la creación de perfiles de clientes efectuando 
     clasificación a partir de unos datos aportados por el usuario. Por ejemplo, existen
     empresas de préstamos rápidos vía contacto telefónico o internet que predicen si un 
     determinado usuario devolverá el préstamo a partir de las respuestas aportadas por el mismo
     a una serie de preguntas.     

 * Mejora de la vida de las personas:
     Automatización de procesos. Detección de enfermedades. La clasificación puede
     usarse para predecir enfermedades (se estudia si una persona tiene características
     genéticas determinadas y se puede predecir si padecerá o podría padecer la enfermedad
     en función de su perfil genético).


## Justificación del uso de la IA

En el mundo de la minería de datos, y concretamente en el problema de 
clasificación, se pretende predecir nuevos datos a partir de la información
con la que contamos. Esto requiere de técnicas que permitan extraer patrones,
relaciones entre los datos a predecir y los conocidos, incluso aquellas que
los humanos no sepamos apreciar, a causa de nuestra perspectiva de cada
problema concreto.

Además, la cantidad ingente de datos (tanto instancias
como atributos) que se suelen analizar impiden que una persona aborde el
problema. Por tanto, no solo se utiliza la gran capacidad de computación
disponible, sino que se han de implementar heurísticas que nos permitan
realizar la clasificación de los nuevos datos, de forma racional, es decir,
atendiendo a ciertos criterios acerca de cómo se relacionan los datos.

## Aplicación 1. Predicción de la diabetes

Se dispone de unos determinados factores médicos para una persona (número de embarazos,
niveles de azúcar en sangre, presión sanguínea, edad ...) y se pretende predecir
si una persona padecerá diabetes o no en función de los valores que presente para
dichos factores médicos.

Nos encontramos ante un problema de clasificación binaria (tenemos dos valores posibles
para el atributo Diabetes - 0,1). Uno de los clasificadores que ofrece buenos resultados 
para este problema son los árboles de decisión (ejemplos de algoritmos para generar dichos
árboles son C4.5, ID3, CART,...).

Los algoritmos de creación de árboles se basan en:

* Selección de atributos:
     Se escoge a cada paso el atributo que mejor separación efectúe entre los
     datos. Matemáticamente, este atributo es el que maximiza medidas como la ganancia de información (IG).
     En el árbol este paso se refleja en la creación de un nodo.

* Selección de clase:
     Se convierte un nodo del árbol en hoja cuando todas las instancias que cumplen la condición
     de dicho nodo son de la misma clase; o bien cuando se acaban los atributos por los que ramificar
     el árbol (en dicho caso la clase del nodo hoja es la mayoritaria del conjunto que cumpla las
     condiciones de dicho nodo); o bien cuando ninguna instancia cumple las condiciones de dicho nodo,
     en cuyo caso, el nodo tendrá la clase mayoritaria del padre.

## Aplicación 2. Reconocedor de dígitos

El problema consiste en dada una imagen en blanco y negro cuadrada, que contiene
píxeles codificados como un número entero entre 0 y 255 (donde el 0 es blanco
y el valor 255 representa el color negro), se pretende predecir en base al
valor de dichos píxeles, qué dígito es el que contiene la imagen.

La importancia de este problema, que podría extenderse a letras también, reside en
la detección automática de captchas, que es explotada por programas de descarga 
automática como *JDownloader*.

Se trata de un problema multiclase (tenemos 10 clases - dígitos del 0 al 9).
Para su resolución se puede emplear el algoritmo de clasificación KNN (K Nearest neighbors).
Este algoritmo consiste en dado un espacio métrico (y por tanto una función distancia),
hallar para una instancia dada los k puntos más cercanos a la misma del conjunto
de entrenamiento, y tomar la clase mayoritaria de entre los mismos.

En el problema resuelto como ejemplo, las imágenes son de 28x28 píxeles, y los
conjuntos de entrenamiento y de test tienen cada uno 42000 instancias, lo que ofrece
una visión de que este problema no puede ser resuelto sin apoyo de técnicas computacionales.

La precisión del algoritmo en la predicción dependerá del espacio métrico en el que nos
hallemos.

## Aplicación 3. Clasificación multietiqueta de música en emociones

La detección de emociones en música se puede modelar como un problema de 
clasificación multietiqueta. Un problema de este tipo implica que una instancia
puede pertenecer a más de una clase, en cuyo caso las denominamos etiquetas.
Por tanto, el problema requiere predecir, para cada nueva instancia, el conjunto de 
etiquetas a las que pertenece.

Observamos que esta variante del problema es mucho más difícil que las anteriores,
puesto que el número de respuestas posibles aumenta exponencialmente con el número
de etiquetas (2^l para l etiquetas). No sólo eso, sino que desde el punto de vista
del aprendizaje, ya no hay que tener en cuenta únicamente las relaciones entre los
atributos, sino que además tenemos la posibilidad de estudiar las relaciones entre 
las etiquetas.

En general, este problema se puede tratar de dos maneras: transformación de los 
datos en uno o varios problemas de un tipo más simple, o adaptación de los algoritmos
conocidos a este tipo de problemas. No se desarrollan técnicas propias en cuanto a
algoritmos de clasificación multietiqueta porque las adaptaciones de algoritmos, o
aquellos basados en las transformaciones, suelen ser suficientemente precisos.

<!-- El texto en cita es menos importante y se puede saltar si no hay tiempo -->
> Por un lado, las transformaciones de los datos reducen el problema a tantos
  problemas binarios como etiquetas (transformación Binary Relevance), o bien a 
  un problema multiclase considerando el conjunto de etiquetas de cada instancia 
  como una posible clase (transformación Label Powerset). Estas transformaciones 
  utilizan algún algoritmo de clasificación por debajo para realizar el trabajo 
  sobre los problemas más sencillos, y después agrupan o adaptan las soluciones 
  obtenidas a una para el problema multietiqueta.

> Por otro lado, algunos algoritmos que se utilizan se basan en mejorar la técnica
  Label Powerset reduciendo el número de etiquetas y entrenando varios clasificadores
  (algoritmos como HOMER, RAkEL), y otros tratan de adaptarse a la nueva situación
  realizando cálculos con las etiquetas (por ejemplo, ML-kNN, que realiza una cuenta
  de ocurrencias de etiquetas para las instancias más cercanas).

Algunos de los avances en el tratamiento de este problema, sin embargo, no están
en la clasificación en sí, sino en el preprocesamiento del dataset (un tratamiento
que se realiza a los datos para mejorar la solución del clasificador). Existen
nuevas técnicas que, basándose en medidas de desequilibrio de etiquetas y otras
relaciones entre ellas, permiten actuar sobre el dataset (por ejemplo, desactivando
etiquetas mayoritarias de ciertas instancias) de forma que al aplicar un 
clasificador sobre él los resultados sean mejores.

Uno de los algoritmos más interesantes es *HOMER*, que agrupa las etiquetas en
grupos atendiendo a su similitud (si suelen aparecer juntas en las mismas 
instancias) y crea clasificadores capaces de distinguir entre ellas, para luego
reunir la información de todos los clasificadores en uno grande que solo distinga
entre los grupos de etiquetas.

Para la aplicación de clasificación de música, se utilizaron casi 600 fragmentos
de canciones de 30 segundos y se analizaron el ritmo y el timbre, dando lugar a 
más de 70 atributos de entrada para cada canción. En la figura siguiente se
muestra visualmente cómo se relacionan sus 6 etiquetas, algo que un algoritmo de
preprocesamiento o clasificación deberá tener en cuenta y actuar en consecuencia:

![emotions concurrence plot](imgs/emotions-concurrence.png)

Referencias:
  - Trohidis, K.; Tsoumakas, G.; Kalliris, G.; Vlahavas, I. - Multi-Label 
  Classification of Music into Emotions

> - Min-Ling Zhang; Zhi-Hua Zhou - ML-kNN: A Lazy Learning Approach to Multi-Label 
  Learning
  - Tsoumakas, G.; Katakis, I.; Vlahavas, I. - Effective and Efficient Multilabel 
  Classification in Domains with Large Number of Labels
  - Tsoumakas, G.; Katakis, I.; Vlahavas, I. - Random k-Labelsets for Multi-Label 
  Classification