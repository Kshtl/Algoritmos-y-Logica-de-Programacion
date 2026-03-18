Proceso TrianguloInteligente
	
    Definir a, b, c, altura, angulo Como Real
    Definir tipoLados, tipoAngulo, mensaje Como Cadena
    Definir area Como Real
	
    Escribir "Ingrese lado 1:"
    Leer a
	
    Escribir "Ingrese lado 2:"
    Leer b
	
    Escribir "Ingrese lado 3:"
    Leer c
	
    Escribir "Ingrese altura:"
    Leer altura
	
    Escribir "Ingrese angulo principal:"
    Leer angulo
	
    // 1. Verificar si existe triangulo
    Si a + b > c Y a + c > b Y b + c > a Entonces
		
        Escribir "Validez: TRIANGULO VALIDO"
		
        // 2. Clasificacion por lados
        Si a = b Y b = c Entonces
            tipoLados <- "Equilatero"
        Sino
            Si a = b O a = c O b = c Entonces
                tipoLados <- "Isosceles"
            Sino
                tipoLados <- "Escaleno"
            FinSi
        FinSi
		
        // 3. Clasificacion por angulos
        Si angulo = 90 Entonces
            tipoAngulo <- "Rectangulo"
        Sino
            Si angulo < 90 Entonces
                tipoAngulo <- "Acutangulo"
            Sino
                tipoAngulo <- "Obtusangulo"
            FinSi
        FinSi
		
        // 4. Calculo de area (base = lado a)
        area <- (a * altura) / 2
		
        // 5. Verificar consistencia de la altura
        Si altura > a O altura > b O altura > c Entonces
            mensaje <- "Advertencia: altura inconsistente"
        Sino
            mensaje <- "Altura consistente"
        FinSi
		
        // Resultados
        Escribir "Tipo por lados: ", tipoLados
        Escribir "Tipo por angulos: ", tipoAngulo
        Escribir "Area: ", area
        Escribir mensaje
		
    Sino
        Escribir "Validez: NO ES TRIANGULO"
    FinSi
	
FinProceso