## Relevancia del problema.

Diariamente se recopilan enormes cantidades de datos e información útil desde
redes sociales, ventas, organizaciones [... % Rellenar]
Toda esta información sólo es útil si se extraen patrones y conocimiento de
estas grandes bases de datos. Ese conocimiento puede usarse para predecir y
para tomar decisiones basadas en la información.

 * Beneficios económicos:
     Optimización de decisiones logísticas y empresariales (tratamientos en
     hospitales, ventas de la empresa). Automatización de procesos humanos
     (detección y clasificación de especies o de dígitos).

 * Beneficios para los usuarios:
     Aprovechan el conocimiento de las grandes bases de datos en servicios
     (recomendaciones personalizadas, inteligencia)

 * Mejora de la vida de las personas:
     Automatización de procesos. Detección de enfermedades.

Todos los datos recolectados por una organización pueden ser útiles para
mejorar las decisiones futuras de la organización. Para usar los enormes
volúmenes de datos que se recolectan, es necesario encontrar patrones en
ellos. Un ejemplo de uso de clasificación de datos lo constituyen los anuncios
publicitarios de \texttt{Google Adds}: se recolecta información sobre las búsquedas en
la web de un usuario y se le muestra un determinado tipo de anuncios en función
de la clasificación de sus preferencias a través de la información recolectada.
Por tanto detrás de la clasificación de datos hay un beneficio económico
potencialmente explotable.

La clasificación puede usarse para predecir enfermedades (se estudia si una
persona tiene características genéticas determinadas y se puede predecir si padecerá o
podría padecer la enfermedad en función de ellas).

Puede suponer un importante ahorro en recursos para una empresa, esto es, se estudia qué
datos de los almacenados por una empresa resultan más relevantes para su utilidad, y se reducen
los recursos destinados a los menos relevantes.
    
Resulta relevante para las empresas la creación de perfiles de clientes efectuando 
clasificación a partir de unos datos aportados por el usuario. Por ejemplo, existen
empresas de préstamos rápidos vía contacto telefónico o internet que predicen si un 
determinado usuario devolverá el préstamo a partir de las respuestas aportadas por el mismo
a una serie de preguntas.


Referencia: Alex A. Freitas - A Survey of Evolutionary Algorithms for Data
Mining and Knowledge Discovery - Introduction

## Descripción del problema

Extracción de conocimiento de grandes bases de datos.

Un problema de clasificación es el problema de asignar una clase a cada una de
las instancias de un conjunto en función de sus atributos. (Por ejemplo,
clasificar flores por especie según las medidas de sus pétalos)

Normalmente poseeremos un conjunto de instancias de entrenamiento, ya clasificadas, que
usaremos como base para que el ordenador aprenda a clasificar las siguientes.
(En el ejemplo, tenemos un conjunto de flores de las que conocemos la especie ya
clasificadas).

El problema consistirá en clasificar las nuevas instancias que nos vayan
llegando, de las que sólo conoceremos los atributos.



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
