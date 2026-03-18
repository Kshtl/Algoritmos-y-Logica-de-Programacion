Proceso Copiadora
	
    Definir hojas, tipoUsuario, horario, anillado, tipoImpresion Como Entero
    Definir precioHoja, subtotal, descuento, recargo, valorAnillado, total Como Real
	
    subtotal <- 0
    descuento <- 0
    recargo <- 0
    valorAnillado <- 0
	
    Escribir "Numero de hojas:"
    Leer hojas
	
    Escribir "Tipo de impresion (1=Blanco/Negro, 2=Color):"
    Leer tipoImpresion
	
    Escribir "Tipo de usuario (1=Estudiante, 2=Docente):"
    Leer tipoUsuario
	
    Escribir "Horario (1=Normal, 2=Nocturno):"
    Leer horario
	
    Escribir "Desea anillado? (1=Si, 0=No):"
    Leer anillado
	
    // Precio por hoja
    Si hojas <= 20 Entonces
        precioHoja <- 0.05
    Sino
        Si hojas <= 100 Entonces
            precioHoja <- 0.04
        Sino
            precioHoja <- 0.03
        FinSi
    FinSi
	
    // Aumento por color
    Si tipoImpresion = 2 Entonces
        precioHoja <- precioHoja + 0.02
    FinSi
	
    // Subtotal
    subtotal <- hojas * precioHoja
	
    // Descuento docente
    Si tipoUsuario = 2 Entonces
        descuento <- subtotal * 0.05
    FinSi
	
    // Descuento estudiante (solo si es mayor)
    Si tipoUsuario = 1 Y hojas > 50 Entonces
        Si subtotal * 0.08 > descuento Entonces
            descuento <- subtotal * 0.08
        FinSi
    FinSi
	
    // Recargo nocturno
    Si horario = 2 Entonces
        recargo <- subtotal * 0.10
    FinSi
	
    // Anillado
    Si anillado = 1 Entonces
        valorAnillado <- 2
		
        Si hojas > 100 Entonces
            valorAnillado <- valorAnillado * 0.8
        FinSi
    FinSi
	
    // Total
    total <- subtotal - descuento + recargo + valorAnillado
	
    Escribir "Subtotal impresion: ", subtotal
    Escribir "Descuento aplicado: ", descuento
    Escribir "Recargo: ", recargo
    Escribir "Valor anillado: ", valorAnillado
    Escribir "Total a pagar: ", total
	
FinProceso