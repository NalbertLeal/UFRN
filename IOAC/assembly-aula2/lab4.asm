	.data
str1: .asciiz "Resultado: "

	.text	
	.globl main
	
main:		li $t5, 10
		li $s0, 20
		j comecou
	
comecou:
		addi $t5, $t5,1
		j A
		
A:
		addi $t5, $t5,1
		j B

B:
		addi $t5, $t5,1
		j C
		
C:
		addi $t5, $t5,1
		j D
		
D:
		addi $t5, $t5,1
		j fim
	
fim:
		li $v0, 4
		la $a0, str1
		syscall

		
		li $v0, 1
		move $a0, $t5
		syscall
					
		li $v0, 10
		syscall
		
		
		