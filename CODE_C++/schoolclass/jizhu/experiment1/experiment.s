.file	"experiment.c"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.section	.rodata
	.align	3
.LC0:
	.string	"%d"
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-144
	sd	ra,136(sp)
	sd	s0,128(sp)
	addi	s0,sp,144
	li	a5,27
	sw	a5,-20(s0)
	sw	zero,-28(s0)
	j	.L2
.L4:
	lw	a5,-20(s0)
	andi	a5,a5,1
	sext.w	a5,a5
	beq	a5,zero,.L3
	lw	a5,-28(s0)
	slli	a5,a5,2
	addi	a4,s0,-16
	add	a5,a4,a5
	li	a4,1
	sw	a4,-64(a5)
.L3:
	lw	a5,-20(s0)
	sraiw	a5,a5,1
	sw	a5,-20(s0)
	lw	a5,-28(s0)
	addiw	a5,a5,1
	sw	a5,-28(s0)
.L2:
	lw	a5,-20(s0)
	sext.w	a5,a5
	bgt	a5,zero,.L4
	sw	zero,-32(s0)
	sw	zero,-36(s0)
	j	.L5
.L9:
	lw	a5,-36(s0)
	sw	a5,-32(s0)
	sw	zero,-40(s0)
	j	.L6
.L8:
	lw	a5,-32(s0)
	slli	a5,a5,2
	addi	a4,s0,-16
	add	a5,a4,a5
	lw	a4,-128(a5)
	lw	a5,-36(s0)
	slli	a5,a5,2
	addi	a3,s0,-16
	add	a5,a3,a5
	lw	a3,-64(a5)
	lw	a5,-40(s0)
	slli	a5,a5,2
	addi	a2,s0,-16
	add	a5,a2,a5
	lw	a5,-64(a5)
	and	a5,a3,a5
	sext.w	a5,a5
	addw	a5,a4,a5
	sext.w	a4,a5
	lw	a5,-32(s0)
	slli	a5,a5,2
	addi	a3,s0,-16
	add	a5,a3,a5
	sw	a4,-128(a5)
	lw	a5,-32(s0)
	slli	a5,a5,2
	addi	a4,s0,-16
	add	a5,a4,a5
	lw	a5,-128(a5)
	mv	a4,a5
	li	a5,1
	ble	a4,a5,.L7
	lw	a5,-32(s0)
	slli	a5,a5,2
	addi	a4,s0,-16
	add	a5,a4,a5
	lw	a5,-128(a5)
	mv	a4,a5
	sraiw	a5,a4,31
	srliw	a5,a5,31
	addw	a4,a4,a5
	andi	a4,a4,1
	subw	a5,a4,a5
	sext.w	a4,a5
	lw	a5,-32(s0)
	slli	a5,a5,2
	addi	a3,s0,-16
	add	a5,a3,a5
	sw	a4,-128(a5)
	lw	a5,-32(s0)
	sext.w	a4,a5
	li	a5,14
	bgt	a4,a5,.L7
	lw	a5,-32(s0)
	addiw	a5,a5,1
	sext.w	a4,a5
	slli	a5,a4,2
	addi	a3,s0,-16
	add	a5,a3,a5
	lw	a5,-128(a5)
	addiw	a5,a5,1
	sext.w	a3,a5
	slli	a5,a4,2
	addi	a4,s0,-16
	add	a5,a4,a5
	sw	a3,-128(a5)
.L7:
	lw	a5,-32(s0)
	addiw	a5,a5,1
	sw	a5,-32(s0)
	lw	a5,-40(s0)
	addiw	a5,a5,1
	sw	a5,-40(s0)
.L6:
	lw	a4,-40(s0)
	lw	a5,-28(s0)
	sext.w	a4,a4
	sext.w	a5,a5
	blt	a4,a5,.L8
	lw	a5,-36(s0)
	addiw	a5,a5,1
	sw	a5,-36(s0)
.L5:
	lw	a4,-36(s0)
	lw	a5,-28(s0)
	sext.w	a4,a4
	sext.w	a5,a5
	blt	a4,a5,.L9
	li	a5,1
	sw	a5,-44(s0)
	sw	zero,-48(s0)
	j	.L10
.L12:
	lw	a5,-48(s0)
	slli	a5,a5,2
	addi	a4,s0,-16
	add	a5,a4,a5
	lw	a5,-128(a5)
	mv	a4,a5
	li	a5,1
	bne	a4,a5,.L11
	lw	a4,-24(s0)
	lw	a5,-44(s0)
	addw	a5,a4,a5
	sw	a5,-24(s0)
.L11:
	lw	a5,-44(s0)
	slliw	a5,a5,1
	sw	a5,-44(s0)
	lw	a5,-48(s0)
	addiw	a5,a5,1
	sw	a5,-48(s0)
.L10:
	lw	a5,-48(s0)
	sext.w	a4,a5
	li	a5,15
	ble	a4,a5,.L12
	lw	a5,-24(s0)
	mv	a1,a5
	lui	a5,%hi(.LC0)
	addi	a0,a5,%lo(.LC0)
	call	printf
	li	a5,0
	mv	a0,a5
	ld	ra,136(sp)
	ld	s0,128(sp)
	addi	sp,sp,144
	jr	ra
	.size	main, .-main
	.ident	"GCC: (GNU) 9.2.0"