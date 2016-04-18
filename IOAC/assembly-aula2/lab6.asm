	.data	
str1:	.asciiz "Digite o primeiro numero: "
str2:	.asciiz "Digite o segundo numero: "
str3:	.asciiz "Resultado: "

	.text
	.globl main
	
main: 
	#Para simular, atribua valores para 
	#li $s1, 2
	#li $s2, 3 
	
	bne $s1, $s2, Else 		
	addi $s1, $s2, 1		  
	j EXIT				

Else: 

	addi $s1, $s1, 2   	

EXIT: 
	
	li $v0, 10	#codigo da chamada de sistema para encerrar o programa
	syscall		#chamada de sistema

