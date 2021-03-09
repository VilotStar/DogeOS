#include "BasicRenderer.h"

BasicRenderer::BasicRenderer(Framebuffer* targetFramebuffer, PSF1_FONT* psf1_Font){
    TargetFramebuffer = targetFramebuffer;
    PSF1_Font = psf1_Font;
    Color = 0xffffffff;
    CursorPos = {0,0};
}

void BasicRenderer::Print(const char* str) {
	char* chr = (char*)str;
	while (*chr != 0) {
		PutChar(*chr, CursorPos.X, CursorPos.Y);
		CursorPos.X+=8;
		if (CursorPos.X + 8 > TargetFramebuffer->Width) {
			CursorPos.X = 0;
			CursorPos.Y += 16;
		}
		chr++;
	}
}

void BasicRenderer::PutChar(char chr, unsigned int xOff, unsigned int yOff) {
	unsigned int* pixPtr = (unsigned int*)TargetFramebuffer->BaseAddress;
	char* fontPtr = (char*)PSF1_Font->glyphBuffer + (chr * PSF1_Font->psf1_Header->charsize);
	for (unsigned long y = yOff; y < yOff + 16; y++) {
		for (unsigned long x = xOff; x < xOff + 8; x++) {
			if ((*fontPtr & (0b10000000 >> (x - xOff))) > 0) {
				*(unsigned int*)(pixPtr + x + (y * TargetFramebuffer->PixelPerScanline)) = Color;
			}
		}
		fontPtr++;
	}
}