#include <stdint.h>

static uint16_t* const VGA = (uint16_t*)0xB8000;

void kernel_main(uint32_t magic, void* mbi) {
    (void)magic; (void)mbi;

    const uint16_t color = 0x0F00;
    const char* msg = "Hello from my OS!";

    for (int i = 0; msg[i] != '\0'; i++) {
        VGA[i] = color | (uint8_t)msg[i];
    }
}
