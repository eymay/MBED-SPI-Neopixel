#include "mbed.h"
#include <cstdint>
#include <cstdio>
#include "neopixel.h"


#define fade_delay 200000
#define fade_step 16


void *handle;
int main()
{

    initNeo(&handle);

    setNeoRGB(handle, 0xFF, 0xFF, 0xFF);
    printf("Constant White Colour for 4s \n");
    wait_us(1000000);
    printf("Fading In and Out \n");

    while (true) {
        uint8_t i = 0;
        
        while(i < 255 - fade_step){
            printf("redup %d", i);
            setNeoRGB(handle, i, 0x00, 0x00);
            wait_us(fade_delay);
            i+=fade_step;
        }
        i = 255;
        while(i > 0x00 + fade_step){
            printf("reddown %d", i);
            setNeoRGB(handle, i, 0x00, 0x00);
            wait_us(fade_delay);
            i-=fade_step;
        }
        printf("\n");
        while(i < 255 - fade_step){
            printf("greenup %d", i);
            setNeoRGB(handle, 0x00, i, 0x00);
            wait_us(fade_delay);
            i+=fade_step;
        }
        i = 255;
        while(i > 0x00 + fade_step){
            printf("greendown %d", i);
            setNeoRGB(handle, 0x00, i, 0x00);
            wait_us(fade_delay);
            i-=fade_step;
        }
        printf("\n");
        while(i < 255 - fade_step){
            printf("blueup %d", i);
            setNeoRGB(handle, 0x00, 0x00, i);
            wait_us(fade_delay);
            i+=fade_step;
        }
        i = 255;
        while(i > 0x00 + fade_step){
            printf("bluedown %d", i);
            setNeoRGB(handle, 0x00, 0x00, i);
            wait_us(fade_delay);
            i-=fade_step;
        }
        printf("\n");
        

    }
     
}

