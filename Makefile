build:
	cd gnu-efi ; make bootloader
	cd kernel ; make kernel ; make buildimg
run:
	cd kernel ; make run
