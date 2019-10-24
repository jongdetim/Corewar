#debut du mega truc qu'il est trop dur a faire

.name "Jumper !"
.comment "en fait C forker !"

jump:	
	zjmp %:jump1
	ld %11, r2
	ld %11, r3
	ld %12, r4
	sub r2, r3, r5
	add r3, r4, r6
	ld %20, r16
	and -5, r4, r7
	or r2, r3, r8
	xor %10, %12, r9
	sub r2, r3, r10


jump1:
	zjmp %:jump2

jump2:
	fork %:jump
	zjmp %:jump
	

	

