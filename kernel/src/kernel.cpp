#include <stdint.h>
#include "BasicRenderer.h"
#include "cstr.h"

struct BootInfo {
	Framebuffer* framebuffer;
	PSF1_FONT* psf1_Font;
	void* mMap;
	uint64_t mMapSize;
	uint64_t mMapDescSize;
};

extern "C" void _start(BootInfo* BootInfo) {
	/*unsigned int BBP = 4; // Bytes per line

	CursorPos.X = 50;
	CursorPos.Y = 120;

	putChar(frameBuffer, psf1_font, 0xffffffff, 'F', 15, 15);
	
	for (int k = 0; k < 50; k+=1){
	Print(frameBuffer, psf1_font, 0xffffffff, "Ok");
	}*/

	BasicRenderer newRenderer = BasicRenderer(BootInfo->framebuffer, BootInfo->psf1_Font);
	newRenderer.Print("Test 123 C++");
	newRenderer.CursorPos = {0, newRenderer.CursorPos.Y + 16};
	//
	newRenderer.PutChar('l', 50, 50);
	//
	newRenderer.Print(to_string((uint64_t)7331));
	newRenderer.CursorPos = {0, newRenderer.CursorPos.Y + 16};
	newRenderer.Print(to_string((int64_t)-7331));

    return;
}






/*for (unsigned int i = 0; i < 30; i++) {
		unsigned int y = 49+i;

		for (unsigned int x = 0; x < frameBuffer->Width * BBP; x+=BBP) {
			*(unsigned int*)(x + (y * frameBuffer->PixelPerScanline * BBP) + frameBuffer->BaseAddress) = 0xff00ffff;
		}
	}*/