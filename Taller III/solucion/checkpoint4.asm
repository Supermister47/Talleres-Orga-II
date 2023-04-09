extern malloc
extern free
extern fprintf

section .data

section .text

global strCmp
global strClone
global strDelete
global strPrint
global strLen

; ** String **

; int32_t strCmp(char* a, char* b)
strCmp:
	ret

; char* strClone(char* a)
strClone:
	; Fue necesario agregar -no-pie como flag para compilar el checkpoint
	; Prólogo
	push rbp	; Ahora el stack está alineado a 16bytes
	mov rsp, rbp

	; Tengo que reservar espacio en el heap para copiar el string
	; Llamo a strLen para saber cuánto espacio reservar
	call strLen
	mov rdi, rsi	; Copio el parámetro 'a' a otro registro para usar malloc
	mov rsi, rax	; Muevo la longitud del string para pasarselo a malloc como parámetro
	inc rsi			; Sumo 1 para reservar espacio para el caracter nulo '\0'
	mov rcx, rsi	; Copio strLen para luego saber cuántas iteraciones hacer en la copia
	call malloc		; Llamo a malloc, 1caracter es 1byte

	; Copio el string
	.cycle:
		mov rsi, [rdi]
		mov [rax], rsi
		inc rdi
		inc rax
		loop .cycle
	
	; Epílogo
	pop rbp
	ret

; void strDelete(char* a)
strDelete:
	; Esto no funciona porque copia el puntero al string
	; pero no el string en sí mismo
	mov rax, rdi
	call free
	ret

; void strPrint(char* a, FILE* pFile)
strPrint:
	ret

; uint32_t strLen(char* a)
strLen:
	; Prólogo
	push rbp
	mov rsp, rbp

	xor rax, rax
	dec rax		; Seteo rax en -1 para hacer el do..while
	.cycle:
	; Tengo que especificarle a CMP que haga una comparación de 1byte, por eso va el BYTE como prefijo al inmediato
		cmp [rdi], BYTE 0x00	
		inc rax
		jnz .cycle

	; Epílogo
	pop rbp
	ret


